`include "defines.v"
module ID
#(
    parameter ID2EX_WD = 49,
    parameter WB2RF_WD = 50
)(
    input wire clk,
    input wire rst_n,
    input wire flush,
    input wire [5:0] stall,
    input wire br_e,
    //when id stallreq
    //ex is load and data 相关
    output wire stallreq_id,

    input wire pc_valid,
    input wire [63:0] pc,
    input wire [63:0] inst_sram_rdata,
    input wire [31:0] csr_vec_h,

    input wire [WB2RF_WD-1:0] wb2rf_bus,
    output wire [ID2EX_WD-1:0] id2ex_bus,
    `ifdef DIFF_EN
    output wire [63:0] regs_o[0:31] 
    `endif
);

    reg pc_valid_r;
    reg [63:0] pc_r;
    reg [31:0] csr_vec_h_r;

    wire [1:0] sel_src1;
    wire sel_src2;
    wire [3:0] sel_rf_res;
    wire [14:0] alu_op;
    wire [7:0] bru_op;
    wire [6:0] lsu_op;
    wire [4:0] mul_op;
    wire [3:0] div_op;

    // csr instruction
    wire [3:0] csr_op;
    wire [11:0] csr_addr;
    wire csr_wdata_sel;  // select the imm
    wire [63:0] csr_wdata;
    wire [63:0] csr_vec;
    wire [31:0] csr_vec_l;
    wire rf_we;

    wire [4:0] rs1, rs2;
    wire [63:0] rdata1, rdata2;
    wire [63:0] imm;
    wire [4:0] rf_waddr;

    always @ (posedge clk)begin
        if (!rst_n) begin
            pc_valid_r <= 1'b0;
            pc_r <= 64'b0;
            csr_vec_h_r <= 32'b0;
        end
        else if (flush) begin
            pc_valid_r <= 1'b0;
            pc_r <= 64'b0;
            csr_vec_h_r <= 32'b0;
        end
        //nop, ID stall and EX not stall
        else if (stall[1]&(!stall[2]))begin
            pc_valid_r <= 1'b0;
            pc_r <= 64'b0;
            csr_vec_h_r <= 32'b0;
        end
        //nop, ID not stall but branch/jump
        else if (!stall[1]&br_e) begin
            pc_valid_r <= 1'b0;
            pc_r <= 64'b0;
            csr_vec_h_r <= 32'b0;
        end
        // ID not stall so go on
        else if (!stall[1]) begin
            pc_valid_r <= pc_valid;
            pc_r <= pc;
            csr_vec_h_r <= csr_vec_h;
        end
    end

    reg [63:0] inst_r;
    reg stall_flag;

    always @ (posedge clk) begin
        if (!rst_n) begin
            inst_r <= 64'b0;
            stall_flag <= 1'b0;
        end
        else if (flush) begin
            inst_r <= 64'b0;
            stall_flag <= 1'b0;
        end
        //if not stall, get inst from inst_sram
        else if (!stall[1]) begin
            inst_r <= inst_sram_rdata;
            stall_flag <= 1'b0;
        end
        else if (stall_flag) begin

        end
        //if stall and id stall, get inst from inst_ram ?
        else if (stall[1]&stall[2]) begin
            inst_r <= inst_sram_rdata;
            stall_flag <= 1'b1;
        end
    end

    wire [31:0] inst;
    wire [63:0] inst_tmp;

    assign inst_tmp = stall_flag ? inst_r : inst_sram_rdata;
    assign inst = ~pc_valid_r ? 32'b0 : pc_r[2] ? inst_tmp[63:32] : inst_tmp[31:0];

    decoder_64i u_decoder_64i(
        .inst         (inst           ),
        .sel_src1     (sel_src1       ),
        .sel_src2     (sel_src2       ),
        .rs1          (rs1            ),
        .rs2          (rs2            ),
        .imm          (imm            ),
        .alu_op       (alu_op         ),
        .bru_op       (bru_op         ),
        .lsu_op       (lsu_op         ),
        .mul_op       (mul_op         ),
        .div_op       (div_op         ),
        .csr_op       (csr_op         ),
        .csr_addr     (csr_addr       ),
        .sel_rf_res   (sel_rf_res     ),
        .csr_wdata_sel(csr_wdata_sel  ),
        .csr_vec_l    (csr_vec_l      ),
        .rf_we        (rf_we          ),
        .rf_waddr     (rf_waddr       )
    );

    wire wb_rf_we;
    wire [4:0] wb_rf_waddr;
    wire [63:0] wb_rf_wdata;
    assign {wb_rf_we,wb_rf_waddr,wb_rf_wdata} = wb2rf_bus;

    regfile u_regfile(
    	.clk    (clk    ),
        .rst_n  (rst_n  ),
        .rs1    (rs1    ),
        .rdata1 (rdata1 ),
        .rs2    (rs2    ),
        .rdata2 (rdata2 ),
        .we     (wb_rf_we     ),
        .waddr  (wb_rf_waddr  ),
        .wdata  (wb_rf_wdata  ),
`ifdef DIFF_EN
        .regs_o (regs_o)
`endif
    );

    assign csr_vec = {csr_vec_h_r, csr_vec_l};
    assign id2ex_bus = {
        csr_vec,                      //64
        csr_op,                       //4
        csr_addr,                     //12
        csr_wdata_sel,                //1
        sel_src1,                     //2
        sel_src2,                     //1
        rs1,                          //5
        rs2,                          //5
        rdata1,                       //64
        rdata2,                       //64
        imm,                          //64
        alu_op,                       //15
        bru_op & {8{pc_valid_r}},     //8
        lsu_op & {7{pc_valid_r}},     //7
        mul_op & {5{pc_valid_r}},     //5
        div_op & {4{pc_valid_r}},     //4
        sel_rf_res,                   //4
        rf_we & pc_valid_r,           //1
        rf_waddr & {5{pc_valid_r}},   //5
        pc_r,                         //64
        inst & {32{pc_valid_r}}       //32
    };

    //通过时钟，在下一个状态获取，但是放在了ID段（好离谱
    reg [6:0] ex_load_buffer;
    reg ex_csr_buffer;

    always @ (posedge clk) begin
        if (!rst_n) begin
            ex_load_buffer <= 7'b0;
            ex_csr_buffer <= 1'b0;
        end
        else if (flush) begin
            ex_load_buffer <= 7'b0;
            ex_csr_buffer <= 1'b0;
        end
        else if (stall[2]&(!stall[3])) begin
            ex_load_buffer <= 7'b0;
            ex_csr_buffer <= 1'b0;
        end
        else if (!stall[2]) begin
            ex_load_buffer <= {sel_rf_res[1], rf_we, rf_waddr};
            ex_csr_buffer <= sel_rf_res[2];
        end
    end

    wire ex_is_load;
    wire ex_is_csr;
    wire ex_rf_we;
    wire [4:0] ex_rf_waddr;
    assign {ex_is_load,ex_rf_we,ex_rf_waddr} = ex_load_buffer;
    assign ex_is_csr = ex_csr_buffer;
    //ex段为load指令，且发生数据相关时，id段需要被暂停
    wire stallreq_load;
    wire stallreq_csr;
    assign stallreq_load = ex_is_load & ex_rf_we & ((ex_rf_waddr==rs1 & rs1!=0)|(ex_rf_waddr==rs2 & rs2!=0));
    assign stallreq_csr  = ex_is_csr  & ex_rf_we & ((ex_rf_waddr==rs1 & rs1!=0)|(ex_rf_waddr==rs2 & rs2!=0));
    assign stallreq_id = stallreq_load | stallreq_csr;

endmodule
