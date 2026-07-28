//See LICENSE for license details.

package firechip.chip

import org.chipsalliance.cde.config.Config

/** FireSim targets for the SoCs RiskyBird measures on KU040.
 *
 *  A design point is a `chipyard.<X>Config`. It gets two wrappers that differ
 *  only in what surrounds it:
 *
 *  {{{
 *  // area:        WithKU040Tweaks           ++ WithBroadcastManager   ++ chipyard.<X>Config
 *  // performance: WithDefaultFireSimBridges ++ WithFireSimConfigTweaks ++ chipyard.<X>Config
 *  }}}
 *
 *  Because both wrap the same base, the elaborated SoC is the same machine and
 *  a resource measurement can be joined to a latency measurement exactly. That
 *  is the whole point: without a FireSim wrapper, no configuration measured for
 *  area has ever actually been run, and its benchmark numbers have to be
 *  borrowed from a different machine and labelled extrapolated.
 *
 *  These are keyed on the *base* config, not on the KU040 wrapper, so the
 *  several board variants that differ only in periphery -- plain, `Ospi`, and
 *  `DroneLogic` -- share one FireSim target. Periphery changes area; it does
 *  not change how many cycles a network takes.
 *
 *  Two divergences from the KU040 shells remain and are deliberate, since
 *  FireSim is a performance vehicle rather than a deployment target:
 *  `WithFireSimConfigTweaks` runs every bus at 1000 MHz where the KU040 shells
 *  declare 50, and FireSim models an L2 and DDR where the KU040 shell wires a
 *  32 KiB scratchpad. The first is harmless -- profiles are recorded in cycles
 *  and converted to wall time once, at whatever frequency is being reported --
 *  while the second changes cycle counts and is why the KU040 DDR4 config
 *  still needs writing.
 *
 *  This file is the RiskyBird-owned corner of firechip. Keeping the wrappers
 *  here rather than in `TargetConfigs.scala` means upstream edits to that file
 *  never conflict with ours.
 */

/** Rocket alone. The scalar baseline, and the only KU040 point that leaves
 *  meaningful room on the device (16.2% of LUTs).
 */
class FireSimRiskyBirdRocketConfig extends Config(
  new WithDefaultFireSimBridges ++
  new WithFireSimConfigTweaks ++
  new chipyard.RocketConfig)

/** Rocket plus the V256D128 Saturn vector unit, no matrix engine.
 *  Elaborates with `zvl256b`; the backing profile shape is `V256D128_rvv`.
 */
class FireSimRiskyBirdSaturnV256D128Config extends Config(
  new WithDefaultFireSimBridges ++
  new WithFireSimConfigTweaks ++
  new chipyard.REFV256D128RocketConfig)

/** Rocket plus the default 16x16 int8 Gemmini: 256 mesh cells.
 *  No vector unit -- this hart's ISA carries no `zvl*`.
 */
class FireSimRiskyBirdGemmini16x16Config extends Config(
  new WithDefaultFireSimBridges ++
  new WithFireSimConfigTweaks ++
  new chipyard.GemminiRocketConfig)

/** Rocket plus the Q0.31 weight-stationary 32x32 Gemmini: 1024 mesh cells,
 *  128 KB accumulator. Also has no vector unit, which is why pairing it with
 *  an RVV profile describes hardware it does not have.
 */
class FireSimRiskyBirdGemminiQ31Ws32x32Config extends Config(
  new WithDefaultFireSimBridges ++
  new WithFireSimConfigTweaks ++
  new chipyard.Q31Ws32x32AccGemminiRocketConfig)

/** Rocket plus the V128D128 Saturn vector unit carrying the int8 Outer Product
 *  Unit: 256 OuterProductCell instances, two DSP48E2 each.
 */
class FireSimRiskyBirdSaturnOPUV128D128Config extends Config(
  new WithDefaultFireSimBridges ++
  new WithFireSimConfigTweaks ++
  new chipyard.REFV128D128RocketOPUConfig)

/** V128D128 Saturn vector unit and the Q0.31 32x32 Gemmini on one Rocket.
 *
 *  The same base chain as `Q31Ws32x32AccGemminiSaturnV128D128KU040Config` in
 *  `fpga/src/main/scala/ku040/Configs.scala`, differing only in the two wrapper
 *  tweaks -- which is what makes the area measurement and the latency
 *  measurement describe one machine.
 *
 *  Closest of these to the machine the shipped gemmini_q31 and V256D128_rvv
 *  profiles were captured on: same accelerator pair, one hart instead of two,
 *  and VLEN 128 instead of 256.
 */
class FireSimRiskyBirdGemminiQ31SaturnV128D128Config extends Config(
  new WithDefaultFireSimBridges ++
  new WithFireSimConfigTweaks ++
  new saturn.rocket.WithRocketVectorUnit(128, 128, saturn.common.VectorParams.refParams) ++
  new gemmini.Q31Ws32x32AccGemminiConfig ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)
