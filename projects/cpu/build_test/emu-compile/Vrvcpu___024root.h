// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vrvcpu.h for the primary calling header

#ifndef VERILATED_VRVCPU___024ROOT_H_
#define VERILATED_VRVCPU___024ROOT_H_  // guard

#include "verilated.h"

class Vrvcpu__Syms;

class Vrvcpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(inst_ena,0,0);
    CData/*0:0*/ rvcpu__DOT__rs1_r_ena;
    CData/*4:0*/ rvcpu__DOT__rd_w_addr;
    CData/*4:0*/ rvcpu__DOT__inst_type;
    CData/*0:0*/ rvcpu__DOT__Id_stage__DOT__inst_addi;
    CData/*0:0*/ rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(inst_addr,63,0);
    QData/*63:0*/ rvcpu__DOT__rd_data;
    QData/*63:0*/ rvcpu__DOT__If_stage__DOT__pc;
    VlUnpacked<QData/*63:0*/, 32> rvcpu__DOT__Regfile__DOT__regs;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vrvcpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vrvcpu___024root(Vrvcpu__Syms* symsp, const char* v__name);
    ~Vrvcpu___024root();
    VL_UNCOPYABLE(Vrvcpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
