package chipyard.fpga.ku040

import chisel3._

import freechips.rocketchip.diplomacy.LazyRawModuleImp

import sifive.blocks.devices.uart.UARTPortIO

import chipyard.harness._
import chipyard.iobinders._

// UART through the FMC UART overlay placed by the harness.
class WithKu040UART extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTPort, chipId: Int) => {
    val ku = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Ku040ScratchpadHarness]
    ku.io_uart_bb.bundle <> port.io
  }
})
