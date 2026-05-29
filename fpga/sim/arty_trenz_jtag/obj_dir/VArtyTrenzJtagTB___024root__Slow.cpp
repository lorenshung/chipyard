// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArtyTrenzJtagTB.h for the primary calling header

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB__Syms.h"
#include "VArtyTrenzJtagTB___024root.h"

void VArtyTrenzJtagTB___024root___ctor_var_reset(VArtyTrenzJtagTB___024root* vlSelf);

VArtyTrenzJtagTB___024root::VArtyTrenzJtagTB___024root(VArtyTrenzJtagTB__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VArtyTrenzJtagTB___024root___ctor_var_reset(this);
}

void VArtyTrenzJtagTB___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VArtyTrenzJtagTB___024root::~VArtyTrenzJtagTB___024root() {
}
