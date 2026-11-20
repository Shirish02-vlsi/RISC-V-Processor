#!/bin/bash
# Synthesis wrapper script for RV32I Processor

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
RTL_DIR="$SCRIPT_DIR/../rtl"
WORK_DIR="$SCRIPT_DIR/work_synth"

mkdir -p "$WORK_DIR"
cd "$WORK_DIR"

echo "=== RV32I Synthesis with Yosys ==="
echo "RTL Dir: $RTL_DIR"
echo "Work Dir: $WORK_DIR"

# Run Yosys synthesis
yosys -s "$SCRIPT_DIR/synth.ys" 2>&1 | tee synth.log

# Check if synthesis succeeded
if [ -f rv32i_synth.v ]; then
    echo "=== Synthesis SUCCESS ==="
    echo "Output: $WORK_DIR/rv32i_synth.v"
    
    # Show stats
    echo ""
    echo "=== Module Statistics ==="
    yosys -q -p "read_verilog rv32i_synth.v; hierarchy -top rv32i; stat" 2>&1 | grep -A 20 "=== rv32i ==="
else
    echo "=== Synthesis FAILED ==="
    exit 1
fi

# Run quick simulation to verify netlist
echo ""
echo "=== Verifying Netlist with Icarus Verilog ==="
cd "$SCRIPT_DIR"
iverilog -g2012 -o work_synth/tb.vvp \
    work_synth/rv32i_synth.v \
    ../sim/rv32i_pipe_tb.sv \
    2>&1 | grep -E '(error|Error)' || true

vvp work_synth/tb.vvp 2>&1 | tail -20