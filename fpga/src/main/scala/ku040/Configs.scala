// See LICENSE for license details.
package chipyard.fpga.ku040

import org.chipsalliance.cde.config._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.devices.debug._
import freechips.rocketchip.devices.tilelink._
import org.chipsalliance.diplomacy._
import org.chipsalliance.diplomacy.lazymodule._
import freechips.rocketchip.system._
import freechips.rocketchip.tile._

import sifive.blocks.devices.uart._
import sifive.fpgashells.shell.{DesignKey}

import testchipip.serdes.{SerialTLKey}

import chipyard.{BuildSystem}

// don't use FPGAShell's DesignKey
class WithNoDesignKey extends Config((site, here, up) => {
  case DesignKey => (p: Parameters) => new SimpleLazyRawModule()(p)
})

// The sifive UART (Zephyr console) gets the wired PMOD pins D3/D4; UART-TSI
// is parked on spare pins A4/B4 until needed.
class WithKU040Tweaks(freqMHz: Double = 50, uartRxdPin: String = "D3") extends Config(
  new WithKU040UART(rxdPin = uartRxdPin) ++
  new WithKU040UARTTSI ++
  new WithKU040JTAG ++
  new WithNoDesignKey ++
  new testchipip.tsi.WithUARTTSIClient ++
  new chipyard.harness.WithSerialTLTiedOff ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(freqMHz) ++
  new chipyard.config.WithUniformBusFrequencies(freqMHz) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new testchipip.soc.WithMbusScratchpad(base = 0x80000000L, size = (BigInt(1) << 15)) ++
  new freechips.rocketchip.subsystem.WithNoMemPort ++
  new freechips.rocketchip.subsystem.WithoutTLMonitors)

/** Opt-in HM01B0 capture, including the I2C controller used to configure the sensor. */
class WithKU040OspiPeriphery extends Config(
  new WithKU040I2C ++
  new WithKU040Ospi ++
  new chipyard.iobinders.WithOspiPunchthrough ++
  new ospi.WithOspiCapture ++
  new chipyard.config.WithI2C)

class RocketKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class RocketKU040OspiConfig extends Config(
  new WithKU040OspiPeriphery ++
  new WithKU040Tweaks(uartRxdPin = "C3") ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

/**
 * Logical full-drone SoC for the custom XCKU040-SFVA784-1-C board.
 *
 * The PMW3901 SPI/control GPIO and motor PWM package pins are deliberately
 * unbound until the custom base-connector mapping and voltage domains are
 * provided and verified.
 */
class RocketKU040DroneLogicConfig extends Config(
  new chipyard.config.WithRiskyBirdDronePeriphery ++
  new WithKU040OspiPeriphery ++
  new WithKU040Tweaks(uartRxdPin = "C3") ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class SaturnKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.REFV256D128RocketConfig)

class SaturnKU040OspiConfig extends Config(
  new WithKU040OspiPeriphery ++
  new WithKU040Tweaks(uartRxdPin = "C3") ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.REFV256D128RocketConfig)

class SaturnKU040DroneLogicConfig extends Config(
  new chipyard.config.WithRiskyBirdDronePeriphery ++
  new WithKU040OspiPeriphery ++
  new WithKU040Tweaks(uartRxdPin = "C3") ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.REFV256D128RocketConfig)

/** Rocket plus the default 16x16 int8 Gemmini.
 *
 *  An area-characterization target, not a deployable configuration: the KU040
 *  shell has a 32 KiB scratchpad and no DRAM, so there is nothing for Gemmini to
 *  DMA against. Synthesis-only measurement does not execute code, so the
 *  resource cost is still meaningful.
 *
 *  The default mesh is 16x16, giving 256 MacUnit instances. That is the
 *  population the `use_dsp` injection in riskybird/tcl/rb_attributes.tcl targets,
 *  so this config is what makes the DSP-inference claim measurable without
 *  moving any submodule pin.
 */
class GemminiKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.GemminiRocketConfig)

/** Q0.31 weight-stationary Gemmini, 32x32 mesh, 128 KB accumulator.
 *
 *  1024 MacUnit instances -- the largest use_dsp injection target. The 128 KB
 *  accumulator keeps the banks BRAM-mappable at this mesh width; at 64 KB they
 *  demote to LUTRAM.
 *
 *  Measured synth-only on xcku040-sfva784-1-c:
 *    pristine  223,841 LUT (92.3%)    326 DSP (17.0%)
 *    use_dsp   129,190 LUT (53.3%)  1,355 DSP (70.6%)
 */
class Q31Ws32x32AccGemminiKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.Q31Ws32x32AccGemminiRocketConfig)

/** V128D128 Saturn vector unit with the int8 Outer Product Unit.
 *
 *  512 OuterProductCell instances.
 *
 *  Measured synth-only on xcku040-sfva784-1-c:
 *    pristine  191,455 LUT (79.0%)  155 DSP (8.1%)
 *    use_dsp   161,133 LUT (66.5%)  672 DSP (35.0%)
 */
class SaturnOPUV128D128KU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.REFV128D128RocketOPUConfig)

class NoCoresKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.NoCoresConfig)
