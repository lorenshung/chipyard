# RiskyBird additions to the Chipyard backend

**Everything RiskyBird adds to this Chipyard checkout lives in this directory.**

Chipyard is a pinned backend. RiskyBird's rule is that integration code belongs
at the repository top level and backends are inputs, not places to accumulate
project glue. This directory is a deliberate, bounded exception: an FPGA
area-characterization flow has to run *inside* Chipyard's Vivado build, because
it needs Chipyard's elaborated RTL, its generated IP TCL, its source manifest,
and its board tables. Reimplementing that plumbing at the top level would
duplicate backend logic.

So the flow lives here, in one clearly named place, and hooks into Chipyard
through exactly one line.

## The complete set of RiskyBird edits to Chipyard's FPGA flow

One line, at the end of `fpga/Makefile`:

```make
-include $(base_dir)/riskybird/area.mk
```

That is the entire footprint. `-include` (not `include`) means deleting this
directory leaves Chipyard fully functional. To find every RiskyBird change to
this backend:

```console
grep -rn riskybird backends/chipyard/fpga/Makefile
```

Nothing else in Chipyard is patched. No existing script is modified, no existing
target changes behaviour, and no submodule pin moves.

## Contents

```text
backends/chipyard/riskybird/
├── README.md                   this file
├── area.mk                     make include: the rb-area* targets
└── tcl/
    ├── rb_synth_area.tcl       synth-only driver + provenance manifest
    └── rb_attributes.tcl       opt-in RTL attribute injection
```

## What the flow does

`make rb-area` runs Chipyard/fpga-shells synthesis and stops — no place, route,
timing closure, or bitstream — then emits hierarchical utilization reports and a
provenance manifest. A full P&R plus bitgen costs roughly an order of magnitude
more wall time, and area comparison across a config matrix does not need
routing.

```console
# through the RiskyBird CLI (preferred: records results and provenance)
rb area --board ku040
rb area --board ku040 --config SaturnKU040OspiConfig --attrs hierarchy

# directly
make -C backends/chipyard/fpga SUB_PROJECT=ku040 \
     CONFIG=RocketKU040OspiConfig RB_ATTRS=none rb-area
```

Targets:

| Target | Effect |
| --- | --- |
| `rb-area` | Synthesize and report, if the report is not already up to date |
| `rb-area-force` | Re-run unconditionally |
| `rb-area-restore` | Undo any RTL attribute injection in `gen-collateral` |

Outputs land in `$(build_dir)/obj/report/`: `rb_utilization_hier.txt`,
`rb_utilization_hier_d6.txt`, `rb_utilization_flat.txt`,
`rb_ram_utilization.txt`, and `rb_manifest.json`. fpga-shells' `synth.tcl` also
writes `post_synth.dcp`.

`fpga-shells`' own `report.tcl` is deliberately not used: it runs
`report_timing_summary`, `report_drc`, and `report_io`, which need a placed and
routed design, and it calls `exit 1` on negative slack — not a failure condition
for an area probe.

## Attribute injection, and why it is off by default

Two kinds of area are unreachable from any Chipyard parameter:

1. **Small signed multipliers map to LUTs instead of DSPs.** Gemmini's `MacUnit`
   and Saturn's `OuterProductCell` emit as combinational `a * b + c`. The
   sub-9-bit operands and surrounding muxes defeat Vivado's DSP-inference
   heuristic, so a 16×16 Gemmini mesh can spend tens of thousands of LUTs on
   multipliers that fit in one DSP48E2 each.
2. **`-flatten_hierarchy rebuilt` optimizes across module boundaries** before
   rebuilding hierarchy for reporting, so hierarchical utilization attributes
   shared logic arbitrarily.

Both are fixable with SystemVerilog attributes (`use_dsp`, `keep_hierarchy`),
which Chisel 6 + CIRCT firtool cannot emit on a module declaration — the legacy
`firrtl.AttributeAnnotation` is only consumed by the SFC `AddDescriptionNodes`
pass, which firtool does not run. So `rb_attributes.tcl` injects them into the
generated Verilog between elaboration and synthesis.

That is a mutation of generated RTL, which is exactly the kind of thing that
silently invalidates a provenance chain. Three properties keep it honest:

- **Off by default.** `RB_ATTRS=none` measures pristine generated RTL.
- **Recorded.** Every applied, skipped, or missing injection appears in
  `rb_manifest.json` under `rtl_mutation.injections`, so no measurement is ever
  silently attributed to unmodified RTL.
- **Reversible.** The pristine file is preserved as `<file>.rb-orig` before the
  first edit; `make rb-area-restore` restores it exactly rather than attempting
  a regex reversal.

| `RB_ATTRS` | Injects | Use for |
| --- | --- | --- |
| `none` (default) | nothing | Trustworthy device totals |
| `hierarchy` | `keep_hierarchy` on ChipTop, tiles, Saturn units, Gemmini, mesh, OPU | Faithful per-module attribution |
| `dsp` | `use_dsp` on `MacUnit`, `OuterProductCell`, `MulAddRecFNPipe_*` | Measuring the DSP-inference win |
| `all` | both | Attribution of a DSP-mapped design |

**`keep_hierarchy` inhibits cross-boundary optimization, so totals from a
`hierarchy` or `all` run are an upper bound.** The manifest sets
`rtl_mutation.totals_are_upper_bound` accordingly, and the top-level tooling
refuses to plot mixed modes on one axis. This caveat is not mentioned in the
upstream work these techniques came from.

`use_dsp` is a hint, not a mandate — Vivado may ignore it. The manifest records
what was requested; the utilization report records what happened.

## Differences from the upstream flow

These techniques come from `ucb-bar/chipyard` branch `xpurt` (see
`experiments/fpga-configs/` for the full archive and provenance). This
implementation is a rewrite, not a patch, and differs deliberately:

| Upstream | Here | Why |
| --- | --- | --- |
| Injection always on | Opt-in, default off | A measurement must be attributable to known RTL |
| Injection unrecorded | Recorded in `rb_manifest.json` | Mutation invisible in output is a provenance hole |
| No way back | `.rb-orig` backups + `rb-area-restore` | A mutated `gen-collateral` silently feeds later `make bitstream` |
| Hardcoded `RocketTile_1`, `SaturnRocketUnit_1` | Globs | Uniquified module counts vary by config |
| Copy-pasted injection blocks | One data-driven table | Adding a module is one line |
| `DONT_TOUCH` on matched cells post-synth | Not applied | Needed upstream because pinless VCU118 wrappers were DCE'd whole; RiskyBird shells bind real pins |
| `NSTD-1`/`UCIO-1` DRC downgraded to Warning in the shared `run_impl_bitstream.tcl` | Not applied | Upstream needed it for unpinned fit-check builds; downgrading unconstrained-IO checks on a real board hides pin errors |
| No provenance output | `rb_manifest.json` per run | Every figure needs part, tool version, config, and mutation state |

## Removing this

```console
rm -rf backends/chipyard/riskybird
# then delete the -include line from backends/chipyard/fpga/Makefile
```

Chipyard builds unchanged either way; `-include` tolerates the missing file.
