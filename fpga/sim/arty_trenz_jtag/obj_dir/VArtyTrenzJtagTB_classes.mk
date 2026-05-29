# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VArtyTrenzJtagTB.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	VArtyTrenzJtagTB \
	VArtyTrenzJtagTB___024root__DepSet_h03cb5cce__0 \
	VArtyTrenzJtagTB___024root__DepSet_h03cb5cce__1 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__0 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__1 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__2 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__3 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__4 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__5 \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__6 \
	VArtyTrenzJtagTB_AsyncQueue__DepSet_he228e476__0 \
	VArtyTrenzJtagTB_AsyncQueue__DepSet_h7d40d3a2__0 \
	VArtyTrenzJtagTB__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	VArtyTrenzJtagTB__ConstPool_0 \
	VArtyTrenzJtagTB___024root__Slow \
	VArtyTrenzJtagTB___024root__DepSet_h03cb5cce__0__Slow \
	VArtyTrenzJtagTB___024root__DepSet_h03cb5cce__1__Slow \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__0__Slow \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__1__Slow \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__2__Slow \
	VArtyTrenzJtagTB___024root__DepSet_h7f0e37ec__3__Slow \
	VArtyTrenzJtagTB_AsyncQueue__Slow \
	VArtyTrenzJtagTB_AsyncQueue__DepSet_he228e476__0__Slow \
	VArtyTrenzJtagTB_AsyncQueue__DepSet_h7d40d3a2__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	VArtyTrenzJtagTB__Trace__0 \
	VArtyTrenzJtagTB__Trace__1 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	VArtyTrenzJtagTB__Syms \
	VArtyTrenzJtagTB__Trace__0__Slow \
	VArtyTrenzJtagTB__TraceDecls__0__Slow \
	VArtyTrenzJtagTB__Trace__1__Slow \
	VArtyTrenzJtagTB__Trace__2__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_fst_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
