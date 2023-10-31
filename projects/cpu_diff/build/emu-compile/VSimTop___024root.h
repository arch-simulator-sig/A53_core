// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSimTop.h for the primary calling header

#ifndef VERILATED_VSIMTOP___024ROOT_H_
#define VERILATED_VSIMTOP___024ROOT_H_  // guard

#include "verilated.h"

class VSimTop__Syms;
class VSimTop___024unit;


class VSimTop___024root final : public VerilatedModule {
  public:
    // CELLS
    VSimTop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_perfInfo_clean,0,0);
        VL_IN8(io_perfInfo_dump,0,0);
        VL_OUT8(io_uart_out_valid,0,0);
        VL_OUT8(io_uart_out_ch,7,0);
        VL_OUT8(io_uart_in_valid,0,0);
        VL_IN8(io_uart_in_ch,7,0);
        CData/*0:0*/ SimTop__DOT__inst_sram_en;
        CData/*0:0*/ SimTop__DOT__cmt_wen;
        CData/*7:0*/ SimTop__DOT__cmt_wdest;
        CData/*0:0*/ SimTop__DOT__cmt_valid;
        CData/*0:0*/ SimTop__DOT__trap;
        CData/*7:0*/ SimTop__DOT__trap_code;
        CData/*0:0*/ SimTop__DOT__inst_valid;
        CData/*5:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__stall;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_valid;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r;
        CData/*1:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__sel_rf_res;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__rf_we;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag;
        CData/*6:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer;
        CData/*7:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h;
        CData/*7:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h;
        CData/*7:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu;
    };
    struct {
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hf639659f__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2;
        CData/*7:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel;
        CData/*0:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag;
        CData/*7:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data;
        CData/*3:0*/ __Vtableidx1;
        CData/*2:0*/ __Vtableidx2;
        CData/*2:0*/ __Vtableidx3;
        CData/*3:0*/ __Vtableidx4;
        CData/*2:0*/ __Vtableidx5;
        CData/*2:0*/ __Vtableidx6;
        CData/*0:0*/ __Vtrigrprev__TOP__clock;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l;
        SData/*15:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l;
        SData/*15:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data;
        IData/*31:0*/ SimTop__DOT__inst;
        IData/*31:0*/ SimTop__DOT__cmt_inst;
        VlWide<19>/*599:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus;
        IData/*31:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst;
        VlWide<19>/*599:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r;
        IData/*31:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result;
        IData/*31:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result;
        IData/*31:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w;
        VlWide<19>/*599:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r;
        IData/*31:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data;
        VlWide<19>/*599:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
    };
    struct {
        VL_IN64(io_logCtrl_log_begin,63,0);
        VL_IN64(io_logCtrl_log_end,63,0);
        VL_IN64(io_logCtrl_log_level,63,0);
        QData/*63:0*/ SimTop__DOT__inst_sram_rdata;
        QData/*63:0*/ SimTop__DOT__data_sram_addr;
        QData/*63:0*/ SimTop__DOT__data_sram_rdata;
        QData/*63:0*/ SimTop__DOT__cmt_wdata;
        QData/*63:0*/ SimTop__DOT__cmt_pc;
        QData/*63:0*/ SimTop__DOT__cycleCnt;
        QData/*63:0*/ SimTop__DOT__instrCnt;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_nxt;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_result;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__br_addr;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r;
        QData/*63:0*/ SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data;
        QData/*63:0*/ __Vfunc_ram_read_helper__0__Vfuncout;
        QData/*63:0*/ __Vfunc_ram_read_helper__2__Vfuncout;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__regs;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__regs_diff;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSimTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSimTop___024root(VSimTop__Syms* symsp, const char* v__name);
    ~VSimTop___024root();
    VL_UNCOPYABLE(VSimTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
