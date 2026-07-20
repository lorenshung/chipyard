package ospi

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.{Config, Field, Parameters}
import freechips.rocketchip.subsystem.{BaseSubsystem, PBUS}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.interrupts.{IntSourceNode, IntSourcePortSimple}
import freechips.rocketchip.prci._
import freechips.rocketchip.regmapper.{RegField, RegReadFn, RegWriteFn}
import freechips.rocketchip.tilelink._

/** SoC-level parameters for the HM01B0 capture peripheral. */
case class OspiParams(
  address:          BigInt = 0x10080000L,
  dataWidth:        Int    = 8,
  defaultWidth:     Int    = 324,
  defaultHeight:    Int    = 244,
  maxWidth:         Int    = 324,
  maxHeight:        Int    = 324,
  captureFifoDepth: Int    = 1024,
  frameBufferDepth: Int    = 324 * 324 + 1
) {
  require(frameBufferDepth >= maxWidth * maxHeight + 1,
    "frameBufferDepth must hold a maximum-size frame and its EOF marker")
}

case object OspiKey extends Field[Option[OspiParams]](None)

/** TileLink MMIO wrapper around [[HM01B0Capture]].
  *
  * The capture core drains continuously into a block-RAM frame buffer. This is essential: the
  * core only commits `frameCount` when its in-band EOF marker is accepted, so exposing the CDC
  * FIFO directly to software would make "wait for frame, then drain" deadlock. The default frame
  * buffer holds a complete 324x324 frame plus its EOF marker.
  *
  * Register map (word offsets):
  *   0x00 CTRL      [0]=enable [1]=continuous [2]=irqEnable
  *                  write-one pulses: [3]=trigger [4]=clear status/IRQ [5]=flush frame buffer
  *   0x04 GEOM      [15:0]=expWidth [31:16]=expHeight
  *   0x08 MCLKDIV   MCLK = sysclk / (2*(mclkDiv+1))
  *   0x0c FIFOCOUNT number of buffered pixel/marker beats (RO)
  *   0x10 FRAMECNT  completed frames committed to the frame buffer (RO)
  *   0x14 LASTWIDTH measured width of the last completed frame (RO)
  *   0x18 LASTHEIGHT measured height of the last completed frame (RO)
  *   0x1c FLAGS     [0]=dataValid [1]=overflow [2]=geomErr [3]=sensorInt [4]=busy
  *                  [5]=irqPending [6]=frameBufferFull (RO)
  *   0x20 DATA      nonblocking read/pop: [31]=valid [10]=eof [9]=eol [8]=sof [7:0]=data
  *   0x24 CAPACITY  frame-buffer capacity in beats (RO)
  */
class OspiCapture(params: OspiParams, beatBytes: Int)(implicit p: Parameters)
    extends ClockSinkDomain(ClockSinkParameters())(p) {
  val device = new SimpleDevice("ospi", Seq("ucbbar,ospi-hm01b0"))
  val node = TLRegisterNode(
    Seq(AddressSet(params.address, 4096 - 1)),
    device,
    "reg/control",
    beatBytes = beatBytes)
  val intnode = IntSourceNode(IntSourcePortSimple(num = 1, resources = device.int))

  override lazy val module = new OspiImpl
  class OspiImpl extends Impl {
    private val cp = CaptureParams(
      dataWidth = params.dataWidth,
      defaultWidth = params.defaultWidth,
      defaultHeight = params.defaultHeight,
      maxWidth = params.maxWidth,
      maxHeight = params.maxHeight,
      fifoDepth = params.captureFifoDepth)

    val io = IO(new SensorIO(params.dataWidth))

    withClockAndReset(clock, reset) {
      val capture = Module(new HM01B0Capture(cp))
      // Isolate the async-reset CDC dequeue flag from the block-RAM write controls. Besides adding
      // two beats of elasticity, this synchronously reset register queue lets Vivado analyze the
      // frame-buffer enables without REQP-1839 async-control warnings.
      val capturePipe = Module(new Queue(new PixelFlit(cp.dataWidth), entries = 2))
      val frameBuffer = Module(new FrameBuffer(cp, params.frameBufferDepth))

      // Sensor pins: chip IO <-> capture core.
      capture.io.sensor.pclk := io.pclk
      capture.io.sensor.fvld := io.fvld
      capture.io.sensor.lvld := io.lvld
      capture.io.sensor.d    := io.d
      capture.io.sensor.intr := io.intr
      io.mclk := capture.io.sensor.mclk
      io.trig := capture.io.sensor.trig

      // Persistent controls and write-one command pulses.
      val enableReg     = RegInit(false.B)
      val continuousReg = RegInit(false.B)
      val irqEnableReg  = RegInit(false.B)
      val geomInit      = (BigInt(cp.defaultHeight) << 16) | BigInt(cp.defaultWidth)
      val geomReg       = RegInit(geomInit.U(32.W))
      val mclkDivReg    = RegInit(0.U(cp.mclkDivWidth.W))
      val triggerPulse  = WireDefault(false.B)
      val clearPulse    = WireDefault(false.B)
      val flushPulse    = WireDefault(false.B)

      val triggerWrite = RegWriteFn((valid: Bool, data: UInt) => {
        triggerPulse := valid && data(0)
        true.B
      })
      val clearWrite = RegWriteFn((valid: Bool, data: UInt) => {
        clearPulse := valid && data(0)
        true.B
      })
      val flushWrite = RegWriteFn((valid: Bool, data: UInt) => {
        flushPulse := valid && data(0)
        true.B
      })

      capture.io.ctrl.enable     := enableReg
      capture.io.ctrl.continuous := continuousReg
      capture.io.ctrl.irqEnable  := irqEnableReg
      capture.io.ctrl.trigPulse  := triggerPulse
      capture.io.ctrl.clear      := clearPulse
      capture.io.ctrl.mclkDiv    := mclkDivReg
      capture.io.ctrl.expWidth   := geomReg(cp.pixCountWidth - 1, 0)
      capture.io.ctrl.expHeight  := geomReg(16 + cp.lineCountWidth - 1, 16)

      // Drain the CDC FIFO autonomously. Pause both handshakes for the flush cycle; buffered CDC
      // or elastic-stage beats remain in order and resume on the next cycle.
      capturePipe.io.enq.valid := capture.io.pixels.valid && !flushPulse
      capturePipe.io.enq.bits  := capture.io.pixels.bits
      capture.io.pixels.ready  := capturePipe.io.enq.ready && !flushPulse
      frameBuffer.io.enq.valid := capturePipe.io.deq.valid && !flushPulse
      frameBuffer.io.enq.bits  := capturePipe.io.deq.bits
      capturePipe.io.deq.ready := frameBuffer.io.enq.ready && !flushPulse
      frameBuffer.io.flush     := flushPulse

      // Latch completion so the PLIC sees a level until software acknowledges it with CTRL.clear.
      val irqPending = RegInit(false.B)
      when(clearPulse) { irqPending := false.B }
      when(frameBuffer.io.frameReady) { irqPending := true.B }
      val (interrupts, _) = intnode.out(0)
      interrupts(0) := irqPending && irqEnableReg

      val flags = Cat(
        frameBuffer.io.full,           // [6]
        irqPending,                    // [5]
        capture.io.status.busy,        // [4]
        capture.io.status.sensorInt,   // [3]
        capture.io.status.geomErr,     // [2]
        capture.io.status.overflow,    // [1]
        frameBuffer.io.deq.valid       // [0]
      )

      // DATA never stalls TileLink. An empty read returns zero; bit 31 distinguishes that from a
      // valid all-zero pixel. A valid read pops exactly one buffered flit.
      frameBuffer.io.deq.ready := false.B
      val dataWord = Mux(frameBuffer.io.deq.valid,
        Cat(
          1.B,
          0.U(20.W),
          frameBuffer.io.deq.bits.eof,
          frameBuffer.io.deq.bits.eol,
          frameBuffer.io.deq.bits.sof,
          frameBuffer.io.deq.bits.data),
        0.U(32.W))
      val dataRead = RegReadFn((ready: Bool) => {
        frameBuffer.io.deq.ready := ready
        (true.B, dataWord)
      })

      node.regmap(
        0x00 -> Seq(
          RegField(1, enableReg),
          RegField(1, continuousReg),
          RegField(1, irqEnableReg),
          RegField.w(1, triggerWrite),
          RegField.w(1, clearWrite),
          RegField.w(1, flushWrite),
          RegField(26)),
        0x04 -> Seq(RegField(32, geomReg)),
        0x08 -> Seq(RegField(cp.mclkDivWidth, mclkDivReg)),
        0x0c -> Seq(RegField.r(32, frameBuffer.io.count.pad(32))),
        0x10 -> Seq(RegField.r(32, capture.io.status.frameCount)),
        0x14 -> Seq(RegField.r(16, capture.io.status.lastWidth.pad(16))),
        0x18 -> Seq(RegField.r(16, capture.io.status.lastHeight.pad(16))),
        0x1c -> Seq(RegField.r(7, flags)),
        0x20 -> Seq(RegField.r(32, dataRead)),
        0x24 -> Seq(RegField.r(32, params.frameBufferDepth.U(32.W)))
      )
    }
  }
}

/** Mix into the SoC to optionally instantiate the OSPI capture peripheral. */
trait CanHavePeripheryOspi { this: BaseSubsystem =>
  private val portName = "ospi"
  private val pbus = locateTLBusWrapper(PBUS)

  val ospi_sensor = p(OspiKey).map { params =>
    val ospiLM = LazyModule(new OspiCapture(params, pbus.beatBytes)(p))
    ospiLM.clockNode := pbus.fixedClockNode
    pbus.coupleTo(portName) {
      TLInwardClockCrossingHelper(s"${portName}_crossing", ospiLM, ospiLM.node)(SynchronousCrossing()) :=
      TLFragmenter(pbus.beatBytes, pbus.blockBytes) := _
    }
    ibus.fromSync := ospiLM.intnode

    InModuleBody {
      val sensor = IO(chiselTypeOf(ospiLM.module.io)).suggestName("ospi_sensor")
      sensor <> ospiLM.module.io
      sensor
    }
  }
}

/** Config fragment: enable the OSPI capture peripheral. */
class WithOspiCapture(
  address: BigInt = 0x10080000L,
  frameBufferDepth: Int = 324 * 324 + 1
) extends Config((site, here, up) => {
  case OspiKey => Some(OspiParams(address = address, frameBufferDepth = frameBufferDepth))
})
