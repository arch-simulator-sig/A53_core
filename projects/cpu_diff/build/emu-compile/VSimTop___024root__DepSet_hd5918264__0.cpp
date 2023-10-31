// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VSimTop___024root.h"

VL_INLINE_OPT void VSimTop___024root___ico_sequent__TOP__0(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall 
        = ((IData)(vlSelf->reset) ? 0U : ((IData)((
                                                   (0x60U 
                                                    == 
                                                    (0x60U 
                                                     & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer))) 
                                                   & ((((0x1fU 
                                                         & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer)) 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                            >> 0xfU))) 
                                                       & (0U 
                                                          != 
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0xfU)))) 
                                                      | (((0x1fU 
                                                           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer)) 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0x14U))) 
                                                         & (0U 
                                                            != 
                                                            (0x1fU 
                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                >> 0x14U)))))))
                                           ? 7U : 0U));
}

void VSimTop___024root___eval_ico(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VSimTop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VSimTop___024root___eval_act(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_act\n"); );
}

VL_INLINE_OPT void VSimTop___024root___nba_sequent__TOP__1(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdly__SimTop__DOT__trap;
    __Vdly__SimTop__DOT__trap = 0;
    QData/*63:0*/ __Vdly__SimTop__DOT__cycleCnt;
    __Vdly__SimTop__DOT__cycleCnt = 0;
    QData/*63:0*/ __Vdly__SimTop__DOT__instrCnt;
    __Vdly__SimTop__DOT__instrCnt = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v0;
    __Vdlyvval__SimTop__DOT__regs_diff__v0 = 0;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__regs_diff__v0;
    __Vdlyvset__SimTop__DOT__regs_diff__v0 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v1;
    __Vdlyvval__SimTop__DOT__regs_diff__v1 = 0;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__regs_diff__v1;
    __Vdlyvset__SimTop__DOT__regs_diff__v1 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v2;
    __Vdlyvval__SimTop__DOT__regs_diff__v2 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v3;
    __Vdlyvval__SimTop__DOT__regs_diff__v3 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v4;
    __Vdlyvval__SimTop__DOT__regs_diff__v4 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v5;
    __Vdlyvval__SimTop__DOT__regs_diff__v5 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v6;
    __Vdlyvval__SimTop__DOT__regs_diff__v6 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v7;
    __Vdlyvval__SimTop__DOT__regs_diff__v7 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v8;
    __Vdlyvval__SimTop__DOT__regs_diff__v8 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v9;
    __Vdlyvval__SimTop__DOT__regs_diff__v9 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v10;
    __Vdlyvval__SimTop__DOT__regs_diff__v10 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v11;
    __Vdlyvval__SimTop__DOT__regs_diff__v11 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v12;
    __Vdlyvval__SimTop__DOT__regs_diff__v12 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v13;
    __Vdlyvval__SimTop__DOT__regs_diff__v13 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v14;
    __Vdlyvval__SimTop__DOT__regs_diff__v14 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v15;
    __Vdlyvval__SimTop__DOT__regs_diff__v15 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v16;
    __Vdlyvval__SimTop__DOT__regs_diff__v16 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v17;
    __Vdlyvval__SimTop__DOT__regs_diff__v17 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v18;
    __Vdlyvval__SimTop__DOT__regs_diff__v18 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v19;
    __Vdlyvval__SimTop__DOT__regs_diff__v19 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v20;
    __Vdlyvval__SimTop__DOT__regs_diff__v20 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v21;
    __Vdlyvval__SimTop__DOT__regs_diff__v21 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v22;
    __Vdlyvval__SimTop__DOT__regs_diff__v22 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v23;
    __Vdlyvval__SimTop__DOT__regs_diff__v23 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v24;
    __Vdlyvval__SimTop__DOT__regs_diff__v24 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v25;
    __Vdlyvval__SimTop__DOT__regs_diff__v25 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v26;
    __Vdlyvval__SimTop__DOT__regs_diff__v26 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v27;
    __Vdlyvval__SimTop__DOT__regs_diff__v27 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v28;
    __Vdlyvval__SimTop__DOT__regs_diff__v28 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v29;
    __Vdlyvval__SimTop__DOT__regs_diff__v29 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v30;
    __Vdlyvval__SimTop__DOT__regs_diff__v30 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v31;
    __Vdlyvval__SimTop__DOT__regs_diff__v31 = 0;
    // Body
    __Vdly__SimTop__DOT__instrCnt = vlSelf->SimTop__DOT__instrCnt;
    __Vdly__SimTop__DOT__cycleCnt = vlSelf->SimTop__DOT__cycleCnt;
    __Vdly__SimTop__DOT__trap = vlSelf->SimTop__DOT__trap;
    __Vdlyvset__SimTop__DOT__regs_diff__v0 = 0U;
    __Vdlyvset__SimTop__DOT__regs_diff__v1 = 0U;
    if (vlSelf->reset) {
        vlSelf->SimTop__DOT__cmt_wen = 0U;
        vlSelf->SimTop__DOT__cmt_wdest = 0U;
        vlSelf->SimTop__DOT__cmt_wdata = 0ULL;
        vlSelf->SimTop__DOT__cmt_pc = 0ULL;
        vlSelf->SimTop__DOT__cmt_inst = 0U;
        vlSelf->SimTop__DOT__cmt_valid = 0U;
        __Vdly__SimTop__DOT__trap = 0U;
        vlSelf->SimTop__DOT__trap_code = 0U;
        __Vdly__SimTop__DOT__cycleCnt = 0ULL;
        __Vdly__SimTop__DOT__instrCnt = 0ULL;
    } else if ((1U & (~ (IData)(vlSelf->SimTop__DOT__trap)))) {
        __Vdly__SimTop__DOT__cycleCnt = (1ULL + vlSelf->SimTop__DOT__cycleCnt);
        __Vdly__SimTop__DOT__instrCnt = (vlSelf->SimTop__DOT__instrCnt 
                                         + (QData)((IData)(vlSelf->SimTop__DOT__inst_valid)));
        vlSelf->SimTop__DOT__cmt_wen = (1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                              >> 5U));
        vlSelf->SimTop__DOT__cmt_wdest = (0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U]);
        vlSelf->SimTop__DOT__cmt_wdata = (((QData)((IData)(
                                                           vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])));
        vlSelf->SimTop__DOT__cmt_pc = (((QData)((IData)(
                                                        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[1U])));
        vlSelf->SimTop__DOT__cmt_inst = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0U];
        vlSelf->SimTop__DOT__cmt_valid = vlSelf->SimTop__DOT__inst_valid;
        __Vdlyvval__SimTop__DOT__regs_diff__v0 = vlSelf->SimTop__DOT__regs
            [0U];
        __Vdlyvset__SimTop__DOT__regs_diff__v0 = 1U;
        __Vdly__SimTop__DOT__trap = (0x6bU == (0x7fU 
                                               & vlSelf->SimTop__DOT__inst));
        vlSelf->SimTop__DOT__trap_code = (0xffU & (IData)(
                                                          vlSelf->SimTop__DOT__regs
                                                          [0xaU]));
        __Vdlyvval__SimTop__DOT__regs_diff__v1 = vlSelf->SimTop__DOT__regs
            [1U];
        __Vdlyvset__SimTop__DOT__regs_diff__v1 = 1U;
        __Vdlyvval__SimTop__DOT__regs_diff__v2 = vlSelf->SimTop__DOT__regs
            [2U];
        __Vdlyvval__SimTop__DOT__regs_diff__v3 = vlSelf->SimTop__DOT__regs
            [3U];
        __Vdlyvval__SimTop__DOT__regs_diff__v4 = vlSelf->SimTop__DOT__regs
            [4U];
        __Vdlyvval__SimTop__DOT__regs_diff__v5 = vlSelf->SimTop__DOT__regs
            [5U];
        __Vdlyvval__SimTop__DOT__regs_diff__v6 = vlSelf->SimTop__DOT__regs
            [6U];
        __Vdlyvval__SimTop__DOT__regs_diff__v7 = vlSelf->SimTop__DOT__regs
            [7U];
        __Vdlyvval__SimTop__DOT__regs_diff__v8 = vlSelf->SimTop__DOT__regs
            [8U];
        __Vdlyvval__SimTop__DOT__regs_diff__v9 = vlSelf->SimTop__DOT__regs
            [9U];
        __Vdlyvval__SimTop__DOT__regs_diff__v10 = vlSelf->SimTop__DOT__regs
            [0xaU];
        __Vdlyvval__SimTop__DOT__regs_diff__v11 = vlSelf->SimTop__DOT__regs
            [0xbU];
        __Vdlyvval__SimTop__DOT__regs_diff__v12 = vlSelf->SimTop__DOT__regs
            [0xcU];
        __Vdlyvval__SimTop__DOT__regs_diff__v13 = vlSelf->SimTop__DOT__regs
            [0xdU];
        __Vdlyvval__SimTop__DOT__regs_diff__v14 = vlSelf->SimTop__DOT__regs
            [0xeU];
        __Vdlyvval__SimTop__DOT__regs_diff__v15 = vlSelf->SimTop__DOT__regs
            [0xfU];
        __Vdlyvval__SimTop__DOT__regs_diff__v16 = vlSelf->SimTop__DOT__regs
            [0x10U];
        __Vdlyvval__SimTop__DOT__regs_diff__v17 = vlSelf->SimTop__DOT__regs
            [0x11U];
        __Vdlyvval__SimTop__DOT__regs_diff__v18 = vlSelf->SimTop__DOT__regs
            [0x12U];
        __Vdlyvval__SimTop__DOT__regs_diff__v19 = vlSelf->SimTop__DOT__regs
            [0x13U];
        __Vdlyvval__SimTop__DOT__regs_diff__v20 = vlSelf->SimTop__DOT__regs
            [0x14U];
        __Vdlyvval__SimTop__DOT__regs_diff__v21 = vlSelf->SimTop__DOT__regs
            [0x15U];
        __Vdlyvval__SimTop__DOT__regs_diff__v22 = vlSelf->SimTop__DOT__regs
            [0x16U];
        __Vdlyvval__SimTop__DOT__regs_diff__v23 = vlSelf->SimTop__DOT__regs
            [0x17U];
        __Vdlyvval__SimTop__DOT__regs_diff__v24 = vlSelf->SimTop__DOT__regs
            [0x18U];
        __Vdlyvval__SimTop__DOT__regs_diff__v25 = vlSelf->SimTop__DOT__regs
            [0x19U];
        __Vdlyvval__SimTop__DOT__regs_diff__v26 = vlSelf->SimTop__DOT__regs
            [0x1aU];
        __Vdlyvval__SimTop__DOT__regs_diff__v27 = vlSelf->SimTop__DOT__regs
            [0x1bU];
        __Vdlyvval__SimTop__DOT__regs_diff__v28 = vlSelf->SimTop__DOT__regs
            [0x1cU];
        __Vdlyvval__SimTop__DOT__regs_diff__v29 = vlSelf->SimTop__DOT__regs
            [0x1dU];
        __Vdlyvval__SimTop__DOT__regs_diff__v30 = vlSelf->SimTop__DOT__regs
            [0x1eU];
        __Vdlyvval__SimTop__DOT__regs_diff__v31 = vlSelf->SimTop__DOT__regs
            [0x1fU];
    }
    vlSelf->SimTop__DOT__trap = __Vdly__SimTop__DOT__trap;
    vlSelf->SimTop__DOT__cycleCnt = __Vdly__SimTop__DOT__cycleCnt;
    vlSelf->SimTop__DOT__instrCnt = __Vdly__SimTop__DOT__instrCnt;
    if (__Vdlyvset__SimTop__DOT__regs_diff__v0) {
        vlSelf->SimTop__DOT__regs_diff[0U] = __Vdlyvval__SimTop__DOT__regs_diff__v0;
    }
    if (__Vdlyvset__SimTop__DOT__regs_diff__v1) {
        vlSelf->SimTop__DOT__regs_diff[1U] = __Vdlyvval__SimTop__DOT__regs_diff__v1;
        vlSelf->SimTop__DOT__regs_diff[2U] = __Vdlyvval__SimTop__DOT__regs_diff__v2;
        vlSelf->SimTop__DOT__regs_diff[3U] = __Vdlyvval__SimTop__DOT__regs_diff__v3;
        vlSelf->SimTop__DOT__regs_diff[4U] = __Vdlyvval__SimTop__DOT__regs_diff__v4;
        vlSelf->SimTop__DOT__regs_diff[5U] = __Vdlyvval__SimTop__DOT__regs_diff__v5;
        vlSelf->SimTop__DOT__regs_diff[6U] = __Vdlyvval__SimTop__DOT__regs_diff__v6;
        vlSelf->SimTop__DOT__regs_diff[7U] = __Vdlyvval__SimTop__DOT__regs_diff__v7;
        vlSelf->SimTop__DOT__regs_diff[8U] = __Vdlyvval__SimTop__DOT__regs_diff__v8;
        vlSelf->SimTop__DOT__regs_diff[9U] = __Vdlyvval__SimTop__DOT__regs_diff__v9;
        vlSelf->SimTop__DOT__regs_diff[0xaU] = __Vdlyvval__SimTop__DOT__regs_diff__v10;
        vlSelf->SimTop__DOT__regs_diff[0xbU] = __Vdlyvval__SimTop__DOT__regs_diff__v11;
        vlSelf->SimTop__DOT__regs_diff[0xcU] = __Vdlyvval__SimTop__DOT__regs_diff__v12;
        vlSelf->SimTop__DOT__regs_diff[0xdU] = __Vdlyvval__SimTop__DOT__regs_diff__v13;
        vlSelf->SimTop__DOT__regs_diff[0xeU] = __Vdlyvval__SimTop__DOT__regs_diff__v14;
        vlSelf->SimTop__DOT__regs_diff[0xfU] = __Vdlyvval__SimTop__DOT__regs_diff__v15;
        vlSelf->SimTop__DOT__regs_diff[0x10U] = __Vdlyvval__SimTop__DOT__regs_diff__v16;
        vlSelf->SimTop__DOT__regs_diff[0x11U] = __Vdlyvval__SimTop__DOT__regs_diff__v17;
        vlSelf->SimTop__DOT__regs_diff[0x12U] = __Vdlyvval__SimTop__DOT__regs_diff__v18;
        vlSelf->SimTop__DOT__regs_diff[0x13U] = __Vdlyvval__SimTop__DOT__regs_diff__v19;
        vlSelf->SimTop__DOT__regs_diff[0x14U] = __Vdlyvval__SimTop__DOT__regs_diff__v20;
        vlSelf->SimTop__DOT__regs_diff[0x15U] = __Vdlyvval__SimTop__DOT__regs_diff__v21;
        vlSelf->SimTop__DOT__regs_diff[0x16U] = __Vdlyvval__SimTop__DOT__regs_diff__v22;
        vlSelf->SimTop__DOT__regs_diff[0x17U] = __Vdlyvval__SimTop__DOT__regs_diff__v23;
        vlSelf->SimTop__DOT__regs_diff[0x18U] = __Vdlyvval__SimTop__DOT__regs_diff__v24;
        vlSelf->SimTop__DOT__regs_diff[0x19U] = __Vdlyvval__SimTop__DOT__regs_diff__v25;
        vlSelf->SimTop__DOT__regs_diff[0x1aU] = __Vdlyvval__SimTop__DOT__regs_diff__v26;
        vlSelf->SimTop__DOT__regs_diff[0x1bU] = __Vdlyvval__SimTop__DOT__regs_diff__v27;
        vlSelf->SimTop__DOT__regs_diff[0x1cU] = __Vdlyvval__SimTop__DOT__regs_diff__v28;
        vlSelf->SimTop__DOT__regs_diff[0x1dU] = __Vdlyvval__SimTop__DOT__regs_diff__v29;
        vlSelf->SimTop__DOT__regs_diff[0x1eU] = __Vdlyvval__SimTop__DOT__regs_diff__v30;
        vlSelf->SimTop__DOT__regs_diff[0x1fU] = __Vdlyvval__SimTop__DOT__regs_diff__v31;
    }
}

void VSimTop___024root___nba_sequent__TOP__0(VSimTop___024root* vlSelf);

void VSimTop___024root___eval_nba(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VSimTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VSimTop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void VSimTop___024root___eval_triggers__ico(VSimTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__ico(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG
void VSimTop___024root___eval_triggers__act(VSimTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__act(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__nba(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG

void VSimTop___024root___eval(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VSimTop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VSimTop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/fluctlight/project/oscpu/projects/cpu_diff/build/SimTop.v", 6, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VSimTop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VSimTop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VSimTop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/fluctlight/project/oscpu/projects/cpu_diff/build/SimTop.v", 6, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VSimTop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VSimTop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/fluctlight/project/oscpu/projects/cpu_diff/build/SimTop.v", 6, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VSimTop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VSimTop___024root___eval_debug_assertions(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_perfInfo_clean & 0xfeU))) {
        Verilated::overWidthError("io_perfInfo_clean");}
    if (VL_UNLIKELY((vlSelf->io_perfInfo_dump & 0xfeU))) {
        Verilated::overWidthError("io_perfInfo_dump");}
}
#endif  // VL_DEBUG
