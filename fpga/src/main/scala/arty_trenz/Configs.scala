// See LICENSE for license details.
package chipyard.fpga.arty_trenz

import org.chipsalliance.cde.config._
import org.chipsalliance.diplomacy._
import org.chipsalliance.diplomacy.lazymodule._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.system._
import freechips.rocketchip.tile._

import sifive.fpgashells.shell.{DesignKey}

import chipyard.{BuildSystem}

// don't use FPGAShell's DesignKey
class WithNoDesignKey extends Config((site, here, up) => {
  case DesignKey => (p: Parameters) => new SimpleLazyRawModule()(p)
})

// Full BigRocket with the on-SoM 1 GB DDR3L behind ExtMem.
// The harness (ArtyTrenzHarness) unconditionally places the DDR overlay,
// so this config must include WithExtMemSize + WithTLBackingMemory.
class WithArtyTrenzTweaks(freqMHz: Double = 50) extends Config(
  new WithArtyTrenzUART ++
  new WithArtyTrenzJTAG ++
  new WithArtyTrenzDDRTL ++
  new WithNoDesignKey ++
  new chipyard.harness.WithSerialTLTiedOff ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(freqMHz) ++
  new chipyard.config.WithUniformBusFrequencies(freqMHz) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new chipyard.config.WithTLBackingMemory ++ // FPGA-shells converts the AXI to TL for us
  new freechips.rocketchip.subsystem.WithExtMemSize(BigInt(1) << 30) ++ // 1 GB on TE0713-01
  new freechips.rocketchip.subsystem.WithoutTLMonitors)

class RocketArtyTrenzConfig extends Config(
  new WithArtyTrenzTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

// Bringup-host variant. The FPGA acts as the host driver for an external
// chip attached via SerialTL on the J11 40-pin header. The deadlocking
// PHY is fine here because traffic is bringup-only (program load).
// Will fail timing above ~50 MHz.
class BringupArtyTrenzConfig extends Config(
  new WithArtyTrenzSerialTLToGPIO ++
  new WithArtyTrenzTweaks(freqMHz = 50) ++
  new testchipip.serdes.WithSerialTLPHYParams(testchipip.serdes.DecoupledInternalSyncSerialPhyParams(freqMHz=50)) ++
  new chipyard.ChipBringupHostConfig)
