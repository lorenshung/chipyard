// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VArtyTrenzJtagTB.h for the primary calling header

#ifndef VERILATED_VARTYTRENZJTAGTB_ASYNCQUEUE_H_
#define VERILATED_VARTYTRENZJTAGTB_ASYNCQUEUE_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class VArtyTrenzJtagTB__Syms;

class alignas(VL_CACHE_LINE_BYTES) VArtyTrenzJtagTB_AsyncQueue final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(io_enq_clock,0,0);
        VL_IN8(io_enq_reset,0,0);
        VL_IN8(io_deq_clock,0,0);
        VL_IN8(io_deq_reset,0,0);
        CData/*0:0*/ sink__DOT____Vcellinp__sink_valid_0__reset;
        VL_OUT8(io_enq_ready,0,0);
        VL_IN8(io_enq_valid,0,0);
        VL_IN8(io_deq_ready,0,0);
        VL_OUT8(io_deq_valid,0,0);
        CData/*0:0*/ __PVT__source__DOT___widx_T_1;
        CData/*3:0*/ __PVT__source__DOT__widx_widx_bin;
        CData/*0:0*/ __PVT__source__DOT__ready_reg;
        CData/*3:0*/ __PVT__source__DOT__widx_gray;
        CData/*2:0*/ __PVT__source__DOT__index;
        CData/*3:0*/ __PVT__source__DOT__widx_incremented;
        CData/*3:0*/ __PVT__source__DOT__widx;
        CData/*3:0*/ source__DOT____VdfgTmp_h04800923__0;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*3:0*/ __PVT__sink__DOT__ridx_ridx_bin;
        CData/*3:0*/ __PVT__sink__DOT__ridx_incremented;
        CData/*2:0*/ __PVT__sink__DOT___index_T;
        CData/*3:0*/ __PVT__sink__DOT__ridx;
        CData/*0:0*/ __PVT__sink__DOT__valid;
        CData/*0:0*/ __PVT__sink__DOT__valid_reg;
        CData/*3:0*/ __PVT__sink__DOT__ridx_gray;
        CData/*3:0*/ sink__DOT____VdfgTmp_h53fc3cf3__0;
        CData/*0:0*/ sink__DOT____VdfgTmp_h4434c2cc__0;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    };
    struct {
        CData/*0:0*/ __PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        CData/*0:0*/ __PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
        CData/*0:0*/ __PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
        CData/*0:0*/ __PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
        VL_IN(io_enq_bits_phit,31,0);
        VL_OUT(io_deq_bits_phit,31,0);
        IData/*31:0*/ __PVT__source__DOT__mem_0_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_1_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_2_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_3_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_4_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_5_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_6_phit;
        IData/*31:0*/ __PVT__source__DOT__mem_7_phit;
        IData/*31:0*/ __PVT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg;
    };

    // INTERNAL VARIABLES
    VArtyTrenzJtagTB__Syms* const vlSymsp;

    // CONSTRUCTORS
    VArtyTrenzJtagTB_AsyncQueue(VArtyTrenzJtagTB__Syms* symsp, const char* v__name);
    ~VArtyTrenzJtagTB_AsyncQueue();
    VL_UNCOPYABLE(VArtyTrenzJtagTB_AsyncQueue);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
