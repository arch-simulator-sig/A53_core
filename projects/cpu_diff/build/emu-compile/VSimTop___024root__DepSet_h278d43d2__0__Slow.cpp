// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VSimTop__Syms.h"
#include "VSimTop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__stl(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VSimTop___024root___eval_triggers__stl(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSimTop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*7:0*/, 8> VSimTop__ConstPool__TABLE_h4b04e8c6_0;
void VSimTop___024unit____Vdpiimwrap_ram_read_helper_TOP____024unit(CData/*0:0*/ en, QData/*63:0*/ rIdx, QData/*63:0*/ &ram_read_helper__Vfuncrtn);
extern const VlUnpacked<SData/*15:0*/, 16> VSimTop__ConstPool__TABLE_h7a2fd741_0;

VL_ATTR_COLD void VSimTop___024root___stl_sequent__TOP__0(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___stl_sequent__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h9befc343__0;
    VlWide<3>/*95:0*/ __Vtemp_ha4db1ee1__0;
    VlWide<3>/*95:0*/ __Vtemp_hae3cbe47__0;
    VlWide<3>/*95:0*/ __Vtemp_h54852520__0;
    VlWide<3>/*95:0*/ __Vtemp_h93336fe5__0;
    VlWide<5>/*159:0*/ __Vtemp_h4d85910c__0;
    // Body
    vlSelf->SimTop__DOT__inst_valid = ((0x80000000ULL 
                                        != (((QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[2U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[1U])))) 
                                       | (0U != vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0U]));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin 
        = ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
            >> 0x1fU) | (0U != (3U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2 
        = (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] 
             >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U]) 
                        == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                     >> 6U))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                                     >> 6U)))))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))
            : (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                 >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U]) 
                            == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                         >> 6U))) & 
                           (0U != (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                            >> 6U)))))
                ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                    << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                : (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U])) 
                    << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[7U])) 
                                  << 0x1aU) | ((QData)((IData)(
                                                               vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                                               >> 6U)))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 
        = (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] 
             >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U]) 
                        == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                     >> 0xbU))) & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                                       >> 0xbU)))))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))
            : (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                 >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U]) 
                            == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                         >> 0xbU))) 
                           & (0U != (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                              >> 0xbU)))))
                ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                    << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                : (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])) 
                    << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[9U])) 
                                  << 0x1aU) | ((QData)((IData)(
                                                               vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U])) 
                                               >> 6U)))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
        [0U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[1U] 
        = ((IData)((0x21U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [1U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[2U] 
        = ((IData)((0x22U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [2U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[3U] 
        = ((IData)((0x23U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [3U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[4U] 
        = ((IData)((0x24U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [4U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[5U] 
        = ((IData)((0x25U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [5U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[6U] 
        = ((IData)((0x26U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [6U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[7U] 
        = ((IData)((0x27U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [7U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[8U] 
        = ((IData)((0x28U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [8U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[9U] 
        = ((IData)((0x29U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [9U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xaU] 
        = ((IData)((0x2aU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xaU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xbU] 
        = ((IData)((0x2bU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xbU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xcU] 
        = ((IData)((0x2cU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xcU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xdU] 
        = ((IData)((0x2dU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xdU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xeU] 
        = ((IData)((0x2eU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xeU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xfU] 
        = ((IData)((0x2fU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xfU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x10U] 
        = ((IData)((0x30U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x10U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x11U] 
        = ((IData)((0x31U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x11U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x12U] 
        = ((IData)((0x32U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x12U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x13U] 
        = ((IData)((0x33U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x13U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x14U] 
        = ((IData)((0x34U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x14U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x15U] 
        = ((IData)((0x35U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x15U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x16U] 
        = ((IData)((0x36U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x16U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x17U] 
        = ((IData)((0x37U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x17U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x18U] 
        = ((IData)((0x38U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x18U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x19U] 
        = ((IData)((0x39U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x19U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1aU] 
        = ((IData)((0x3aU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1aU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1bU] 
        = ((IData)((0x3bU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1bU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1cU] 
        = ((IData)((0x3cU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1cU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1dU] 
        = ((IData)((0x3dU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1dU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1eU] 
        = ((IData)((0x3eU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1eU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1fU] 
        = ((IData)((0x3fU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1fU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 
        = ((0x10000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U])) 
                              << 0x1aU) | ((QData)((IData)(
                                                           vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])) 
                                           >> 6U)))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2);
    vlSelf->SimTop__DOT__data_sram_addr = ((((QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                                             << 0x3aU) 
                                            | (((QData)((IData)(
                                                                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U])) 
                                                << 0x1aU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])) 
                                                  >> 6U))) 
                                           + vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
        = ((0x20000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U])))
            : ((0x40000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])
                ? 0ULL : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2 
        = (0U != (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 
                  ^ vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2 
        = VL_LTS_IQQ(64, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2 
        = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 
           < vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[1U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [1U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[2U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [2U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[3U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [3U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[4U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [4U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[5U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [5U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[6U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [6U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[7U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [7U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[8U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [8U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[9U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [9U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xaU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xaU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xbU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xbU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xcU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xcU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xdU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xdU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xeU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xeU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xfU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xfU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x10U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x10U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x11U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x11U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x12U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x12U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x13U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x13U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x14U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x14U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x15U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x15U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x16U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x16U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x17U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x17U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x18U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x18U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x19U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x19U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1aU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1aU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1bU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1bU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1cU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1cU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1dU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1dU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1eU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1eU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1fU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1fU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin)
            ? (~ vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2);
    vlSelf->__Vtableidx6 = (7U & (IData)(vlSelf->SimTop__DOT__data_sram_addr));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx6];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__br_addr 
        = ((IData)((0U != (0x5f8000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])))
            ? ((((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                 << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U])) 
                               << 0x1aU) | ((QData)((IData)(
                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])) 
                                            >> 6U))) 
               + (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U])) 
                   << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U]))))
            : ((0x200000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                ? (0xfffffffeULL & vlSelf->SimTop__DOT__data_sram_addr)
                : 0ULL));
    VSimTop___024unit____Vdpiimwrap_ram_read_helper_TOP____024unit(
                                                                   (1U 
                                                                    & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                       >> 0xeU)), 
                                                                   ((vlSelf->SimTop__DOT__data_sram_addr 
                                                                     - 0x80000000ULL) 
                                                                    >> 3U), vlSelf->__Vfunc_ram_read_helper__2__Vfuncout);
    vlSelf->SimTop__DOT__data_sram_rdata = vlSelf->__Vfunc_ram_read_helper__2__Vfuncout;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1) 
           >> (0x1fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result 
        = VL_SHIFTRS_III(32,32,5, (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1), 
                         (0x1fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1) 
           + (((0x4000000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                ? (~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2))
                : (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
              + (1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                       >> 0x1aU))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e 
        = (1U & (((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2)) 
                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                     >> 0x14U)) | (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                     >> 0x13U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2)) 
                                   | (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                        >> 0x12U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2)) 
                                      | (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                           >> 0x10U) 
                                          & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2)) 
                                         | (((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2)) 
                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                >> 0x11U)) 
                                            | (((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2)) 
                                                & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                   >> 0xfU)) 
                                               | (IData)(
                                                         (0U 
                                                          != 
                                                          (0x600000U 
                                                           & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U]))))))))));
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[1U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [1U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[2U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [2U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[3U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [3U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[4U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [4U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[5U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [5U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[6U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [6U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[7U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [7U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[8U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [8U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[9U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [9U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xaU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xaU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xbU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xbU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xcU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xcU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xdU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xdU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xeU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xeU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xfU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xfU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x10U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x10U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x11U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x11U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x12U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x12U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x13U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x13U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x14U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x14U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x15U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x15U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x16U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x16U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x17U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x17U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x18U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x18U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x19U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x19U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1aU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1aU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1bU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1bU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1cU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1cU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1dU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1dU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1eU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1eU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1fU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1fU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result 
        = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
           + (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b 
              + (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag)
            ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r
            : vlSelf->SimTop__DOT__data_sram_rdata);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_nxt 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e)
            ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__br_addr
            : (4ULL + vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc));
    vlSelf->SimTop__DOT__inst_sram_en = ((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e)) 
                                         & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_valid));
    vlSelf->SimTop__DOT__regs[0U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0U];
    vlSelf->SimTop__DOT__regs[1U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [1U];
    vlSelf->SimTop__DOT__regs[2U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [2U];
    vlSelf->SimTop__DOT__regs[3U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [3U];
    vlSelf->SimTop__DOT__regs[4U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [4U];
    vlSelf->SimTop__DOT__regs[5U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [5U];
    vlSelf->SimTop__DOT__regs[6U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [6U];
    vlSelf->SimTop__DOT__regs[7U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [7U];
    vlSelf->SimTop__DOT__regs[8U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [8U];
    vlSelf->SimTop__DOT__regs[9U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [9U];
    vlSelf->SimTop__DOT__regs[0xaU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xaU];
    vlSelf->SimTop__DOT__regs[0xbU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xbU];
    vlSelf->SimTop__DOT__regs[0xcU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xcU];
    vlSelf->SimTop__DOT__regs[0xdU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xdU];
    vlSelf->SimTop__DOT__regs[0xeU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xeU];
    vlSelf->SimTop__DOT__regs[0xfU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xfU];
    vlSelf->SimTop__DOT__regs[0x10U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x10U];
    vlSelf->SimTop__DOT__regs[0x11U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x11U];
    vlSelf->SimTop__DOT__regs[0x12U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x12U];
    vlSelf->SimTop__DOT__regs[0x13U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x13U];
    vlSelf->SimTop__DOT__regs[0x14U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x14U];
    vlSelf->SimTop__DOT__regs[0x15U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x15U];
    vlSelf->SimTop__DOT__regs[0x16U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x16U];
    vlSelf->SimTop__DOT__regs[0x17U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x17U];
    vlSelf->SimTop__DOT__regs[0x18U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x18U];
    vlSelf->SimTop__DOT__regs[0x19U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x19U];
    vlSelf->SimTop__DOT__regs[0x1aU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1aU];
    vlSelf->SimTop__DOT__regs[0x1bU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1bU];
    vlSelf->SimTop__DOT__regs[0x1cU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1cU];
    vlSelf->SimTop__DOT__regs[0x1dU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1dU];
    vlSelf->SimTop__DOT__regs[0x1eU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1eU];
    vlSelf->SimTop__DOT__regs[0x1fU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1fU];
    __Vtemp_h9befc343__0[0U] = (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1);
    __Vtemp_h9befc343__0[1U] = (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                        >> 0x20U));
    __Vtemp_h9befc343__0[2U] = 0U;
    __Vtemp_ha4db1ee1__0[0U] = (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b);
    __Vtemp_ha4db1ee1__0[1U] = (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b 
                                        >> 0x20U));
    __Vtemp_ha4db1ee1__0[2U] = 0U;
    __Vtemp_hae3cbe47__0[0U] = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin;
    __Vtemp_hae3cbe47__0[1U] = 0U;
    __Vtemp_hae3cbe47__0[2U] = 0U;
    VL_ADD_W(3, __Vtemp_h54852520__0, __Vtemp_ha4db1ee1__0, __Vtemp_hae3cbe47__0);
    VL_ADD_W(3, __Vtemp_h93336fe5__0, __Vtemp_h9befc343__0, __Vtemp_h54852520__0);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_result 
        = (((- (QData)((IData)((1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                                      >> 5U))))) & 
            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
             & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
           | (((- (QData)((IData)((1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                                         >> 4U))))) 
               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                  | vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
              | (((- (QData)((IData)((1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                                            >> 3U))))) 
                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                     ^ vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
                 | (((- (QData)((IData)((0U != (6U 
                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U]))))) 
                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result) 
                    | (((- (QData)((IData)((1U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])))) 
                        & (QData)((IData)((1U & (((~ (IData)(
                                                             (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 
                                                              >> 0x3fU))) 
                                                  & (IData)(
                                                            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                                             >> 0x3fU))) 
                                                 | ((~ 
                                                     ((IData)(
                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                                               >> 0x3fU)) 
                                                      ^ (IData)(
                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 
                                                                 >> 0x3fU)))) 
                                                    & (IData)(
                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result 
                                                               >> 0x3fU)))))))) 
                       | (((- (QData)((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                               >> 0x1fU)))) 
                           & (QData)((IData)((1U & 
                                              (~ (1U 
                                                  & __Vtemp_h93336fe5__0[2U])))))) 
                          | (((- (QData)((IData)((1U 
                                                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                     >> 0x1eU))))) 
                              & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                 << (0x3fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)))) 
                             | (((- (QData)((IData)(
                                                    (1U 
                                                     & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                        >> 0x1dU))))) 
                                 & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                    >> (0x3fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)))) 
                                | (((- (QData)((IData)(
                                                       (1U 
                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                           >> 0x1cU))))) 
                                    & VL_SHIFTRS_QQI(64,64,6, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1, 
                                                     (0x3fU 
                                                      & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)))) 
                                   | (((- (QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (0xc000000U 
                                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U]))))) 
                                       & (((QData)((IData)(
                                                           (- (IData)(
                                                                      (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w 
                                                                       >> 0x1fU))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w)))) 
                                      | (((- (QData)((IData)(
                                                             (1U 
                                                              & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                 >> 0x19U))))) 
                                          & (((QData)((IData)(
                                                              (- (IData)(
                                                                         (1U 
                                                                          & (IData)(
                                                                                ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                                                                << 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2))) 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1) 
                                                                << 
                                                                (0x1fU 
                                                                 & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2))))))) 
                                         | (((- (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                    >> 0x18U))))) 
                                             & (((QData)((IData)(
                                                                 (- (IData)(
                                                                            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result 
                                                                             >> 0x1fU))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result)))) 
                                            | ((- (QData)((IData)(
                                                                  (1U 
                                                                   & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                      >> 0x17U))))) 
                                               & (((QData)((IData)(
                                                                   (- (IData)(
                                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result 
                                                                               >> 0x1fU))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result))))))))))))))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data 
        = (0xffU & ((0x4000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                     ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                >> 0x38U)) : ((0x2000U 
                                               & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                               ? (IData)(
                                                         (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                          >> 0x30U))
                                               : ((0x1000U 
                                                   & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                   ? (IData)(
                                                             (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                              >> 0x28U))
                                                   : 
                                                  ((0x800U 
                                                    & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                    ? (IData)(
                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                               >> 0x20U))
                                                    : 
                                                   ((0x400U 
                                                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                     ? (IData)(
                                                               (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                                >> 0x18U))
                                                     : 
                                                    ((0x200U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                      ? (IData)(
                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                                 >> 0x10U))
                                                      : 
                                                     ((0x100U 
                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                       ? (IData)(
                                                                 (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                                  >> 8U))
                                                       : 
                                                      ((0x80U 
                                                        & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                        ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data)
                                                        : 0U)))))))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data 
        = (0xffffU & ((0x2000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                       ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                  >> 0x30U)) : ((0x800U 
                                                 & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                 ? (IData)(
                                                           (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                            >> 0x20U))
                                                 : 
                                                ((0x200U 
                                                  & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                  ? (IData)(
                                                            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                             >> 0x10U))
                                                  : 
                                                 ((0x80U 
                                                   & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                   ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data)
                                                   : 0U)))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data 
        = ((0x800U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
            ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                       >> 0x20U)) : ((0x80U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                      ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data)
                                      : 0U));
    VSimTop___024unit____Vdpiimwrap_ram_read_helper_TOP____024unit(vlSelf->SimTop__DOT__inst_sram_en, 
                                                                   ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc 
                                                                     - 0x80000000ULL) 
                                                                    >> 3U), vlSelf->__Vfunc_ram_read_helper__0__Vfuncout);
    vlSelf->SimTop__DOT__inst_sram_rdata = vlSelf->__Vfunc_ram_read_helper__0__Vfuncout;
    __Vtemp_h4d85910c__0[3U] = (IData)(((0x40U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                         ? ((IData)(
                                                    (0x18000U 
                                                     == 
                                                     (0x18000U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                             ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data))
                                             : ((0x10000U 
                                                 & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                 ? 
                                                (((- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data) 
                                                                         >> 7U))))) 
                                                  << 8U) 
                                                 | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data)))
                                                 : 
                                                ((IData)(
                                                         (0x28000U 
                                                          == 
                                                          (0x28000U 
                                                           & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                  ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data))
                                                  : 
                                                 ((0x20000U 
                                                   & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                   ? 
                                                  (((- (QData)((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data) 
                                                                           >> 0xfU))))) 
                                                    << 0x10U) 
                                                   | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data)))
                                                   : 
                                                  ((IData)(
                                                           (0x48000U 
                                                            == 
                                                            (0x48000U 
                                                             & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                    ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data))
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (- (IData)(
                                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data 
                                                                                >> 0x1fU))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data)))
                                                     : 
                                                    ((0x80000U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                      ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data
                                                      : 0ULL)))))))
                                         : (((QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))));
    __Vtemp_h4d85910c__0[4U] = (IData)((((0x40U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                          ? ((IData)(
                                                     (0x18000U 
                                                      == 
                                                      (0x18000U 
                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                              ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data))
                                              : ((0x10000U 
                                                  & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                  ? 
                                                 (((- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data) 
                                                                          >> 7U))))) 
                                                   << 8U) 
                                                  | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data)))
                                                  : 
                                                 ((IData)(
                                                          (0x28000U 
                                                           == 
                                                           (0x28000U 
                                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                   ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data))
                                                   : 
                                                  ((0x20000U 
                                                    & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data) 
                                                                            >> 0xfU))))) 
                                                     << 0x10U) 
                                                    | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data)))
                                                    : 
                                                   ((IData)(
                                                            (0x48000U 
                                                             == 
                                                             (0x48000U 
                                                              & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                     ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data))
                                                     : 
                                                    ((0x40000U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                      ? 
                                                     (((QData)((IData)(
                                                                       (- (IData)(
                                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data 
                                                                                >> 0x1fU))))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data)))
                                                      : 
                                                     ((0x80000U 
                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                       ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data
                                                       : 0ULL)))))))
                                          : (((QData)((IData)(
                                                              vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))) 
                                        >> 0x20U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[1U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[1U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[2U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[2U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[3U] 
        = __Vtemp_h4d85910c__0[3U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[4U] 
        = __Vtemp_h4d85910c__0[4U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[5U] 
        = (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[6U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[7U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[8U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[9U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xaU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xbU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xcU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xdU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xeU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xfU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x10U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x11U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x12U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag)
            ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r
            : vlSelf->SimTop__DOT__inst_sram_rdata);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
        = ((1U & (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r 
                          >> 2U))) ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp 
                                              >> 0x20U))
            : (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp));
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
    vlSelf->__Vtableidx4 = (0xfU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                    >> 0x19U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l 
        = VSimTop__ConstPool__TABLE_h7a2fd741_0[vlSelf->__Vtableidx4];
    vlSelf->__Vtableidx5 = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                            >> 0x1dU);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx5];
    vlSelf->__Vtableidx3 = (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                  >> 0xcU));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx3];
    vlSelf->__Vtableidx1 = (0xfU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l 
        = VSimTop__ConstPool__TABLE_h7a2fd741_0[vlSelf->__Vtableidx1];
    vlSelf->__Vtableidx2 = (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                  >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx2];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0 
        = (1U & ((~ (IData)((0U != (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                          >> 0x1aU))))) 
                 & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h) 
                  >> 2U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0 
        = (1U & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h) 
                 & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 3U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 7U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 1U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 7U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal 
        = (IData)((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                    >> 6U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                              >> 0xfU)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 6U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 7U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 2U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 6U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 3U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 0xbU)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 1U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 0xbU)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l)) 
                 >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0 
        = (1U & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                 & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                    >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 1U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0 
        = (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
            >> 1U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui) 
           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 1U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 2U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 1U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 6U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 7U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 7U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 6U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 4U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 2U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 3U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 1U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 2U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 6U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 2U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 6U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 7U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 1U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb) 
           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh) 
              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw) 
                 | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hf639659f__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
              | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0) 
           & ((~ (IData)((0U != (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                       >> 0x1aU))))) 
              & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h) 
                 >> 2U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__sel_rf_res 
        = ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                   | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                      | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned))))) 
            << 1U) | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal) 
                      | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm 
        = (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr) 
            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                  | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                     | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
                           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                 | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi) 
                                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw) 
                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti) 
                                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu) 
                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori) 
                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori) 
                                                   | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi)))))))))))))))
            ? (((- (QData)((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                    >> 0x1fU)))) << 0xcU) 
               | (QData)((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                  >> 0x14U)))) : ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we)
                                                   ? 
                                                  (((- (QData)((IData)(
                                                                       (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                        >> 0x1fU)))) 
                                                    << 0xcU) 
                                                   | (QData)((IData)(
                                                                     ((0xfe0U 
                                                                       & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                          >> 0x14U)) 
                                                                      | (0x1fU 
                                                                         & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                            >> 7U))))))
                                                   : 
                                                  (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq) 
                                                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne) 
                                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt) 
                                                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge) 
                                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu) 
                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu))))))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      ((0x800U 
                                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                           << 4U)) 
                                                                       | ((0x7e0U 
                                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                              >> 0x14U)) 
                                                                          | (0x1eU 
                                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 7U)))))))
                                                    : 
                                                   ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (- (IData)(
                                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 0x1fU))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       (0xfffff000U 
                                                                        & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst))))
                                                     : 
                                                    ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal)
                                                      ? 
                                                     (((- (QData)((IData)(
                                                                          (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                           >> 0x1fU)))) 
                                                       << 0x14U) 
                                                      | (QData)((IData)(
                                                                        ((0xff000U 
                                                                          & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst) 
                                                                         | ((0x800U 
                                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 9U)) 
                                                                            | (0x7feU 
                                                                               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 0x14U)))))))
                                                      : 
                                                     (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw) 
                                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw) 
                                                          | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw)))
                                                       ? (QData)((IData)(
                                                                         (0x1fU 
                                                                          & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                             >> 0x14U))))
                                                       : 
                                                      (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli) 
                                                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli) 
                                                           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai)))
                                                        ? (QData)((IData)(
                                                                          (0x3fU 
                                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                              >> 0x14U))))
                                                        : 0ULL)))))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__rf_we 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0) 
           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal) 
              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr) 
                 | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                                   | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                      | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi) 
                                         | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw) 
                                            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti) 
                                               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu) 
                                                  | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori) 
                                                     | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori) 
                                                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi) 
                                                           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli) 
                                                              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw) 
                                                                 | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli) 
                                                                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw) 
                                                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai) 
                                                                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw) 
                                                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and))))))))))))))))))))))))))))))))))))));
}
