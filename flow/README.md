# RTL to GDSII Flow for RV32I Processor

## Overview
This directory contains scripts to run the complete RTL-to-GDSII flow using open-source EDA tools:
- **Yosys** - RTL Synthesis
- **OpenROAD** - Place & Route (Physical Design)
- **Magic** - Layout viewing/editing
- **STA** - Static Timing Analysis
- **KLayout** - GDSII viewing
- **Netgen** - LVS (Layout vs Schematic)

## Prerequisites
```bash
# In WSL Ubuntu 22.04
sudo apt-get update
sudo apt-get install -y yosys openroad magic sta klayout netgen
```

## PDK Setup (SkyWater 130nm)
```bash
# Install sky130 PDK
git clone https://github.com/google/skywater-pdk.git
cd skywater-pdk
make

# Or use openlane's pre-built PDK
git clone https://github.com/The-OpenROAD-Project/OpenLane.git
cd OpenLane
make pdk
```

## Quick Start - Synthesis Only
```bash
cd flow
yosys -s synth.ys
```

## Full Flow with OpenROAD (requires PDK)
```bash
# Set up environment
export PDK_ROOT=/path/to/pdk
export OPENROAD_FLOW_SCRIPTS=/path/to/OpenROAD-flow-scripts

# Run flow
cd flow
openroad -python openroad_flow.py
```

## Scripts
- `synth.ys` - Yosys synthesis script
- `openroad_flow.tcl` - OpenROAD place & route script
- `run_synth.sh` - Synthesis wrapper
- `run_flow.sh` - Full flow wrapper

## Output Files
- `rv32i_synth.v` - Synthesized netlist
- `rv32i.gds` - Final GDSII layout
- `reports/timing.rpt` - Timing report
- `reports/area.rpt` - Area report
- `reports/power.rpt` - Power report

## Notes
- The RV32I design uses a 10ns clock period (100MHz)
- Pipeline design with 5 stages requires careful CTS
- Data forwarding logic needs proper buffering for timing closure