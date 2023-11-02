`include "defines.v"
module sram(
    input wire clk,
    input wire rst_n,

    input wire en,
    input wire [7:0] we,
    input wire [63:0] addr,
    input wire [63:0] wdata,
    output reg [63:0] rdata
);
    // RAMHelper RAMHelper(
    //     .clk              (clk),
    //     .en               (en),
    //     .rIdx             ((addr - `PC_START) >> 3),
    //     .rdata            (rdata),
    //     .wIdx             ((addr - `PC_START) >> 3),
    //     .wdata            (wdata),
    //     .wmask            (we),
    //     .wen              (|we)
    // );
endmodule
