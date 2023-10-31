// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrvcpu.h for the primary calling header

#include "verilated.h"

#include "Vrvcpu__Syms.h"
#include "Vrvcpu___024root.h"

void Vrvcpu___024root___ctor_var_reset(Vrvcpu___024root* vlSelf);

Vrvcpu___024root::Vrvcpu___024root(Vrvcpu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vrvcpu___024root___ctor_var_reset(this);
}

void Vrvcpu___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vrvcpu___024root::~Vrvcpu___024root() {
}
