# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  ipgui::add_param $IPINST -name "C_TDEST_WIDTH"
  ipgui::add_param $IPINST -name "C_TDEST_VALUE"
  ipgui::add_param $IPINST -name "C_USE_BUFG"
  #Adding Group
  ipgui::add_group $IPINST -name "Delay"


}

proc update_PARAM_VALUE.C_TDEST_VALUE { PARAM_VALUE.C_TDEST_VALUE } {
	# Procedure called to update C_TDEST_VALUE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_TDEST_VALUE { PARAM_VALUE.C_TDEST_VALUE } {
	# Procedure called to validate C_TDEST_VALUE
	return true
}

proc update_PARAM_VALUE.C_TDEST_WIDTH { PARAM_VALUE.C_TDEST_WIDTH } {
	# Procedure called to update C_TDEST_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_TDEST_WIDTH { PARAM_VALUE.C_TDEST_WIDTH } {
	# Procedure called to validate C_TDEST_WIDTH
	return true
}

proc update_PARAM_VALUE.C_USE_BUFG { PARAM_VALUE.C_USE_BUFG } {
	# Procedure called to update C_USE_BUFG when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_USE_BUFG { PARAM_VALUE.C_USE_BUFG } {
	# Procedure called to validate C_USE_BUFG
	return true
}


proc update_MODELPARAM_VALUE.C_TDEST_WIDTH { MODELPARAM_VALUE.C_TDEST_WIDTH PARAM_VALUE.C_TDEST_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_TDEST_WIDTH}] ${MODELPARAM_VALUE.C_TDEST_WIDTH}
}

proc update_MODELPARAM_VALUE.C_TDEST_VALUE { MODELPARAM_VALUE.C_TDEST_VALUE PARAM_VALUE.C_TDEST_VALUE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_TDEST_VALUE}] ${MODELPARAM_VALUE.C_TDEST_VALUE}
}

proc update_MODELPARAM_VALUE.C_USE_BUFG { MODELPARAM_VALUE.C_USE_BUFG PARAM_VALUE.C_USE_BUFG } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_USE_BUFG}] ${MODELPARAM_VALUE.C_USE_BUFG}
}

