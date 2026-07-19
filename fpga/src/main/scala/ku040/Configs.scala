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
class WithKU040Tweaks(freqMHz: Double = 50) extends Config(
  new WithKU040UART ++
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

class RocketKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class SaturnKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.REFV256D128RocketConfig)

class NoCoresKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.NoCoresConfig)
