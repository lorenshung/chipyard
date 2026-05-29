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

import sifive.blocks.devices.uart._

import chipyard._
import chipyard.harness._

trait HasArtyTrenzJTAGDebugLEDs {
  val jtagDebugLEDs: Seq[ModuleValue[Bool]]
}

// ----------------------------------------------------------------------------
// Full harness: Rocket + on-SoM DDR3 (XilinxArtyTrenzMIG) + JTAG on J5.
// ----------------------------------------------------------------------------
class ArtyTrenzHarness(override implicit val p: Parameters) extends ArtyTrenzShell with HasArtyTrenzJTAGDebugLEDs {
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

  val ddrOverlay = dp(DDROverlayKey).head.place(DDRDesignInput(dp(ExtTLMem).get.master.base, dutWrangler.node, harnessSysPLLNode)).asInstanceOf[DDRArtyTrenzPlacedOverlay]
  val ddrClient = TLClientNode(Seq(TLMasterPortParameters.v1(Seq(TLMasterParameters.v1(
    name = "chip_ddr",
    sourceId = IdRange(0, 1 << dp(ExtTLMem).get.master.idBits)
  )))))
  val ddrBlockDuringReset = LazyModule(new TLBlockDuringReset(4))
  ddrOverlay.overlayOutput.ddr := ddrBlockDuringReset.node := ddrClient

  val ledOverlays = dp(LEDOverlayKey).map(_.place(LEDDesignInput()))
  val jtagDebugLEDs = ledOverlays.map(_.overlayOutput.led)

  override lazy val module = new HarnessLikeImpl

  class HarnessLikeImpl extends Impl with HasHarnessInstantiators {
    jtagDebugLEDs.foreach(_ := false.B)
    // Drive the DUT clock-group reset from the shell's self-clearing power-on
    // reset (pllReset == powerOnReset), NOT the external T3 pin. T3 on the TE0712
    // is an ACTIVE-HIGH carrier reset (and was observed unreliable/stuck), so the
    // original `~resetPin` inversion is the wrong polarity and pins the whole DUT
    // (and, via referenceReset, the debug TAP) in reset during normal operation.
    // This matches the shell's documented "authoritative cold-boot reset".
    clockOverlay.overlayOutput.node.out(0)._1.reset := pllReset

    harnessSysPLL.plls.foreach(_._1.getReset.get := pllReset)

    def referenceClockFreqMHz = dutFreqMHz
    def referenceClock = dutClock.in.head._1.clock
    def referenceReset = dutClock.in.head._1.reset
    def success = { require(false, "Unused"); false.B }

    childClock := harnessBinderClock
    childReset := harnessBinderReset

    ddrOverlay.mig.module.clock := harnessBinderClock
    ddrOverlay.mig.module.reset := harnessBinderReset
    ddrBlockDuringReset.module.clock := harnessBinderClock
    ddrBlockDuringReset.module.reset := harnessBinderReset.asBool || !ddrOverlay.mig.module.io.port.init_calib_complete

    instantiateChipTops()
  }
}

// ----------------------------------------------------------------------------
// Scratchpad harness: Rocket + JTAG on J5, no DDR. Memory comes from the
// configured backing (TL-RAM scratchpad on the MBus, or SerialTL to host).
// ----------------------------------------------------------------------------
class ArtyTrenzScratchpadHarness(override implicit val p: Parameters) extends ArtyTrenzShell with HasArtyTrenzJTAGDebugLEDs {
  def dp = designParameters

  val clockOverlay = dp(ClockInputOverlayKey).map(_.place(ClockInputDesignInput())).head
  val harnessSysPLL = dp(PLLFactoryKey)
  val harnessSysPLLNode = harnessSysPLL()
  val dutFreqMHz = (dp(SystemBusKey).dtsFrequency.get / (1000 * 1000)).toInt
  val dutClock = ClockSinkNode(freqMHz = dutFreqMHz)
  println(s"ArtyTrenz (scratchpad) FPGA Base Clock Freq: ${dutFreqMHz} MHz")
  val dutWrangler = LazyModule(new ResetWrangler())
  val dutGroup = ClockGroup()
  dutClock := dutWrangler.node := dutGroup := harnessSysPLLNode

  harnessSysPLLNode := clockOverlay.overlayOutput.node

  val ledOverlays = dp(LEDOverlayKey).map(_.place(LEDDesignInput()))
  val jtagDebugLEDs = ledOverlays.map(_.overlayOutput.led)

  override lazy val module = new HarnessLikeImpl

  class HarnessLikeImpl extends Impl with HasHarnessInstantiators {
    jtagDebugLEDs.foreach(_ := false.B)
    // Drive the DUT clock-group reset from the shell's self-clearing power-on
    // reset (pllReset == powerOnReset), NOT the external T3 pin. T3 on the TE0712
    // is an ACTIVE-HIGH carrier reset (and was observed unreliable/stuck), so the
    // original `~resetPin` inversion is the wrong polarity and pins the whole DUT
    // (and, via referenceReset, the debug TAP) in reset during normal operation.
    // This matches the shell's documented "authoritative cold-boot reset".
    clockOverlay.overlayOutput.node.out(0)._1.reset := pllReset

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
