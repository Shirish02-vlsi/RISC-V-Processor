# Module Specifications

This document provides detailed specifications for each module in the RV32I processor.

---

## 1. ALU (`alu.sv`)

### Interface
```systemverilog
module alu (
    input  logic [31:0] operand_a,
    input  logic [31:0] operand_b,
    input  logic [3:0]  alu_control,
    output logic [31:0] alu_result,
    output logic        zero_flag
);
```

### Parameters
- **operand_a**: First ALU operand (32 bits)
- **operand_b**: Second ALU operand (32 bits)
- **alu_control**: 4-bit operation selector
- **alu_result**: 32-bit result
- **zero_flag**: High when result == 0

### Operations
| alu_control | Operation | Notes |
|-------------|-----------|-------|
| 4'b0000 | ADD | operand_a + operand_b |
| 4'b0001 | SUB | operand_a - operand_b |
| 4'b0010 | AND | operand_a & operand_b |
| 4'b0011 | OR | operand_a \| operand_b |
| 4'b0100 | XOR | operand_a ^ operand_b |
| 4'b0101 | SLL | operand_a << operand_b[4:0] |
| 4'b0110 | SRL | operand_a >> operand_b[4:0] |
| 4'b0111 | SRA | $signed(operand_a) >>> operand_b[4:0] |
| 4'b1000 | SLT | $signed(operand_a) < $signed(operand_b) |
| 4'b1001 | SLTU | operand_a < operand_b (unsigned) |
| default | 0 | Invalid opcode returns 0 |

### Testbench Coverage
- 25 tests covering all operations, edge cases (overflow, zero, sign extension)

---

## 2. ALU Control (`alu_ctrl.sv`)

### Interface
```systemverilog
module alu_ctrl (
    input  logic [1:0]  alu_op,
    input  logic [2:0]  funct3,
    input  logic [6:0]  funct7,
    output logic [3:0]  alu_control
);
```

### Mapping Table
| alu_op | funct3 | funct7 | Instruction | alu_control |
|--------|--------|--------|-------------|-------------|
| 2'b00 | - | - | LOAD/STORE | 4'b0000 (ADD) |
| 2'b01 | - | - | BRANCH | 4'b0001 (SUB) |
| 2'b10 | 0x0 | 0x00 | ADD | 4'b0000 |
| 2'b10 | 0x0 | 0x20 | SUB | 4'b0001 |
| 2'b10 | 0x1 | 0x00 | SLL | 4'b0101 |
| 2'b10 | 0x2 | 0x00 | SLT | 4'b1000 |
| 2'b10 | 0x3 | 0x00 | SLTU | 4'b1001 |
| 2'b10 | 0x4 | 0x00 | XOR | 4'b0100 |
| 2'b10 | 0x5 | 0x00 | SRL | 4'b0110 |
| 2'b10 | 0x5 | 0x20 | SRA | 4'b0111 |
| 2'b10 | 0x6 | 0x00 | OR | 4'b0011 |
| 2'b10 | 0x7 | 0x00 | AND | 4'b0010 |
| 2'b10 | 0x0 | - | ADDI | 4'b0000 |
| 2'b10 | 0x2 | - | SLTI | 4'b1000 |
| 2'b10 | 0x3 | - | SLTIU | 4'b1001 |
| 2'b10 | 0x4 | - | XORI | 4'b0100 |
| 2'b10 | 0x6 | - | ORI | 4'b0011 |
| 2'b10 | 0x7 | - | ANDI | 4'b0010 |
| 2'b10 | 0x1 | 0x00 | SLLI | 4'b0101 |
| 2'b10 | 0x5 | 0x00 | SRLI | 4'b0110 |
| 2'b10 | 0x5 | 0x20 | SRAI | 4'b0111 |
| default | - | - | - | 4'b0000 |

### Testbench Coverage
- 21 tests covering all valid combinations

---

## 3. Control Unit (`ctrl.sv`)

### Interface
```systemverilog
module ctrl (
    input  logic [6:0] opcode,
    input  logic [2:0] funct3,
    input  logic [6:0] funct7,
    output logic       reg_write,
    output logic       alu_src,
    output logic       mem_write,
    output logic       mem_to_reg,
    output logic       branch,
    output logic       jump,
    output logic [1:0] alu_op
);
```

### Opcode Map
| Instruction | Opcode | reg_write | alu_src | mem_write | mem_to_reg | branch | jump | alu_op |
|-------------|--------|-----------|---------|-----------|------------|--------|------|--------|
| R-TYPE | 0x33 | 1 | 0 | 0 | 0 | 0 | 0 | 2'b10 |
| I-TYPE | 0x13 | 1 | 1 | 0 | 0 | 0 | 0 | 2'b10 |
| LOAD (LW) | 0x03 | 1 | 1 | 0 | 1 | 0 | 0 | 2'b00 |
| STORE (SW) | 0x23 | 0 | 1 | 1 | 0 | 0 | 0 | 2'b00 |
| BRANCH | 0x63 | 0 | 0 | 0 | 0 | 1 | 0 | 2'b01 |
| JAL | 0x6F | 1 | 0 | 0 | 0 | 0 | 1 | 2'b00 |
| JALR | 0x67 | 1 | 1 | 0 | 0 | 0 | 1 | 2'b00 |

### Testbench Coverage
- 6 tests (one per instruction class)

---

## 4. Immediate Generator (`imm_gen.sv`)

### Interface
```systemverilog
module imm_gen (
    input  logic [31:0] instr,
    output logic [31:0] imm
);
```

### Format Extraction
| Type | Opcode | Immediate Construction |
|------|--------|------------------------|
| I | 0x03, 0x13, 0x67 | `{{20{instr[31]}}, instr[31:20]}` |
| S | 0x23 | `{{20{instr[31]}}, instr[31:25], instr[11:7]}` |
| B | 0x63 | `{{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0}` |
| U (LUI) | 0x37 | `{instr[31:12], 12'b0}` |
| U (AUIPC) | 0x17 | `{instr[31:12], 12'b0}` |
| J | 0x6F | `{{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0}` |

All immediates are **sign-extended** to 32 bits.

### Testbench Coverage
- 5 tests (I, S, B, U, J types)

---

## 5. Program Counter (`pc.sv`)

### Interface
```systemverilog
module pc (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] next_pc,
    input  logic        pc_write,
    output logic [31:0] pc
);
```

### Behavior
- **Reset**: PC = 0 on active-low reset
- **Write**: PC = next_pc on posedge clk when pc_write = 1
- **Hold**: PC retains value when pc_write = 0

### Testbench Coverage
- 6 tests (reset, hold, write, multiple writes)

---

## 6. Register File (`rf.sv`)

### Interface
```systemverilog
module rf (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [4:0]  rs1,
    input  logic [4:0]  rs2,
    input  logic [4:0]  rd,
    input  logic [31:0] wr_data,
    input  logic        wr_en,
    output logic [31:0] rs1_data,
    output logic [31:0] rs2_data
);
```

### Features
- **32 registers** (x0-x31), 32 bits each
- **x0 hardwired to 0**: reads return 0, writes ignored
- **2 asynchronous read ports** (combinational)
- **1 synchronous write port** (posedge clk)
- **Active-low reset** clears all registers

### Testbench Coverage
- 41 tests (reset, single/dual write, read, x0, overwrite, write enable, full sweep)

---

## 7. Pipeline Top-Level (`rv32i.sv`)

### Interface
```systemverilog
module rv32i (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] instr_if,
    output logic [31:0] pc_if
);
```

### Pipeline Registers

| Stage | Registers |
|-------|-----------|
| IF/ID | pc[31:0], instr[31:0] |
| ID/EX | pc[31:0], rs1_data[31:0], rs2_data[31:0], imm[31:0], rs1[4:0], rs2[4:0], rd[4:0], funct3[2:0], funct7[6:0], reg_write, alu_src, mem_write, mem_to_reg, branch, jump, alu_op[1:0] |
| EX/MEM | alu_result[31:0], rs2_data[31:0], rd[4:0], reg_write, mem_write, mem_to_reg |
| MEM/WB | alu_result[31:0], rd[4:0], reg_write, mem_to_reg |

### Key Features
- **5-stage pipeline**: IF → ID → EX → MEM → WB
- **Data forwarding**: EX/MEM → EX and MEM/WB → EX
- **Forwarding resolution**: Combinational in EX stage
- **No stalling**: Load-use hazards not yet handled

### Testbench (`rv32i_pipe_tb.sv`)
- Tests: ADDI x1,x0,1; ADDI x2,x0,2; ADDI x3,x0,3; ADD x1,x2,x3
- Verifies: x1=5 (1+2+3 with forwarding), x2=2, x3=3

---

## Testbench Pattern

All testbenches follow this pattern:
```systemverilog
module module_tb;
    // Clock generation
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // DUT instantiation
    module dut (...);

    // Task for checking results
    task check_...;
        total++;
        // stimulus
        #1; // settle
        if (actual !== expected) begin
            $display("FAIL: ...");
            errors++;
        end else begin
            $display("PASS: ...");
        end
    endtask

    initial begin
        // Reset sequence
        // Test sequence with check_... calls
        // Summary
        if (errors == 0)
            $display("=== TEST PASSED: all %0d tests passed ===", total);
        else
            $display("=== TEST FAILED: %0d of %0d checks failed ===", errors, total);
        $finish;
    end
endmodule
```

---

## Running Tests

```bash
# Individual module tests
iverilog -g2012 -o sim/test.vvp rtl/alu.sv sim/alu_tb.sv
vvp sim/test.vvp

# Pipeline integration test
iverilog -g2012 -o sim/test.vvp rtl/*.sv sim/rv32i_pipe_tb.sv
vvp sim/test.vvp
```

---

## Known Issues / TODOs

1. **Load-use hazard**: No stall insertion for LW followed by dependent instruction
2. **Branch hazard**: No flush on branch taken (PC continues sequentially)
3. **Memory interface**: MEM stage pass-through only
4. **JAL/JALR**: Jump targets not implemented in PC logic
5. **CSR/Privilege**: Not implemented