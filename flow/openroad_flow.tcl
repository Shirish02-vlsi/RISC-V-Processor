# OpenROAD Flow Script for RV32I Processor
# This is a generic template - needs PDK-specific configuration

# Source the OpenROAD flow setup
source $::env(OPENROAD_FLOW_SCRIPTS)/openroad/common_flow.tcl

# Design configuration
set ::env(DESIGN_NAME) rv32i
set ::env(VERILOG_FILES) [list ../flow/rv32i_synth.v]
set ::env(CLOCK_PORT) clk
set ::env(CLOCK_PERIOD) 10.00

# Floorplan
set ::env(DIE_AREA) "0 0 1000 1000"
set ::env(CORE_AREA) "100 100 900 900"

# Placement
set ::env(PLACE_DENSITY) 0.55

# CTS
set ::env(CTS_BUF_CELL) BUF_X1
set ::env(CTS_ROOT_BUF) BUF_X1

# Routing
set ::env(ROUTING_LAYERS) "metal1 metal2 metal3 metal4 metal5"

# Run the flow
flow_run all

# Reports
report_checks -path_delay min_max -format full -fields {net cap slew input_pins} -digits 4 > reports/timing.rpt
report_checks -path_delay min_max -format full -fields {net cap slew input_pins} -digits 4 -max_paths 100 > reports/timing_full.rpt

# Write final GDS
write_gds -compress rv32i.gds