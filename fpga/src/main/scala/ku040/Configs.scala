// See LICENSE for license details.
package chipyard.fpga.ku040

import org.chipsalliance.cde.config._
import org.chipsalliance.diplomacy.lazymodule._

import sifive.blocks.devices.uart.{PeripheryUARTKey, UARTParams}
import sifive.fpgashells.shell.DesignKey

import chipyard.{BuildSystem}

// Don't use FPGAShell's DesignKey - chipyard supplies its own ChipTop builder.
class WithNoDesignKey extends Config((site, here, up) => {
  case DesignKey => (p: Parameters) => new SimpleLazyRawModule()(p)
})

class WithKu040UARTParams extends Config((site, here, up) => {
  case PeripheryUARTKey => List(UARTParams(address = BigInt(0x64000000L)))
})

// Scratchpad-only tweaks: no DDR / MIG. Just clocking, UART, and
// tie-offs so the chip elaborates into a synth-ready harness.
class WithKu040ScratchpadTweaks(freqMHz: Double = 100) extends Config(
  new WithKu040UART ++
  new WithKu040UARTParams ++
  new chipyard.harness.WithTiedOffJTAG ++
  new chipyard.harness.WithSerialTLTiedOff ++
  new WithNoDesignKey ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(freqMHz) ++
  new chipyard.config.WithUniformBusFrequencies(freqMHz) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new freechips.rocketchip.subsystem.WithoutTLMonitors)

// REFV128D128 Rocket + Saturn vector, scratchpad memory, KU040 harness.
// First-cut synthesis target for utilization reports against XCKU040.
class REFV128D128Ku040ScratchpadConfig extends Config(
  new WithKu040ScratchpadTweaks ++
  new chipyard.config.WithL2TLBs(0) ++
  new testchipip.soc.WithNoScratchpads ++
  new freechips.rocketchip.subsystem.WithNBanks(0) ++
  new freechips.rocketchip.subsystem.WithNoMemPort ++
  new freechips.rocketchip.rocket.WithScratchpadsOnly ++
  new chipyard.REFV128D128RocketConfig)

class Ku040GemminiConfig extends Config(
  new WithKu040ScratchpadTweaks ++
  new chipyard.config.WithL2TLBs(0) ++
  new testchipip.soc.WithNoScratchpads ++
  new freechips.rocketchip.subsystem.WithNBanks(0) ++
  new freechips.rocketchip.subsystem.WithNoMemPort ++
  new freechips.rocketchip.rocket.WithScratchpadsOnly ++
  new chipyard.GemminiRocketConfig)