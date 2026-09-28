# RiskyBird Chipyard integration

The `integration` branch preserves the original KU040, Arty200T and recovered
garden histories. The reviewed migration commits are retained unchanged:

- `57900bd8`: merge `ku040-codesign-cnn-repro` (`cacf5d83`) with
  `arty200t-dual-uart` (`bb33c836`), selecting the newer accelerator dependencies
  and the Arty flash-boot shell fixes.
- `5172bd0b`: merge Dima's recovered `041d19ea` KU040 configurations. Its tree
  matches Git's automatic merge of its two parents.
- `a46a0d54`: restore KU040 harness binders and FcRoCC source/resources from the
  recorded garden snapshot. The source hashes are in
  `recovery/garden-20260927/imported-files.json`.
- `11c259fd` and `91a5a49a`: preserve additional research files and patches under
  `recovery/`. These archives are outside the active compiler source paths.

Integration cleanup removes an unused `.gitmodules` entry for
`fpga/fpga/fpga-shells` (there was no gitlink) and corrects misleading scalar-FPU
comments. It does not change the selected configurations' FPU widths.

Generated-RTL review found that the recovered unconnected KU040 UART binder's
`DontCare` RX became a constant zero, asserting a permanent UART break. The
integration fix uses the existing `UART.tieoff` helper, which drives RX idle-high
and permits discarded TX to drain when optional active-low CTS is present.
This is a follow-up correction to the preserved recovery; its original import
manifest continues to record the original source snapshot.

## Selected RTL dependencies

| Path | Commit | Published repository / branch |
| --- | --- | --- |
| generators/gemmini | `7d91e9ecec5d52e7f2cae659272606aec59e3af8` | CobbledSteel/gemmini / riskybird-gemmini-statuspoll |
| generators/rocket-chip | `4023521326f14663069e9ed6ce57fbed6209b746` | CobbledSteel/rocket-chip / riskybird-rocketfpu16 |
| generators/saturn | `e73d9bcc479eec4064ced555956da766781e06ef` | CobbledSteel/saturn-vectors / saturn-vmem-be-gate |
| generators/tacit | `dd7a19cd075d1b53085eaf0097165b517093a237` | CobbledSteel/tacit / optional-branch-predictor |
| fpga/fpga-shells | `80831d87fa35e326cdaf5ba88057ea1940ba89e0` | lorenshung/fpga-shells / trenz |

All selected commits were confirmed published. The four accelerator updates
descend from the previous Arty pins; the shell pin is unchanged. Rocket and
Saturn advance together because Rocket's vector-memory interrupt deferral uses
Saturn's `vec_mem_busy` signal. No nested dependency source was modified here.

## Validation procedure

The isolated checkout uses the exact committed generator pins. Dependency Git
objects and Maven artifacts were seeded from local caches; no dirty source
files or old generated RTL were used. This is not an empty-cache installation
test. The tools are sbt 1.8.2, Scala 2.13.16, Chisel 6.7.0 and firtool 1.75.0
(the memory-macro compiler uses the repository's Chisel 3 configuration).

After initializing the required generator dependencies and setting up the
Chipyard tool environment, the build commands are:

```sh
sbt 'chipyard_fpga/compile'
make -C fpga SUB_PROJECT=arty200t CONFIG=RocketArty200TDroneFullDDRConfig \
  FIRTOOL_BIN=/path/to/firtool firrtl verilog
```

Repeat the second command for the configurations below, using `SUB_PROJECT=ku040`
for KU040. `verilog` includes firtool lowering, module/file-list processing and
memory-macro generation. It does not invoke Vivado synthesis or implementation.

Validation on 2026-09-28 passed Scala compilation and all ten complete Verilog
builds and collateral checks below. The UART correction is confined to KU040;
all affected configurations were rebuilt after the final helper change in
`3803af8ac9dfeadc1378ea2d519cb21e200297c8`.

| Configuration | Clock | Gemmini DIM | Scalar fLen, hart 0 / hart 1 | Result |
| --- | --- | --- | --- | --- |
| RocketArty200TDroneFullDDRConfig | 50 MHz | none | 64 / none | pass |
| RocketArty200TDroneFullDDRDmaUartConfig | 50 MHz | none | 64 / none | pass |
| RocketArty200TDroneGemminiSaturnIntAt35Config | 35 MHz | 16 | 64 / none | pass |
| RocketArty200TDroneGemminiSaturnFp16At35Config | 35 MHz | 16 | 16 / none | pass |
| RocketKU040DroneSensorsConfig | 50 MHz | none | 64 / none | pass |
| RocketKU040DroneDualConfig | 50 MHz | 32 | 32 / 32 | pass |
| RocketKU040DroneDualFp16Config | 50 MHz | 32 | 16 / 32 | pass |
| RocketKU040DroneDual16Fp16Config | 50 MHz | 16 | 16 / 32 | pass |
| RocketKU040DroneDualFp16D64Config | 50 MHz | 32 | 16 / 32 | pass |
| Q31Ws32x32AccGemminiSaturnV128D128Fp16NoMvinScaleOspiSingleDDRKU040Config | 100 MHz | 32 | 16 / none | pass |

Runtime configuration inspection also reads the actual per-hart scalar FPU and
vector parameters. Generated DTS checks cover clocks, DDR ranges, CPU count,
UART and sensor addresses, camera/DMA presence and advertised vector extensions;
per-elaboration Gemmini headers check DIM and the custom3 opcode. KU040 RTL
checks verify the unused UART's idle-high input. The regression check rejects
the original constant-low output and accepts the corrected output.

The integer-dual hierarchy maps FcRoCC and Saturn to hart 0 and Gemmini to hart 1.
The FcRoCC SV and both ROM hex files reach the final FPGA source list. These are
structural build checks; no firmware execution, numerical test, FPGA timing or
board validation is implied.

## Hardware and software limits

- KU040 dual FP16 configurations have a scalar FP16-only FPU on hart 0
  (`minFLen=16`, `fLen=16`) and scalar FP32 on hart 1. The former comments saying
  hart 0 retained FP32 were incorrect for the selected Rocket fragment.
  The DTS advertises `f` whenever Rocket has an FPU, so that string alone does
  not prove scalar FP32 capability. Firmware must match the actual hart
  parameters; FcRoCC does not supply scalar floating-point instructions.
- The recovered FcRoCC module leaves inactive memory/FPU interfaces as
  inherited `DontCare`. The checked integer-dual Verilog ties FcRoCC's cache request
  valid to zero; no spurious-request failure was demonstrated. Explicit
  source tie-offs remain possible hardening rather than a merge correction.
- The FcRoCC ROM resources are preserved, but the original `fc_rocc_asm.c`
  generator source has not been recovered. Historical ROM/numerical claims
  are not new validation results. The supported Chisel 6 generation emits both
  hex files into the blackbox file list, and the FPGA manifest pipeline
  preserves them; synthesis must still verify memory initialization.
- The archived proposal for a trace-DMA broadcast-manager deadlock is not
  applied. It adds an L2 configuration and changes TACIT branch-predictor
  settings, so it requires a separate reviewed experiment.
- Sibling NVFP4 and other archived research is preserved, not enabled in this
  branch's builds. The original dirty research checkout must be retained.
- Scala/RTL checks cannot establish FPGA fit, timing, interrupt correctness,
  sustained concurrent trace/inference/flight-controller operation, or numerical
  equivalence. Prior bitstream results do not qualify this merged RTL.
