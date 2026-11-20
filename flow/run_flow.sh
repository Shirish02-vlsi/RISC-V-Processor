#!/bin/bash
# Complete RTL-to-GDSII Flow for RV32I Processor

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORK_DIR="$SCRIPT_DIR/work_flow"

mkdir -p "$WORK_DIR"
cd "$WORK_DIR"

echo "=== RV32I Complete RTL-to-GDSII Flow ==="
echo "Work Dir: $WORK_DIR"

# Step 1: Synthesis
echo ""
echo "=== Step 1: Synthesis ==="
yosys -s "$SCRIPT_DIR/synth.ys" 2>&1 | tee synth.log
if [ ! -f rv32i_synth.v ]; then
    echo "ERROR: Synthesis failed"
    exit 1
fi
echo "Synthesis complete: rv32i_synth.v"

# Step 2: Check for PDK
if [ -z "$PDK_ROOT" ]; then
    echo ""
    echo "WARNING: PDK_ROOT not set. Skipping physical design."
    echo "To run full flow, set PDK_ROOT to your sky130 PDK path:"
    echo "  export PDK_ROOT=/path/to/skywater-pdk"
    echo ""
    echo "Synthesized netlist available at: $WORK_DIR/rv32i_synth.v"
    exit 0
fi

# Step 3: Physical Design with OpenROAD
echo ""
echo "=== Step 2: Physical Design ==="

# Check for OpenROAD flow scripts
if [ -z "$OPENROAD_FLOW_SCRIPTS" ]; then
    export OPENROAD_FLOW_SCRIPTS="$HOME/OpenROAD-flow-scripts"
fi

if [ ! -d "$OPENROAD_FLOW_SCRIPTS" ]; then
    echo "ERROR: OpenROAD flow scripts not found at $OPENROAD_FLOW_SCRIPTS"
    echo "Clone from: https://github.com/The-OpenROAD-Project/OpenROAD-flow-scripts"
    exit 1
fi

# Create design config for OpenROAD
cat > config.mk << EOF
DESIGN_NAME = rv32i
VERILOG_FILES = $(SCRIPT_DIR)/rv32i_synth.v
CLOCK_PORT = clk
CLOCK_PERIOD = 10.00
DIE_AREA = 0 0 1000 1000
CORE_AREA = 100 100 900 900
PLACE_DENSITY = 0.55
EOF

# Run OpenROAD flow
cd "$OPENROAD_FLOW_SCRIPTS"
make -j$(nproc) DESIGN_CONFIG="$WORK_DIR/config.mk" 2>&1 | tee "$WORK_DIR/openroad.log"

# Step 4: Results
echo ""
echo "=== Flow Complete ==="
echo "Results in: $OPENROAD_FLOW_SCRIPTS/results/$DESIGN_NAME/"
ls -la "$OPENROAD_FLOW_SCRIPTS/results/$DESIGN_NAME/" 2>/dev/null || true