#!/bin/bash
# ============================================================================
# verilator_build.sh - Build Verilator Testbench with Coverage
# ============================================================================

set -e

PROJECT_DIR="/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor"
BUILD_DIR="${PROJECT_DIR}/sim/verilator_build"
RTL_DIR="${PROJECT_DIR}/rtl"
SIM_DIR="${PROJECT_DIR}/sim"

mkdir -p ${BUILD_DIR}

echo "=== Building Verilator Testbench ==="

cd ${BUILD_DIR}

# Build with coverage and tracing (exclude FV wrapper, use SV2012 mode)
# Use system verilator (4.038) with manual coverage
verilator \
    --cc \
    --coverage \
    --trace \
    --language 1800-2012 \
    --top-module rv32i_verilator_tb \
    -I${RTL_DIR} \
    -Wno-WIDTH \
    -Wno-STMTDLY \
    -Wno-CASEINCOMPLETE \
    -Wno-IGNOREDRETURN \
    ${RTL_DIR}/alu.sv \
    ${RTL_DIR}/rf.sv \
    ${RTL_DIR}/ctrl.sv \
    ${RTL_DIR}/imm_gen.sv \
    ${RTL_DIR}/pc.sv \
    ${RTL_DIR}/alu_ctrl.sv \
    ${RTL_DIR}/forward_unit.sv \
    ${RTL_DIR}/hazard_unit.sv \
    ${RTL_DIR}/rv32i.sv \
    ${SIM_DIR}/rv32i_verilator_tb.sv \
    --exe ${SIM_DIR}/verilator_main.cpp \
    -o rv32i_tb \
    -j 2 \
    2>&1 | tee verilator_compile.log

# Build the executable
make -C obj_dir -f Vrv32i_verilator_tb.mk rv32i_tb \
    2>&1 | tee verilator_make.log

echo "=== Build Complete ==="
echo "Executable: ${BUILD_DIR}/obj_dir/rv32i_tb"