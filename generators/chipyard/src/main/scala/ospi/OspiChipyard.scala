package ospi

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.{Parameters, Field, Config}
import freechips.rocketchip.subsystem.{BaseSubsystem, PBUS}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.prci._
import freechips.rocketchip.regmapper.RegField
import freechips.rocketchip.tilelink._

/** SoC-level parameters for the HM01B0 capture peripheral. */
case class OspiParams(
  address:   BigInt = 0x10080000L,
  dataWidth: Int    = 8
)

case object OspiKey extends Field[Option[OspiParams]](None)

/** TileLink MMIO wrapper around [[HM01B0Capture]].
  *
  * GCD-style: a register-mapped slave living in the PBUS clock domain (ClockSinkDomain). The
  * capture core does its own PCLK->system clock CDC internally (AsyncFifo), so the sensor PCLK
  * enters as a plain input clock pin — no diplomatic clock crossing is needed. v1 is poll-based
  * (status registers, no PLIC interrupt); an IRQ via IntSourceNode is a follow-up.
  *
  * Register map (word offsets, RW unless noted):
  *   0x00 CTRL      [0]=enable [1]=continuous [2]=irqEnable [3]=trigPulse [4]=clear
  *   0x04 GEOM      [15:0]=expWidth  [31:16]=expHeight
  *   0x08 MCLKDIV   MCLK = sysclk / (2*(mclkDiv+1))
  *   0x10 FRAMECNT  (RO) frames completed since reset
  *   0x14 LASTWIDTH (RO) measured width  of last frame
  *   0x18 LASTHEIGHT(RO) measured height of last frame
  *   0x1C FLAGS     (RO) [0]=dataValid [1]=overflow [2]=geomErr [3]=sensorInt [4]=busy
  *   0x20 DATA      (RO) read pops one pixel beat: [7:0]=data [8]=sof [9]=eol [10]=eof
  */
class OspiCapture(params: OspiParams, beatBytes: Int)(implicit p: Parameters)
    extends ClockSinkDomain(ClockSinkParameters())(p) {
  val device = new SimpleDevice("ospi", Seq("ucbbar,ospi-hm01b0"))
  val node = TLRegisterNode(Seq(AddressSet(params.address, 4096 - 1)), device, "reg/control", beatBytes = beatBytes)

  override lazy val module = new OspiImpl
  class OspiImpl extends Impl {
    val cp = CaptureParams(dataWidth = params.dataWidth)
    val io = IO(new SensorIO(params.dataWidth)) // chip-level sensor pins (mirror of the HM01B0)
    withClockAndReset(clock, reset) {
      val capture = Module(new HM01B0Capture(cp))

      // --- sensor pins: chip IO <-> capture core ---
      capture.io.sensor.pclk := io.pclk
      capture.io.sensor.fvld := io.fvld
      capture.io.sensor.lvld := io.lvld
      capture.io.sensor.d    := io.d
      capture.io.sensor.intr := io.intr
      io.mclk := capture.io.sensor.mclk
      io.trig := capture.io.sensor.trig

      // --- control registers (written by the SoC) ---
      val ctrlReg    = RegInit(0.U(32.W))
      val geomInit   = (BigInt(cp.defaultHeight) << 16) | BigInt(cp.defaultWidth)
      val geomReg    = RegInit(geomInit.U(32.W))
      val mclkDivReg = RegInit(0.U(cp.mclkDivWidth.W))

      capture.io.ctrl.enable     := ctrlReg(0)
      capture.io.ctrl.continuous := ctrlReg(1)
      capture.io.ctrl.irqEnable  := ctrlReg(2)
      capture.io.ctrl.trigPulse  := ctrlReg(3)
      capture.io.ctrl.clear      := ctrlReg(4)
      capture.io.ctrl.mclkDiv    := mclkDivReg
      capture.io.ctrl.expWidth   := geomReg(cp.pixCountWidth - 1, 0)
      capture.io.ctrl.expHeight  := geomReg(16 + cp.lineCountWidth - 1, 16)

      // --- status flags (read by the SoC) ---
      val flags = Cat(
        capture.io.status.busy,      // [4]
        capture.io.status.sensorInt, // [3]
        capture.io.status.geomErr,   // [2]
        capture.io.status.overflow,  // [1]
        capture.io.pixels.valid      // [0] data available
      )

      // --- pixel read-FIFO: reading DATA pops one beat from the capture stream ---
      val deqWord = Wire(Decoupled(UInt(32.W)))
      deqWord.valid := capture.io.pixels.valid
      deqWord.bits := Cat(
        0.U(21.W),
        capture.io.pixels.bits.eof,
        capture.io.pixels.bits.eol,
        capture.io.pixels.bits.sof,
        capture.io.pixels.bits.data
      )
      capture.io.pixels.ready := deqWord.ready

      node.regmap(
        0x00 -> Seq(RegField(32, ctrlReg)),
        0x04 -> Seq(RegField(32, geomReg)),
        0x08 -> Seq(RegField(cp.mclkDivWidth, mclkDivReg)),
        0x10 -> Seq(RegField.r(32, capture.io.status.frameCount)),
        0x14 -> Seq(RegField.r(16, capture.io.status.lastWidth.pad(16))),
        0x18 -> Seq(RegField.r(16, capture.io.status.lastHeight.pad(16))),
        0x1C -> Seq(RegField.r(5, flags)),
        0x20 -> Seq(RegField.r(32, deqWord))
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
    // Surface the sensor pins at the SoC (DigitalTop) boundary.
    InModuleBody {
      val sensor = IO(chiselTypeOf(ospiLM.module.io)).suggestName("ospi_sensor")
      sensor <> ospiLM.module.io
      sensor
    }
  }
}

/** Config fragment: enable the OSPI capture peripheral. */
class WithOspiCapture(address: BigInt = 0x10080000L) extends Config((site, here, up) => {
  case OspiKey => Some(OspiParams(address = address))
})
