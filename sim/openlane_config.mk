export DESIGN_NICKNAME = rv32i_pipe
export DESIGN_NAME = rv32i
export PLATFORM    = sky130hd

export VERILOG_FILES = $(sort $(wildcard $(DESIGN_HOME)/src/rv32i_pipe/*.sv))
export SDC_FILE      = $(DESIGN_HOME)/$(PLATFORM)/rv32i_pipe/constraint.sdc

export CORE_UTILIZATION = 40
export PLACE_DENSITY_LB_ADDON = 0.2

export REMOVE_ABC_BUFFERS = 1

export ABSTRACT_GF = 0