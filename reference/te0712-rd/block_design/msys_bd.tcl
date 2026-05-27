catch {TE::UTILS::te_msg TE_BD-0 INFO "This block design tcl-file was generate with Trenz Electronic GmbH Board Part:trenz.biz:te0712_35_2i:part0:1.0, FPGA: xc7a35tfgg484-2 at 2025-04-10T15:08:30."}
catch {TE::UTILS::te_msg TE_BD-1 INFO "This block design tcl-file was modified by TE-Scripts. Modifications are labelled with comment tag  # #TE_MOD# on the Block-Design tcl-file."}

if { ![info exist TE::VERSION_CONTROL] } {
  namespace eval ::TE  {
    set ::TE::VERSION_CONTROL true
  }
}
################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2024.2
set current_vivado_version [version -short ]
if { [string first $scripts_vivado_version $current_vivado_version] == -1 &&  $TE::VERSION_CONTROL } {
   puts ""
   catch {common::send_msg_id "BD_TCL-109" "ERROR" "This script was generated using Vivado < $scripts_vivado_version> and is being run in < $current_vivado_version> of Vivado. Please run the script in Vivado < $scripts_vivado_version> then open the design in Vivado < $current_vivado_version>. Upgrade the design by running "Tools => Report => Report IP Status...", then run write_bd_tcl to create an updated script."}
 return 1
}

################################################################
# This is a generated script based on design: msys
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

namespace eval _tcl {
proc get_script_folder {} {
   set script_path [file normalize [info script]]
   set script_folder [file dirname $script_path]
   return $script_folder
}
}
variable script_folder
set script_folder [_tcl::get_script_folder]

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2024.2
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   common::send_gid_msg -ssname BD::TCL -id 2040 -severity "CRITICAL WARNING" "This script was generated using Vivado <$scripts_vivado_version> without IP versions in the create_bd_cell commands, but is now being run in <$current_vivado_version> of Vivado. There may have been changes to the IP between Vivado <$scripts_vivado_version> and <$current_vivado_version>, which could impact the functionality and configuration of the design."

}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source msys_script.tcl

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xc7a35tfgg484-2
   set_property BOARD_PART trenz.biz:te0712_35_2i:part0:1.0 [current_project]
}


# CHANGE DESIGN NAME HERE
variable design_name
set design_name msys

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      common::send_gid_msg -ssname BD::TCL -id 2001 -severity "INFO" "Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   common::send_gid_msg -ssname BD::TCL -id 2002 -severity "INFO" "Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   common::send_gid_msg -ssname BD::TCL -id 2003 -severity "INFO" "Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   common::send_gid_msg -ssname BD::TCL -id 2004 -severity "INFO" "Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

common::send_gid_msg -ssname BD::TCL -id 2005 -severity "INFO" "Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   catch {common::send_gid_msg -ssname BD::TCL -id 2006 -severity "ERROR" $errMsg}
   return $nRet
}

set bCheckIPsPassed 1
##################################################################
# CHECK IPs
##################################################################
set bCheckIPs 1
if { $bCheckIPs == 1 } {
   set list_check_ips "\ 
trenz.biz:user:SC0712:*\
xilinx.com:ip:axi_ethernetlite:*\
xilinx.com:ip:axi_gpio:*\
xilinx.com:ip:axi_iic:*\
xilinx.com:ip:axi_quad_spi:*\
trenz.biz:user:axi_reg32:*\
xilinx.com:ip:axi_timer:*\
xilinx.com:ip:axi_uartlite:*\
xilinx.com:ip:jtag_axi:*\
trenz.biz:user:labtools_fmeter:*\
xilinx.com:ip:mdm:*\
xilinx.com:ip:microblaze:*\
xilinx.com:ip:axi_intc:*\
xilinx.com:ip:xlconcat:*\
xilinx.com:ip:microblaze_mcs:*\
xilinx.com:ip:mig_7series:*\
xilinx.com:ip:mii_to_rmii:*\
trenz.biz:user:mii_y_adapater:*\
xilinx.com:ip:proc_sys_reset:*\
trenz.biz:user:unio_mac:*\
xilinx.com:ip:util_ds_buf:*\
xilinx.com:ip:vio:*\
xilinx.com:ip:lmb_bram_if_cntlr:*\
xilinx.com:ip:lmb_v10:*\
xilinx.com:ip:blk_mem_gen:*\
"

   set list_ips_missing ""
   common::send_gid_msg -ssname BD::TCL -id 2011 -severity "INFO" "Checking if the following IPs exist in the project's IP catalog: $list_check_ips ."

   foreach ip_vlnv $list_check_ips {
      set ip_obj [get_ipdefs -all $ip_vlnv]
      if { $ip_obj eq "" } {
         lappend list_ips_missing $ip_vlnv
      }
   }

   if { $list_ips_missing ne "" } {
      catch {common::send_gid_msg -ssname BD::TCL -id 2012 -severity "ERROR" "The following IPs are not found in the IP Catalog:\n  $list_ips_missing\n\nResolution: Please add the repository containing the IP(s) to the project." }
      set bCheckIPsPassed 0
   }

}

if { $bCheckIPsPassed != 1 } {
  common::send_gid_msg -ssname BD::TCL -id 2023 -severity "WARNING" "Will not continue with creation of design due to the error(s) above."
  return 3
}

##################################################################
# DESIGN PROCs
##################################################################


# Hierarchical cell: microblaze_0_local_memory
proc create_hier_cell_microblaze_0_local_memory { parentCell nameHier } {

  variable script_folder

  if { $parentCell eq "" || $nameHier eq "" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2092 -severity "ERROR" "create_hier_cell_microblaze_0_local_memory() - Empty argument(s)!"}
     return
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2090 -severity "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2091 -severity "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj

  # Create cell and set as current instance
  set hier_obj [create_bd_cell -type hier $nameHier]
  current_bd_instance $hier_obj

  # Create interface pins
  create_bd_intf_pin -mode MirroredMaster -vlnv xilinx.com:interface:lmb_rtl:1.0 DLMB

  create_bd_intf_pin -mode MirroredMaster -vlnv xilinx.com:interface:lmb_rtl:1.0 ILMB


  # Create pins
  create_bd_pin -dir I -type clk LMB_Clk
  create_bd_pin -dir I -type rst SYS_Rst

  # Create instance: dlmb_bram_if_cntlr, and set properties
  set dlmb_bram_if_cntlr [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_bram_if_cntlr dlmb_bram_if_cntlr ]
  set_property CONFIG.C_ECC {0} $dlmb_bram_if_cntlr


  # Create instance: dlmb_v10, and set properties
  set dlmb_v10 [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_v10 dlmb_v10 ]

  # Create instance: ilmb_bram_if_cntlr, and set properties
  set ilmb_bram_if_cntlr [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_bram_if_cntlr ilmb_bram_if_cntlr ]
  set_property CONFIG.C_ECC {0} $ilmb_bram_if_cntlr


  # Create instance: ilmb_v10, and set properties
  set ilmb_v10 [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_v10 ilmb_v10 ]

  # Create instance: lmb_bram, and set properties
  set lmb_bram [ create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen lmb_bram ]
  set_property -dict [list \
    CONFIG.Memory_Type {True_Dual_Port_RAM} \
    CONFIG.use_bram_block {BRAM_Controller} \
  ] $lmb_bram


  # Create interface connections
  connect_bd_intf_net -intf_net microblaze_0_dlmb [get_bd_intf_pins DLMB] [get_bd_intf_pins dlmb_v10/LMB_M]
  connect_bd_intf_net -intf_net microblaze_0_dlmb_bus [get_bd_intf_pins dlmb_bram_if_cntlr/SLMB] [get_bd_intf_pins dlmb_v10/LMB_Sl_0]
  connect_bd_intf_net -intf_net microblaze_0_dlmb_cntlr [get_bd_intf_pins dlmb_bram_if_cntlr/BRAM_PORT] [get_bd_intf_pins lmb_bram/BRAM_PORTA]
  connect_bd_intf_net -intf_net microblaze_0_ilmb [get_bd_intf_pins ILMB] [get_bd_intf_pins ilmb_v10/LMB_M]
  connect_bd_intf_net -intf_net microblaze_0_ilmb_bus [get_bd_intf_pins ilmb_bram_if_cntlr/SLMB] [get_bd_intf_pins ilmb_v10/LMB_Sl_0]
  connect_bd_intf_net -intf_net microblaze_0_ilmb_cntlr [get_bd_intf_pins ilmb_bram_if_cntlr/BRAM_PORT] [get_bd_intf_pins lmb_bram/BRAM_PORTB]

  # Create port connections
  connect_bd_net -net SYS_Rst_1  [get_bd_pins SYS_Rst] \
  [get_bd_pins dlmb_bram_if_cntlr/LMB_Rst] \
  [get_bd_pins dlmb_v10/SYS_Rst] \
  [get_bd_pins ilmb_bram_if_cntlr/LMB_Rst] \
  [get_bd_pins ilmb_v10/SYS_Rst]
  connect_bd_net -net microblaze_0_Clk  [get_bd_pins LMB_Clk] \
  [get_bd_pins dlmb_bram_if_cntlr/LMB_Clk] \
  [get_bd_pins dlmb_v10/LMB_Clk] \
  [get_bd_pins ilmb_bram_if_cntlr/LMB_Clk] \
  [get_bd_pins ilmb_v10/LMB_Clk]

  # Restore current instance
  current_bd_instance $oldCurInst
}


# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  variable script_folder
  variable design_name

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2090 -severity "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2091 -severity "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports
  set CLK0 [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:diff_clock_rtl:1.0 CLK0 ]

  set DDR3_SDRAM [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:ddrx_rtl:1.0 DDR3_SDRAM ]

  set EEPROM [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:gpio_rtl:1.0 EEPROM ]

  set ETH0_MDIO_MDC [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:mdio_rtl:1.0 ETH0_MDIO_MDC ]

  set IIC_0 [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:iic_rtl:1.0 IIC_0 ]

  set RMII_PHY_M_0 [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:rmii_rtl:1.0 RMII_PHY_M_0 ]

  set UART0 [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:uart_rtl:1.0 UART0 ]

  set mgt_clk0 [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:diff_clock_rtl:1.0 mgt_clk0 ]
  set_property -dict [ list \
   CONFIG.FREQ_HZ {125000000} \
   ] $mgt_clk0

  set qspi_flash [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:spi_rtl:1.0 qspi_flash ]

  set sys_diff_clock [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:diff_clock_rtl:1.0 sys_diff_clock ]
  set_property -dict [ list \
   CONFIG.FREQ_HZ {100000000} \
   ] $sys_diff_clock


  # Create ports
  set CLK1B [ create_bd_port -dir I -from 0 -to 0 -type clk -freq_hz 50000000 CLK1B ]
  set PLL_I2C_ext_scl_o [ create_bd_port -dir O PLL_I2C_ext_scl_o ]
  set PLL_I2C_ext_sda [ create_bd_port -dir IO PLL_I2C_ext_sda ]
  set phy_rst_n [ create_bd_port -dir O phy_rst_n ]
  set reset [ create_bd_port -dir I -type rst reset ]
  set_property -dict [ list \
   CONFIG.POLARITY {ACTIVE_HIGH} \
 ] $reset

  # Create instance: SC0712_0, and set properties
  set SC0712_0 [ create_bd_cell -type ip -vlnv trenz.biz:user:SC0712 SC0712_0 ]
  set_property -dict [list \
    CONFIG.MODULE_REVISION {2} \
    CONFIG.PROGRAM_PLL {1} \
  ] $SC0712_0


  # Create instance: axi_ethernetlite_0, and set properties
  set axi_ethernetlite_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_ethernetlite axi_ethernetlite_0 ]
  set_property -dict [list \
    CONFIG.MDIO_BOARD_INTERFACE {ETH0_MDIO_MDC} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $axi_ethernetlite_0


  # Create instance: axi_gpio_0, and set properties
  set axi_gpio_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio axi_gpio_0 ]
  set_property -dict [list \
    CONFIG.C_ALL_INPUTS {1} \
    CONFIG.C_ALL_INPUTS_2 {1} \
    CONFIG.C_GPIO2_WIDTH {16} \
    CONFIG.C_IS_DUAL {1} \
  ] $axi_gpio_0


  # Create instance: axi_iic_0, and set properties
  set axi_iic_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_iic axi_iic_0 ]

  # Create instance: axi_iic_1, and set properties
  set axi_iic_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_iic axi_iic_1 ]

  # Create instance: axi_interconnect_0, and set properties
  set axi_interconnect_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect axi_interconnect_0 ]
  set_property -dict [list \
    CONFIG.NUM_MI {1} \
    CONFIG.NUM_SI {3} \
    CONFIG.S00_HAS_DATA_FIFO {2} \
    CONFIG.S01_HAS_DATA_FIFO {2} \
    CONFIG.S02_HAS_DATA_FIFO {2} \
    CONFIG.STRATEGY {2} \
  ] $axi_interconnect_0


  # Create instance: axi_interconnect_1, and set properties
  set axi_interconnect_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect axi_interconnect_1 ]
  set_property -dict [list \
    CONFIG.NUM_MI {9} \
    CONFIG.NUM_SI {2} \
    CONFIG.S00_HAS_DATA_FIFO {2} \
    CONFIG.S01_HAS_DATA_FIFO {2} \
    CONFIG.STRATEGY {2} \
  ] $axi_interconnect_1


  # Create instance: axi_quad_spi_0, and set properties
  set axi_quad_spi_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_quad_spi axi_quad_spi_0 ]
  set_property -dict [list \
    CONFIG.QSPI_BOARD_INTERFACE {qspi_flash} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $axi_quad_spi_0

# #TE_MOD# #Empty Line

  # Create instance: axi_reg32_0, and set properties
  set axi_reg32_0 [ create_bd_cell -type ip -vlnv trenz.biz:user:axi_reg32 axi_reg32_0 ]
  set_property -dict [list \
    CONFIG.C_NUM_RO_REG {4} \
    CONFIG.C_NUM_WR_REG {0} \
  ] $axi_reg32_0


  # Create instance: axi_timer_0, and set properties
  set axi_timer_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_timer axi_timer_0 ]

  # Create instance: axi_uartlite_0, and set properties
  set axi_uartlite_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite axi_uartlite_0 ]
  set_property -dict [list \
    CONFIG.UARTLITE_BOARD_INTERFACE {UART0} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $axi_uartlite_0


  # Create instance: jtag_axi_0, and set properties
  set jtag_axi_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:jtag_axi jtag_axi_0 ]

  # Create instance: jtag_axi_1, and set properties
  set jtag_axi_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:jtag_axi jtag_axi_1 ]

  # Create instance: labtools_fmeter_0, and set properties
  set labtools_fmeter_0 [ create_bd_cell -type ip -vlnv trenz.biz:user:labtools_fmeter labtools_fmeter_0 ]

  # Create instance: mdm_1, and set properties
  set mdm_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:mdm mdm_1 ]

  # Create instance: microblaze_0, and set properties
  set microblaze_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:microblaze microblaze_0 ]
  set_property -dict [list \
    CONFIG.C_ADDR_TAG_BITS {16} \
    CONFIG.C_CACHE_BYTE_SIZE {16384} \
    CONFIG.C_DCACHE_ADDR_TAG {16} \
    CONFIG.C_DCACHE_BYTE_SIZE {16384} \
    CONFIG.C_DEBUG_ENABLED {1} \
    CONFIG.C_DIV_ZERO_EXCEPTION {1} \
    CONFIG.C_D_AXI {1} \
    CONFIG.C_D_LMB {1} \
    CONFIG.C_ENABLE_CONVERSION {0} \
    CONFIG.C_ICACHE_LINE_LEN {8} \
    CONFIG.C_ICACHE_STREAMS {1} \
    CONFIG.C_ICACHE_VICTIMS {8} \
    CONFIG.C_ILL_OPCODE_EXCEPTION {1} \
    CONFIG.C_I_LMB {1} \
    CONFIG.C_MMU_ZONES {2} \
    CONFIG.C_M_AXI_D_BUS_EXCEPTION {1} \
    CONFIG.C_M_AXI_I_BUS_EXCEPTION {1} \
    CONFIG.C_OPCODE_0x0_ILLEGAL {1} \
    CONFIG.C_PVR {2} \
    CONFIG.C_UNALIGNED_EXCEPTIONS {1} \
    CONFIG.C_USE_BARREL {1} \
    CONFIG.C_USE_DCACHE {1} \
    CONFIG.C_USE_DIV {1} \
    CONFIG.C_USE_HW_MUL {2} \
    CONFIG.C_USE_ICACHE {1} \
    CONFIG.C_USE_MMU {3} \
    CONFIG.C_USE_MSR_INSTR {1} \
    CONFIG.C_USE_PCMP_INSTR {1} \
    CONFIG.G_TEMPLATE_LIST {4} \
    CONFIG.G_USE_EXCEPTIONS {1} \
  ] $microblaze_0


  # Create instance: microblaze_0_axi_intc, and set properties
  set microblaze_0_axi_intc [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_intc microblaze_0_axi_intc ]
  set_property CONFIG.C_HAS_FAST {1} $microblaze_0_axi_intc


  # Create instance: microblaze_0_local_memory
  create_hier_cell_microblaze_0_local_memory [current_bd_instance .] microblaze_0_local_memory

  # Create instance: microblaze_0_xlconcat, and set properties
  set microblaze_0_xlconcat [ create_bd_cell -type ip -vlnv xilinx.com:ip:xlconcat microblaze_0_xlconcat ]
  set_property CONFIG.NUM_PORTS {6} $microblaze_0_xlconcat


  # Create instance: microblaze_mcs_0, and set properties
  set microblaze_mcs_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:microblaze_mcs microblaze_mcs_0 ]
  set_property -dict [list \
    CONFIG.MEMSIZE {20480} \
    CONFIG.USE_GPI1 {1} \
    CONFIG.USE_GPO1 {1} \
  ] $microblaze_mcs_0


  # Create instance: mig_7series_0, and set properties
  set mig_7series_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:mig_7series mig_7series_0 ]
  set_property CONFIG.BOARD_MIG_PARAM {DDR3_SDRAM} $mig_7series_0


  # Create instance: mii_to_rmii_0, and set properties
  set mii_to_rmii_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:mii_to_rmii mii_to_rmii_0 ]
  set_property CONFIG.RMII_BOARD_INTERFACE {ETH0_RMII} $mii_to_rmii_0


  # Create instance: mii_y_adapater_0, and set properties
  set mii_y_adapater_0 [ create_bd_cell -type ip -vlnv trenz.biz:user:mii_y_adapater mii_y_adapater_0 ]

  # Create instance: proc_sys_reset_0, and set properties
  set proc_sys_reset_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset proc_sys_reset_0 ]
  set_property -dict [list \
    CONFIG.RESET_BOARD_INTERFACE {reset} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $proc_sys_reset_0


  # Create instance: proc_sys_reset_eth, and set properties
  set proc_sys_reset_eth [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset proc_sys_reset_eth ]

  # Create instance: rst_mig_7series_0_100M, and set properties
  set rst_mig_7series_0_100M [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset rst_mig_7series_0_100M ]

  # Create instance: rst_mig_7series_0_50M, and set properties
  set rst_mig_7series_0_50M [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset rst_mig_7series_0_50M ]

  # Create instance: unio_mac_0, and set properties
  set unio_mac_0 [ create_bd_cell -type ip -vlnv trenz.biz:user:unio_mac unio_mac_0 ]

  # Create instance: util_ds_buf_0, and set properties
  set util_ds_buf_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:util_ds_buf util_ds_buf_0 ]
  set_property CONFIG.C_BUF_TYPE {BUFG} $util_ds_buf_0


  # Create instance: util_ds_buf_1, and set properties
  set util_ds_buf_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:util_ds_buf util_ds_buf_1 ]
  set_property -dict [list \
    CONFIG.DIFF_CLK_IN_BOARD_INTERFACE {mgt_clk0} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $util_ds_buf_1


  # Create instance: util_ds_buf_2, and set properties
  set util_ds_buf_2 [ create_bd_cell -type ip -vlnv xilinx.com:ip:util_ds_buf util_ds_buf_2 ]

  # Create instance: xlconcat_0, and set properties
  set xlconcat_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:xlconcat xlconcat_0 ]
  set_property CONFIG.NUM_PORTS {4} $xlconcat_0


  # Create instance: vio_0, and set properties
  set vio_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:vio vio_0 ]
  set_property -dict [list \
    CONFIG.C_NUM_PROBE_IN {8} \
    CONFIG.C_NUM_PROBE_OUT {0} \
  ] $vio_0


  # Create interface connections
  connect_bd_intf_net -intf_net CLK_IN_D_0_1 [get_bd_intf_ports CLK0] [get_bd_intf_pins util_ds_buf_2/CLK_IN_D]
  connect_bd_intf_net -intf_net axi_ethernetlite_0_MDIO [get_bd_intf_ports ETH0_MDIO_MDC] [get_bd_intf_pins axi_ethernetlite_0/MDIO]
  connect_bd_intf_net -intf_net axi_ethernetlite_0_MII [get_bd_intf_pins axi_ethernetlite_0/MII] [get_bd_intf_pins mii_y_adapater_0/S_MII]
  connect_bd_intf_net -intf_net axi_iic_0_IIC [get_bd_intf_pins SC0712_0/EMIO_I2C] [get_bd_intf_pins axi_iic_0/IIC]
  connect_bd_intf_net -intf_net axi_iic_1_IIC [get_bd_intf_ports IIC_0] [get_bd_intf_pins axi_iic_1/IIC]
  connect_bd_intf_net -intf_net axi_interconnect_0_M00_AXI [get_bd_intf_pins axi_interconnect_0/M00_AXI] [get_bd_intf_pins mig_7series_0/S_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M00_AXI [get_bd_intf_pins axi_ethernetlite_0/S_AXI] [get_bd_intf_pins axi_interconnect_1/M00_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M01_AXI [get_bd_intf_pins axi_gpio_0/S_AXI] [get_bd_intf_pins axi_interconnect_1/M01_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M02_AXI [get_bd_intf_pins axi_iic_0/S_AXI] [get_bd_intf_pins axi_interconnect_1/M02_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M03_AXI [get_bd_intf_pins axi_iic_1/S_AXI] [get_bd_intf_pins axi_interconnect_1/M03_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M04_AXI [get_bd_intf_pins axi_interconnect_1/M04_AXI] [get_bd_intf_pins axi_quad_spi_0/AXI_LITE]
  connect_bd_intf_net -intf_net axi_interconnect_1_M05_AXI [get_bd_intf_pins axi_interconnect_1/M05_AXI] [get_bd_intf_pins axi_reg32_0/S_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M06_AXI [get_bd_intf_pins axi_interconnect_1/M06_AXI] [get_bd_intf_pins axi_timer_0/S_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M07_AXI [get_bd_intf_pins axi_interconnect_1/M07_AXI] [get_bd_intf_pins axi_uartlite_0/S_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_1_M08_AXI [get_bd_intf_pins axi_interconnect_1/M08_AXI] [get_bd_intf_pins microblaze_0_axi_intc/s_axi]
  connect_bd_intf_net -intf_net axi_quad_spi_0_SPI_0 [get_bd_intf_ports qspi_flash] [get_bd_intf_pins axi_quad_spi_0/SPI_0]
  connect_bd_intf_net -intf_net axi_uartlite_0_UART [get_bd_intf_ports UART0] [get_bd_intf_pins axi_uartlite_0/UART]
  connect_bd_intf_net -intf_net jtag_axi_0_M_AXI [get_bd_intf_pins axi_interconnect_0/S00_AXI] [get_bd_intf_pins jtag_axi_0/M_AXI]
  connect_bd_intf_net -intf_net jtag_axi_1_M_AXI [get_bd_intf_pins axi_interconnect_1/S01_AXI] [get_bd_intf_pins jtag_axi_1/M_AXI]
  connect_bd_intf_net -intf_net mgt_clk0_1 [get_bd_intf_ports mgt_clk0] [get_bd_intf_pins util_ds_buf_1/CLK_IN_D]
  connect_bd_intf_net -intf_net microblaze_0_M_AXI_DC [get_bd_intf_pins axi_interconnect_0/S01_AXI] [get_bd_intf_pins microblaze_0/M_AXI_DC]
  connect_bd_intf_net -intf_net microblaze_0_M_AXI_DP [get_bd_intf_pins axi_interconnect_1/S00_AXI] [get_bd_intf_pins microblaze_0/M_AXI_DP]
  connect_bd_intf_net -intf_net microblaze_0_M_AXI_IC [get_bd_intf_pins axi_interconnect_0/S02_AXI] [get_bd_intf_pins microblaze_0/M_AXI_IC]
  connect_bd_intf_net -intf_net microblaze_0_debug [get_bd_intf_pins mdm_1/MBDEBUG_0] [get_bd_intf_pins microblaze_0/DEBUG]
  connect_bd_intf_net -intf_net microblaze_0_dlmb_1 [get_bd_intf_pins microblaze_0/DLMB] [get_bd_intf_pins microblaze_0_local_memory/DLMB]
  connect_bd_intf_net -intf_net microblaze_0_ilmb_1 [get_bd_intf_pins microblaze_0/ILMB] [get_bd_intf_pins microblaze_0_local_memory/ILMB]
  connect_bd_intf_net -intf_net microblaze_0_interrupt [get_bd_intf_pins microblaze_0/INTERRUPT] [get_bd_intf_pins microblaze_0_axi_intc/interrupt]
  connect_bd_intf_net -intf_net microblaze_mcs_0_GPIO1 [get_bd_intf_pins SC0712_0/MCS_GPIO] [get_bd_intf_pins microblaze_mcs_0/GPIO1]
  connect_bd_intf_net -intf_net mig_7series_0_DDR3 [get_bd_intf_ports DDR3_SDRAM] [get_bd_intf_pins mig_7series_0/DDR3]
  connect_bd_intf_net -intf_net mii_to_rmii_0_RMII_PHY_M [get_bd_intf_ports RMII_PHY_M_0] [get_bd_intf_pins mii_to_rmii_0/RMII_PHY_M]
  connect_bd_intf_net -intf_net mii_y_adapater_0_M_MII [get_bd_intf_pins mii_to_rmii_0/MII] [get_bd_intf_pins mii_y_adapater_0/M_MII]
  connect_bd_intf_net -intf_net sys_diff_clock_1 [get_bd_intf_ports sys_diff_clock] [get_bd_intf_pins mig_7series_0/SYS_CLK]
  connect_bd_intf_net -intf_net unio_mac_0_SCIO [get_bd_intf_ports EEPROM] [get_bd_intf_pins unio_mac_0/SCIO]

  # Create port connections
  connect_bd_net -net BUFG_I_0_1  [get_bd_ports CLK1B] \
  [get_bd_pins util_ds_buf_0/BUFG_I]
  connect_bd_net -net Net  [get_bd_ports PLL_I2C_ext_sda] \
  [get_bd_pins SC0712_0/ext_sda]
  connect_bd_net -net Net1  [get_bd_pins proc_sys_reset_eth/peripheral_aresetn] \
  [get_bd_pins axi_ethernetlite_0/s_axi_aresetn] \
  [get_bd_pins axi_interconnect_1/M00_ARESETN] \
  [get_bd_pins mii_to_rmii_0/rst_n]
  connect_bd_net -net SC0712_0_ext_scl_o  [get_bd_pins SC0712_0/ext_scl_o] \
  [get_bd_ports PLL_I2C_ext_scl_o]
  connect_bd_net -net SC0712_0_mcs_clk_out  [get_bd_pins SC0712_0/mcs_clk_out] \
  [get_bd_pins microblaze_mcs_0/Clk] \
  [get_bd_pins proc_sys_reset_0/slowest_sync_clk] \
  [get_bd_pins vio_0/clk]
  connect_bd_net -net SC0712_0_mon_GPIO1_I  [get_bd_pins SC0712_0/mon_GPIO1_I] \
  [get_bd_pins vio_0/probe_in7]
  connect_bd_net -net SC0712_0_mon_GPIO1_O  [get_bd_pins SC0712_0/mon_GPIO1_O] \
  [get_bd_pins vio_0/probe_in6]
  connect_bd_net -net SC0712_0_reset_out  [get_bd_pins SC0712_0/reset_out] \
  [get_bd_pins mig_7series_0/sys_rst] \
  [get_bd_pins vio_0/probe_in5]
  connect_bd_net -net axi_ethernetlite_0_ip2intc_irpt  [get_bd_pins axi_ethernetlite_0/ip2intc_irpt] \
  [get_bd_pins microblaze_0_xlconcat/In4]
  connect_bd_net -net axi_iic_0_iic2intc_irpt  [get_bd_pins axi_iic_0/iic2intc_irpt] \
  [get_bd_pins microblaze_0_xlconcat/In3]
  connect_bd_net -net axi_iic_1_iic2intc_irpt  [get_bd_pins axi_iic_1/iic2intc_irpt] \
  [get_bd_pins microblaze_0_xlconcat/In5]
  connect_bd_net -net axi_quad_spi_0_cfgmclk  [get_bd_pins axi_quad_spi_0/cfgmclk] \
  [get_bd_pins SC0712_0/mcs_clk_in]
  connect_bd_net -net axi_quad_spi_0_eos  [get_bd_pins axi_quad_spi_0/eos] \
  [get_bd_pins proc_sys_reset_0/dcm_locked]
  connect_bd_net -net axi_quad_spi_0_ip2intc_irpt  [get_bd_pins axi_quad_spi_0/ip2intc_irpt] \
  [get_bd_pins microblaze_0_xlconcat/In2]
  connect_bd_net -net axi_timer_0_interrupt  [get_bd_pins axi_timer_0/interrupt] \
  [get_bd_pins microblaze_0_xlconcat/In0]
  connect_bd_net -net axi_uartlite_0_interrupt  [get_bd_pins axi_uartlite_0/interrupt] \
  [get_bd_pins microblaze_0_xlconcat/In1]
  connect_bd_net -net fm_mgt_ref  [get_bd_pins labtools_fmeter_0/F1] \
  [get_bd_pins axi_reg32_0/RR1] \
  [get_bd_pins vio_0/probe_in1]
  connect_bd_net -net fm_mig_50mhz  [get_bd_pins labtools_fmeter_0/F0] \
  [get_bd_pins axi_reg32_0/RR0] \
  [get_bd_pins vio_0/probe_in0]
  connect_bd_net -net labtools_fmeter_0_update  [get_bd_pins labtools_fmeter_0/update] \
  [get_bd_pins vio_0/probe_in4]
  connect_bd_net -net lt_CLK0  [get_bd_pins labtools_fmeter_0/F3] \
  [get_bd_pins axi_reg32_0/RR3] \
  [get_bd_pins vio_0/probe_in3]
  connect_bd_net -net lt_CLK1B  [get_bd_pins labtools_fmeter_0/F2] \
  [get_bd_pins axi_reg32_0/RR2] \
  [get_bd_pins vio_0/probe_in2]
  connect_bd_net -net mac_hi  [get_bd_pins unio_mac_0/mac_hi] \
  [get_bd_pins axi_gpio_0/gpio2_io_i]
  connect_bd_net -net mac_lo  [get_bd_pins unio_mac_0/mac_lo] \
  [get_bd_pins axi_gpio_0/gpio_io_i]
  connect_bd_net -net mdm_1_debug_sys_rst  [get_bd_pins mdm_1/Debug_SYS_Rst] \
  [get_bd_pins proc_sys_reset_eth/mb_debug_sys_rst] \
  [get_bd_pins rst_mig_7series_0_100M/mb_debug_sys_rst]
  connect_bd_net -net microblaze_0_Clk  [get_bd_pins mig_7series_0/ui_clk] \
  [get_bd_pins axi_gpio_0/s_axi_aclk] \
  [get_bd_pins axi_iic_0/s_axi_aclk] \
  [get_bd_pins axi_iic_1/s_axi_aclk] \
  [get_bd_pins axi_interconnect_0/ACLK] \
  [get_bd_pins axi_interconnect_0/M00_ACLK] \
  [get_bd_pins axi_interconnect_0/S00_ACLK] \
  [get_bd_pins axi_interconnect_0/S01_ACLK] \
  [get_bd_pins axi_interconnect_0/S02_ACLK] \
  [get_bd_pins axi_interconnect_1/ACLK] \
  [get_bd_pins axi_interconnect_1/M01_ACLK] \
  [get_bd_pins axi_interconnect_1/M02_ACLK] \
  [get_bd_pins axi_interconnect_1/M03_ACLK] \
  [get_bd_pins axi_interconnect_1/M05_ACLK] \
  [get_bd_pins axi_interconnect_1/M06_ACLK] \
  [get_bd_pins axi_interconnect_1/M07_ACLK] \
  [get_bd_pins axi_interconnect_1/M08_ACLK] \
  [get_bd_pins axi_interconnect_1/S00_ACLK] \
  [get_bd_pins axi_interconnect_1/S01_ACLK] \
  [get_bd_pins axi_reg32_0/s_axi_aclk] \
  [get_bd_pins axi_timer_0/s_axi_aclk] \
  [get_bd_pins axi_uartlite_0/s_axi_aclk] \
  [get_bd_pins jtag_axi_0/aclk] \
  [get_bd_pins jtag_axi_1/aclk] \
  [get_bd_pins labtools_fmeter_0/refclk] \
  [get_bd_pins microblaze_0/Clk] \
  [get_bd_pins microblaze_0_axi_intc/processor_clk] \
  [get_bd_pins microblaze_0_axi_intc/s_axi_aclk] \
  [get_bd_pins microblaze_0_local_memory/LMB_Clk] \
  [get_bd_pins rst_mig_7series_0_100M/slowest_sync_clk] \
  [get_bd_pins unio_mac_0/clk]
  connect_bd_net -net microblaze_0_intr  [get_bd_pins microblaze_0_xlconcat/dout] \
  [get_bd_pins microblaze_0_axi_intc/intr]
  connect_bd_net -net mig_7series_0_mmcm_locked  [get_bd_pins mig_7series_0/mmcm_locked] \
  [get_bd_pins proc_sys_reset_eth/dcm_locked] \
  [get_bd_pins rst_mig_7series_0_100M/dcm_locked]
  connect_bd_net -net mig_7series_0_ui_addn_clk_0  [get_bd_pins mig_7series_0/ui_addn_clk_0] \
  [get_bd_pins mig_7series_0/clk_ref_i]
  connect_bd_net -net mig_7series_0_ui_addn_clk_2  [get_bd_pins mig_7series_0/ui_addn_clk_2] \
  [get_bd_pins axi_interconnect_1/M04_ACLK] \
  [get_bd_pins axi_quad_spi_0/ext_spi_clk] \
  [get_bd_pins axi_quad_spi_0/s_axi_aclk] \
  [get_bd_pins rst_mig_7series_0_50M/slowest_sync_clk] \
  [get_bd_pins xlconcat_0/In0]
  connect_bd_net -net mig_7series_0_ui_clk_sync_rst  [get_bd_pins mig_7series_0/ui_clk_sync_rst] \
  [get_bd_pins proc_sys_reset_eth/ext_reset_in] \
  [get_bd_pins rst_mig_7series_0_100M/ext_reset_in] \
  [get_bd_pins rst_mig_7series_0_50M/ext_reset_in]
  connect_bd_net -net mii_y_adapater_0_phy_rst_n  [get_bd_pins mii_y_adapater_0/phy_rst_n] \
  [get_bd_ports phy_rst_n]
  connect_bd_net -net proc_sys_reset_0_mb_reset  [get_bd_pins proc_sys_reset_0/mb_reset] \
  [get_bd_pins microblaze_mcs_0/Reset]
  connect_bd_net -net reset_1  [get_bd_ports reset] \
  [get_bd_pins proc_sys_reset_0/ext_reset_in]
  connect_bd_net -net rst_mig_7series_0_100M_bus_struct_reset  [get_bd_pins rst_mig_7series_0_100M/bus_struct_reset] \
  [get_bd_pins microblaze_0_local_memory/SYS_Rst]
  connect_bd_net -net rst_mig_7series_0_100M_mb_reset  [get_bd_pins rst_mig_7series_0_100M/mb_reset] \
  [get_bd_pins microblaze_0/Reset] \
  [get_bd_pins microblaze_0_axi_intc/processor_rst]
  connect_bd_net -net rst_mig_7series_0_100M_peripheral_aresetn  [get_bd_pins rst_mig_7series_0_100M/peripheral_aresetn] \
  [get_bd_pins axi_gpio_0/s_axi_aresetn] \
  [get_bd_pins axi_iic_0/s_axi_aresetn] \
  [get_bd_pins axi_iic_1/s_axi_aresetn] \
  [get_bd_pins axi_interconnect_0/ARESETN] \
  [get_bd_pins axi_interconnect_0/M00_ARESETN] \
  [get_bd_pins axi_interconnect_0/S00_ARESETN] \
  [get_bd_pins axi_interconnect_0/S01_ARESETN] \
  [get_bd_pins axi_interconnect_0/S02_ARESETN] \
  [get_bd_pins axi_interconnect_1/ARESETN] \
  [get_bd_pins axi_interconnect_1/M01_ARESETN] \
  [get_bd_pins axi_interconnect_1/M02_ARESETN] \
  [get_bd_pins axi_interconnect_1/M03_ARESETN] \
  [get_bd_pins axi_interconnect_1/M05_ARESETN] \
  [get_bd_pins axi_interconnect_1/M06_ARESETN] \
  [get_bd_pins axi_interconnect_1/M07_ARESETN] \
  [get_bd_pins axi_interconnect_1/M08_ARESETN] \
  [get_bd_pins axi_interconnect_1/S00_ARESETN] \
  [get_bd_pins axi_interconnect_1/S01_ARESETN] \
  [get_bd_pins axi_reg32_0/s_axi_aresetn] \
  [get_bd_pins axi_timer_0/s_axi_aresetn] \
  [get_bd_pins axi_uartlite_0/s_axi_aresetn] \
  [get_bd_pins jtag_axi_0/aresetn] \
  [get_bd_pins jtag_axi_1/aresetn] \
  [get_bd_pins microblaze_0_axi_intc/s_axi_aresetn] \
  [get_bd_pins mig_7series_0/aresetn] \
  [get_bd_pins unio_mac_0/rst_n]
  connect_bd_net -net rst_mig_7series_0_50M_peripheral_aresetn  [get_bd_pins rst_mig_7series_0_50M/peripheral_aresetn] \
  [get_bd_pins axi_interconnect_1/M04_ARESETN] \
  [get_bd_pins axi_quad_spi_0/s_axi_aresetn]
  connect_bd_net -net util_ds_buf_0_BUFG_O  [get_bd_pins util_ds_buf_0/BUFG_O] \
  [get_bd_pins axi_ethernetlite_0/s_axi_aclk] \
  [get_bd_pins axi_interconnect_1/M00_ACLK] \
  [get_bd_pins mii_to_rmii_0/ref_clk] \
  [get_bd_pins proc_sys_reset_eth/slowest_sync_clk] \
  [get_bd_pins xlconcat_0/In2]
  connect_bd_net -net util_ds_buf_1_IBUF_OUT  [get_bd_pins util_ds_buf_1/IBUF_OUT] \
  [get_bd_pins xlconcat_0/In1]
  connect_bd_net -net util_ds_buf_2_IBUF_OUT  [get_bd_pins util_ds_buf_2/IBUF_OUT] \
  [get_bd_pins xlconcat_0/In3]
  connect_bd_net -net xlconcat_0_dout  [get_bd_pins xlconcat_0/dout] \
  [get_bd_pins labtools_fmeter_0/fin]

  # Create address segments
  assign_bd_address -offset 0x80000000 -range 0x40000000 -target_address_space [get_bd_addr_spaces jtag_axi_0/Data] [get_bd_addr_segs mig_7series_0/memmap/memaddr] -force
  assign_bd_address -offset 0x40E00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_ethernetlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40000000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_gpio_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40800000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_iic_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40810000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_iic_1/S_AXI/Reg] -force
  assign_bd_address -offset 0x44A00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_quad_spi_0/AXI_LITE/Reg] -force
  assign_bd_address -offset 0x44A10000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_reg32_0/S_AXI/S_AXI_reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x41200000 -range 0x00010000 -target_address_space [get_bd_addr_spaces jtag_axi_1/Data] [get_bd_addr_segs microblaze_0_axi_intc/S_AXI/Reg] -force
  assign_bd_address -offset 0x40E00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_ethernetlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40000000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_gpio_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40800000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_iic_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40810000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_iic_1/S_AXI/Reg] -force
  assign_bd_address -offset 0x44A00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_quad_spi_0/AXI_LITE/Reg] -force
  assign_bd_address -offset 0x44A10000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_reg32_0/S_AXI/S_AXI_reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x00000000 -range 0x00004000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs microblaze_0_local_memory/dlmb_bram_if_cntlr/SLMB/Mem] -force
  assign_bd_address -offset 0x41200000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs microblaze_0_axi_intc/S_AXI/Reg] -force
  assign_bd_address -offset 0x80000000 -range 0x40000000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs mig_7series_0/memmap/memaddr] -force
  assign_bd_address -offset 0x00000000 -range 0x00004000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs microblaze_0_local_memory/ilmb_bram_if_cntlr/SLMB/Mem] -force
  assign_bd_address -offset 0x80000000 -range 0x40000000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs mig_7series_0/memmap/memaddr] -force


  # Restore current instance
  current_bd_instance $oldCurInst

  validate_bd_design
  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""



