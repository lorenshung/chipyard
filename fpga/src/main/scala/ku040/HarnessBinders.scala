package chipyard.fpga.ku040

import chisel3._

import freechips.rocketchip.jtag.{JTAGIO}
import freechips.rocketchip.subsystem.{PeripheryBusKey}
import freechips.rocketchip.tilelink.{TLBundle}
import freechips.rocketchip.diplomacy.{LazyRawModuleImp}
import org.chipsalliance.diplomacy.nodes.{HeterogeneousBag}
import sifive.blocks.devices.uart.{UARTPortIO, UARTParams}
import sifive.fpgashells.shell._
import sifive.fpgashells.ip.xilinx._
import sifive.fpgashells.shell.xilinx._
import sifive.fpgashells.clocks._
import chipyard._
import chipyard.harness._
import chipyard.iobinders._
import testchipip.serdes._

// All pins below sit in bank 68, an HP bank (1.8V max, LVCMOS33 illegal).
// The header must be level-shifted on board if it is 3.3V at the connector,
// as on the Alinx KU040 FMC pins.
//
// UART-TSI is parked on spare bank-68 pins A4/B4 (unconnected for now); the
// PMOD UART pins D3/D4 carry the sifive UART (WithKU040UART below).
class WithKU040UARTTSI(rxdPin: String = "A4", txdPin: String = "B4") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTTSIPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(new UARTPortIO(port.io.uartParams)).suggestName("uart_tsi")
    harnessIO <> port.io.uart
    val packagePinsWithPackageIOs = Seq(
      (rxdPin, IOPin(harnessIO.rxd)),
      (txdPin, IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addIOB(io)
    } }
  }
})

// Maps the sifive UART device to the PMOD UART pins (PMOD2):
//   RX (FPGA in)  - D3
//   TX (FPGA out) - D4
class WithKU040UART(rxdPin: String = "D3", txdPin: String = "D4") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("uart")
    harnessIO <> port.io
    val packagePinsWithPackageIOs = Seq(
      (rxdPin, IOPin(harnessIO.rxd)),
      (txdPin, IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addIOB(io)
    } }
  }
})

// Pin assignments (PMOD1):
//   TCK - E5, TMS - C6, TDI - D5, TDO - D6
class WithKU040JTAG(tckPin: String = "E5", tmsPin: String = "C6",
                    tdiPin: String = "D5", tdoPin: String = "D6") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: JTAGPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(new JTAGChipIO(false)).suggestName("jtag")
    harnessIO.TDO := port.io.TDO
    port.io.TCK := harnessIO.TCK
    port.io.TDI := harnessIO.TDI
    port.io.TMS := harnessIO.TMS
    port.io.reset.foreach(_ := th.referenceReset)

    kth.sdc.addClock("JTCK", IOPin(harnessIO.TCK), 10)
    kth.sdc.addGroup(clocks = Seq("JTCK"))
    // E5 is clock-capable (IO_L13P_GC_QBC_68); kept anyway to match the
    // working Trenz arty100t binder
    kth.xdc.clockDedicatedRouteFalse(IOPin(harnessIO.TCK))
    val packagePinsWithPackageIOs = Seq(
      (tckPin, IOPin(harnessIO.TCK)),
      (tmsPin, IOPin(harnessIO.TMS)),
      (tdiPin, IOPin(harnessIO.TDI)),
      (tdoPin, IOPin(harnessIO.TDO))
    )

    packagePinsWithPackageIOs foreach { case (pin, io) => {
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addPullup(io)
    } }
  }
})
