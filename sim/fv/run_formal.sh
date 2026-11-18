#!/bin/bash
# ============================================================================
# run_formal.sh - Run Formal Verification with Yosys SMTBMC
# ============================================================================

set -e

PROJECT_DIR="/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor"
SIM_DIR="${PROJECT_DIR}/sim/fv"

cd ${SIM_DIR}

echo "=== Running Formal Verification ==="

# Run Yosys formal script to generate SMT2 file
yosys formal_simple.ys 2>&1 | tee formal_run.log

# Run BMC (bounded model checking) - 20 cycles
echo "=== Running BMC (20 cycles) ==="
yosys-smtbmc -t 20 -f rv32i.smt2 > bmc_20.log 2>&1

# Run temporal induction - 10 cycles
echo "=== Running Induction (10 cycles) ==="
yosys-smtbmc -i -t 10 -f rv32i.smt2 > induction_10.log 2>&1

# Run cover analysis
echo "=== Running Cover Analysis (20 cycles) ==="
yosys-smtbmc -c -t 20 -f rv32i.smt2 > cover_20.log 2>&1

echo "=== Formal Verification Complete ==="
echo "Logs:"
echo "  - bmc_20.log     : Bounded model check (20 cycles)"
echo "  - induction_10.log : Temporal induction (10 cycles)"
echo "  - cover_20.log   : Coverage analysis (20 cycles)"

# Summary
echo ""
echo "=== Results Summary ==="
for log in bmc_20.log induction_10.log cover_20.log; do
    if [ -f "$log" ]; then
        echo "--- $log ---"
        tail -20 "$log"
    fi
done