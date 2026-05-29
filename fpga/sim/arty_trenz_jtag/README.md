# Arty-Trenz JTAG TAP simulation ("dummy OpenOCD")

Drives the soft RISC-V JTAG TAP of the **real generated** `ArtyTrenzScratchpadHarness`
RTL in Verilator and checks whether the TAP responds to scan-chaining — the same
interrogation `openocd -f arty.cfg` performs and that fails on hardware with
*"all ones" / "IR capture saw 0x1f not 0x01"*.

This isolates **logic vs. physical**: a clock is a clock in RTL sim, so if the RTL
responds here, the hardware bug is physical (TCK clock routing / pad / pin), not in
the reset/TAP logic.

## Run

```bash
cd fpga/sim/arty_trenz_jtag
./run.sh           # console PASS/FAIL + per-bit TDO trace (fast)
./run.sh +trace    # also write arty_trenz_jtag.fst  (open in GTKWave/Surfer)
```

Prereq: the FPGA RTL must already be generated (it is — the manifest
`...ScratchpadArtyTrenzConfig.all.f` exists from the bitstream build). The first
Verilator build elaborates a full Rocket core and takes a few minutes; re-runs are fast.

## What it does

1. `goto_tlr()` — drive TMS=1 to Test-Logic-Reset (also clears the **TCK-clocked**
   power-on reset that gates the TAP).
2. **IDCODE** — shift the 32-bit DR; expect a valid code (LSB==1, not `0xFFFFFFFF`)
   on a TDO line that actually **toggles**. rocket-chip's default is `0x00000001`.
3. **IR capture** — capture the 5-bit IR; expect the mandatory low bits `0b01`
   (hardware sees `0x1f`).

## Reading the result

| Console result | Meaning | Next step |
|---|---|---|
| `RESULT: PASS` (TDO toggles, IDCODE/IR correct) | RTL + reset logic are **fine** | Bug is **physical** → Phase B: mirror internal nets (TAP-reset POR, TCK heartbeat, internal `port.io.TDO`) to spare J5 pins and watch on the Saleae |
| `IDCODE all-ones` | Reproduces the HW symptom in sim | Bug is **logical** → open the FST (`+trace`), inspect `dut.chiptop0` `jtag_reset`, TAP FSM state, `tdoReg` |
| `IDCODE all-zeros` | TAP stuck in reset / unclocked in sim | TAP reset never released — check the POR/`jtag_reset` wiring |

The console prints a per-bit TDO string for the IDCODE scan, so you can see
"frozen" vs "toggling" without opening a waveform.

> Note: the RTL predicts **TDO idles LOW (0)** while the TAP is in reset. The
> hardware shows TDO frozen **HIGH** — that is the pin's pull-up value, i.e. the
> pad is likely not being driven by the TAP at all. A `PASS` here makes that the
> leading hypothesis.

## Files

- `ArtyTrenzJtagTB.sv` — the testbench / JTAG bit-bang master + checks
- `xilinx_sim_stubs.sv` — behavioral `IBUFDS` / `IBUF` / `harnessSysPLLNode` (clk_wiz) stubs
- `run.sh` — Verilator build/run over `...all.f` + the stubs

## RESULT (2026-05-28)

**The sim PASSES** — the real RTL answers an OpenOCD-style scan correctly
(IDCODE=`0x00000001`, IR-capture=`0x01`, TDO toggles; TDO idles LOW in reset).
So the bug is **physical**, and the Vivado logs pinpoint it:

`jtag_TCK` is on **W20 = `IO_L12N_T1_MRCC_14`** — the **N-side** of a clock-capable
pair — so it has no dedicated route to the clock network
(`[Place 30-574]` / DRC `PLCK-12`, tolerated only by CLOCK_DEDICATED_ROUTE=FALSE).
The TAP flops and the TCK-clocked power-on reset never clock reliably → the TAP
never advances → JTAG reads garbage.

**Fix:** move TCK to a **_P** clock pin — **W19 = `IO_L12P_T1_MRCC_14` (J5-3)** —
i.e. swap TCK↔TDI in `src/main/scala/arty_trenz/HarnessBinders.scala` + the master
XDC, and swap those two leads on the FTDI cable; then rebuild + reflash.
