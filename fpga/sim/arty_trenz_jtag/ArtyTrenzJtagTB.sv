// ---------------------------------------------------------------------------
// ArtyTrenzJtagTB - a "dummy OpenOCD" that bit-bangs the soft RISC-V JTAG TAP
// of the REAL generated harness (ArtyTrenzScratchpadHarness) and checks that
// the TAP actually responds.
//
// It reproduces exactly the scan-chain interrogation that OpenOCD performs and
// that fails on hardware ("all ones", "IR capture saw 0x1f not 0x01"):
//   1. Drive the TAP to Test-Logic-Reset (also clears the TCK-clocked POR).
//   2. Read the 32-bit IDCODE DR  -> expect a valid code (LSB==1, not 0xFFFFFFFF),
//      and a TDO line that actually TOGGLES.
//   3. Capture the Instruction Register -> expect the mandatory low bits 0b01.
//
// Pass/fail and a per-bit TDO trace are printed to stdout, so the console alone
// tells you whether the RTL responds. Run with +trace to also dump an FST.
//
// JTAG timing: the TAP updates TDO on the FALLING edge of TCK (see
// JtagTapController.sv: clock_falling = ~clock). This master sets TMS/TDI while
// TCK is low, pulses TCK high then low, and samples TDO while TCK is low (the
// value the TAP presented on the previous falling edge) -- i.e. sample-then-shift.
// ---------------------------------------------------------------------------

`timescale 1ns/1ps

module ArtyTrenzJtagTB;

  // ---- board-level stimulus -------------------------------------------------
  logic sys_clk = 1'b0;
  always #5 sys_clk = ~sys_clk;        // 100 MHz system clock

  logic reset_pin = 1'b1;              // T3 carrier reset (active-high); unused
                                       // by the scratchpad DUT, driven anyway
  logic uart_rxd  = 1'b1;             // idle UART

  // ---- JTAG pins driven by this master -------------------------------------
  logic jtag_TCK = 1'b0;
  logic jtag_TMS = 1'b1;             // idle high
  logic jtag_TDI = 1'b0;

  // ---- harness outputs ------------------------------------------------------
  wire  jtag_TDO;
  wire  uart_txd, led_0, led_1;
  wire  jtag_probe_TCK, jtag_probe_TMS, jtag_probe_TDI, jtag_probe_TDO;

  // ---- DUT: the actual generated FPGA harness ------------------------------
  ArtyTrenzScratchpadHarness dut (
    .sys_clock_p    (sys_clk),
    .sys_clock_n    (~sys_clk),
    .led_0          (led_0),
    .led_1          (led_1),
    .reset          (reset_pin),
    .uart_txd       (uart_txd),
    .uart_rxd       (uart_rxd),
    .jtag_TCK       (jtag_TCK),
    .jtag_TMS       (jtag_TMS),
    .jtag_TDI       (jtag_TDI),
    .jtag_TDO       (jtag_TDO),
    .jtag_probe_TCK (jtag_probe_TCK),
    .jtag_probe_TMS (jtag_probe_TMS),
    .jtag_probe_TDI (jtag_probe_TDI),
    .jtag_probe_TDO (jtag_probe_TDO)
  );

  // ---- JTAG bit-bang primitives --------------------------------------------
  localparam int TCK_HALF = 50;        // ns (timescale 1ns) -> ~10 MHz TCK

  string scan_trace;                   // per-bit TDO trace (MSB..LSB) of last scan

  // One TCK cycle: set TMS/TDI (while TCK low), rising edge, falling edge.
  task automatic tck_tick(input logic tms, input logic tdi);
    jtag_TMS = tms;
    jtag_TDI = tdi;
    #(TCK_HALF) jtag_TCK = 1'b1;        // rising: TAP samples TMS/TDI, advances
    #(TCK_HALF) jtag_TCK = 1'b0;        // falling: TAP updates TDO
  endtask

  // Force the TAP to Test-Logic-Reset from any state (>=5 TMS=1) and clear the
  // TCK-clocked power-on reset. Leaves the TAP in TLR (TMS held high).
  task automatic goto_tlr();
    for (int i = 0; i < 6; i++) tck_tick(1'b1, 1'b0);
  endtask

  // TLR -> Run-Test/Idle
  task automatic tlr_to_rti();
    tck_tick(1'b0, 1'b0);
  endtask

  // Scan a data register of `n` bits. Assumes Run-Test/Idle on entry; returns to
  // Run-Test/Idle. `din` is shifted in LSB-first; `dout` is read LSB-first.
  // The per-bit TDO trace (MSB..LSB) is left in module-level `scan_trace`.
  task automatic scan_dr(input int n, input logic [63:0] din,
                         output logic [63:0] dout);
    // RTI -> Select-DR -> Capture-DR -> Shift-DR
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b0, 1'b0);
    tck_tick(1'b0, 1'b0);
    dout       = '0;
    scan_trace = "";
    // rocket-chip's TDO is REGISTERED (negedge tdoReg), so captured bit i
    // appears on TDO *after* the i-th shift clock: clock first, then sample.
    for (int i = 0; i < n; i++) begin
      tck_tick(1'b0, din[i]);                          // shift bit i (stay in Shift-DR)
      dout[i]    = jtag_TDO;                            // sample after the shift
      scan_trace = $sformatf("%b%s", jtag_TDO, scan_trace);
    end
    // Shift-DR -> Exit1-DR -> Update-DR -> Run-Test/Idle
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b0, 1'b0);
  endtask

  // Scan the instruction register of `n` bits. Same conventions as scan_dr.
  task automatic scan_ir(input int n, input logic [63:0] din,
                         output logic [63:0] dout);
    // RTI -> Select-DR -> Select-IR -> Capture-IR -> Shift-IR
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b0, 1'b0);
    tck_tick(1'b0, 1'b0);
    dout       = '0;
    scan_trace = "";
    for (int i = 0; i < n; i++) begin
      tck_tick(1'b0, din[i]);                          // shift bit i (stay in Shift-IR)
      dout[i]    = jtag_TDO;                            // sample after the shift (registered TDO)
      scan_trace = $sformatf("%b%s", jtag_TDO, scan_trace);
    end
    // Shift-IR -> Exit1-IR -> Update-IR -> Run-Test/Idle
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b1, 1'b0);
    tck_tick(1'b0, 1'b0);
  endtask

  // count 0<->1 transitions in the low `n` bits of v (LSB-first read order)
  function automatic int n_transitions(input logic [63:0] v, input int n);
    int   c;
    logic prev;
    c    = 0;
    prev = v[0];
    for (int i = 1; i < n; i++) begin
      if (v[i] !== prev) c++;
      prev = v[i];
    end
    return c;
  endfunction

  // ---- main sequence --------------------------------------------------------
  localparam int IR_LEN = 5;           // JtagTapController: [4:0] instruction

  logic [63:0] idcode, ircap;
  logic        reset_tdo;
  int          fails = 0;

  initial begin
    if ($test$plusargs("trace")) begin
      $dumpfile("arty_trenz_jtag.fst");
      $dumpvars(0, ArtyTrenzJtagTB);
      $display("[TB] FST tracing enabled -> arty_trenz_jtag.fst");
    end

    // Release the (unused) carrier reset; let the PLL stub lock and the DUT
    // come out of reset before we start clocking JTAG.
    #200 reset_pin = 1'b0;
    #2000;

    $display("\n================ Arty-Trenz JTAG TAP interrogation ================");

    // Snapshot TDO while the TAP is still in its power-on reset (no TCK yet).
    // Prediction from the RTL: a reset TAP drives TDO LOW (tdoReg<=0).
    reset_tdo = jtag_TDO;
    $display("[TB] TDO before any TCK (TAP in POR)         : %0b  (RTL predicts 0)",
             reset_tdo);

    // ---- 1) Test-Logic-Reset -----------------------------------------------
    goto_tlr();
    tlr_to_rti();

    // ---- 2) IDCODE ----------------------------------------------------------
    scan_dr(32, 64'h0, idcode);
    $display("\n[TB] IDCODE shift (MSB..LSB) TDO = %s", scan_trace);
    $display("[TB] IDCODE = 0x%08x   transitions=%0d",
             idcode[31:0], n_transitions(idcode, 32));
    if (idcode[31:0] === 32'hFFFFFFFF) begin
      $display("[FAIL] IDCODE all-ones: TDO frozen HIGH (reproduces the HW symptom).");
      fails++;
    end else if (idcode[31:0] === 32'h0) begin
      $display("[FAIL] IDCODE all-zeros: TDO frozen LOW (TAP likely still in reset / unclocked).");
      fails++;
    end else if (idcode[0] !== 1'b1) begin
      $display("[FAIL] IDCODE LSB != 1: not a valid IEEE 1149.1 IDCODE.");
      fails++;
    end else if (n_transitions(idcode, 32) == 0) begin
      $display("[FAIL] IDCODE has no TDO transitions: line is stuck.");
      fails++;
    end else begin
      $display("[PASS] IDCODE valid and TDO toggles%s.",
               (idcode[31:0] === 32'h1) ? " (== 0x00000001, the rocket-chip default)" : "");
    end

    // ---- 3) IR capture ------------------------------------------------------
    // Shift in all-ones while reading the capture value; OpenOCD checks the low
    // bits are 0b01. (Shifting in 0x1F also selects BYPASS, which is harmless.)
    scan_ir(IR_LEN, 64'h1F, ircap);
    $display("\n[TB] IR capture (MSB..LSB) TDO = %s", scan_trace);
    $display("[TB] IR capture = 0x%02x  (low 2 bits = 0b%02b)",
             ircap[IR_LEN-1:0], ircap[1:0]);
    if (ircap[1:0] !== 2'b01) begin
      $display("[FAIL] IR capture low bits = 0b%02b, expected 0b01 (HW saw 0x1f).",
               ircap[1:0]);
      fails++;
    end else begin
      $display("[PASS] IR capture low bits == 0b01 (== 0x%02x).", ircap[IR_LEN-1:0]);
    end

    // ---- summary ------------------------------------------------------------
    $display("\n================================================================");
    if (fails == 0) begin
      $display("RESULT: PASS - the generated RTL responds to JTAG scan-chaining.");
      $display("        => the all-ones bug is NOT in the RTL/reset logic; it is");
      $display("           physical (TCK clock routing / pad / pin). Go to Phase B.");
    end else begin
      $display("RESULT: FAIL (%0d) - the RTL reproduces the JTAG failure in sim.", fails);
      $display("        => the bug is logical. Inspect the FST (run with +trace):");
      $display("           dut.chiptop0 jtag_reset, the TAP FSM state, tdoReg.");
    end
    $display("================================================================\n");
    $finish;
  end

  // ---- watchdog -------------------------------------------------------------
  initial begin
    #2_000_000;                        // 2 ms
    $display("[TB] TIMEOUT - simulation did not finish.");
    $finish;
  end

endmodule
