#!/bin/bash
# ============================================================================
# run_all_verification.sh - Complete Verification Flow
# ============================================================================
# Runs: Icarus tests -> Formal (Yosys) -> Verilator lint -> Verilator sim + coverage
# ============================================================================

set -e

PROJECT_DIR="/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor"
SIM_DIR="${PROJECT_DIR}/sim"

echo "========================================="
echo "  RV32I Complete Verification Flow"
echo "========================================="

# -------------------------------------------
# 1. Icarus Verilog Tests (existing)
# -------------------------------------------
echo ""
echo "=== [1/4] Icarus Verilog Module Tests ==="
cd ${SIM_DIR}
for tb in alu_tb.sv rf_tb.sv ctrl_tb.sv imm_gen_tb.sv pc_tb.sv alu_ctrl_tb.sv rv32i_pipe_tb.sv; do
    echo "  Testing $tb..."
    iverilog -g2012 -o test.vvp rtl/*.sv ${tb} 2>&1 | grep -v "sorry:"
    vvp test.vvp 2>&1 | grep -E "PASS|FAIL|TEST DONE"
done

# -------------------------------------------
# 2. Formal Verification (Yosys SMTBMC)
# -------------------------------------------
echo ""
echo "=== [2/4] Formal Verification (Yosys SMTBMC) ==="
cd ${SIM_DIR}/fv
./run_formal.sh

# -------------------------------------------
# 3. Verilator Lint
# -------------------------------------------
echo ""
echo "=== [3/4] Verilator Lint ==="
cd ${PROJECT_DIR}
verilator --lint-only -Irtl rtl/*.sv 2>&1 | tee ${SIM_DIR}/verilator_lint.log | grep -E "Error|Warning|%Error" || echo "  No errors found"

# -------------------------------------------
# 4. Verilator Simulation + Coverage
# -------------------------------------------
echo ""
echo "=== [4/4] Verilator Simulation + Coverage ==="
cd ${SIM_DIR}
./verilator_build.sh

# Run coverage simulation
cd ${SIM_DIR}/verilator_build/obj_dir
./rv32i_tb 2>&1 | tee ${SIM_DIR}/verilator_sim.log | grep -E "coverage|PASS|FAIL|Coverage"

# Generate report
cd ${SIM_DIR}
./gen_coverage_report.sh

echo ""
echo "========================================="
echo "  Verification Complete!"
echo "========================================="
echo "Reports available in:"
echo "  - ${SIM_DIR}/fv/bmc_20.log"
echo "  - ${SIM_DIR}/fv/induction_10.log"
echo "  - ${SIM_DIR}/verilator_lint.log"
echo "  - ${SIM_DIR}/verilator_build/obj_dir/logs/coverage.dat"
echo "  - ${SIM_DIR}/verilator_build/obj_dir/logs/coverage.annotated/"