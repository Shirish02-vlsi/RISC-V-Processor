#!/bin/bash
cd /mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor/sim/fv
yosys -p 'read_verilog -sv test_fv.sv; hierarchy -top test_fv; proc; opt; write_smt2 test_fv.smt2; shell "yosys-smtbmc -t 20 -f test_fv.smt2"' 2>&1