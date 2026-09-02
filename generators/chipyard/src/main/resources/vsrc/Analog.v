// See LICENSE for license details

`timescale 1ns/1ps

// Defaults are required: Vivado reads a .v file in Verilog-2001 mode, which
// rejects a parameter declared without an initial value. Every instantiation
// overrides both, so this changes no elaborated hardware.
module AnalogConst #(parameter CONST = 0, parameter WIDTH = 1) (
    output [WIDTH-1:0] io
);

    assign io = CONST;

endmodule
