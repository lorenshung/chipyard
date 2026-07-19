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
  new chipyard.config.WithI2C ++                 // TLI2C master @0x10040000: one 2-wire bus, many slaves (HM01B0 0x24 + others)
  new WithArty100TI2C ++                         // route I2C SCL/SDA to FPGA pins (overrides default WithI2CTiedOff)
  new ospi.WithOspiCapture ++                    // HM01B0 parallel-video capture peripheral @0x10080000 (MMIO read-FIFO)
  new chipyard.iobinders.WithOspiPunchthrough ++ // expose the OSPI sensor pins at the chip boundary
  new WithArty100TOspi ++                        // route the OSPI sensor pins to FPGA (PMOD) pins
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

class RocketArty100TConfig extends Config(
  new WithArty100TTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class NoCoresArty100TConfig extends Config(
  new WithArty100TTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.NoCoresConfig)
