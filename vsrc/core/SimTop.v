
//--xuezhen--

`include "defines.v"

module SimTop(
    input         clock,
    input         reset,

    input  [63:0] io_logCtrl_log_begin,
    input  [63:0] io_logCtrl_log_end,
    input  [63:0] io_logCtrl_log_level,
    input         io_perfInfo_clean,
    input         io_perfInfo_dump,

    output        io_uart_out_valid,
    output [7:0]  io_uart_out_ch,
    output        io_uart_in_valid,
    input  [7:0]  io_uart_in_ch
);

// if_stage
wire [63 : 0] pc;
wire [31 : 0] inst;

// id_stage
// id_stage -> regfile
wire rs1_r_ena;
wire [4 : 0]rs1_r_addr;
wire rs2_r_ena;
wire [4 : 0]rs2_r_addr;
wire rd_w_ena;
wire [4 : 0]rd_w_addr;
// id_stage -> exe_stage
wire [4 : 0]inst_type;
wire [7 : 0]inst_opcode;
wire [`REG_BUS]op1;
wire [`REG_BUS]op2;

// regfile -> id_stage
wire [`REG_BUS] r_data1;
wire [`REG_BUS] r_data2;
// regfile -> difftest
wire [`REG_BUS] regs[0 : 31];
// csr -> difftest
wire [63:0] satp;
wire [63:0] mstatus;
wire [63:0] mie;
wire [63:0] mtvec;
wire [63:0] mtimecmp;
wire [63:0] mtime;
wire [63:0] mscratch;
wire [63:0] mepc;
wire [63:0] mcause;
wire [63:0] mip;

// exe_stage
// exe_stage -> other stage
wire [4 : 0]inst_type_o;
// exe_stage -> regfile
wire [`REG_BUS]rd_data;

wire clk;
assign clk = clock;
wire rst_n;
assign rst_n = ~reset;

// inst sram 
wire         inst_sram_en;
wire [7:0]   inst_sram_we;
wire [63:0]  inst_sram_addr;
wire [63:0]  inst_sram_wdata;
wire [63:0]  inst_sram_rdata;
// data sram 
wire         data_sram_en;
wire [7:0]   data_sram_we;
wire [63:0]  data_sram_addr;
wire [63:0]  data_sram_wdata;
wire [63:0]  data_sram_rdata;
// confreg 
wire        conf_en;
wire [7 :0] conf_wen;
wire [63:0] conf_addr;
wire [63:0] conf_wdata;
wire [63:0] conf_rdata;

wire [63:0]  debug_wb_pc;
wire [31:0]  debug_wb_inst;
wire [7:0]   debug_wb_rf_we;
wire [4:0]   debug_wb_rf_wnum;
wire [63:0]  debug_wb_rf_wdata;

mycpu_pipeline 
#(
  .ID2EX_WD  (`ID2EX_WD  ),
  .EX2MEM_WD (`EX2MEM_WD ),
  .MEM2WB_WD (`MEM2WB_WD ),
  .WB2RF_WD  (`WB2RF_WD  ),
  .MEM2EX_WD (`MEM2EX_WD ),
  .WB2EX_WD  (`WB2EX_WD  )
)
u_mycpu_pipeline(
  .clk               (clk               ),
  .rst_n             (rst_n             ),
  .timer_int         (0                 ),
  .stallreq_axi      (0                 ),
  .inst_sram_en      (inst_sram_en      ),
  .inst_sram_we      (inst_sram_we      ),
  .inst_sram_addr    (inst_sram_addr    ),
  .inst_sram_wdata   (inst_sram_wdata   ),
  .inst_sram_rdata   (inst_sram_rdata   ),
  .data_sram_en      (data_sram_en      ),
  .data_sram_we      (data_sram_we      ),
  .data_sram_addr    (data_sram_addr    ),
  .data_sram_wdata   (data_sram_wdata   ),
  .data_sram_rdata   (data_sram_rdata   ),
  .debug_wb_pc       (debug_wb_pc       ),
  .debug_wb_inst     (debug_wb_inst     ),
  .debug_wb_rf_we    (debug_wb_rf_we    ),
  .debug_wb_rf_wnum  (debug_wb_rf_wnum  ),
  .debug_wb_rf_wdata (debug_wb_rf_wdata )
);

sram u_inst_sram(
  .clk   (clk   ),
  .rst_n (rst_n ),
  .en    (inst_sram_en    ),
  .we    (inst_sram_we    ),
  .addr  (inst_sram_addr  ),
  .wdata (inst_sram_wdata ),
  .rdata (inst_sram_rdata )
);

sram u_data_sram(
  .clk   (clk   ),
  .rst_n (rst_n ),
  .en    (data_sram_en    ),
  .we    (data_sram_we    ),
  .addr  (data_sram_addr  ),
  .wdata (data_sram_wdata ),
  .rdata (data_sram_rdata )
);


endmodule