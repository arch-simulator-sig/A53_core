`include "defines.v"
module MEM 
#(
    parameter EX2MEM_WD = 50,
    parameter MEM2WB_WD = 50,
    parameter MEM2EX_WD = 50
)(
    input wire clk,
    input wire rst_n,
    input wire flush,
    input wire [5:0] stall,
    output wire except_en,
    output wire [63:0] new_pc,

    input wire [EX2MEM_WD-1:0] ex2mem_bus,
    output wire [MEM2WB_WD-1:0] mem2wb_bus,
    output wire [MEM2EX_WD-1:0] mem2ex_fwd,


    input wire [63:0] data_sram_rdata
);
    
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
    reg [EX2MEM_WD-1:0] ex2mem_bus_r;
    always @ (posedge clk) begin
        if (!rst_n) begin
            ex2mem_bus_r <= 0;
        end
        else if (flush) begin
            ex2mem_bus_r <= 0;
        end
        else if (stall[3]&(!stall[4])) begin
            ex2mem_bus_r <= 0;
        end
        else if (!stall[3]) begin
            ex2mem_bus_r <= ex2mem_bus;
        end
    end

    wire [6:0] lsu_op;
    wire data_ram_en;
    wire data_ram_we;
    wire [3:0] data_size_sel;
    wire data_unsigned;
    wire [7:0] data_ram_sel;
    wire [2:0] sel_rf_res;
    wire rf_we;
    wire [4:0] rf_waddr;
    wire [63:0] ex_result;
    wire [63:0] pc;
    wire [31:0] inst;
    wire [79:0] csr_bus;
    wire [63:0] csr_vec;
    wire [3:0] csr_op;
    wire [11:0] csr_addr;
    wire [63:0] csr_wdata;
    wire [63:0] csr_rdata;
    wire [63:0] csr_result;


    reg [63:0] data_sram_rdata_r;
    reg [63:0] csr_rdata_r;
    reg stall_flag;
    always @ (posedge clk) begin
        if (!rst_n) begin
            data_sram_rdata_r <= 0;
            csr_rdata_r <= 0;
            stall_flag <= 1'b0;
        end
        else if (flush) begin
            data_sram_rdata_r <= 0;
            csr_rdata_r <= 0;
            stall_flag <= 1'b0;
        end
        else if (!stall[3]) begin
            data_sram_rdata_r <= data_sram_rdata;
            csr_rdata_r <= csr_rdata;
            stall_flag <= 1'b0;
        end
        else if (stall_flag) begin
            
        end
        else if (stall[3]&stall[4])begin
            data_sram_rdata_r <= data_sram_rdata;
            csr_rdata_r <= csr_rdata;
            stall_flag <= 1'b1;
        end
    end
    wire [63:0] data_tmp;
    assign data_tmp = stall_flag ? data_sram_rdata_r : data_sram_rdata;
    assign csr_result = stall_flag ? csr_rdata_r : csr_rdata;

    assign {
        csr_vec,
        csr_bus,
        lsu_op,
        data_ram_sel,
        sel_rf_res,
        rf_we,
        rf_waddr,
        ex_result,
        pc,
        inst
    } = ex2mem_bus_r;

    assign {
        data_ram_en, data_ram_we, data_size_sel, data_unsigned
    } = lsu_op;

    wire [63:0] mem_result;
    wire [63:0] rf_wdata;

    wire [7:0] b_data;
    wire [15:0] h_data;
    wire [31:0] w_data;
    wire [63:0] d_data;

    assign b_data = data_ram_sel[7] ? data_tmp[63:56] :
                    data_ram_sel[6] ? data_tmp[55:48] :
                    data_ram_sel[5] ? data_tmp[47:40] :
                    data_ram_sel[4] ? data_tmp[39:32] :
                    data_ram_sel[3] ? data_tmp[31:24] :
                    data_ram_sel[2] ? data_tmp[23:16] :
                    data_ram_sel[1] ? data_tmp[15: 8] :
                    data_ram_sel[0] ? data_tmp[ 7: 0] : 8'b0;
    assign h_data = data_ram_sel[6] ? data_tmp[63:48] :
                    data_ram_sel[4] ? data_tmp[47:32] :
                    data_ram_sel[2] ? data_tmp[31:16] :
                    data_ram_sel[0] ? data_tmp[15: 0] : 16'b0;
    assign w_data = data_ram_sel[4] ? data_tmp[63:32] : 
                    data_ram_sel[0] ? data_tmp[31: 0] : 32'b0;
    assign d_data = data_tmp;

    assign mem_result = data_size_sel[0] & data_unsigned ? {56'b0,b_data} :
                        data_size_sel[0] ? {{56{b_data[7]}},b_data} :
                        data_size_sel[1] & data_unsigned ? {48'b0,h_data} :
                        data_size_sel[1] ? {{48{h_data[15]}},h_data} :
                        data_size_sel[2] & data_unsigned ? {32'b0,w_data} :
                        data_size_sel[2] ? {{32{w_data[31]}},w_data} :
                        data_size_sel[3] ? d_data : 64'b0;


    assign {csr_op, csr_addr, csr_wdata} = csr_bus;

    csr u_csr(
    	.clk       (clk       ),
        .rst_n     (rst_n     ),
        .stall     (stall[3]&stall[4]),
        .pc        (pc        ),
        .csr_vec   (csr_vec   ),
        .csr_op    (csr_op    ),
        .csr_addr  (csr_addr  ),
        .csr_wdata (csr_wdata ),
        .csr_rdata (csr_rdata ),
        .satp      (satp      ),
        .mstatus   (mstatus   ),
        .mie       (mie       ),
        .mtvec     (mtvec     ),
        .mtimecmp  (mtimecmp  ),
        .mtime     (mtime     ),
        .mscratch  (mscratch  ),
        .mepc      (mepc      ),
        .mcause    (mcause    ),
        .mip       (mip       ),
        .except_en (except_en ),
        .new_pc    (new_pc    )
    );    
    
    assign rf_wdata = sel_rf_res[1] ? mem_result 
                    : sel_rf_res[2] ? csr_result : ex_result;

    assign mem2wb_bus = {
        rf_we,
        rf_waddr,
        rf_wdata,
        pc,
        inst
    };

    assign mem2ex_fwd = {
        rf_we,
        rf_waddr,
        ex_result
    };
endmodule
