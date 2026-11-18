# RV32I Processor - Command Manual

## Quick Start

```bash
# Enter WSL Ubuntu
wsl.exe -d Ubuntu-22.04

# Navigate to project
cd /mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor

# Run pipeline integration test (verifies forwarding works)
iverilog -g2012 -o sim/test.vvp rtl/*.sv sim/rv32i_pipe_tb.sv && vvp sim/test.vvp
```

---

## Simulation Commands

### 1. Individual Module Tests

```bash
# ALU (25 tests)
iverilog -g2012 -o sim/test.vvp rtl/alu.sv sim/alu_tb.sv && vvp sim/test.vvp

# Register File (41 tests)
iverilog -g2012 -o sim/test.vvp rtl/rf.sv sim/rf_tb.sv && vvp sim/test.vvp

# Control Unit (6 tests)
iverilog -g2012 -o sim/test.vvp rtl/ctrl.sv sim/ctrl_tb.sv && vvp sim/test.vvp

# Immediate Generator (5 tests)
iverilog -g2012 -o sim/test.vvp rtl/imm_gen.sv sim/imm_gen_tb.sv && vvp sim/test.vvp

# Program Counter (6 tests)
iverilog -g2012 -o sim/test.vvp rtl/pc.sv sim/pc_tb.sv && vvp sim/test.vvp

# ALU Control (21 tests)
iverilog -g2012 -o sim/test.vvp rtl/alu_ctrl.sv sim/alu_ctrl_tb.sv && vvp sim/test.vvp
```

### 2. Pipeline Integration Test

```bash
# Full 5-stage pipeline with forwarding (3 tests)
iverilog -g2012 -o sim/test.vvp rtl/*.sv sim/rv32i_pipe_tb.sv && vvp sim/test.vvp
```

### 3. Run All Tests (Bash One-Liner)

```bash
for f in sim/*_tb.sv; do
  echo "=== Testing $f ==="
  iverilog -g2012 -o sim/test.vvp rtl/*.sv "$f" 2>&1 | grep -E '(error|Error)'
  vvp sim/test.vvp
  echo ""
done
```

---

## Waveform Generation & Analysis

### 1. Generate VCD Waveform

```bash
# Compile with VCD dump support
iverilog -g2012 -o sim/test.vvp rtl/*.sv sim/rv32i_pipe_tb.sv

# Run simulation with VCD output
vvp sim/test.vvp +vcd=sim/waveform.vcd
```

**Note**: Testbenches need `$dumpfile` and `$dumpvars` added. Add to any testbench:

```systemverilog
initial begin
    $dumpfile("sim/waveform.vcd");
    $dumpvars(0, module_tb);  // or dut instance name
    // ... rest of testbench
end
```

### 2. View Waveforms

#### GTKWave (Linux/WSL)
```bash
# Install
sudo apt-get install gtkwave

# Open waveform
gtkwave sim/waveform.vcd
```

#### VS Code + WaveTrace (Recommended for Windows)
1. Install "WaveTrace" extension in VS Code
2. Right-click `waveform.vcd` → "Open with WaveTrace"

#### Surfer (CLI Waveform Viewer)
```bash
# Install
cargo install surfer

# View in terminal
surfer sim/waveform.vcd
```

---

## Debugging Commands

### 1. Verbose Compilation (See All Warnings)
```bash
iverilog -g2012 -Wall -o sim/test.vvp rtl/*.sv sim/rv32i_pipe_tb.sv
```

### 2. Syntax Check Only (No Simulation)
```bash
iverilog -g2012 -tnull rtl/*.sv sim/rv32i_pipe_tb.sv
```

### 3. Debug Specific Module with VCD
```bash
# Example: ALU with waveforms
iverilog -g2012 -o sim/alu_debug.vvp rtl/alu.sv sim/alu_tb.sv
vvp sim/alu_debug.vvp +vcd=sim/alu_wave.vcd
gtkwave sim/alu_wave.vcd
```

---

## Common Tasks

### Add a New Test Case
1. Edit the relevant `sim/*_tb.sv`
2. Add a new `check_...` call in the `initial` block
3. Run: `iverilog -g2012 -o sim/test.vvp rtl/<module>.sv sim/<module>_tb.sv && vvp sim/test.vvp`

### Modify Pipeline Test Program
Edit `sim/rv32i_pipe_tb.sv`:
```systemverilog
imem[0] = 32'h00100093;  // ADDI x1, x0, 1
imem[1] = 32'h00200113;  // ADDI x2, x0, 2
// ... add more instructions
```

### Check Synthesis (Lint)
```bash
# Basic lint with iverilog
iverilog -g2012 -Wall -tnull rtl/*.sv

# With Verilator (if installed)
verilator --lint-only -Wall rtl/*.sv
```

---

## File Reference

| File | Purpose |
|------|---------|
| `rtl/alu.sv` | ALU implementation |
| `rtl/alu_ctrl.sv` | ALU control decoder |
| `rtl/ctrl.sv` | Main control unit |
| `rtl/forward_unit.sv` | Data forwarding logic |
| `rtl/hazard_unit.sv` | Hazard detection (stub) |
| `rtl/imm_gen.sv` | Immediate generator |
| `rtl/pc.sv` | Program counter |
| `rtl/rf.sv` | Register file |
| `rtl/rv32i.sv` | 5-stage pipeline top-level |
| `sim/*_tb.sv` | Self-checking testbenches |

---

## Troubleshooting

| Issue | Fix |
|-------|-----|
| `constant selects in always_*` warning | Harmless iverilog limitation; logic is correct |
| `Wildcard port connection` error | Update testbench to match module port names |
| Simulation hangs | Check for missing `@(posedge clk)` or infinite loop |
| VCD not generated | Add `$dumpfile`/`$dumpvars` to testbench |
| Module not found | Ensure all `rtl/*.sv` included in compile command |

---

## PowerShell Shortcuts (Windows)

```powershell
# Run pipeline test from PowerShell
wsl.exe -d Ubuntu-22.04 bash -c "cd /mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor && iverilog -g2012 -o sim/test.vvp rtl/*.sv sim/rv32i_pipe_tb.sv && vvp sim/test.vvp"

# Run all tests
wsl.exe -d Ubuntu-22.04 bash -c "cd /mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor && for f in sim/*_tb.sv; do echo \"=== \$f ===\"; iverilog -g2012 -o sim/test.vvp rtl/*.sv \"\$f\" 2>&1 | grep -E '(error|Error)'; vvp sim/test.vvp; done"
```

---

## Waveform Signals of Interest

For pipeline analysis in GTKWave, add these signals:
```
dut.pc_if
dut.pc_id, dut.instr_id
dut.rs1_data_ex, dut.rs2_data_ex, dut.imm_ex
dut.alu_result_ex_int
dut.alu_result_mem
dut.alu_result_wb
dut.reg_write_ex, dut.reg_write_mem, dut.reg_write_wb
dut.forward_a, dut.forward_b
dut.rf_inst.registers[1], dut.rf_inst.registers[2], dut.rf_inst.registers[3]
```

---

*Last Updated: 2026 - RV32I 5-Stage Pipeline*