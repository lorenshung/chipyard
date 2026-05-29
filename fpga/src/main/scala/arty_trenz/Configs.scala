// See LICENSE for license details.
package chipyard.fpga.arty_trenz

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

// Don't use FPGAShell's DesignKey.
class WithNoDesignKey extends Config((site, here, up) => {
  case DesignKey => (p: Parameters) => new SimpleLazyRawModule()(p)
})

// ----------------------------------------------------------------------------
// Common knobs shared by Rocket (DDR) and Scratchpad (no-DDR) configs.
// ----------------------------------------------------------------------------
class WithArtyTrenzCommon(freqMHz: Double = 50) extends Config(
  new WithArtyTrenzUART ++
  new WithArtyTrenzJTAG ++
  new WithNoDesignKey ++
  new chipyard.harness.WithSerialTLTiedOff ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(freqMHz) ++
  new chipyard.config.WithUniformBusFrequencies(freqMHz) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new freechips.rocketchip.subsystem.WithoutTLMonitors)

// ----------------------------------------------------------------------------
// Full Rocket config: 1 GB DDR3 on the TE0712 SoM + JTAG on J5 + UART.
// ----------------------------------------------------------------------------
class WithArtyTrenzTweaks(freqMHz: Double = 50) extends Config(
  new WithArtyTrenzDDRTL ++
  new WithArtyTrenzCommon(freqMHz) ++
  new chipyard.config.WithTLBackingMemory ++ // FPGA-shells converts the AXI to TL for us
  new freechips.rocketchip.subsystem.WithExtMemSize(BigInt(1) << 30)) // 1 GB

class RocketArtyTrenzConfig extends Config(
  new WithArtyTrenzTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class NoCoresArtyTrenzConfig extends Config(
  new WithArtyTrenzTweaks ++
  new chipyard.config.WithBroadcastManager ++
  new chipyard.NoCoresConfig)

// ----------------------------------------------------------------------------
// Scratchpad config: Rocket + JTAG + UART, NO DDR. Memory is a TL-RAM
// scratchpad on the MemoryBus, suitable for early bringup of the FPGA shell
// without the MIG / DDR3 calibration as a confounding variable.
// Pair with ArtyTrenzScratchpadHarness.
// ----------------------------------------------------------------------------
class WithArtyTrenzScratchpadTweaks(freqMHz: Double = 50) extends Config(
  new WithArtyTrenzCommon(freqMHz) ++
  new freechips.rocketchip.subsystem.WithNoMemPort ++
  new testchipip.soc.WithMbusScratchpad(base = 0x80000000L, size = (BigInt(1) << 15))) // 32 KB BRAM-backed

class ScratchpadArtyTrenzConfig extends Config(
  new WithArtyTrenzScratchpadTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)
