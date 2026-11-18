#!/bin/bash
# ============================================================================
# gen_coverage_report.sh - Generate Coverage Reports
# ============================================================================

set -e

PROJECT_DIR="/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor"
BUILD_DIR="${PROJECT_DIR}/sim/verilator_build/obj_dir"

cd ${BUILD_DIR}

echo "=== Generating Coverage Reports ==="

# Run the testbench (generates coverage.dat)
if [ -f "./rv32i_tb" ]; then
    ./rv32i_tb 2>&1 | tee sim.log
fi

# Generate HTML report
if [ -f "logs/coverage.dat" ]; then
    echo "Generating HTML coverage report..."
    verilator_coverage --annotate logs/coverage.annotated logs/coverage.dat 2>&1 | tee coverage_report.log
    
    # Generate summary
    verilator_coverage --summary logs/coverage.dat 2>&1 | tee coverage_summary.log
    
    echo "=== Coverage Summary ==="
    cat coverage_summary.log
    
    # Line-by-line annotation
    echo "=== Annotated Source ==="
    cat logs/coverage.annotated/rv32i.sv 2>/dev/null | head -100 || true
else
    echo "No coverage.dat found. Run simulation first."
fi