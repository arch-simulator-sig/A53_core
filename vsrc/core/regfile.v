`include "defines.v"
`include "defines.svh"
`include "DPI-C.svh"

module regfile(
    input wire clk,
    input wire rst_n,

    input wire [4:0] rs1,
    output wire [63:0] rdata1,
    input wire [4:0] rs2,
    output wire [63:0] rdata2,

    input wire we,
    input wire [4:0] waddr,
    input wire [63:0] wdata,
    
    input wire [63:0]  debug_wb_pc,
    input wire [31:0]  debug_wb_inst
  );
  reg [63:0] rf [31:0];

  always @ (posedge clk)
  begin
    if (!rst_n)
    begin
      rf[ 0] <= 64'b0;
      rf[ 1] <= 64'b0;
      rf[ 2] <= 64'b0;
      rf[ 3] <= 64'b0;
      rf[ 4] <= 64'b0;
      rf[ 5] <= 64'b0;
      rf[ 6] <= 64'b0;
      rf[ 7] <= 64'b0;
      rf[ 8] <= 64'b0;
      rf[ 9] <= 64'b0;
      rf[10] <= 64'b0;
      rf[11] <= 64'b0;
      rf[12] <= 64'b0;
      rf[13] <= 64'b0;
      rf[14] <= 64'b0;
      rf[15] <= 64'b0;
      rf[16] <= 64'b0;
      rf[17] <= 64'b0;
      rf[18] <= 64'b0;
      rf[19] <= 64'b0;
      rf[20] <= 64'b0;
      rf[21] <= 64'b0;
      rf[22] <= 64'b0;
      rf[23] <= 64'b0;
      rf[24] <= 64'b0;
      rf[25] <= 64'b0;
      rf[26] <= 64'b0;
      rf[27] <= 64'b0;
      rf[28] <= 64'b0;
      rf[29] <= 64'b0;
      rf[30] <= 64'b0;
      rf[31] <= 64'b0;
    end
    else if (we & (waddr!=0))
    begin
      rf[waddr] <= wdata;
    end
  end

  // assign rdata1 = we & (rs1==waddr) ? wdata : |rs1 ? rf[rs1] : 32'b0;
  assign rdata1 = ~(|rs1) ? 64'b0 : we & (rs1==waddr) ? wdata : rf[rs1];
  // assign rdata2 = we & (rs2==waddr) ? wdata : |rs2 ? rf[rs2] : 32'b0;
  assign rdata2 = ~(|rs2) ? 64'b0 : we & (rs2==waddr) ? wdata : rf[rs2];

import "DPI-C" function void set_gpr_ptr(input xlen_t r[]);
            initial
                set_gpr_ptr(rf);

import "DPI-C" function void set_pc_ptr(input xlen_t pc[]);
            initial
                set_pc_ptr(debug_wb_pc);

            xlen_t rPC;

import "DPI-C" function void halt();
            always @(posedge clk)
            begin
                rPC <= debug_wb_pc;
            end
            always @(debug_wb_pc)
            begin
                if(debug_wb_pc >= `PC_RST_VAL && rPC != debug_wb_pc)
                begin
                    call_step(debug_wb_pc);
`ifdef CONFIG_ITRACE
                    itrace(`zext(debug_wb_inst));
`endif

                end
            end
endmodule
