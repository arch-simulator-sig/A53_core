`include "defines.v"
`include "DPI-C.svh"
`include "defines.svh"
module sram(
    input wire clk,
    input wire rst_n,

    input wire en,
    input wire [7:0] we,
    input wire [63:0] addr,
    input wire [63:0] wdata,
    output reg [63:0] rdata
  );

  always @(posedge clk)
  begin
    if(en)
    begin
      if(|we)
      begin
        pmem_write(`zext(addr), wdata, we);
      end
      else
      begin
        pmem_read(`zext(addr), rdata);
      end
    end
  end


endmodule
