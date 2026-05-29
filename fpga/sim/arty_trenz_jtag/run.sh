#!/usr/bin/env bash
# Build + run the Arty-Trenz JTAG TAP interrogation testbench against the REAL
# generated harness RTL, using Verilator. Pass +trace to also emit an FST.
#
#   ./run.sh            # fast: console PASS/FAIL + per-bit TDO trace
#   ./run.sh +trace     # also dump arty_trenz_jtag.fst for GTKWave/Surfer
#
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GENSRC="/scratch/lorenhung/chipyard/fpga/generated-src/chipyard.fpga.arty_trenz.ArtyTrenzScratchpadHarness.ScratchpadArtyTrenzConfig"
ALLF="$GENSRC/chipyard.fpga.arty_trenz.ArtyTrenzScratchpadHarness.ScratchpadArtyTrenzConfig.all.f"
# Behavioral SRAM (*_ext) models. all.f excludes these because the Vivado flow
# maps SRAMs to BRAM IP; for simulation we compile the behavioral models.
MEMS="$GENSRC/gen-collateral/chipyard.fpga.arty_trenz.ArtyTrenzScratchpadHarness.ScratchpadArtyTrenzConfig.top.mems.v"
OBJ="$HERE/obj_dir"
EXE="ArtyTrenzJtagTB"

if [[ ! -f "$ALLF" ]]; then
  echo "ERROR: RTL manifest not found: $ALLF"
  echo "Generate the FPGA RTL first (the normal 'make ... SUB_PROJECT=arty_trenz_sp' bitstream flow)."
  exit 1
fi

echo "=== verilating (first build elaborates a full Rocket core; takes a few minutes) ==="
verilator \
  --binary --timing -j 0 \
  --top-module "$EXE" \
  --trace-fst \
  --timescale 1ns/1ps \
  --Mdir "$OBJ" \
  -o "$EXE" \
  -Wno-fatal \
  -Wno-WIDTH -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE -Wno-LATCH \
  -Wno-WIDTHCONCAT -Wno-UNSIGNED -Wno-CMPCONST -Wno-MULTIDRIVEN \
  -Wno-BLKANDNBLK -Wno-INITIALDLY \
  -f "$ALLF" \
  "$MEMS" \
  "$HERE/xilinx_sim_stubs.sv" \
  "$HERE/$EXE.sv"

echo ""
echo "=== running sim ==="
"$OBJ/$EXE" "$@"
