package chipyard.fpga.arty_trenz

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
import sifive.fpgashells.ip.xilinx.{IBUF, PowerOnResetFPGAOnly}

import chipyard._
import chipyard.harness._

class ArtyTrenzHarness(override implicit val p: Parameters) extends ArtyTrenzShell {
  def dp = designParameters

  val clockOverlay = dp(ClockInputOverlayKey).map(_.place(ClockInputDesignInput())).head
  val harnessSysPLL = dp(PLLFactoryKey)
  val harnessSysPLLNode = harnessSysPLL()
  val dutFreqMHz = (dp(SystemBusKey).dtsFrequency.get / (1000 * 1000)).toInt
  val dutClock = ClockSinkNode(freqMHz = dutFreqMHz)
  println(s"ArtyTrenz FPGA Base Clock Freq: ${dutFreqMHz} MHz")
  val dutWrangler = LazyModule(new ResetWrangler())
  val dutGroup = ClockGroup()
  dutClock := dutWrangler.node := dutGroup := harnessSysPLLNode

  harnessSysPLLNode := clockOverlay.overlayOutput.node

  def includeDDR: Boolean = true

  val (ddrOverlay, ddrClient, ddrBlockDuringReset) = if (includeDDR) {
    val o = dp(DDROverlayKey).head.place(DDRDesignInput(dp(ExtTLMem).get.master.base, dutWrangler.node, harnessSysPLLNode)).asInstanceOf[DDRArtyTrenzPlacedOverlay]
    val c = TLClientNode(Seq(TLMasterPortParameters.v1(Seq(TLMasterParameters.v1(
      name = "chip_ddr",
      sourceId = IdRange(0, 1 << dp(ExtTLMem).get.master.idBits)
    )))))
    val b = LazyModule(new TLBlockDuringReset(4))
    o.overlayOutput.ddr := b.node := c
    (Some(o), Some(c), Some(b))
  } else {
    (None, None, None)
  }

  override lazy val module = new HarnessLikeImpl

  class HarnessLikeImpl extends Impl with HasHarnessInstantiators {
    // resetPin is ACTIVE HIGH on this board (Trenz convention); ClockBundle
    // reset is also active-high so no inversion needed.
    clockOverlay.overlayOutput.node.out(0)._1.reset := resetPin

    harnessSysPLL.plls.foreach(_._1.getReset.get := pllReset)

    def referenceClockFreqMHz = dutFreqMHz
    def referenceClock = dutClock.in.head._1.clock
    def referenceReset = dutClock.in.head._1.reset
    def success = { require(false, "Unused"); false.B }

    childClock := harnessBinderClock
    childReset := harnessBinderReset

    ddrOverlay.foreach { o =>
      o.mig.module.clock := harnessBinderClock
      o.mig.module.reset := harnessBinderReset
      ddrBlockDuringReset.get.module.clock := harnessBinderClock
      ddrBlockDuringReset.get.module.reset := harnessBinderReset.asBool || !o.mig.module.io.port.init_calib_complete
    }

    instantiateChipTops()
  }
}

class ArtyTrenzScratchpadHarness(override implicit val p: Parameters) extends ArtyTrenzHarness {
  override def includeDDR = false
}
