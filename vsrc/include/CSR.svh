`ifndef __CSR_SVH__
`define __CSR_SVH__

`include "defines.svh"

`define CSR_INTL_IDX_LEN 4
typedef logic [`w(`CSR_INTL_IDX_LEN)] csrIdx_t;
localparam CSR_CNT = 1 << `CSR_INTL_IDX_LEN;

typedef enum uint2_t {
            M_MODE = 2'b11,
            S_MODE = 2'b01,
            U_MODE = 2'b00
} priv_t;

typedef enum uint12_t {
            CSR_MEPC = 'h341,
            CSR_MTVEC = 'h305,
            CSR_MSTATUS = 'h300,
            CSR_MCAUSE = 'h342,
            CSR_MTVAL = 'h343
} csrAddr_t;

typedef struct packed {
            logic [`w(`MXLEN)] epc;
        } epc_t;

typedef struct packed {
            logic [`w(`MXLEN-2)] base;
            logic [`w(2)] mode;
        } tvec_t;

typedef struct packed {
            logic SD;
            logic [`w(`MXLEN - 37)] WRPI1;
            uint2_t SXL;
            uint2_t UXL;
            uint9_t WPRI2;
            logic TSR;
            logic TW;
            logic TVM;
            logic MXR;
            logic SUM;
            logic MPRV;
            uint2_t XS;
            uint2_t FS;
            priv_t MPP;
            uint2_t WPRI3;
            logic SPP;
            logic MPIE;
            logic WRPI4;
            logic SPIE;
            logic UPIE;
            logic MIE;
            logic WPRI5;
            logic SIE;
            logic UIE;
        } mstatus_t;

typedef enum logic [`w(`MXLEN - 1)] {
            INST_ADDR_MISALIGNED = 'd0,
            INST_ACCESS_FAULT = 'd1,
            ILLEGAL_INST = 'd2,
            BREAKPOINT = 'd3,
            LOAD_ADDR_MISALIFNED = 'd4,
            LOAD_ACCESS_FAULT = 'd5,
            STORE_ADDR_MISALIGNED = 'd6,
            STORE_ACCESS_FAULT = 'd7,
            ECALL_U = 'd8,
            ECALL_S = 'd9,
            ECALL_M = 'd11,
            INST_PAGE_FAULT = 'd12,
            LOAD_PAGE_FAULT = 'd13,
            STORE_PAGE_FAULT = 'd15
} excptCause_t;

typedef struct packed {
            logic intr;
            logic [`w(`MXLEN - 1)] code;
        } cause_t;

typedef struct packed {
            mxlen_t val;
            priv_t priv;
        } tval_t;

typedef union packed {
            mxlen_t [`w(CSR_CNT)] data;
            struct packed {
                tval_t mtval;
                cause_t mcause;
                mstatus_t mstatus;
                tvec_t mtvec;
                epc_t mepc;
            } r;
        } CSR_t;

`endif
