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
        //nop, id stall and ex not stall
        else if (stall[2]&(!stall[3])) begin
            id2ex_bus_r <= 0;
        end
        //nop, id stall and br_bus[64] ? 
        else if (!stall[2]&br_bus[64]) begin
            id2ex_bus_r <= 0;
        end
        // id not stall so can go on
        else if (!stall[2]) begin
            id2ex_bus_r <= id2ex_bus;
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
    wire [1:0] sel_rf_res;
    wire rf_we;
    wire [4:0] rf_waddr;
    wire [63:0] pc;
    wire [31:0] inst;
    wire [9:0] csr_op;

    assign {
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
        sel_rf_res,     //2
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
    assign br_bus = {br_e,br_addr};

    wire [7:0] data_ram_sel;
    lsu u_lsu(
    	.lsu_op          (lsu_op          ),
        .rdata1          (src1            ),
        .rdata2          (src2            ),
        .imm             (imm             ),
        .data_sram_en    (data_sram_en    ),
        .data_sram_we    (data_sram_we    ),
        .data_sram_addr  (data_sram_addr ),
        .data_sram_wdata (data_sram_wdata ),
        .data_ram_sel    (data_ram_sel    )
    );

    wire [63:0] ex_result;

    assign ex_result    = sel_rf_res[0] ? br_result 
                        : alu_result;
    
    assign ex2mem_bus = {
        lsu_op,
        data_ram_sel,
        sel_rf_res[1],
        rf_we,
        rf_waddr,
        ex_result,
        pc,
        inst
    };

    assign stallreq_ex = 1'b0;
endmodule
