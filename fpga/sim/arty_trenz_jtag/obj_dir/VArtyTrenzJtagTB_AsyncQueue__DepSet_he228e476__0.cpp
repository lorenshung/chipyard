// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArtyTrenzJtagTB.h for the primary calling header

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB_AsyncQueue.h"

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_6;
    // Body
    if (vlSelf->__PVT__sink__DOT__valid) {
        __Vtemp_6[0U] = vlSelf->__PVT__source__DOT__mem_0_phit;
        __Vtemp_6[1U] = vlSelf->__PVT__source__DOT__mem_1_phit;
        __Vtemp_6[2U] = vlSelf->__PVT__source__DOT__mem_2_phit;
        __Vtemp_6[3U] = vlSelf->__PVT__source__DOT__mem_3_phit;
        __Vtemp_6[4U] = vlSelf->__PVT__source__DOT__mem_4_phit;
        __Vtemp_6[5U] = vlSelf->__PVT__source__DOT__mem_5_phit;
        __Vtemp_6[6U] = (IData)((((QData)((IData)(vlSelf->__PVT__source__DOT__mem_7_phit)) 
                                  << 0x20U) | (QData)((IData)(vlSelf->__PVT__source__DOT__mem_6_phit))));
        __Vtemp_6[7U] = (IData)(((((QData)((IData)(vlSelf->__PVT__source__DOT__mem_7_phit)) 
                                   << 0x20U) | (QData)((IData)(vlSelf->__PVT__source__DOT__mem_6_phit))) 
                                 >> 0x20U));
        vlSelf->__PVT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                              ((IData)(vlSelf->__PVT__sink__DOT___index_T) 
                                               ^ ((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                                  << 2U)), 5U)))
                 ? 0U : (__Vtemp_6[(((IData)(0x1fU) 
                                     + (0xffU & VL_SHIFTL_III(8,8,32, 
                                                              ((IData)(vlSelf->__PVT__sink__DOT___index_T) 
                                                               ^ 
                                                               ((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                                                << 2U)), 5U))) 
                                    >> 5U)] << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(8,8,32, 
                                                                   ((IData)(vlSelf->__PVT__sink__DOT___index_T) 
                                                                    ^ 
                                                                    ((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                                                     << 2U)), 5U))))) 
               | (__Vtemp_6[(7U & (VL_SHIFTL_III(8,8,32, 
                                                 ((IData)(vlSelf->__PVT__sink__DOT___index_T) 
                                                  ^ 
                                                  ((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                                   << 2U)), 5U) 
                                   >> 5U))] >> (0x1fU 
                                                & VL_SHIFTL_III(8,8,32, 
                                                                ((IData)(vlSelf->__PVT__sink__DOT___index_T) 
                                                                 ^ 
                                                                 ((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                                                  << 2U)), 5U))));
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__3(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__3\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__valid_reg = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
                                           && (IData)(vlSelf->__PVT__sink__DOT__valid));
    if (vlSelf->io_deq_reset) {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__sink__DOT__ridx_gray = 0U;
    } else {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = vlSelf->__PVT__sink__DOT__ridx_incremented;
        vlSelf->__PVT__sink__DOT__ridx_gray = vlSelf->__PVT__sink__DOT__ridx;
    }
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    if (vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) {
        vlSelf->io_deq_valid = vlSelf->__PVT__sink__DOT__valid_reg;
        vlSelf->__PVT__sink__DOT__ridx_incremented 
            = vlSelf->__PVT__sink__DOT__ridx_ridx_bin;
    } else {
        vlSelf->io_deq_valid = 0U;
        vlSelf->__PVT__sink__DOT__ridx_incremented = 0U;
    }
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    >> 3U));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 3U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 2U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 1U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->io_deq_reset))) 
           && (1U & (IData)(vlSelf->__PVT__source__DOT__widx_gray)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__4(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__4\n"); );
    // Body
    vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__6(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__6\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__1\n"); );
    // Body
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0) 
                                                   >> 1U)
                                                   : 0U))));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__7(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__7\n"); );
    // Body
    vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__3(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__3\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__5(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__5\n"); );
    // Body
    vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__1\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__6(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__6\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset)));
}
