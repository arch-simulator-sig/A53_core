`ifndef __PORTS_SVH__
`define __PORTS_SVH__

`include "defines.svh"

        typedef struct packed {
            xlen_t pc;
            xlen_t nxtPC;
            inst_t inst;
        } DbgInfo_t;

typedef struct packed {
            logic   wrEn;
            logic   rdEn;
            xlen_t  addr;
            width_t width;
            xlen_t  wrDat;
        } MemReq_t;

typedef struct packed {
            logic req;
            logic wrOrRd;
            logic [1:0] size;
            word_t addr;
            byte_t wrStrb;
            xlen_t wrDat;
        } SramReq_t;

typedef struct packed {
            logic  addrOK;
            logic  datOK;
            xlen_t rdDat;
        } SramRsp_t;

typedef struct packed {
            logic  jmp;
            xlen_t addr;
        } IfuJmp_t;

typedef struct packed {
            inst_t inst;
            xlen_t pc;
        } Fetch_t;

typedef struct packed {
`include "decode_generated.svh"
        } DecodeGen_t;

typedef struct packed {
            logic rs1En;
            gprIdx_t rs1Idx;
            logic rs2En;
            gprIdx_t rs2Idx;
            logic gprWrEn;
            logic immAsSrc2;
            xlen_t imm;
            gprIdx_t gprWrIdx;
            logic csrRdEn;
            logic csrWrEn;
            csrIdx_t csrIdx;
`include "decode_generated.svh"
        } Decode_t;

typedef struct packed {
            logic gprWrEn;
            gprIdx_t gprWrIdx;
            xlen_t gprWrDat;
            logic csrWrEn;
            csrIdx_t csrWrIdx;
            xlen_t csrWrDat;
        } ExWb_t;

typedef struct packed {
            struct packed {
                logic instAccessFault;
                logic breakpoint;
                logic ecall;
                logic illegalInst;
                logic ldAddrMisali;
                logic ldAccessFault;
                logic StAddrMisali;
                logic StAccessFault;
            } e;
            struct packed {
                logic intr;
            } i;
            struct packed {
                logic mret;
                logic sret;
            } ret;
            tval_t val;
        } Excpt_t;

typedef struct packed {
            priv_t priv;
            tvec_t mtvec;
            epc_t mepc;
        } CsrOut_t;

typedef struct packed {
            logic excpt;
            epc_t epc;
            cause_t cause;
            tval_t val;

            logic mret;
            logic sret;
        } ExcptInfo_t;

`endif
