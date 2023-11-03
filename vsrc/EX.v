`include "defines.v"
module EX
#(
    parameter ID2EX_WD = 49,
    parameter EX2MEM_WD = 49,
    parameter MEM2EX_WD = 50,
    parameter WB2EX_WD = 50
)(
    input wire clk,
    input wire rst_n,
    input wire flush,
    input wire [5:0] stall,
    output wire stallreq_ex,

    input wire [ID2EX_WD-1:0] id2ex_bus,
    input wire [MEM2EX_WD-1:0] mem2ex_fwd,
    input wire [WB2EX_WD-1:0] wb2ex_fwd,
    output wire [EX2MEM_WD-1:0] ex2mem_bus,

    output wire [64:0] br_bus,

    output wire data_sram_en,
    output wire [7:0] data_sram_we,
    output wire [63:0] data_sram_addr,
    output wire [63:0] data_sram_wdata
);

    reg [ID2EX_WD-1:0] id2ex_bus_r;
    always @ (posedge clk) begin
        if (!rst_n) begin
            id2ex_bus_r <= 0;
        end
        else if (flush) begin
            id2ex_bus_r <= 0;
        end
        //nop, id stall and ex not stall
        else if (stall[2]&(!stall[3])) begin
            id2ex_bus_r <= 0;
        end
        //nop, id not stall and br_bus[64]
        else if (!stall[2]&br_bus[64]) begin
            id2ex_bus_r <= 0;
        end
        // id not stall so can go on
        else if (!stall[2]) begin
            id2ex_bus_r <= id2ex_bus;
        end
    end

    reg csr_cancel_reg;
    wire csr_cancel;
    always @ (posedge clk) begin
        if (!rst_n) begin
            csr_cancel_reg <= 0;
        end
        else if (flush) begin
            csr_cancel_reg <= 0;
        end
        else if (csr_cancel) begin
            csr_cancel_reg <= 1;
        end
    end

    wire [1:0] sel_src1;
    wire sel_src2;
    wire [4:0] rs1, rs2;
    wire [63:0] rdata1, rdata2;
    wire [63:0] imm;
    wire [14:0] alu_op;
    wire [7:0] bru_op;
    wire [6:0] lsu_op;
    wire [4:0] mul_op;
    wire [3:0] div_op;
    wire [3:0] sel_rf_res;
    wire rf_we;
    wire [4:0] rf_waddr;
    wire [63:0] pc;
    wire [31:0] inst;
    wire [3:0] csr_op;
    wire [11:0] csr_addr;
    wire csr_wdata_sel;
    wire [63:0] csr_wdata;
    wire [79:0] csr_bus;
    wire [63:0] csr_vec;
    
    //要改成63：0的话，这里还需要从csr里拉 mie[7] & mstatus[3] 过来判断是否中断屏蔽
    assign csr_cancel = |csr_vec[31:0];

    assign {
        csr_vec,        //64
        csr_op,         //4
        csr_addr,       //12
        csr_wdata_sel,  //1
        sel_src1,       //2
        sel_src2,       //1
        rs1,            //5
        rs2,            //5
        rdata1,         //64
        rdata2,         //64
        imm,            //64
        alu_op,         //15
        bru_op,         //8
        lsu_op,         //7
        mul_op,         //5
        div_op,         //4
        sel_rf_res,     //4
        rf_we,          //1
        rf_waddr,       //5
        pc,             //64
        inst            //32
    } = id2ex_bus_r;

    wire [63:0] src1, src2;
    wire [63:0] alu_src1, alu_src2;
    wire mem_rf_we, wb_rf_we;
    wire [4:0] mem_rf_waddr, wb_rf_waddr;
    wire [63:0] mem_rf_wdata, wb_rf_wdata;
    assign {mem_rf_we, mem_rf_waddr, mem_rf_wdata} = mem2ex_fwd;
    assign {wb_rf_we, wb_rf_waddr, wb_rf_wdata} = wb2ex_fwd;
    assign src1 = mem_rf_we & (mem_rf_waddr==rs1) & (|rs1) ? mem_rf_wdata
                : wb_rf_we & (wb_rf_waddr==rs1) & (|rs1) ? wb_rf_wdata 
                : rdata1;
    assign src2 = mem_rf_we & (mem_rf_waddr==rs2) & (|rs2) ? mem_rf_wdata
                : wb_rf_we & (wb_rf_waddr==rs2) & (|rs2) ? wb_rf_wdata
                : rdata2;

    assign alu_src1 = sel_src1[0] ? pc
                    : sel_src1[1] ? 64'b0
                    : src1;
    assign alu_src2 = sel_src2 ? imm 
                    : src2;

    wire [63:0] alu_result;
    alu u_alu(
    	.alu_op     (alu_op     ),
        .alu_src1   (alu_src1   ),
        .alu_src2   (alu_src2   ),
        .alu_result (alu_result )
    );
    
    wire br_e;
    wire [63:0] br_addr;
    wire [63:0] br_result;
    bru u_bru(
    	.pc        (pc        ),
        .bru_op    (bru_op    ),
        .rdata1    (src1      ),
        .rdata2    (src2      ),
        .imm       (imm       ),
        .br_e      (br_e      ),
        .br_addr   (br_addr   ),
        .br_result (br_result )
    );
    assign br_bus = {br_e&~(csr_cancel|csr_cancel_reg),br_addr};

    wire [7:0] data_ram_sel;
    wire data_sram_en_tmp;
    lsu u_lsu(
    	.lsu_op          (lsu_op          ),
        .rdata1          (src1            ),
        .rdata2          (src2            ),
        .imm             (imm             ),
        .data_sram_en    (data_sram_en_tmp),
        .data_sram_we    (data_sram_we    ),
        .data_sram_addr  (data_sram_addr ),
        .data_sram_wdata (data_sram_wdata ),
        .data_ram_sel    (data_ram_sel    )
    );
    assign data_sram_en = (csr_cancel|csr_cancel_reg) ? 1'b0 : data_sram_en_tmp;

    wire [63:0] m_result;
    wire stallreq_for_m;
    m_top u_m_top(
    	.clk      (clk              ),
        .rst_n    (rst_n            ),
        .stall    (stall            ),
        .stallreq (stallreq_for_m   ),
        .mul_op   (mul_op           ),
        .div_op   (div_op           ),
        .a        (src1             ),
        .b        (src2             ),
        .result   (m_result         )
    );
    

    wire [63:0] ex_result;

    assign ex_result    = sel_rf_res[0] ? br_result 
                        : sel_rf_res[3] ? m_result
                        : alu_result;
    
    assign csr_wdata = csr_wdata_sel ? imm : src1;
    assign csr_bus = {csr_op, csr_addr, csr_wdata};

    assign ex2mem_bus = {
        csr_vec,
        csr_bus,
        lsu_op,
        data_ram_sel,
        sel_rf_res[2:0],
        rf_we,
        rf_waddr,
        ex_result,
        pc,
        inst
    };

    assign stallreq_ex = stallreq_for_m;
endmodule
