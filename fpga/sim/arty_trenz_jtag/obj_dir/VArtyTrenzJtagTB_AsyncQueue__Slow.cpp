// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArtyTrenzJtagTB.h for the primary calling header

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB_AsyncQueue.h"
#include "VArtyTrenzJtagTB__Syms.h"

void VArtyTrenzJtagTB_AsyncQueue___ctor_var_reset(VArtyTrenzJtagTB_AsyncQueue* vlSelf);

VArtyTrenzJtagTB_AsyncQueue::VArtyTrenzJtagTB_AsyncQueue(VArtyTrenzJtagTB__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VArtyTrenzJtagTB_AsyncQueue___ctor_var_reset(this);
}

void VArtyTrenzJtagTB_AsyncQueue::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VArtyTrenzJtagTB_AsyncQueue::~VArtyTrenzJtagTB_AsyncQueue() {
}
