# I²C + OSPI (HM01B0 camera) integration — Arty100T

Adds a **general-purpose I²C bus** and the **HM01B0 parallel-video capture peripheral ("OSPI")**
to the Chipyard SoC and routes both out on the **Arty100T** FPGA shell. Targets a **Rocket** core.

## Build status — verified green through Verilog + XDC

| Stage | Command | Result |
|---|---|---|
| Scala compile | `make SUB_PROJECT=arty100t launch-sbt SBT_COMMAND=";project chipyard_fpga; compile"` | ✅ `[success]` |
| Chisel elaboration → FIRRTL | `make SUB_PROJECT=arty100t CONFIG=RocketArty100TConfig firrtl` | ✅ (I²C + OSPI wired to ChipTop) |
| firtool → Verilog | `make SUB_PROJECT=arty100t CONFIG=RocketArty100TConfig run-firtool` | ✅ 347 `.sv`, incl. OSPI/I²C modules |
| XDC pin constraints | (emitted during elaboration) | ✅ I²C + OSPI package pins + pull-ups |
| Vivado bitstream | `make SUB_PROJECT=arty100t CONFIG=RocketArty100TConfig bitstream` | ⏳ **not run** (needs Vivado + verified pins — see caveats) |

Run from `chipyard/fpga/` after `source ../env.sh` (activates `.conda-env`: JDK 20, sbt, firtool).

## Files changed

All paths relative to the chipyard root. The `fpga/fpga-shells` submodule shows as modified in
`git status` — that is a **pre-existing pointer difference in this checkout, not part of this work**.

### New — OSPI peripheral (`generators/chipyard/src/main/scala/ospi/`)
RTL (copied verbatim from the standalone `ospi/` mill project, `package ospi`):
- `Params.scala`, `CapturePort.scala`, `CaptureFrontend.scala`, `AsyncFifo.scala`, `HM01B0Capture.scala`
- **`OspiChipyard.scala`** (new wrapper): `OspiParams`, `OspiKey`, `OspiCapture`
  (`ClockSinkDomain` + `TLRegisterNode` + regmap, PBUS-clocked, GCD-style), the
  `CanHavePeripheryOspi` subsystem trait, and the `WithOspiCapture` config fragment.

### Modified — OSPI wiring (chipyard generator)
- `generators/chipyard/src/main/scala/DigitalTop.scala` — mixed in `ospi.CanHavePeripheryOspi`.
- `generators/chipyard/src/main/scala/iobinders/Ports.scala` — added `OspiPort`.
- `generators/chipyard/src/main/scala/iobinders/IOBinders.scala` — added `WithOspiPunchthrough`
  (exposes the sensor bundle at the chip boundary).

### Modified — Arty100T shell (fpga)
- `fpga/src/main/scala/arty100t/HarnessBinders.scala` — added **`WithArty100TI2C`** (open-drain
  SCL/SDA via `UIntToAnalog`/`AnalogToUInt` IOBUFs + package pins + pull-ups) and
  **`WithArty100TOspi`** (maps the sensor pins to PMOD package pins).
- `fpga/src/main/scala/arty100t/Configs.scala` — added to `WithArty100TTweaks`:
  `chipyard.config.WithI2C`, `WithArty100TI2C`, `ospi.WithOspiCapture`,
  `chipyard.iobinders.WithOspiPunchthrough`, `WithArty100TOspi`.

> Because these are in `WithArty100TTweaks`, **both `RocketArty100TConfig` and `NoCoresArty100TConfig`**
> now include I²C + OSPI. Harness binders are leftmost, so they override the default
> `WithI2CTiedOff` (first-match-wins in the `fn orElse up(HarnessBinders)` chain).

## Address map (PBUS)

| Device | Base | Notes |
|---|---|---|
| I²C (`sifive…TLI2C`) | `0x1004_0000` | chipyard default `WithI2C` address |
| OSPI capture | `0x1008_0000` | `OspiParams.address` (4 KiB region) |

## OSPI register map (word offsets from `0x1008_0000`)

| Off | Name | R/W | Fields |
|---|---|---|---|
| `0x00` | CTRL | RW | `[0]`enable `[1]`continuous `[2]`irqEnable `[3]`trigPulse `[4]`clear |
| `0x04` | GEOM | RW | `[15:0]`expWidth `[31:16]`expHeight (defaults 324×244) |
| `0x08` | MCLKDIV | RW | MCLK = sysclk / (2·(mclkDiv+1)) |
| `0x10` | FRAMECNT | RO | frames completed since reset |
| `0x14` | LASTWIDTH | RO | measured width of last frame |
| `0x18` | LASTHEIGHT | RO | measured height of last frame |
| `0x1C` | FLAGS | RO | `[0]`dataValid `[1]`overflow `[2]`geomErr `[3]`sensorInt `[4]`busy |
| `0x20` | DATA | RO | read **pops** one pixel beat: `[7:0]`data `[8]`sof `[9]`eol `[10]`eof |

v1 is **poll-based** (no PLIC interrupt). PCLK enters as a plain input clock; the core's internal
`AsyncFifo` does the PCLK→system-clock CDC, so no diplomatic clock crossing is used.
Software flow: set CTRL.enable (+GEOM), poll FRAMECNT/FLAGS, drain DATA until an `eof` beat.

## Pin assignments (Arty A7-100T, in the generated `*.shell.xdc`)

**I²C** (PMOD JB, LVCMOS33, internal pull-up enabled): `i2c_scl`→**E15**, `i2c_sda`→**E16**.

**OSPI** (PMOD JA = data, PMOD JC = control, LVCMOS33):
`ospi_d[0..7]`→**G13,B11,A11,D12,D13,B18,A18,K16**; `ospi_pclk`→**U12**, `ospi_fvld`→**V12**,
`ospi_lvld`→**V10**, `ospi_intr`→**V14**, `ospi_mclk`→**V11**, `ospi_trig`→**U14**
(`ospi_pclk` gets `clockDedicatedRouteFalse`).

## Caveats before bitstream / hardware

1. **Verify pins against your board master XDC.** The pins above are a sensible Digilent Arty A7
   PMOD allocation (JA/JB/JC) and pass elaboration, but confirm they're free and correct for your
   board before Vivado P&R. Override via `new WithArty100TI2C("<scl>","<sda>")`; for OSPI edit the
   pin lists in `WithArty100TOspi`.
2. **I/O voltage.** HM01B0 IOVDD max is **3.0 V**; Arty100T PMOD is **3.3 V LVCMOS** → use a level
   shifter (or run the sensor at 2.8 V). External ~4.7 kΩ I²C pull-ups are recommended (the XDC sets
   only the weak internal pull-up).
3. **PCLK** lands on a non-clock-capable PMOD pin; for higher pixel clocks route it to a
   clock-capable user pin (and/or a BUFG/MMCM in the shell).

## Notes / follow-ups

- OSPI lives **inside the `chipyard` generator** (like the `GCD` example), not a separate sbt
  subproject — zero `build.sbt` surgery, simplest to build. Extracting to `generators/ospi` later
  is mechanical.
- **IRQ:** add an `IntSourceNode` + `ibus.fromSync := ospi.intnode` (RegisterRouter/HasInterruptSources
  style) for a frame-done interrupt instead of polling.
- **DMA-to-DRAM:** for Saturn/Gemmini, add a `TLClientNode` master (icenet `StreamReaderCore` pattern)
  so frames land in DRAM; the core's `Decoupled[PixelFlit]` output is unchanged.
