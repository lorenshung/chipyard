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
 *  256 OuterProductCell instances -- one OuterProductUnit x 16 clusters x 16
 *  cells. Each cell costs two DSP48E2 under use_dsp, not one: the 8x8 signed
 *  multiply feeds a 32-bit add whose addend arrives through a 4:1 mux over the
 *  cell's register file, so the DSP's internal accumulate feedback cannot be
 *  used. That is why the +517 DSP delta is 256*2+5 and not 512+5.
 *
 *  Measured synth-only on xcku040-sfva784-1-c:
 *    pristine  191,455 LUT (79.0%)  155 DSP (8.1%)
 *    use_dsp   161,133 LUT (66.5%)  672 DSP (35.0%)
 */
class SaturnOPUV128D128KU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.REFV128D128RocketOPUConfig)

/** V128D128 Saturn vector unit and the Q0.31 32x32 Gemmini on one Rocket.
 *
 *  Both accelerators on a single hart: Saturn as the vector unit in the tile,
 *  Gemmini as a RoCC coprocessor on that tile's port. This is the shape the
 *  FireSim profiling machine has, so it is the design point where a borrowed
 *  profile stands the best chance of transferring.
 *
 *  Feasibility is the open question. The measured accelerator increments with
 *  use_dsp are ~90,100 LUT for this Gemmini and ~122,100 LUT for the V128D128
 *  Saturn *including* its Outer Product Unit, which together overrun the device.
 *  Dropping the OPU is what might make room: the OPU is 256 cells at two
 *  DSP48E2 each, and this workload mix reaches int8 matmul through Gemmini
 *  rather than through Saturn's outer-product path.
 *
 *  The FPU is deliberately kept. `mlp_control` is fp32 and is the only
 *  safety-critical workload in the mix, so the ~14K LUTs a WithoutFPU cut would
 *  recover are not available here.
 */
class Q31Ws32x32AccGemminiSaturnV128D128KU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new saturn.rocket.WithRocketVectorUnit(128, 128, saturn.common.VectorParams.refParams) ++
  new gemmini.Q31Ws32x32AccGemminiConfig ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

/** As above, with Saturn's floating-point units stripped.
 *
 *  Measured from the hierarchy of the full build: Saturn's `ExecutionUnitfp` is
 *  49,670 LUT, over half the vector unit's 92,447 and the single largest item
 *  after Gemmini's mesh. `intOnlyParams` sets `noFP = true`, removing the
 *  FPFMAPipe, FPConv, FPDiv and FPCmp instantiations.
 *
 *  The Rocket *scalar* FPU is deliberately retained -- `WithRocketNoFPU` is not
 *  applied -- so `mlp_control`, the fp32 and only safety-critical workload in
 *  the mix, still executes. It loses vector acceleration for fp32 and falls
 *  back to the scalar FPU, which its 0.527 ms against a 20 ms deadline can
 *  absorb. The int8 networks are unaffected: they reach the vector unit through
 *  integer paths and Gemmini through RoCC.
 */
class Q31Ws32x32AccGemminiSaturnV128D128IntOnlyKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new saturn.rocket.WithRocketVectorUnit(128, 128, saturn.common.VectorParams.intOnlyParams) ++
  new gemmini.Q31Ws32x32AccGemminiConfig ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

/** FP16-only Saturn alongside the Q0.31 32x32 Gemmini, targeting 100 MHz.
 *
 *  Third point in the FP-stripping waterfall: full FP (223,787 LUT, 92.3%) was
 *  infeasible, integer-only (177,064 LUT, 73.0%) fits, and this puts vector FP
 *  back at FP16 only. `robotMpcParams` sets `noFP64` and `noFP32`, keeping the
 *  FP16 FMA and dropping the FP32/FP64 datapaths, and switches to TandemFMAPipe
 *  because FP-stripping is gated there rather than in SegmentedFMAPipe.
 *
 *  `useElementwiseFP64 = true` is inert in this
 *  combination: `SIMDFPFMAFactory` filters SEW=3 and SEW=2 instructions out
 *  before the element-wise mapping runs, so with FP64 and FP32 already stripped
 *  there is nothing left for it to convert. It is set so the intent survives if
 *  the FP64 strip is ever relaxed.
 *
 *  The Rocket scalar FPU is still retained, so `mlp_control` -- fp32, and the
 *  only safety-critical workload in the mix -- keeps a correct execution path.
 *
 *  The 100 MHz target is a *synthesis constraint*, not a closed frequency. The
 *  only KU040 config ever placed and routed is the 16%-LUT Rocket, which
 *  achieved 69.5 MHz. Whether a design at this occupancy closes at 100 MHz is
 *  unknown until it is routed, and synth-only will report area regardless.
 */
class Q31Ws32x32AccGemminiSaturnV128D128Fp16KU040Config extends Config(
  new WithKU040Tweaks(freqMHz = 100) ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new saturn.rocket.WithRocketVectorUnit(128, 128,
    saturn.common.VectorParams.robotMpcParams.copy(useElementwiseFP64 = true)) ++
  new gemmini.Q31Ws32x32AccGemminiConfig ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

/** FP16 Saturn paired with an FP16-only Rocket scalar FPU, at 100 MHz.
 *
 *  Completes the pairing upstream's REFV128D128RocketRobotMpcConfig intends:
 *  robotMpcParams strips FP64/FP32 from the vector unit, WithRocketFPU16 does
 *  the same to the scalar FPU. The previous build had only the first half, so
 *  its fpuOpt was still the full 14,060 LUT f16/f32/f64 unit.
 *
 *  Measured composition of that scalar FPU: the FP16 FMA is 489 LUT of 14,032.
 *  The rest is per-precision FMA pipes, three separate div/sqrt units, format
 *  converters, and a 32x65-bit register file sized to hold doubles.
 *
 *  Caveat carried from docs/design-space.md: WithRocketFPU16 is non-spec -- Zfh
 *  without the F base -- and cannot run standard soft-float. It is only viable
 *  once MPC is genuinely fp16 and nothing else in the image needs fp32.
 *
 *  `noPermute` drops the vrgather / vcompress / vslide shuffle network, 2,101
 *  LUT measured. It is the only integer-side cut VectorParams exposes; the
 *  integer divider (1,326 LUT, nothing in the workload divides) and the
 *  bitmanip pipe (1,219 LUT, no vector bitmanip is issued) are unconditional in
 *  `integerALUs` / `integerFUs` and would need knobs adding in Saturn.
 *
 *  The permute cut is safe for an area probe -- synthesis executes nothing --
 *  but is not yet validated functionally. maxpool2d_s8, upsample_nearest_s8 and
 *  the cat ops could plausibly lower to slides or gathers, which would
 *  trap-illegal at runtime. That has to be checked before anything is run.
 */
class Q31Ws32x32AccGemminiSaturnV128D128Fp16FullKU040Config extends Config(
  new WithKU040Tweaks(freqMHz = 100) ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new saturn.rocket.WithRocketVectorUnit(128, 128,
    saturn.common.VectorParams.robotMpcParams.copy(
      useElementwiseFP64 = true,
      noPermute = true)) ++
  new freechips.rocketchip.rocket.WithRocketFPU16 ++
  new gemmini.Q31Ws32x32AccGemminiConfig ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

/** As the FP16 point above, with Gemmini's fp32 mvin scale removed.
 *
 *  Place-and-route of the FP16 build missed 100 MHz by WNS -9.83 ns on a 10 ns
 *  period -- a ~20 ns critical path. Every one of the 100+ paths physical
 *  optimization touched was the same module replicated across scale units:
 *
 *    gemmini/spad/vsm/pipe{,_1,_3}/out_bits_data_muladder/mulAddRecFNToRaw_postMul
 *
 *  That is the `mvin` scale, which the Q0.31 work left as upstream Chipyard
 *  Gemmini: `mvin_scale_args` is inherited from `GemminiConfigs.defaultConfig`
 *  and is fp32 (`Float(8, 24)`), an INToRecFN -> MulAddRecFN -> round chain.
 *  Its `latency = 4` does not help, because `VectorScalarMultiplier` applies
 *  `Pipe(out, latency)` *after* the scale function, so the registers sit outside
 *  the combinational block rather than retiming it. The design was half
 *  converted: fixed-point on the way out, floating-point on the way in.
 *
 *  Removing it is free for this workload. Every call site in the modelblaster
 *  kernels and in the codegen template passes `MVIN_SCALE_IDENTITY` for both A
 *  and B, and requantization is done in scalar software after a `full_C=true`
 *  matmul writes the raw int32 accumulator out. No kernel asks for a
 *  non-identity input scale, so the hardware is dead.
 *
 *  Overridden here rather than in the Gemmini submodule so the existing
 *  measurements of the other Q0.31 configs stay reproducible, and so a
 *  fork-only pin needs no local edit.
 */
class Q31Ws32x32AccGemminiSaturnV128D128Fp16NoMvinScaleKU040Config extends Config(
  new WithKU040Tweaks(freqMHz = 100) ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new saturn.rocket.WithRocketVectorUnit(128, 128,
    saturn.common.VectorParams.robotMpcParams.copy(
      useElementwiseFP64 = true,
      noPermute = true)) ++
  new freechips.rocketchip.rocket.WithRocketFPU16 ++
  new gemmini.Q31GemminiConfig(
    gemmini.GemminiQ31WsConfigs.q31Ws32x32AccConfig.copy(mvin_scale_args = None)) ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

class NoCoresKU040Config extends Config(
  new WithKU040Tweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.NoCoresConfig)
