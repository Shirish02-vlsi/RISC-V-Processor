# RV32I Processor Architecture Documentation

## Overview

This document describes the architecture of the RV32I 5-stage pipelined RISC-V processor implemented in SystemVerilog. The processor implements the RV32I base integer instruction set with a classic 5-stage pipeline.

## Pipeline Stages

### 1. IF (Instruction Fetch)
- **Function**: Fetches instruction from instruction memory using PC
- **Registers**: Program Counter (PC)
- **Output**: 32-bit instruction, PC+4
- **Key Logic**: PC increments by 4 each cycle (no branch prediction yet)

### 2. ID (Instruction Decode / Register Fetch)
- **Function**: Decodes instruction, reads register file, generates immediates
- **Operations**:
  - Extracts opcode, funct3, funct7, rs1, rs2, rd fields
  - Reads register file (2 read ports, asynchronous)
  - Control unit decodes opcode to control signals
  - Immediate generator sign-extends immediates (I/S/B/U/J types)
- **Outputs**: Register values, immediate, control signals, register addresses

### 3. EX (Execute)
- **Function**: Performs ALU operations
- **Components**:
  - ALU Control: Maps (alu_op, funct3, funct7) → alu_control
  - ALU: 10 operations (ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU)
  - **Forwarding Unit**: Resolves RAW hazards by forwarding from EX/MEM and MEM/WB
- **Branch Logic**: Evaluates branch conditions (BEQ, BNE, BLT, BGE, BLTU, BGEU)

### 4. MEM (Memory Access)
- **Function**: Data memory access (load/store)
- **Current Status**: Pass-through for simulation (no actual memory)
- **Registers**: alu_result, rs2_data (store data), rd, control signals

### 5. WB (Write Back)
- **Function**: Writes result back to register file
- **Data Source**: ALU result (or memory data for loads)
- **Register File**: 1 write port, synchronous

## Data Forwarding

The processor implements full data forwarding to resolve Read-After-Write (RAW) hazards:

| Forward Path | Source Stage | Destination | Latency |
|--------------|-------------|-------------|---------|
| EX/MEM → EX | ALU Result | ALU Operand | 1 cycle |
| MEM/WB → EX | WB Result | ALU Operand | 2 cycles |

**Forwarding Logic** (in `rv32i.sv` EX stage):
```systemverilog
// Forward A (rs1)
if (reg_write_mem && (rd_mem != 0) && (rd_mem == rs1_ex))
    forward_a = 2'b10;  // From EX/MEM
else if (reg_write_wb && (rd_wb != 0) && (rd_wb == rs1_ex))
    forward_a = 2'b01;  // From MEM/WB
else
    forward_a = 2'b00;  // No forwarding
```

## Control Signals

| Signal | Description | Stages |
|--------|-------------|--------|
| `reg_write` | Enable register write | ID, EX, MEM, WB |
| `alu_src` | ALU operand B select (0=rs2, 1=imm) | ID, EX |
| `mem_write` | Enable data memory write | ID, EX, MEM |
| `mem_to_reg` | WB data select (0=ALU, 1=memory) | ID, EX, MEM, WB |
| `branch` | Branch instruction | ID, EX |
| `jump` | Jump instruction (JAL/JALR) | ID, EX |
| `alu_op` | ALU operation selector (2 bits) | ID, EX |

## Instruction Set Support

### R-Type (Register-Register)
| Instruction | Opcode | funct3 | funct7 | Operation |
|-------------|--------|--------|--------|-----------|
| ADD | 0x33 | 0x0 | 0x00 | rd = rs1 + rs2 |
| SUB | 0x33 | 0x0 | 0x20 | rd = rs1 - rs2 |
| SLL | 0x33 | 0x1 | 0x00 | rd = rs1 << rs2[4:0] |
| SLT | 0x33 | 0x2 | 0x00 | rd = (rs1 < rs2) ? 1 : 0 |
| SLTU | 0x33 | 0x3 | 0x00 | rd = (rs1 < rs2) ? 1 : 0 (unsigned) |
| XOR | 0x33 | 0x4 | 0x00 | rd = rs1 ^ rs2 |
| SRL | 0x33 | 0x5 | 0x00 | rd = rs1 >> rs2[4:0] |
| SRA | 0x33 | 0x5 | 0x20 | rd = $signed(rs1) >>> rs2[4:0] |
| OR | 0x33 | 0x6 | 0x00 | rd = rs1 \| rs2 |
| AND | 0x33 | 0x7 | 0x00 | rd = rs1 & rs2 |

### I-Type (Immediate Arithmetic/Loads/JALR)
| Instruction | Opcode | funct3 | Operation |
|-------------|--------|--------|-----------|
| ADDI | 0x13 | 0x0 | rd = rs1 + imm |
| SLTI | 0x13 | 0x2 | rd = (rs1 < imm) ? 1 : 0 |
| SLTIU | 0x13 | 0x3 | rd = (rs1 < imm) ? 1 : 0 (unsigned) |
| XORI | 0x13 | 0x4 | rd = rs1 ^ imm |
| ORI | 0x13 | 0x6 | rd = rs1 \| imm |
| ANDI | 0x13 | 0x7 | rd = rs1 & imm |
| SLLI | 0x13 | 0x1 | rd = rs1 << shamt |
| SRLI | 0x13 | 0x5 | rd = rs1 >> shamt (funct7=0) |
| SRAI | 0x13 | 0x5 | rd = $signed(rs1) >>> shamt (funct7=0x20) |
| LW | 0x03 | 0x2 | rd = mem[rs1 + imm] |
| JALR | 0x67 | 0x0 | rd = PC+4; PC = (rs1 + imm) & ~1 |

### S-Type (Stores)
| Instruction | Opcode | funct3 | Operation |
|-------------|--------|--------|-----------|
| SW | 0x23 | 0x2 | mem[rs1 + imm] = rs2 |

### B-Type (Branches)
| Instruction | Opcode | funct3 | Operation |
|-------------|--------|--------|-----------|
| BEQ | 0x63 | 0x0 | PC = PC + imm if rs1 == rs2 |
| BNE | 0x63 | 0x1 | PC = PC + imm if rs1 != rs2 |
| BLT | 0x63 | 0x4 | PC = PC + imm if rs1 < rs2 (signed) |
| BGE | 0x63 | 0x5 | PC = PC + imm if rs1 >= rs2 (signed) |
| BLTU | 0x63 | 0x6 | PC = PC + imm if rs1 < rs2 (unsigned) |
| BGEU | 0x63 | 0x7 | PC = PC + imm if rs1 >= rs2 (unsigned) |

### U-Type (Upper Immediates)
| Instruction | Opcode | Operation |
|-------------|--------|-----------|
| LUI | 0x37 | rd = imm << 12 |
| AUIPC | 0x17 | rd = PC + (imm << 12) |

### J-Type (Jumps)
| Instruction | Opcode | Operation |
|-------------|--------|-----------|
| JAL | 0x6F | rd = PC+4; PC = PC + imm |

## Register File

- **32 registers** (x0-x31), each 32 bits
- **x0 hardwired to zero**: reads return 0, writes ignored
- **2 read ports** (asynchronous), **1 write port** (synchronous, posedge clk)
- **Reset**: All registers cleared to 0 on active-low reset

## Immediate Formats

| Type | Bits | Format |
|------|------|--------|
| I | 12 | `instr[31:20]` |
| S | 12 | `instr[31:25], instr[11:7]` |
| B | 13 | `instr[31], instr[7], instr[30:25], instr[11:8], 1'b0` |
| U | 20 | `instr[31:12], 12'b0` |
| J | 21 | `instr[31], instr[19:12], instr[20], instr[30:21], 1'b0` |

All immediates are **sign-extended** to 32 bits.

## ALU Operations

| alu_control | Operation | Description |
|-------------|-----------|-------------|
| 4'b0000 | ADD | operand_a + operand_b |
| 4'b0001 | SUB | operand_a - operand_b |
| 4'b0010 | AND | operand_a & operand_b |
| 4'b0011 | OR | operand_a \| operand_b |
| 4'b0100 | XOR | operand_a ^ operand_b |
| 4'b0101 | SLL | operand_a << operand_b[4:0] |
| 4'b0110 | SRL | operand_a >> operand_b[4:0] |
| 4'b0111 | SRA | $signed(operand_a) >>> operand_b[4:0] |
| 4'b1000 | SLT | (signed) a < b ? 1 : 0 |
| 4'b1001 | SLTU | (unsigned) a < b ? 1 : 0 |

## Pipeline Register Structure

```
IF/ID:  pc[31:0], instr[31:0]                    (64 bits)
ID/EX:  pc[31:0], rs1_data[31:0], rs2_data[31:0], imm[31:0],
        rs1[4:0], rs2[4:0], rd[4:0], funct3[2:0], funct7[6:0],
        reg_write, alu_src, mem_write, mem_to_reg, branch, jump, alu_op[1:0]  (156 bits)
EX/MEM: alu_result[31:0], rs2_data[31:0], rd[4:0],
        reg_write, mem_write, mem_to_reg                              (74 bits)
MEM/WB: alu_result[31:0], rd[4:0], reg_write, mem_to_reg              (39 bits)
```

## Verification

All modules include self-checking testbenches:
- **ALU**: 25 tests (arithmetic, logic, shifts, comparisons)
- **Register File**: 41 tests (reset, read/write, x0, sweep)
- **Control Unit**: 6 tests (all instruction types)
- **Immediate Generator**: 5 tests (I, S, B, U, J formats)
- **Program Counter**: 6 tests (reset, hold, write)
- **ALU Control**: 21 tests (all op/funct combinations)
- **Pipeline Integration**: 3 tests (ADDI sequence + ADD with forwarding)

## Known Limitations

1. **No hazard stalling**: Load-use hazards not handled (would need bubble insertion)
2. **No branch prediction**: PC always increments by 4
3. **No memory interface**: MEM stage is pass-through for simulation
4. **No exceptions/interrupts**: Not implemented
5. **No CSR support**: Control and Status Registers not implemented

## Future Enhancements

1. Add hazard detection unit for load-use stalls
2. Implement branch prediction (static or dynamic)
3. Add data/instruction memory interfaces
4. Implement CSR unit for privileged mode
5. Add interrupt/exception handling
6. Implement RV32M (multiply/divide) extension