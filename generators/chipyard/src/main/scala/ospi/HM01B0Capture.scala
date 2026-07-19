package ospi

import chisel3._
import chisel3.util._

/** Top-level HM01B0 parallel-video capture core.
  *
  * Implicit clock/reset = the SoC/system domain. The sensor PCLK domain is driven by
  * `io.sensor.pclk`. Data flow:
  *
  *   D/FVLD/LVLD --(PCLK)--> CaptureFrontend --(PCLK)--> AsyncFifo --(sysclk)--> assembler + io.pixels
  *
  * Sensor I2C configuration is intentionally out of scope here (reuse Chipyard's TLI2C).
  */
class HM01B0Capture(p: CaptureParams = CaptureParams()) extends Module {
  val io = IO(new HM01B0CaptureIO(p))

  // ---- Reset synchronizer into the PCLK domain ----
  // Asserts asynchronously with system reset, deasserts synchronously to PCLK.
  private val pclkRst = withClockAndReset(io.sensor.pclk, reset.asAsyncReset) {
    val r0 = RegInit(true.B); val r1 = RegInit(true.B)
    r0 := false.B; r1 := r0
    r1
  }

  // 2-flop synchronizer into the system (implicit) clock domain.
  private def syncSys(sig: Bool): Bool = RegNext(RegNext(sig, false.B), false.B)
  // N-flop synchronizer of a system-domain level into the PCLK domain.
  private def syncPclk(sig: Bool): Bool =
    withClockAndReset(io.sensor.pclk, pclkRst.asAsyncReset) {
      (0 until p.syncStages).foldLeft(sig) { (prev, _) => RegNext(prev, false.B) }
    }

  // ---- PCLK-domain capture front-end ----
  private val frontend = withClockAndReset(io.sensor.pclk, pclkRst.asAsyncReset) {
    Module(new CaptureFrontend(p))
  }
  frontend.io.fvld   := io.sensor.fvld
  frontend.io.lvld   := io.sensor.lvld
  frontend.io.d      := io.sensor.d
  frontend.io.enable := syncPclk(io.ctrl.enable)

  // ---- Clock-domain-crossing FIFO ----
  private val fifo = Module(new AsyncFifo(new PixelFlit(p.dataWidth), p.fifoDepth, p.syncStages))
  fifo.enqClock      := io.sensor.pclk
  fifo.enqReset      := pclkRst.asAsyncReset
  fifo.deqClock      := clock
  fifo.deqReset      := reset.asAsyncReset
  fifo.clearOverflow := io.ctrl.clear
  // Front-end pushes unconditionally (sensor can't stall); FIFO flags overflow on a dropped beat.
  fifo.enq.valid := frontend.io.out.valid
  fifo.enq.bits  := frontend.io.out.bits

  // ---- System-domain consumer: forward stream to SoC and measure geometry ----
  io.pixels.valid  := fifo.deq.valid
  io.pixels.bits   := fifo.deq.bits
  fifo.deq.ready   := io.pixels.ready

  private val pixCol    = RegInit(0.U(p.pixCountWidth.W))
  private val rowCnt    = RegInit(0.U(p.lineCountWidth.W))
  private val widthReg  = RegInit(0.U(p.pixCountWidth.W))
  private val heightReg = RegInit(0.U(p.lineCountWidth.W))
  private val frameCnt  = RegInit(0.U(32.W))
  private val geomErrR  = RegInit(false.B)
  private val frameDone = WireDefault(false.B)

  when(io.pixels.fire) {
    val b = io.pixels.bits
    when(b.eof) {
      // End-of-frame marker: finalize measurement for this frame.
      heightReg := rowCnt
      frameCnt  := frameCnt + 1.U
      frameDone := true.B
      when((widthReg =/= io.ctrl.expWidth) || (rowCnt =/= io.ctrl.expHeight)) {
        geomErrR := true.B
      }
      rowCnt := 0.U
      pixCol := 0.U
    }.otherwise {
      // Pixel beat. `sof` resets the in-frame counters before counting this pixel.
      val colBase = Mux(b.sof, 0.U, pixCol)
      val rowBase = Mux(b.sof, 0.U, rowCnt)
      when(b.eol) {
        widthReg := colBase + 1.U
        rowCnt   := rowBase + 1.U
        pixCol   := 0.U
      }.otherwise {
        pixCol := colBase + 1.U
        rowCnt := rowBase
      }
    }
  }

  when(io.ctrl.clear) { geomErrR := false.B }

  // ---- MCLK generation: divide the system clock. MCLK = sysclk / (2*(mclkDiv+1)). ----
  private val mclkReg = RegInit(false.B)
  private val divCnt  = RegInit(0.U(p.mclkDivWidth.W))
  when(divCnt === io.ctrl.mclkDiv) {
    divCnt  := 0.U
    mclkReg := !mclkReg
  }.otherwise {
    divCnt := divCnt + 1.U
  }
  io.sensor.mclk := mclkReg.asClock

  // ---- TRIG: software-driven pulse (snapshot); held low in free-run continuous mode. ----
  io.sensor.trig := RegNext(io.ctrl.trigPulse && !io.ctrl.continuous, false.B)

  // ---- Status ----
  io.status.frameCount := frameCnt
  io.status.lastWidth  := widthReg
  io.status.lastHeight := heightReg
  io.status.overflow   := syncSys(fifo.overflow)
  io.status.geomErr    := geomErrR
  io.status.frameDone  := frameDone
  io.status.sensorInt  := syncSys(io.sensor.intr)
  io.status.busy       := syncSys(io.sensor.fvld)
  io.status.irq        := frameDone && io.ctrl.irqEnable
}
