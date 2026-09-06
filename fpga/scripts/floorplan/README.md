# FPGA PAR floorplan tool

Renders a **place-and-route floorplan of the FPGA die, colored and labeled by
block** (Rocket core / Gemmini / Saturn / MIG DDR3 / periphery) from a
**post-route checkpoint**. It visualizes the congestion story behind the fmax
work on the riskybird DroNet SoC (XC7A200T).

Everything is re-derived from the checkpoint on each run: the per-block
partition, each block's LUT/FF/BRAM/DSP (via `report_utilization -cells`), the
device occupancy, and the part / speed-grade shown in the title. Nothing is
hardcoded, so it works on any config and any grade (e.g. the `-2` checkpoints
`board.tcl` now produces).

## Files
- `gen_floorplan.sh` — wrapper: resolve DCP -> run Vivado -> run the plotter.
- `extract_floorplan.tcl` — Vivado batch: opens the DCP, dumps per-block
  placement + per-block utilization + optional critical-path endpoints.
- `plot_floorplan.py` — matplotlib renderer (reads the extractor's output).

## Requirements (run on garden)
- Vivado on `PATH` (or pass `--vivado-settings <settingsNN.sh>`; defaults to
  `/ecad/tools/xilinx/Vivado/2023.1/settings64.sh`).
- `python3` with `numpy` and `matplotlib`.
- A routed `post_route.dcp` in the chipyard build tree.

## Usage
```sh
# by config name (resolves .../fpga/generated-src/*<NAME>*/obj/post_route.dcp)
./gen_floorplan.sh --config RocketArty200TDroneGemminiSaturnFp16At35Config \
    --out ~/at35_floorplan.png

# or by explicit checkpoint path (any config / grade)
./gen_floorplan.sh --dcp /path/to/post_route.dcp --out /path/to/floorplan.png
```
Outputs default to `<dcp_dir>/floorplan/` (under `generated-src`, gitignored):
`floorplan.png` plus the intermediates (`meta.txt`, `blocks_util.csv`,
`cells_<block>.txt`, `util_*.rpt`).

## Block partition
A **mutually-exclusive, exhaustive** partition of every placed primitive,
anchored on the Rocket-tile hierarchy (`acc_adders` and `fpuOpt` are hoisted to
the top level by flatten and matched explicitly):

| block   | match |
|---------|-------|
| gemmini | `*rockettile/gemmini/*` or `acc_adders/*` |
| saturn  | `*rockettile/vector_unit/*` |
| rocket  | rest of `*rockettile/*` (not gemmini/vector) or `fpuOpt/*` |
| mig     | `mig/*` |
| uncore  | everything else |

**Important:** the MIG match uses the clean `mig/*` prefix — **not** `*ddr*`,
which false-matches every `addr` register across the design (7-series MIG uses
zero DSP; an `*ddr*` filter wrongly reports otherwise). With the correct
partition the DSP totals reconcile exactly to the device total.

The five block ids are defined in both `extract_floorplan.tcl` (the Tcl filters,
source of truth for the tallies) and `plot_floorplan.py` (colors/labels); keep
them in sync. Blocks that are absent in a given config are skipped automatically.
