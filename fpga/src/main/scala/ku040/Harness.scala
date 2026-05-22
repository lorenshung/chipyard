package chipyard.fpga.ku040

import chisel3._

import freechips.rocketchip.diplomacy.{LazyModule, LazyRawModuleImp, BundleBridgeSource}
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.prci._
import freechips.rocketchip.subsystem.SystemBusKey

import sifive.fpgashells.shell.xilinx._
import sifive.fpgashells.ip.xilinx.{PowerOnResetFPGAOnly}
import sifive.fpgashells.shell._
import sifive.fpgashells.clocks._

import sifive.blocks.devices.uart.{PeripheryUARTKey, UARTPortIO}

import chipyard._
import chipyard.harness._

// Synthesis-only harness for the Alinx AXKU040 (Kintex UltraScale XCKU040).
// Goal: drive Vivado synth/impl far enough to produce per-resource
// utilization reports against this part. Not board/port accurate -
// only sys_clock (LVDS AK17/AK16) and FMC UART are pinned; everything
// else is tied off or routed through the AbstractConfig defaults.
class Ku040ScratchpadHarness(override implicit val p: Parameters)
  extends AlinxAxku040ShellBasicOverlays {

  def dp = designParameters

  val uart_fmc = Overlay(UARTOverlayKey, new UARTAlinxAxku040FmcPlacer(this, UARTShellInput()))

  // Clock tree: 200 MHz LVDS sys_clock -> harness PLL -> wrangler -> dutClock.
  val sysClkNode = dp(ClockInputOverlayKey).head.place(ClockInputDesignInput()).overlayOutput.node
  val harnessSysPLL = dp(PLLFactoryKey)
  val harnessSysPLLNode = harnessSysPLL()
  harnessSysPLLNode := sysClkNode

  val dutFreqMHz = (dp(SystemBusKey).dtsFrequency.get / (1000 * 1000)).toInt
  val dutClock = ClockSinkNode(freqMHz = dutFreqMHz)
  println(s"Ku040 FPGA Base Clock Freq: ${dutFreqMHz} MHz")
  val dutWrangler = LazyModule(new ResetWrangler)
  val dutGroup = ClockGroup()
  dutClock := dutWrangler.node := dutGroup := harnessSysPLLNode

  // UART through the FMC UART overlay (pins T24/T25 - LPC2_LA20_P/N).
  val io_uart_bb = BundleBridgeSource(() => (new UARTPortIO(dp(PeripheryUARTKey).head)))
  dp(UARTOverlayKey).head.place(UARTDesignInput(io_uart_bb))

  override lazy val module = new Ku040ScratchpadHarnessImp(this)
}

class Ku040ScratchpadHarnessImp(_outer: Ku040ScratchpadHarness)
  extends LazyRawModuleImp(_outer) with HasHarnessInstantiators {

  override def provideImplicitClockToLazyChildren = true
  val ku040Outer = _outer

  val sysclk: Clock = _outer.sysClkNode.out.head._1.clock
  val powerOnReset: Bool = PowerOnResetFPGAOnly(sysclk)
  _outer.sdc.addAsyncPath(Seq(powerOnReset))
  _outer.pllReset := powerOnReset
  _outer.harnessSysPLL.plls.foreach(_._1.getReset.get := powerOnReset)

  val hReset = Wire(Reset())
  hReset := _outer.dutClock.in.head._1.reset

  def referenceClockFreqMHz = _outer.dutFreqMHz
  def referenceClock = _outer.dutClock.in.head._1.clock
  def referenceReset = hReset
  def success = { require(false, "Unused"); false.B }

  childClock := referenceClock
  childReset := referenceReset

  instantiateChipTops()
}
