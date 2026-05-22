#SD Card SPI
#set_property PACKAGE_PIN W10 [get_ports sclk_o_0]
#set_property IOSTANDARD LVCMOS18 [get_ports sclk_o_0]
#set_property PACKAGE_PIN AA13 [get_ports cs_bo_0]
#set_property PACKAGE_PIN AA10 [get_ports miso_i_0]
#set_property PACKAGE_PIN V10 [get_ports mosi_o_0]
#set_property IOSTANDARD LVCMOS18 [get_ports mosi_o_0]
#set_property IOSTANDARD LVCMOS18 [get_ports miso_i_0]
#set_property IOSTANDARD LVCMOS18 [get_ports cs_bo_0]




# USB FT600

set_property PACKAGE_PIN U20 [get_ports FIFO_CLK]
set_property IOSTANDARD LVCMOS33 [get_ports FIFO_CLK]
#set_property PACKAGE_PIN AM8 [get_ports {FTDI_RESET_N}]
#set_property IOSTANDARD LVCMOS33 [get_ports {FTDI_RESET_N}]
#set_property PACKAGE_PIN AN8 [get_ports {WAKEUP_N}]
#set_property IOSTANDARD LVCMOS33 [get_ports {WAKEUP_N}]

set_property PACKAGE_PIN N15 [get_ports RXF_N]
set_property IOSTANDARD LVCMOS33 [get_ports RXF_N]
set_property PACKAGE_PIN R18 [get_ports TXE_N]
set_property IOSTANDARD LVCMOS33 [get_ports TXE_N]
set_property PACKAGE_PIN P17 [get_ports {BE[0]}]
set_property PACKAGE_PIN R17 [get_ports {BE[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {BE[*]}]
#set_property PACKAGE_PIN W19 [get_ports {SIWU_N}]
#set_property IOSTANDARD LVCMOS33 [get_ports {SIWU_N}]
set_property PACKAGE_PIN T18 [get_ports WR_N]
set_property IOSTANDARD LVCMOS33 [get_ports WR_N]
set_property PACKAGE_PIN B1 [get_ports RD_N]
set_property IOSTANDARD SSTL135 [get_ports RD_N]
set_property PACKAGE_PIN V20 [get_ports OE_N]
set_property IOSTANDARD LVCMOS33 [get_ports OE_N]

set_property PACKAGE_PIN AA21 [get_ports {DATA[0]}]
set_property PACKAGE_PIN AA20 [get_ports {DATA[1]}]
set_property PACKAGE_PIN W22 [get_ports {DATA[2]}]
set_property PACKAGE_PIN W21 [get_ports {DATA[3]}]
set_property PACKAGE_PIN U22 [get_ports {DATA[4]}]
set_property PACKAGE_PIN V22 [get_ports {DATA[5]}]
set_property PACKAGE_PIN T20 [get_ports {DATA[6]}]
set_property PACKAGE_PIN P20 [get_ports {DATA[7]}]
set_property PACKAGE_PIN N13 [get_ports {DATA[8]}]
set_property PACKAGE_PIN N14 [get_ports {DATA[9]}]
set_property PACKAGE_PIN P14 [get_ports {DATA[10]}]
set_property PACKAGE_PIN R14 [get_ports {DATA[11]}]
set_property PACKAGE_PIN P15 [get_ports {DATA[12]}]
set_property PACKAGE_PIN R16 [get_ports {DATA[13]}]
set_property PACKAGE_PIN P16 [get_ports {DATA[14]}]
set_property PACKAGE_PIN N17 [get_ports {DATA[15]}]
set_property IOSTANDARD LVCMOS33 [get_ports {DATA[*]}]


# SYSTEM CENTRIC APPROACH
##create_clock -period 10.000 -name FIFO_CLK_IN [get_ports FIFO_CLK]

########### ft601 spec INPUT
#tsetup  = 3.0
#thold   = 3.5

#tmax <= tclk - tsetup
#tmin >= thold
#assuming clock delay equals data delay path, no adjustment needed for path lengths

##set_input_delay -clock [get_clocks FIFO_CLK_IN] -max 7.000 [get_ports {{BE[*]} {DATA[*]} {TXE_N}}]
##set_input_delay -clock [get_clocks FIFO_CLK_IN] -min 3.5   [get_ports {{BE[*]} {DATA[*]} {TXE_N}}]

########### ft601 spec OUTPUT
#tsetup = 1
#thold  = 4.8

#tracelen: (.5 (data_out_delay) + .5 (clkin_delay)) = 1
#tsu = 2
#tho = 3.8

#tmax < trace_delay_data_max + tsetup - trace_delay_clock_min(vz? = xilinx guide other)
#tmin > trace_delay_data_min - thold  - trace_delay_clock_max(vz? = xiling guide other)

#these are hard to meet see
#https://support.xilinx.com/s/question/0D52E00006hpnBtSAI/sanity-check-of-basic-timing-constraints?language=en_US
#https://support.xilinx.com/s/question/0D52E00006hpmp2SAA/timing-closure-for-sourcesynchronous-highspeed-interface?language=en_US

##set_output_delay -clock [get_clocks FIFO_CLK_IN] -max       2  [get_ports {{BE[*]} {DATA[*]} {WR_N}}]
##set_output_delay -clock [get_clocks FIFO_CLK_IN] -min    -3.8  [get_ports {{BE[*]} {DATA[*]} {WR_N}}]



