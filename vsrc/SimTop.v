
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
    input  [7:0]  io_uart_in_ch,
    output wire   difftest_step
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
  .debug_wb_rf_wdata (debug_wb_rf_wdata ),
  .satp              (satp              ),
  .mstatus           (mstatus           ),
  .mie               (mie               ),
  .mtvec             (mtvec             ),
  .mtimecmp          (mtimecmp          ),
  .mtime             (mtime             ),
  .mscratch          (mscratch          ),
  .mepc              (mepc              ),
  .mcause            (mcause            ),
  .mip               (mip               ),
      `ifdef DIFF_EN
  .regs_o            (regs              )
  `endif
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


`ifdef DIFF_EN

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

    trap <= debug_wb_inst[6:0] == 7'h6b;
    trap_code <= regs[10][7:0];
    cycleCnt <= cycleCnt + 1;
    instrCnt <= instrCnt + inst_valid;
  end
end

DifftestInstrCommit DifftestInstrCommit(
  .clock                    (clock),
  .enable                   (1),
  .io_valid                 (cmt_valid),
  .io_skip                  (0),
  .io_isRVC                 (0),
  .io_rfwen                 (cmt_wen),
  .io_fpwen                 (0),
  .io_vecwen                (0),
  .io_wpdest                (cmt_wdest),
  .io_wdest                 (cmt_wdest),
  .io_pc                    (cmt_pc),
  .io_instr                 (cmt_inst),
  .io_robIdx                (0),
  .io_lqIdx                 (0),
  .io_sqIdx                 (0),  
//TODO: add signal
  .io_isLoad                (0),
  .io_isStore               (0),
  .io_nFused                (0),
  .io_special               (0),
  .io_coreid                (0),
  .io_index                 (0)
);



DifftestArchIntRegState DifftestArchIntRegState (
.clock                    (clock),
.enable                   (1),
.io_coreid                (0),
.io_value_0               (regs_diff[0]),
.io_value_1               (regs_diff[1]),
.io_value_2               (regs_diff[2]),
.io_value_3               (regs_diff[3]),
.io_value_4               (regs_diff[4]),
.io_value_5               (regs_diff[5]),
.io_value_6               (regs_diff[6]),
.io_value_7               (regs_diff[7]),
.io_value_8               (regs_diff[8]),
.io_value_9               (regs_diff[9]),
.io_value_10              (regs_diff[10]),
.io_value_11              (regs_diff[11]),
.io_value_12              (regs_diff[12]),
.io_value_13              (regs_diff[13]),
.io_value_14              (regs_diff[14]),
.io_value_15              (regs_diff[15]),
.io_value_16              (regs_diff[16]),
.io_value_17              (regs_diff[17]),
.io_value_18              (regs_diff[18]),
.io_value_19              (regs_diff[19]),
.io_value_20              (regs_diff[20]),
.io_value_21              (regs_diff[21]),
.io_value_22              (regs_diff[22]),
.io_value_23              (regs_diff[23]),
.io_value_24              (regs_diff[24]),
.io_value_25              (regs_diff[25]),
.io_value_26              (regs_diff[26]),
.io_value_27              (regs_diff[27]),
.io_value_28              (regs_diff[28]),
.io_value_29              (regs_diff[29]),
.io_value_30              (regs_diff[30]),
.io_value_31              (regs_diff[31])
);



DifftestTrapEvent DifftestTrapEvent(
  .clock              (clock),
  .enable             (1),
  .io_hasTrap         (trap),
  .io_cycleCnt        (cycleCnt),
  .io_instrCnt        (instrCnt),
  .io_hasWFI          (0),
  .io_code            (trap_code),
  .io_pc              (cmt_pc),
  .io_coreid          (0)
);



DifftestCSRState DifftestCSRState(
  .clock                  (clock),
  .enable                 (1),
  .io_coreid              (0),
  .io_priviledgeMode      (`RISCV_PRIV_MODE_M),
  .io_mstatus             (mstatus),
  .io_sstatus             (64'h200000000),
  .io_mepc                (mepc),
  .io_sepc                (0),
  .io_mtval               (0),
  .io_stval               (0),
  .io_mtvec               (mtvec),
  .io_stvec               (0),
  .io_mcause              (mcause),
  .io_scause              (0),
  .io_satp                (satp),
  .io_mip                 (mip),
  .io_mie                 (mie),
  .io_mscratch            (mscratch),
  .io_sscratch            (0),
  .io_mideleg             (0),
  .io_medeleg             (0)
);

DifftestTop DifftestTop(
  .clock (clock),
  .reset (rst_n),
  .difftest_step (difftest_step)
);
`endif
endmodule