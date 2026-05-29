// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArtyTrenzJtagTB.h for the primary calling header

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB___024root.h"

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__26(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__26\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__deglitched_deglitch__DOT__reg_0 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT____Vcellinp__dutWrangler__auto_in_reset) 
           | (0x1388U != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__debounced_debounce__DOT__reg_0)));
    if (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT____Vcellinp__dutWrangler__auto_in_reset) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__debounced_debounce__DOT__reg_0 = 0U;
    } else if (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__increment) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__debounced_debounce__DOT__reg_0 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT____Vcellinp__debounced_debounce__io_d;
    }
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__increment 
        = (0x1388U != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__debounced_debounce__DOT__reg_0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT____Vcellinp__debounced_debounce__io_d 
        = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__dutWrangler__DOT__debounced_debounce__DOT__reg_0)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__27(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__27\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset))) 
           && (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__28(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__28\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__debug_reset 
        = (1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__debug_reset_syncd_debug_reset_sync__DOT__output_chain__DOT__sync_0)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__29(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__29\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__stickyBusyReg 
        = vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__stickyBusyReg;
    if (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset) {
        vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq = 0U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hartsello = 0U;
        vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset = 0U;
        vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0 = 0U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive = 0U;
    } else {
        vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq 
            = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive) 
               & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9)
                   ? (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_a_bits_data 
                      >> 0x1fU) : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq)));
        vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset 
            = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive) 
               & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9)
                   ? (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_a_bits_data 
                      >> 1U) : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset)));
        vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0 
            = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive) 
               & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9)
                   ? (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_a_bits_data 
                      >> 0x1fU) : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0)));
        if ((1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive)))) {
            vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hartsello = 0U;
        }
        if (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9) {
            vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive 
                = (1U & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_a_bits_data);
        }
    }
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_capture_bits_dmiStatus 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__stickyNonzeroRespReg) 
            << 1U) | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__stickyBusyReg) 
                      | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__stickyNonzeroRespReg)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0 
        = vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq 
        = vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset 
        = vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset;
    vlSelf->__VdfgTmp_ha8f8c8b5__0 = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive) 
                                      & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmactiveAck_dmactiveAckSync__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_comb__TOP__4(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_comb__TOP__4\n"); );
    // Init
    CData/*1:0*/ ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_filter_T_1;
    ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_filter_T_1 = 0;
    CData/*0:0*/ ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_1;
    ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_1 = 0;
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_3 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__downgradeOpReg) 
           | (0U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___dmiAccessChain_io_update_bits_op)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_a_valid 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqValidReg) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__requestAIO_0_0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqValidReg) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__requestAIO_0_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass 
        = (1U & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_reset)
                  ? (~ (IData)(vlSelf->__VdfgTmp_ha8f8c8b5__0))
                  : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass_reg)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__stall 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__stall_counter)) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass) 
              != (1U & (~ (IData)(vlSelf->__VdfgTmp_ha8f8c8b5__0)))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT____VdfgTmp_h365966bb__0 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__stall)) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_a_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT___widx_T_1 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__io_enq_ready_0) 
           & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)) 
              & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT____VdfgTmp_h365966bb__0)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__winner_1 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT____VdfgTmp_h365966bb__0) 
            & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__idle));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__widx 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__widx_widx_bin) 
              + (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT___widx_T_1)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___error_auto_in_d_bits_denied 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__beatsLeft)
            ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__state_1)
            : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__winner_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___error_auto_in_d_valid 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT____VdfgTmp_h707cc4b3__0) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__winner_1));
    if (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_bits_opcode 
            = (3U & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___error_auto_in_d_bits_denied)
                      ? ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__da_bits_opcode) 
                         >> 1U) : 0U));
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___error_auto_in_d_valid;
    } else {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_bits_opcode 
            = (3U & (IData)((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                             >> 0x29U)));
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__io_deq_valid_0;
    }
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_valid 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid) 
            << 1U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid));
    ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_filter_T_1 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_mask)) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_io_dmi_dmi_resp_valid 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__beatsLeft)
            ? (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid) 
                & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__state_0)) 
               | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid) 
                  & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__state_1)))
            : ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid) 
               | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___busy_T_1 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_io_dmi_dmi_resp_valid)) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__busyReg));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys 
        = (3U & (~ (((2U & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_mask)) 
                     | (1U & (((IData)(ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_filter_T_1) 
                               >> 1U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_mask)))) 
                    & (((2U & ((IData)(ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_filter_T_1) 
                               << 1U)) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid)) 
                       | (IData)(ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_filter_T_1)))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__busy 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___busy_T_1) 
           | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__stickyBusyReg));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___readys_mask_T 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__winner_1 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
            >> 1U) & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__winner_0 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxState_0 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__beatsLeft)
            ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__state_0)
            : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__winner_0));
    ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_1 
        = (1U & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_io_dmi_dmi_resp_valid)) 
                 | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__busy)));
    if (ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_1) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_addr = 0U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_data = 0U;
    } else {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_addr 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_addr;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_data 
            = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxState_0)
                 ? ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                     ? 0U : (IData)((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 1U))) : 0U) 
               | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__beatsLeft)
                    ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__state_1)
                    : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__winner_1))
                   ? ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___out_T_3)
                       ? ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT____VdfgTmp_hcef7e3f7__0)
                           ? 0x118380U : (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq) 
                                           << 0x1fU) 
                                          | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset) 
                                              << 1U) 
                                             | (IData)(vlSelf->__VdfgTmp_ha8f8c8b5__0))))
                       : 0U) : 0U));
    }
    vlSelf->__VdfgTmp_hf29432a4__0 = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxState_0) 
                                      & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                           ? ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___error_auto_in_d_bits_denied) 
                                              & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__da_bits_opcode))
                                           : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)) 
                                         | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                             ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___error_auto_in_d_bits_denied)
                                             : (IData)(
                                                       (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                        >> 0x21U)))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___nonzeroResp_T_1 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_io_dmi_dmi_resp_valid) 
           & (IData)(vlSelf->__VdfgTmp_hf29432a4__0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_resp 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__busy)
            ? 3U : ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_io_dmi_dmi_resp_valid)
                     ? (IData)(vlSelf->__VdfgTmp_hf29432a4__0)
                     : 0U));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__30(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__30\n"); );
    // Body
    if (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction = 1U;
    } else if ((0xfU == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction = 1U;
    } else if ((0xdU == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction 
            = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_4) 
                << 4U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_3) 
                           << 3U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_2) 
                                      << 2U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_1) 
                                                 << 1U) 
                                                | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_0)))));
    }
}

extern const VlWide<9>/*287:0*/ VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0;

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_comb__TOP__5(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_comb__TOP__5\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_137;
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0U] 
        = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartHalted;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[1U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[2U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[3U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[4U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_3) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_2) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_1) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_0))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[5U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_7) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_6) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_5) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_4))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[6U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_11) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_10) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_9) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_8))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[7U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_15) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_14) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_13) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_12))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[8U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_19) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_18) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_17) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_16))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[9U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_23) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_22) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_21) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_20))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0xaU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_27) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_26) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_25) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_24))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0xbU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_31) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_30) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_29) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_28))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0xcU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0xdU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0xeU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0xfU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x10U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x11U] 
        = (0xa2U | ((0xc0000U & ((- (IData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__haveResetBitRegs))) 
                                 << 0x12U)) | ((0x30000U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__resumereq)
                                                                   ? 
                                                                  ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__resumeReqRegs)) 
                                                                   & (0U 
                                                                      != 
                                                                      (0x3ffU 
                                                                       & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg) 
                                                                          >> 4U))))
                                                                   : 
                                                                  (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__resumeReqRegs)))))) 
                                                   << 0x10U)) 
                                               | ((0x800U 
                                                   & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartHalted)) 
                                                      << 0xbU)) 
                                                  | ((0x400U 
                                                      & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartHalted)) 
                                                         << 0xaU)) 
                                                     | (0x300U 
                                                        & ((- (IData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartHalted))) 
                                                           << 8U)))))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x12U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x13U] 
        = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartHalted;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x14U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x15U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x16U] 
        = (0x10000008U | (((IData)((0U != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ctrlStateReg))) 
                           << 0xcU) | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTCSReg_cmderr) 
                                       << 8U)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x17U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDReg_cmdtype) 
            << 0x18U) | vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDReg_control);
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x18U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTAUTOReg_autoexecprogbuf) 
            << 0x10U) | (0xffU & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTAUTOReg_autoexecdata)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x19U] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x1aU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x1bU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x1cU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x1dU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x1eU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x1fU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x20U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_3) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_2) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_1) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_0))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x21U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_7) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_6) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_5) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_4))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x22U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_11) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_10) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_9) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_8))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x23U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_15) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_14) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_13) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_12))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x24U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_19) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_18) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_17) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_16))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x25U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_23) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_22) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_21) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_20))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x26U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_27) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_26) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_25) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_24))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x27U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_31) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_30) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_29) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_28))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x28U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_35) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_34) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_33) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_32))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x29U] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_39) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_38) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_37) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_36))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x2aU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_43) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_42) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_41) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_40))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x2bU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_47) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_46) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_45) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_44))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x2cU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_51) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_50) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_49) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_48))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x2dU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_55) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_54) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_53) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_52))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x2eU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_59) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_58) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_57) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_56))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x2fU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_63) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_62) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_61) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_60))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x30U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[0U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x31U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[1U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x32U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[2U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x33U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[3U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x34U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[4U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x35U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[5U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x36U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[6U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x37U] 
        = VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[7U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x38U] 
        = (0x20000000U | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbbusyerror) 
                           << 0x16U) | (((IData)((0U 
                                                  != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sb2tlOpt__DOT__sbState))) 
                                         << 0x15U) 
                                        | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbreadonaddr) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbaccess) 
                                               << 0x11U) 
                                              | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbautoincrement) 
                                                  << 0x10U) 
                                                 | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbreadondata) 
                                                     << 0xfU) 
                                                    | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sbErrorReg_2) 
                                                        << 0xeU) 
                                                       | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sbErrorReg_1) 
                                                           << 0xdU) 
                                                          | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sbErrorReg_0) 
                                                              << 0xcU) 
                                                             | VArtyTrenzJtagTB__ConstPool__CONST_hd571eab3_0[8U]))))))))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x39U] 
        = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBADDRESSFieldsReg_0;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x3aU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x3bU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x3cU] 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_3) 
            << 0x18U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_2) 
                          << 0x10U) | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_1) 
                                        << 8U) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_0))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x3dU] 
        = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT____VdfgTmp_hb778be90__0;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x3eU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___GEN_0[0x3fU] = 0U;
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data 
        = ((1U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sb2tlOpt__DOT__sbState))
            ? 0U : (0xffU & (IData)((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sb2tlOpt_io_wrEn)
                                       ? (((QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAWrData_1)) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAWrData_0)))
                                       : (((QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT____VdfgTmp_hb778be90__0)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_3) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_2) 
                                                                 << 0x10U) 
                                                                | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_1) 
                                                                    << 8U) 
                                                                   | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBDATAFieldsReg_0_0)))))))) 
                                     >> (0x3fU & VL_SHIFTL_III(6,6,32, 
                                                               (7U 
                                                                & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sb2tlOpt__DOT__counter)), 3U))))));
    __Vtemp_137[0U] = (IData)((((QData)((IData)((0xffU 
                                                 & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                      ? 
                                                     ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_1) 
                                                        | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_2) 
                                                           & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                       << 7U) 
                                                      | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_1) 
                                                           | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                              & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_2))) 
                                                          << 6U) 
                                                         | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_1) 
                                                              | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_2) 
                                                                 & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                             << 5U) 
                                                            | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_1) 
                                                                 | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                    & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_2))) 
                                                                << 4U) 
                                                               | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_1) 
                                                                    | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_2) 
                                                                       & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                                   << 3U) 
                                                                  | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_1) 
                                                                       | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                          & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_2))) 
                                                                      << 2U) 
                                                                     | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_1) 
                                                                          | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_2) 
                                                                             & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                                         << 1U) 
                                                                        | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_1) 
                                                                           | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                              & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_2))))))))))
                                                      : 0U) 
                                                    | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                        ? 
                                                       ((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U] 
                                                         << 0x12U) 
                                                        | (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U] 
                                                           >> 0xeU))
                                                        : 0U))))) 
                                << 0x2fU) | (((QData)((IData)(
                                                              (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                 ? vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address
                                                                 : 0U) 
                                                               | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                   ? 
                                                                  ((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U] 
                                                                    << 0x12U) 
                                                                   | (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xeU))
                                                                   : 0U)))) 
                                              << 0xfU) 
                                             | (QData)((IData)(
                                                               ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0) 
                                                                  << 0xeU) 
                                                                 | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                      ? 
                                                                     (0xfU 
                                                                      & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0xaU))
                                                                      : 0U) 
                                                                    << 0xaU)) 
                                                                | ((0x3c0U 
                                                                    & ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                          ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbaccess)
                                                                          : 0U) 
                                                                        | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                            ? 
                                                                           ((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             << 0x1aU) 
                                                                            | (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                               >> 6U))
                                                                            : 0U)) 
                                                                       << 6U)) 
                                                                   | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                         ? 
                                                                        (7U 
                                                                         & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 3U))
                                                                         : 0U) 
                                                                       << 3U) 
                                                                      | (7U 
                                                                         & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                              ? 
                                                                             ((1U 
                                                                               == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sb2tlOpt__DOT__sbState)) 
                                                                              << 2U)
                                                                              : 0U) 
                                                                            | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                                ? 
                                                                               vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U]
                                                                                : 0U)))))))))));
    __Vtemp_137[1U] = (((IData)((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                   ? (((QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)) 
                                       << 0x38U) | 
                                      (((QData)((IData)(
                                                        ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_6)
                                                          ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                          : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_6)))) 
                                        << 0x30U) | 
                                       (((QData)((IData)(
                                                         ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_5)
                                                           ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                           : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_5)))) 
                                         << 0x28U) 
                                        | (((QData)((IData)(
                                                            ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_4)
                                                              ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                              : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_4)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_3)
                                                                 ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                 : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_3)) 
                                                               << 0x18U) 
                                                              | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_2)
                                                                    ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                    : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_2)) 
                                                                  << 0x10U) 
                                                                 | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_1)
                                                                       ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                       : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_1)) 
                                                                     << 8U) 
                                                                    | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_0)
                                                                        ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                        : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_0)))))))))))
                                   : 0ULL) | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                               ? (((QData)((IData)(
                                                                   vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[3U])) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[2U])) 
                                                      << 0xaU) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U])) 
                                                        >> 0x16U)))
                                               : 0ULL))) 
                        << 0x17U) | (IData)(((((QData)((IData)(
                                                               (0xffU 
                                                                & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                     ? 
                                                                    ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_1) 
                                                                       | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_2) 
                                                                          & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                                      << 7U) 
                                                                     | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_1) 
                                                                          | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                             & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_3_2))) 
                                                                         << 6U) 
                                                                        | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_1) 
                                                                             | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_2) 
                                                                                & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                                            << 5U) 
                                                                           | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_1) 
                                                                                | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                                & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_2_2))) 
                                                                               << 4U) 
                                                                              | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_1) 
                                                                                | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_2) 
                                                                                & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                                                << 3U) 
                                                                                | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_1) 
                                                                                | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                                & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_1_2))) 
                                                                                << 2U) 
                                                                                | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_1) 
                                                                                | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_2) 
                                                                                & vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address)) 
                                                                                << 1U) 
                                                                                | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_1) 
                                                                                | ((~ vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address) 
                                                                                & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_mask_sub_0_2))))))))))
                                                                     : 0U) 
                                                                   | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                       ? 
                                                                      ((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U] 
                                                                        << 0x12U) 
                                                                       | (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U] 
                                                                          >> 0xeU))
                                                                       : 0U))))) 
                                               << 0x2fU) 
                                              | (((QData)((IData)(
                                                                  (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                     ? vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_address
                                                                     : 0U) 
                                                                   | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                       ? 
                                                                      ((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U] 
                                                                        << 0x12U) 
                                                                       | (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                          >> 0xeU))
                                                                       : 0U)))) 
                                                  << 0xfU) 
                                                 | (QData)((IData)(
                                                                   ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0) 
                                                                      << 0xeU) 
                                                                     | (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                          ? 
                                                                         (0xfU 
                                                                          & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0xaU))
                                                                          : 0U) 
                                                                        << 0xaU)) 
                                                                    | ((0x3c0U 
                                                                        & ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                              ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__SBCSFieldsReg_sbaccess)
                                                                              : 0U) 
                                                                            | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                                ? 
                                                                               ((vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 6U))
                                                                                : 0U)) 
                                                                           << 6U)) 
                                                                       | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                             ? 
                                                                            (7U 
                                                                             & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 3U))
                                                                             : 0U) 
                                                                           << 3U) 
                                                                          | (7U 
                                                                             & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                                                                 ? 
                                                                                ((1U 
                                                                                == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__sb2tlOpt__DOT__sbState)) 
                                                                                << 2U)
                                                                                 : 0U) 
                                                                                | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                                                 ? 
                                                                                vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[0U]
                                                                                 : 0U)))))))))) 
                                             >> 0x20U)));
    __Vtemp_137[2U] = (((IData)((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                   ? (((QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)) 
                                       << 0x38U) | 
                                      (((QData)((IData)(
                                                        ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_6)
                                                          ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                          : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_6)))) 
                                        << 0x30U) | 
                                       (((QData)((IData)(
                                                         ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_5)
                                                           ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                           : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_5)))) 
                                         << 0x28U) 
                                        | (((QData)((IData)(
                                                            ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_4)
                                                              ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                              : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_4)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_3)
                                                                 ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                 : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_3)) 
                                                               << 0x18U) 
                                                              | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_2)
                                                                    ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                    : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_2)) 
                                                                  << 0x10U) 
                                                                 | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_1)
                                                                       ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                       : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_1)) 
                                                                     << 8U) 
                                                                    | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_0)
                                                                        ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                        : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_0)))))))))))
                                   : 0ULL) | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                               ? (((QData)((IData)(
                                                                   vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[3U])) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[2U])) 
                                                      << 0xaU) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U])) 
                                                        >> 0x16U)))
                                               : 0ULL))) 
                        >> 9U) | ((IData)(((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                              ? (((QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_6)
                                                                       ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                       : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_6)))) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(
                                                                        ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_5)
                                                                          ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                          : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_5)))) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(
                                                                           ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_4)
                                                                             ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                             : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_4)))) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_3)
                                                                                ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                                : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_3)) 
                                                                              << 0x18U) 
                                                                             | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_2)
                                                                                 ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                                 : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_2)) 
                                                                                << 0x10U) 
                                                                                | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_1)
                                                                                 ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                                 : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_1)) 
                                                                                << 8U) 
                                                                                | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_0)
                                                                                 ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                                 : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_0)))))))))))
                                              : 0ULL) 
                                            | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                                ? (
                                                   ((QData)((IData)(
                                                                    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[3U])) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[2U])) 
                                                       << 0xaU) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U])) 
                                                         >> 0x16U)))
                                                : 0ULL)) 
                                           >> 0x20U)) 
                                  << 0x17U));
    __Vtemp_137[3U] = ((IData)(((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_0)
                                   ? (((QData)((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)) 
                                       << 0x38U) | 
                                      (((QData)((IData)(
                                                        ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_6)
                                                          ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                          : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_6)))) 
                                        << 0x30U) | 
                                       (((QData)((IData)(
                                                         ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_5)
                                                           ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                           : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_5)))) 
                                         << 0x28U) 
                                        | (((QData)((IData)(
                                                            ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_4)
                                                              ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                              : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_4)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_3)
                                                                 ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                 : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_3)) 
                                                               << 0x18U) 
                                                              | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_2)
                                                                    ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                    : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_2)) 
                                                                  << 0x10U) 
                                                                 | ((((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_1)
                                                                       ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                       : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_1)) 
                                                                     << 8U) 
                                                                    | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_masked_enable_0)
                                                                        ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_auto_dmInner_dmInner_sb2tlOpt_out_a_bits_data)
                                                                        : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_debug_sb__DOT__widget__DOT__anonOut_a_bits_data_rdata_0)))))))))))
                                   : 0ULL) | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1)
                                               ? (((QData)((IData)(
                                                                   vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[3U])) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[2U])) 
                                                      << 0xaU) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[1U])) 
                                                        >> 0x16U)))
                                               : 0ULL)) 
                                >> 0x20U)) >> 9U);
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__buffer__DOT__nodeOut_a_q__DOT____Vcellinp__ram_ext__W0_data[0U] 
        = __Vtemp_137[0U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__buffer__DOT__nodeOut_a_q__DOT____Vcellinp__ram_ext__W0_data[1U] 
        = __Vtemp_137[1U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__buffer__DOT__nodeOut_a_q__DOT____Vcellinp__ram_ext__W0_data[2U] 
        = __Vtemp_137[2U];
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__buffer__DOT__nodeOut_a_q__DOT____Vcellinp__ram_ext__W0_data[3U] 
        = ((0xff800000U & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__fbus_xbar__DOT__muxState_1) 
                            << 0x17U) & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__fbus__DOT__coupler_from_port_named_serial_tl_0_in__DOT__buffer__DOT__nodeOut_a_q__DOT___ram_ext_R0_data[3U] 
                                         << 1U))) | 
           __Vtemp_137[3U]);
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__31(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__31\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT____Vcellinp__dutWrangler__auto_in_reset 
        = (1U & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__harnessSysPLLNode__DOT__locked_r)) 
                 | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT___powerOnReset_fpga_power_on_power_on_reset)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__32(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__32\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset 
        = (1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__chipyard_prcictrl_domain__DOT__resetSynchronizer__DOT__nodeOut_member_allClocks_uncore_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__33(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__33\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_a_bits_data 
        = ((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_op))
            ? vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_data
            : 0U);
    if ((0xeU == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_0 = 1U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_1 = 0U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_2 = 0U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_3 = 0U;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_4 = 0U;
    } else if ((1U & (~ ((0xdU == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)) 
                         | (0xaU != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)))))) {
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_0 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_1;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_1 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_2;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_2 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_3;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_3 
            = vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_4;
        vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_4 
            = vlSelf->ArtyTrenzJtagTB__DOT__jtag_TDI;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__34(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__34\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset 
        = (1U & (~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system_debug_systemjtag_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_comb__TOP__6(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_comb__TOP__6\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tile_prci_domain__DOT__element_reset_domain_rockettile__DOT__dcache__DOT__tlb___05F64 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tile_prci_domain__DOT__element_reset_domain_rockettile__DOT__dcache__DOT__tlb_multipleHits));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tile_prci_domain__DOT__element_reset_domain_rockettile__DOT__frontend__DOT__tlb__DOT___GEN_166 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tile_prci_domain__DOT__element_reset_domain_rockettile__DOT__frontend__DOT__tlb__DOT__multipleHits));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_sequent__TOP__35(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_sequent__TOP__35\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState 
        = vlSelf->__Vdly__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState;
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_comb__TOP__7(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_comb__TOP__7\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__debug_reset) 
           | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset) 
           | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__debug_reset));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_comb__TOP__8(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_comb__TOP__8\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_shift 
        = ((0x11U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_shift 
        = ((1U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_capture 
        = ((1U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (6U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_update 
        = ((0x11U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (5U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_capture 
        = ((0x10U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (6U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update 
        = ((0x10U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (5U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_capture 
        = ((0x11U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
           & (6U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dtmInfoChain__DOT___GEN 
        = (1U & ((~ ((0x10U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                     & (2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)))) 
                 | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___dmiAccessChain_io_update_valid 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_capture)) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_update));
}

VL_INLINE_OPT void VArtyTrenzJtagTB___024root___nba_comb__TOP__9(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___nba_comb__TOP__9\n"); );
    // Body
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_4 
        = ((0xfU == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)) 
           | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dtmInfoChain__DOT__regs_16) 
              & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_capture)) 
                 & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__io_dmi_resp_ready_0 
        = ((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_op))
            ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT___tlDM_io_dmi_dmi_resp_valid)
            : ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__busy)) 
               & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_capture)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__latch 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__beatsLeft)) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__io_dmi_resp_ready_0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_a_ready 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__io_dmi_resp_ready_0) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__beatsLeft)
               ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__state_1)
               : ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                  >> 1U)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_d_ready 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__io_dmi_resp_ready_0) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__beatsLeft)
               ? (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__state_0)
               : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_d_valid) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_a_ready) 
              & ((4U != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___bar_auto_out_0_a_bits_opcode)) 
                 & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT____VdfgTmp_hcef7e3f7__0)) 
                    & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___out_T_3)))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__d_dec 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_d_ready) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__ridx 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__ridx_ridx_bin) 
              + (((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)) 
                  & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_d_ready)) 
                 & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__io_deq_valid_0))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___bar_auto_out_0_d_ready 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_d_ready) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_io_innerCtrl_bits_resumereq 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9) 
            & ((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_op)) 
               & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_data 
                  >> 0x1eU))) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__innerCtrlResumeReqReg));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_io_innerCtrl_bits_ackhavereset 
        = (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9) 
            & ((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_op)) 
               & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_data 
                  >> 0x1cU))) | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__innerCtrlAckHaveResetReg));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_io_innerCtrl_bits_hrmask_0 
        = ((~ ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive)) 
               | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9) 
                  & (((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_op)) 
                      & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_data 
                         >> 2U)) & (0U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hartsello)))))) 
           & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9) 
               & (((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_op)) 
                   & (vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqReg_data 
                      >> 3U)) & (0U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hartsello)))) 
              | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hrmaskReg_0)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_io_innerCtrl_valid 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_9) 
           | (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__innerCtrlValidReg));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__valid 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__ridx) 
              != (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeIn_d_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__da_ready 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___bar_auto_out_0_d_ready) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT____VdfgTmp_h707cc4b3__0));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT___widx_T_1 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_io_innerCtrl_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__r_3 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__da_ready) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__winner_1));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_a_ready 
        = ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__stall)) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
               ? ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__da_ready) 
                  & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__idle))
               : (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__nodeOut_a_source__DOT__io_enq_ready_0)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__widx 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__widx_widx_bin) 
              + (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT___widx_T_1)));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT___GEN_2 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__dtm__DOT__dmiReqValidReg) 
           & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__requestAIO_0_0) 
               & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_a_ready)) 
              | ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__requestAIO_0_1) 
                 & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmOuter_auto_dmi_in_a_ready))));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__r_3 
        = ((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_a_ready) 
           & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_anon_out_0_a_valid));
    vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT___next_flight_T_10 
        = (3U & (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__flight) 
                  + (((IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__d_dec) 
                      & ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__r_counter_3)) 
                         & (IData)((2U == (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__nodeIn_d_bits_opcode))))) 
                     + ((~ (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__r_counter)) 
                        & (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__r_3)))) 
                 - (IData)(vlSelf->ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__d_dec)));
}

void VArtyTrenzJtagTB___024root___timing_resume(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___timing_resume\n"); );
    // Body
    if ((0x4000000000ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void VArtyTrenzJtagTB___024root___eval_triggers__act(VArtyTrenzJtagTB___024root* vlSelf);
void VArtyTrenzJtagTB___024root___eval_act(VArtyTrenzJtagTB___024root* vlSelf);

bool VArtyTrenzJtagTB___024root___eval_phase__act(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<39> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VArtyTrenzJtagTB___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VArtyTrenzJtagTB___024root___timing_resume(vlSelf);
        VArtyTrenzJtagTB___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void VArtyTrenzJtagTB___024root___eval_nba(VArtyTrenzJtagTB___024root* vlSelf);

bool VArtyTrenzJtagTB___024root___eval_phase__nba(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VArtyTrenzJtagTB___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VArtyTrenzJtagTB___024root___dump_triggers__nba(VArtyTrenzJtagTB___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VArtyTrenzJtagTB___024root___dump_triggers__act(VArtyTrenzJtagTB___024root* vlSelf);
#endif  // VL_DEBUG

void VArtyTrenzJtagTB___024root___eval(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VArtyTrenzJtagTB___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/scratch/lorenhung/chipyard/fpga/sim/arty_trenz_jtag/ArtyTrenzJtagTB.sv", 24, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VArtyTrenzJtagTB___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/scratch/lorenhung/chipyard/fpga/sim/arty_trenz_jtag/ArtyTrenzJtagTB.sv", 24, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VArtyTrenzJtagTB___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VArtyTrenzJtagTB___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VArtyTrenzJtagTB___024root___eval_debug_assertions(VArtyTrenzJtagTB___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArtyTrenzJtagTB___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
