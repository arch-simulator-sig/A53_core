`include "defines.v"
/* 
    except_type_vec 

                    2   ecall
                    1   ebreak
                    0   mret
*/
`define SATP_ADDR       12'h180
`define MVENDORID_ADDR  12'hF11
`define MARCHID_ADDR    12'hF12
`define MIMPID_ADDR     12'hF13
`define MHARTID_ADDR    12'hF14
`define MSTATUS_ADDR    12'h300
`define MISA_ADDR       12'h301
`define MIE_ADDR        12'h304
`define MTVEC_ADDR      12'h305
`define MSCRATCH_ADDR   12'h340
`define MEPC_ADDR       12'h341
`define MCAUSE_ADDR     12'h342
`define MTVAL_ADDR      12'h343
`define MIP_ADDR        12'h344
`define MCYCLE_ADDR     12'hB00
`define MINSTRET_ADDR   12'hB02
`define MCYCLEH_ADDR    12'hB80
`define MINSTRETH_ADDR  12'hB82

module csr(
    input wire clk,
    input wire rst_n,
    input wire stall,

    input wire [63:0] pc,

    input wire [63:0] csr_vec,
    input wire [3:0] csr_op,
    input wire [11:0] csr_addr,
    input wire [63:0] csr_wdata,
    output wire [63:0] csr_rdata,

    // 管理员保护与翻译
    output reg [63:0] satp,
    // 机器信息寄存器
    // reg [63:0] mcpuid,
    // reg [63:0] mimpid,
    // reg [63:0] mhartid,
    // 机器自陷
    output reg [63:0] mstatus,
    output reg [63:0] mie,
    output reg [63:0] mtvec,
    // reg [63:0] mtdeleg,
    output reg [63:0] mtimecmp,
    // 机器定时器和计时器
    output reg [63:0] mtime,
    // reg [63:0] mtimeh,
    // 机器自陷处理
    output reg [63:0] mscratch,
    output reg [63:0] mepc,
    output reg [63:0] mcause,
    output reg [63:0] mip,

    output wire except_en,
    output wire [63:0] new_pc
);
    
    reg [63:0] csr_rdata_reg;
    assign csr_rdata = csr_rdata_reg;
    always @ (*) begin
        if (|csr_op) begin
            case (csr_addr)
                `SATP_ADDR      : csr_rdata_reg = satp     ;
                `MSTATUS_ADDR   : csr_rdata_reg = mstatus  ;
                `MIE_ADDR       : csr_rdata_reg = mie      ;
                `MTVEC_ADDR     : csr_rdata_reg = mtvec    ;
                // `MTIMECMP_ADDR  : csr_rdata_reg = mtimecmp ;
                // `MTIME_ADDR     : csr_rdata_reg = mtime    ;
                `MSCRATCH_ADDR  : csr_rdata_reg = mscratch ;
                `MEPC_ADDR      : csr_rdata_reg = mepc     ;
                `MCAUSE_ADDR    : csr_rdata_reg = mcause   ;
                `MIP_ADDR       : csr_rdata_reg = mip      ;
                default         : csr_rdata_reg = 64'b0    ;
            endcase
        end
        else begin
            csr_rdata_reg = 64'b0;
        end
    end 

    wire op_csrrw, op_csrrs, op_csrrc;
    wire csr_we;
    wire [63:0] csr_wdata_tmp;
    wire [63:0] rs_wdata;
    wire [63:0] rc_wdata;
    assign {csr_we, op_csrrw, op_csrrs, op_csrrc} = csr_op;
    assign rs_wdata = csr_rdata_reg | csr_wdata;
    assign rc_wdata = csr_rdata_reg & ~csr_wdata;
    assign csr_wdata_tmp =  op_csrrs ? rs_wdata :
                            op_csrrc ? rc_wdata : 
                            /*csrrw*/  csr_wdata;

    always @ (posedge clk) begin
        if (!rst_n) begin
            satp <= 0;
            mstatus <= 64'ha00001800;
            mie <= 0;
            mtvec <= 0;
            mtimecmp <= 0;
            mtime <= 0;
            mscratch <= 0;
            mepc <= 0;
            mcause <= 0;
            mip <= 0;
        end
        else if (stall) begin
            
        end
        else if (except_en) begin
            if (csr_vec[0]) begin
                mstatus[3] <= mstatus[7];
                mstatus[7] <= 1;
            end
            else if (csr_vec[2]) begin
                mcause <= 64'hb;
                mepc <= pc;
                mstatus[7] <= mstatus[3];
                mstatus[3] <= 0;
            end
            else if (csr_vec[32]) begin
                mcause <= {1'b1, 63'h7};
                mepc <= pc;
                mstatus[7] <= mstatus[3];
                mstatus[3] <= 0;
            end
            else begin
                
            end
        end
        else if (csr_we) begin
            case (csr_addr)
                `SATP_ADDR      : satp      <= csr_wdata_tmp ;
                `MSTATUS_ADDR   : mstatus   <= csr_wdata_tmp ;
                `MIE_ADDR       : mie       <= csr_wdata_tmp ;
                `MTVEC_ADDR     : mtvec     <= csr_wdata_tmp ;
                // `MTIMECMP_ADDR  : mtimecmp  <= csr_wdata_tmp ;
                // `MTIME_ADDR     : mtime     <= csr_wdata_tmp ;
                `MSCRATCH_ADDR  : mscratch  <= csr_wdata_tmp ;
                `MEPC_ADDR      : mepc      <= csr_wdata_tmp ;
                `MCAUSE_ADDR    : mcause    <= csr_wdata_tmp ;
                `MIP_ADDR       : mip       <= csr_wdata_tmp ;
                default:;
            endcase
        end
    end

    assign except_en = (mie[7] & mstatus[3] & |csr_vec[63:32]) | (|csr_vec[31:0]);
    assign new_pc = csr_vec[0] ? mepc : mtvec;
endmodule