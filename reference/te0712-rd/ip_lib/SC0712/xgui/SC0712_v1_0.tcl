# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Settings [ipgui::add_page $IPINST -name "Settings"]
  ipgui::add_param $IPINST -name "MODULE_REVISION" -parent ${Settings} -widget comboBox
  set PROGRAM_PLL [ipgui::add_param $IPINST -name "PROGRAM_PLL" -parent ${Settings} -widget checkBox]
  set_property tooltip {PROGRAM PLL} ${PROGRAM_PLL}


}

proc update_PARAM_VALUE.MODULE_REVISION { PARAM_VALUE.MODULE_REVISION } {
	# Procedure called to update MODULE_REVISION when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.MODULE_REVISION { PARAM_VALUE.MODULE_REVISION } {
	# Procedure called to validate MODULE_REVISION
	return true
}

proc update_PARAM_VALUE.PROGRAM_PLL { PARAM_VALUE.PROGRAM_PLL } {
	# Procedure called to update PROGRAM_PLL when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.PROGRAM_PLL { PARAM_VALUE.PROGRAM_PLL } {
	# Procedure called to validate PROGRAM_PLL
	return true
}


proc update_MODELPARAM_VALUE.MODULE_REVISION { MODELPARAM_VALUE.MODULE_REVISION PARAM_VALUE.MODULE_REVISION } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.MODULE_REVISION}] ${MODELPARAM_VALUE.MODULE_REVISION}
}

proc update_MODELPARAM_VALUE.PROGRAM_PLL { MODELPARAM_VALUE.PROGRAM_PLL PARAM_VALUE.PROGRAM_PLL } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.PROGRAM_PLL}] ${MODELPARAM_VALUE.PROGRAM_PLL}
}

