
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
  .debug_wb_rf_wdata (debug_wb_rf_wdata ),
  .regs_o            (regs              )
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

// Difftest
reg cmt_wen;
reg [7:0] cmt_wdest;
reg [`REG_BUS] cmt_wdata;
reg [`REG_BUS] cmt_pc;
reg [31:0] cmt_inst;
reg cmt_valid;
reg trap;
reg [7:0] trap_code;
reg [63:0] cycleCnt;
reg [63:0] instrCnt;
reg [`REG_BUS] regs_diff [0 : 31];

wire inst_valid = (debug_wb_pc != `PC_START & debug_wb_pc != 0) | (debug_wb_inst != 0);

always @(negedge clock) begin
  if (reset) begin
    {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst, cmt_valid, trap, trap_code, cycleCnt, instrCnt} <= 0;
  end
  else if (~trap) begin
    cmt_wen   <= debug_wb_rf_we & (debug_wb_rf_wnum!=0);
    cmt_wdest <= {3'd0, debug_wb_rf_wnum};
    cmt_wdata <= debug_wb_rf_wdata;
    cmt_pc    <= debug_wb_pc;
    cmt_inst  <= debug_wb_inst;
    cmt_valid <= inst_valid;

		regs_diff <= regs;

    trap <= inst[6:0] == 7'h6b;
    trap_code <= regs[10][7:0];
    cycleCnt <= cycleCnt + 1;
    instrCnt <= instrCnt + inst_valid;
  end
end

DifftestInstrCommit DifftestInstrCommit(
  .clock              (clock),
  .coreid             (0),
  .index              (0),
  .valid              (cmt_valid),
  .pc                 (cmt_pc),
  .instr              (cmt_inst),
  .special            (0),
  .skip               (0),
  .isRVC              (0),
  .scFailed           (0),
  .wen                (cmt_wen),
  .wdest              (cmt_wdest),
  .wdata              (cmt_wdata)
);

DifftestArchIntRegState DifftestArchIntRegState (
  .clock              (clock),
  .coreid             (0),
  .gpr_0              (regs_diff[0]),
  .gpr_1              (regs_diff[1]),
  .gpr_2              (regs_diff[2]),
  .gpr_3              (regs_diff[3]),
  .gpr_4              (regs_diff[4]),
  .gpr_5              (regs_diff[5]),
  .gpr_6              (regs_diff[6]),
  .gpr_7              (regs_diff[7]),
  .gpr_8              (regs_diff[8]),
  .gpr_9              (regs_diff[9]),
  .gpr_10             (regs_diff[10]),
  .gpr_11             (regs_diff[11]),
  .gpr_12             (regs_diff[12]),
  .gpr_13             (regs_diff[13]),
  .gpr_14             (regs_diff[14]),
  .gpr_15             (regs_diff[15]),
  .gpr_16             (regs_diff[16]),
  .gpr_17             (regs_diff[17]),
  .gpr_18             (regs_diff[18]),
  .gpr_19             (regs_diff[19]),
  .gpr_20             (regs_diff[20]),
  .gpr_21             (regs_diff[21]),
  .gpr_22             (regs_diff[22]),
  .gpr_23             (regs_diff[23]),
  .gpr_24             (regs_diff[24]),
  .gpr_25             (regs_diff[25]),
  .gpr_26             (regs_diff[26]),
  .gpr_27             (regs_diff[27]),
  .gpr_28             (regs_diff[28]),
  .gpr_29             (regs_diff[29]),
  .gpr_30             (regs_diff[30]),
  .gpr_31             (regs_diff[31])
);

DifftestTrapEvent DifftestTrapEvent(
  .clock              (clock),
  .coreid             (0),
  .valid              (trap),
  .code               (trap_code),
  .pc                 (cmt_pc),
  .cycleCnt           (cycleCnt),
  .instrCnt           (instrCnt)
);

DifftestCSRState DifftestCSRState(
  .clock              (clock),
  .coreid             (0),
  .priviledgeMode     (`RISCV_PRIV_MODE_M),
  .mstatus            (0),
  .sstatus            (0),
  .mepc               (0),
  .sepc               (0),
  .mtval              (0),
  .stval              (0),
  .mtvec              (0),
  .stvec              (0),
  .mcause             (0),
  .scause             (0),
  .satp               (0),
  .mip                (0),
  .mie                (0),
  .mscratch           (0),
  .sscratch           (0),
  .mideleg            (0),
  .medeleg            (0)
);


endmodule