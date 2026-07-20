// See LICENSE for license details.
package chipyard.fpga.arty100t

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

class WithArty100TTweaks(freqMHz: Double = 50) extends Config(
  new WithArty100TDDRTL ++
  new WithArty100TPMODUART ++
  new WithArty100TUARTTSI ++
  new WithArty100TJTAG ++
  new WithNoDesignKey ++
  new testchipip.tsi.WithUARTTSIClient ++
  new chipyard.harness.WithSerialTLTiedOff ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(freqMHz) ++
  new chipyard.config.WithUniformBusFrequencies(freqMHz) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new chipyard.config.WithTLBackingMemory ++
  new freechips.rocketchip.subsystem.WithExtMemSize(BigInt(1) << 30) ++
  // new testchipip.soc.WithMbusScratchpad(base = 0x80000000L, size = (BigInt(1) << 15))++
  // new freechips.rocketchip.subsystem.WithNoMemPort ++
  new freechips.rocketchip.subsystem.WithoutTLMonitors)

/** Opt-in HM01B0 capture, including the I2C controller used to configure the sensor. */
class WithArty100TOspiPeriphery extends Config(
  new WithArty100TI2C ++
  new WithArty100TOspi ++
  new chipyard.iobinders.WithOspiPunchthrough ++
  new ospi.WithOspiCapture ++
  new chipyard.config.WithI2C)

class RocketArty100TConfig extends Config(
  new WithArty100TTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class RocketArty100TOspiConfig extends Config(
  new WithArty100TOspiPeriphery ++
  new WithArty100TTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class NoCoresArty100TConfig extends Config(
  new WithArty100TTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.NoCoresConfig)
