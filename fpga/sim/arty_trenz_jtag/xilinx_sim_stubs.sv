// ---------------------------------------------------------------------------
// Behavioral simulation stubs for the THREE Xilinx primitives that the real
// generated harness RTL (gen-collateral/ArtyTrenzScratchpadHarness.sv)
// instantiates but that are not part of the FIRRTL/CIRCT output:
//
//   - IBUFDS            (sys_clock differential input buffer)
//   - IBUF              (reset pin input buffer; its output is unused)
//   - harnessSysPLLNode (the Vivado clk_wiz PLL IP blackbox)
//
// Everything else in all.f is real RTL (incl. PowerOnResetFPGAOnly, the IO
// cells, the TAP, the debug module, Rocket) and simulates as-is. These stubs
// let Verilator elaborate the *actual* generated netlist so the JTAG path we
// are debugging is exercised faithfully (a clock is a clock in RTL sim, so
// physical clock-routing issues are intentionally out of scope here).
// ---------------------------------------------------------------------------

`timescale 1ns/1ps

// Differential input buffer: pass the positive leg through as a single-ended
// clock. Parameters are declared (with the IP's defaults) only so the named
// parameter overrides in the harness instantiation elaborate cleanly.
module IBUFDS #(
  parameter CAPACITANCE      = "DONT_CARE",
  parameter DIFF_TERM        = "FALSE",
  parameter DQS_BIAS         = "FALSE",
  parameter IBUF_DELAY_VALUE = 0,
  parameter IBUF_LOW_PWR     = "TRUE",
  parameter IFD_DELAY_VALUE  = "AUTO",
  parameter IOSTANDARD       = "DEFAULT"
) (
  output O,
  input  I,
  input  IB
);
  assign O = I;
endmodule

// Plain input buffer.
module IBUF (
  output O,
  input  I
);
  assign O = I;
endmodule

// Behavioral model of the clk_wiz PLL IP. Ports match
// obj/ip/harnessSysPLLNode/harnessSysPLLNode_bmstub.v
//   (reset is ACTIVE-HIGH; locked asserts a few input-clock edges after reset
//    releases). The output frequency is a 1:1 passthrough -- the exact ratio
//    is irrelevant to the JTAG TAP, which is clocked entirely by TCK.
module harnessSysPLLNode (
  input  reset,
  input  clk_in1,
  output clk_out1,
  output locked
);
  assign clk_out1 = clk_in1;

  reg [3:0] lock_cnt = 4'h0;
  reg       locked_r = 1'b0;
  always @(posedge clk_in1) begin
    if (reset) begin
      lock_cnt <= 4'h0;
      locked_r <= 1'b0;
    end else if (!locked_r) begin
      if (lock_cnt == 4'hF) locked_r <= 1'b1;
      else                  lock_cnt <= lock_cnt + 4'h1;
    end
  end
  assign locked = locked_r;
endmodule
