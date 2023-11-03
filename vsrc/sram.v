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
    wire [63:0] rdata_tmp;
    RAMHelper RAMHelper(
        .clk              (clk),
        .en               (en),
        .rIdx             ((addr - `PC_START) >> 3),
        .rdata            (rdata_tmp),
        .wIdx             ((addr - `PC_START) >> 3),
        .wdata            (wdata),
        .wmask            ({{8{we[7]}},{8{we[6]}},{8{we[5]}},{8{we[4]}},{8{we[3]}},{8{we[2]}},{8{we[1]}},{8{we[0]}}}),
        .wen              (|we)
    );

    always @(posedge clk) begin
        if (!rst_n) begin
            rdata <= 0;
        end
        else begin
            rdata <= rdata_tmp;
        end
    end
endmodule
