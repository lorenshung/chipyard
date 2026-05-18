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

// Overrides WithScratchpadsOnly's 16 KB default (nSets=256) up to 32 KB.
// 512 sets * 64-byte blocks * 1 way = 32 KiB DTIM @ 0x80000000.
class With32KBDTIM extends Config((site, here, up) => {
  case freechips.rocketchip.subsystem.TilesLocated(loc) => up(freechips.rocketchip.subsystem.TilesLocated(loc), site).map {
    case tp: freechips.rocketchip.subsystem.RocketTileAttachParams =>
      tp.copy(tileParams = tp.tileParams.copy(
        dcache = tp.tileParams.dcache.map(_.copy(nSets = 512))
      ))
    case other => other
  }
})

// Scratchpad-only tweaks: same peripheral set as WithArtyTrenzTweaks but
// drops DDR/ExtMem so the ArtyTrenzScratchpadHarness (includeDDR=false) elaborates.
class WithArtyTrenzScratchpadTweaks(freqMHz: Double = 50) extends Config(
  new WithArtyTrenzUART ++
  new WithArtyTrenzJTAG ++
  new WithNoDesignKey ++
  new chipyard.harness.WithSerialTLTiedOff ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(freqMHz) ++
  new chipyard.config.WithUniformBusFrequencies(freqMHz) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new freechips.rocketchip.subsystem.WithoutTLMonitors)

class ScratchpadArtyTrenzConfig extends Config(
  new With32KBDTIM ++
  new WithArtyTrenzScratchpadTweaks ++
  new chipyard.config.WithL2TLBs(0) ++
  new testchipip.soc.WithNoScratchpads ++
  new freechips.rocketchip.subsystem.WithNBanks(0) ++
  new freechips.rocketchip.subsystem.WithNoMemPort ++
  new freechips.rocketchip.rocket.WithScratchpadsOnly ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)
