package chipyard.fpga.ku040

import chisel3._
import chisel3.util._
import freechips.rocketchip.diplomacy._
import org.chipsalliance.cde.config.{Parameters}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.prci._
import freechips.rocketchip.subsystem.{SystemBusKey}

import sifive.fpgashells.shell.xilinx._
import sifive.fpgashells.shell._
import sifive.fpgashells.clocks._

import chipyard._
import chipyard.harness._

class KU040Harness(override implicit val p: Parameters) extends CustomKU040Shell {
  def dp = designParameters

  val clockOverlay = dp(ClockInputOverlayKey).map(_.place(ClockInputDesignInput())).head
  val harnessSysPLL = dp(PLLFactoryKey)
  val harnessSysPLLNode = harnessSysPLL()
  val dutFreqMHz = (dp(SystemBusKey).dtsFrequency.get / (1000 * 1000)).toInt
  val dutClock = ClockSinkNode(freqMHz = dutFreqMHz)
  println(s"KU040 FPGA Base Clock Freq: ${dutFreqMHz} MHz")
  val dutWrangler = LazyModule(new ResetWrangler())
  val dutGroup = ClockGroup()
  dutClock := dutWrangler.node := dutGroup := harnessSysPLLNode

  harnessSysPLLNode := clockOverlay.overlayOutput.node

  override lazy val module = new HarnessLikeImpl

  class HarnessLikeImpl extends Impl with HasHarnessInstantiators {
    clockOverlay.overlayOutput.node.out(0)._1.reset := ~resetPin

    val clk_200mhz = clockOverlay.overlayOutput.node.out.head._1.clock

    harnessSysPLL.plls.foreach(_._1.getReset.get := pllReset)

    def referenceClockFreqMHz = dutFreqMHz
    def referenceClock = dutClock.in.head._1.clock
    def referenceReset = dutClock.in.head._1.reset
    def success = { require(false, "Unused"); false.B }

    childClock := harnessBinderClock
    childReset := harnessBinderReset
    instantiateChipTops()
  }
}
