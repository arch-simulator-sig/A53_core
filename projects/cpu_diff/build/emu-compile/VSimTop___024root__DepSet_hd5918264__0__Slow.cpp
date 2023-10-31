// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VSimTop___024root.h"

VL_ATTR_COLD void VSimTop___024root___eval_static(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VSimTop___024root___eval_initial(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void VSimTop___024root___eval_final(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_final\n"); );
}

VL_ATTR_COLD void VSimTop___024root___eval_triggers__stl(VSimTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__stl(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___eval_stl(VSimTop___024root* vlSelf);

VL_ATTR_COLD void VSimTop___024root___eval_settle(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VSimTop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VSimTop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/fluctlight/project/A53_core/projects/cpu_diff/build/SimTop.v", 6, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VSimTop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__stl(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSimTop___024root___stl_sequent__TOP__0(VSimTop___024root* vlSelf);

VL_ATTR_COLD void VSimTop___024root___eval_stl(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VSimTop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__ico(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__act(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(negedge clock)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__nba(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(negedge clock)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSimTop___024root___ctor_var_reset(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_logCtrl_log_begin = VL_RAND_RESET_Q(64);
    vlSelf->io_logCtrl_log_end = VL_RAND_RESET_Q(64);
    vlSelf->io_logCtrl_log_level = VL_RAND_RESET_Q(64);
    vlSelf->io_perfInfo_clean = VL_RAND_RESET_I(1);
    vlSelf->io_perfInfo_dump = VL_RAND_RESET_I(1);
    vlSelf->io_uart_out_valid = VL_RAND_RESET_I(1);
    vlSelf->io_uart_out_ch = VL_RAND_RESET_I(8);
    vlSelf->io_uart_in_valid = VL_RAND_RESET_I(1);
    vlSelf->io_uart_in_ch = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__inst = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->SimTop__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->SimTop__DOT__inst_sram_en = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__inst_sram_rdata = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__data_sram_addr = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__data_sram_rdata = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->SimTop__DOT__cmt_wen = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__cmt_wdest = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__cmt_wdata = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__cmt_pc = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__cmt_inst = VL_RAND_RESET_I(32);
    vlSelf->SimTop__DOT__cmt_valid = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__trap = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__trap_code = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__cycleCnt = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__instrCnt = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->SimTop__DOT__regs_diff[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->SimTop__DOT__inst_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(600, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall = VL_RAND_RESET_I(6);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_valid = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_nxt = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__sel_rf_res = VL_RAND_RESET_I(2);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__rf_we = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer = VL_RAND_RESET_I(7);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l = VL_RAND_RESET_I(16);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l = VL_RAND_RESET_I(16);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hf639659f__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0 = 0;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    VL_RAND_RESET_W(600, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2 = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_result = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__br_addr = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result = VL_RAND_RESET_I(32);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result = VL_RAND_RESET_I(32);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w = VL_RAND_RESET_I(32);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2 = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2 = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2 = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(600, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r = VL_RAND_RESET_Q(64);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag = VL_RAND_RESET_I(1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data = VL_RAND_RESET_I(8);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data = VL_RAND_RESET_I(16);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data = VL_RAND_RESET_I(32);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(600, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r);
    vlSelf->__Vfunc_ram_read_helper__0__Vfuncout = 0;
    vlSelf->__Vfunc_ram_read_helper__2__Vfuncout = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vtableidx3 = 0;
    vlSelf->__Vtableidx4 = 0;
    vlSelf->__Vtableidx5 = 0;
    vlSelf->__Vtableidx6 = 0;
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
}
