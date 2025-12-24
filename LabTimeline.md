# C Refresher & RISC-V Assembly Programming Module

## Module Overview
This module provides students with a solid refresher in C programming fundamentals before transitioning into RISC-V Assembly language programming and processor development concepts. The progression moves from high-level C concepts down to low-level assembly implementation.

**Prerequisites:** Basic programming experience
**Duration:** 6-8 weeks
**Learning Outcomes:** Students will understand C fundamentals, RISC-V assembly syntax, instruction encoding, and basic processor development principles.

---

## Part I: C Programming Refresher (Weeks 1-2)

### Week 1: C Fundamentals Review

#### 1.1 Memory Management & Pointers
- **Stack vs Heap allocation**
  ```c
  // Stack allocation
  int local_var = 42;
  int array[100];
  
  // Heap allocation
  int *ptr = malloc(sizeof(int) * 100);
  free(ptr);
  ```
- **Pointer arithmetic and dereferencing**
- **Function pointers and callbacks**
- **Common pitfalls:** dangling pointers, memory leaks, buffer overflows

#### 1.2 Data Structures & Arrays
- **Multi-dimensional arrays and memory layout**
- **Structs and unions**
  ```c
  struct Point {
      int x, y;
  };
  
  union Data {
      int i;
      float f;
      char bytes[4];
  };
  ```
- **Bit manipulation and bitwise operations**

#### 1.3 Function Calling Conventions
- **Parameter passing mechanisms**
- **Return values and stack frames**
- **Recursive function implementation**

**Lab 1:** Implement a simple linked list with dynamic memory allocation

### Week 2: Advanced C Concepts

#### 2.1 Compilation Process
- **Preprocessing, compilation, assembly, linking**
- **Object files and executables**
- **Static vs dynamic linking**

#### 2.2 Low-Level Programming
- **Inline assembly in C**
- **Volatile keyword and memory barriers**
- **Hardware interaction through memory-mapped I/O**

#### 2.3 Debugging and Optimization
- **GDB usage for debugging**
- **Compiler optimization levels**
- **Performance profiling basics**

**Lab 2:** Write a C program that interfaces with hardware registers (simulated)

---

## Part II: RISC-V Assembly Fundamentals (Weeks 3-4)

### Week 3: RISC-V Architecture Overview

#### 3.1 RISC-V Philosophy
- **Reduced Instruction Set Computer principles**
- **Open-source ISA benefits**
- **Modular design with base + extensions**

#### 3.2 Register Architecture
- **32 general-purpose registers (x0-x31)**
- **Register naming conventions:**
  ```assembly
  x0  = zero    # Always zero
  x1  = ra      # Return address
  x2  = sp      # Stack pointer
  x3  = gp      # Global pointer
  x4  = tp      # Thread pointer
  x5-x7 = t0-t2 # Temporary registers
  x8  = s0/fp   # Saved register/Frame pointer
  x9  = s1      # Saved register
  x10-x17 = a0-a7 # Argument registers
  x18-x27 = s2-s11 # Saved registers
  x28-x31 = t3-t6  # Temporary registers
  ```

#### 3.3 Memory Model
- **Little-endian byte ordering**
- **Word alignment requirements**
- **Memory segments: text, data, stack, heap**

### Week 4: Basic RISC-V Instructions

#### 4.1 Arithmetic Instructions
```assembly
# R-type instructions
add  rd, rs1, rs2    # rd = rs1 + rs2
sub  rd, rs1, rs2    # rd = rs1 - rs2
and  rd, rs1, rs2    # rd = rs1 & rs2
or   rd, rs1, rs2    # rd = rs1 | rs2
xor  rd, rs1, rs2    # rd = rs1 ^ rs2
sll  rd, rs1, rs2    # rd = rs1 << rs2
srl  rd, rs1, rs2    # rd = rs1 >> rs2 (logical)
sra  rd, rs1, rs2    # rd = rs1 >> rs2 (arithmetic)

# I-type instructions
addi rd, rs1, imm    # rd = rs1 + imm
andi rd, rs1, imm    # rd = rs1 & imm
ori  rd, rs1, imm    # rd = rs1 | imm
xori rd, rs1, imm    # rd = rs1 ^ imm
slli rd, rs1, imm    # rd = rs1 << imm
srli rd, rs1, imm    # rd = rs1 >> imm (logical)
srai rd, rs1, imm    # rd = rs1 >> imm (arithmetic)
```

#### 4.2 Load/Store Instructions
```assembly
# Load instructions
lb   rd, offset(rs1)  # Load byte (sign-extended)
lbu  rd, offset(rs1)  # Load byte unsigned
lh   rd, offset(rs1)  # Load halfword (sign-extended)
lhu  rd, offset(rs1)  # Load halfword unsigned
lw   rd, offset(rs1)  # Load word

# Store instructions
sb   rs2, offset(rs1) # Store byte
sh   rs2, offset(rs1) # Store halfword
sw   rs2, offset(rs1) # Store word
```

#### 4.3 Control Flow Instructions
```assembly
# Branch instructions (B-type)
beq  rs1, rs2, label  # Branch if equal
bne  rs1, rs2, label  # Branch if not equal
blt  rs1, rs2, label  # Branch if less than
bge  rs1, rs2, label  # Branch if greater or equal
bltu rs1, rs2, label  # Branch if less than unsigned
bgeu rs1, rs2, label  # Branch if greater or equal unsigned

# Jump instructions
jal  rd, label        # Jump and link
jalr rd, rs1, offset  # Jump and link register
```

**Lab 3:** Basic arithmetic and control flow programs in RISC-V assembly

---

## Part III: Advanced RISC-V Programming (Week 5)

### 5.1 Function Calling Convention
```assembly
# Function prologue
function_name:
    addi sp, sp, -16    # Allocate stack frame
    sw   ra, 12(sp)     # Save return address
    sw   s0, 8(sp)      # Save frame pointer
    addi s0, sp, 16     # Set new frame pointer

# Function epilogue
    lw   ra, 12(sp)     # Restore return address
    lw   s0, 8(sp)      # Restore frame pointer
    addi sp, sp, 16     # Deallocate stack frame
    jalr zero, ra, 0    # Return
```

### 5.2 Pseudo-instructions and Assembler Directives
```assembly
# Common pseudo-instructions
li   rd, imm          # Load immediate (lui + addi)
la   rd, label        # Load address
mv   rd, rs           # Move (addi rd, rs, 0)
nop                   # No operation (addi x0, x0, 0)

# Assembler directives
.text                 # Code section
.data                 # Data section
.globl main           # Global symbol
.word 0x12345678      # 32-bit data
.byte 0xff            # 8-bit data
.string "Hello"       # String data
```

### 5.3 System Calls and I/O
```assembly
# RISC-V system calls (environment-dependent)
li   a7, 1            # System call number for print integer
li   a0, 42           # Argument
ecall                 # Execute system call

li   a7, 10           # System call number for exit
ecall                 # Exit program
```

**Lab 4:** Implement recursive factorial and Fibonacci functions

---

## Part IV: Instruction Encoding and Processor Concepts (Week 6)

### 6.1 Instruction Formats
```
R-type: [31:25] [24:20] [19:15] [14:12] [11:7] [6:0]
        funct7   rs2     rs1    funct3  rd    opcode

I-type: [31:20] [19:15] [14:12] [11:7] [6:0]
        imm     rs1     funct3  rd     opcode

S-type: [31:25] [24:20] [19:15] [14:12] [11:7] [6:0]
        imm[11:5] rs2   rs1    funct3  imm[4:0] opcode

B-type: [31:25] [24:20] [19:15] [14:12] [11:7] [6:0]
        imm[12,10:5] rs2 rs1   funct3  imm[4:1,11] opcode

U-type: [31:12] [11:7] [6:0]
        imm     rd     opcode

J-type: [31:12] [11:7] [6:0]
        imm     rd     opcode
```

### 6.2 Instruction Decoding Examples
```assembly
# add x1, x2, x3 encoding:
# R-type: funct7=0000000, rs2=x3, rs1=x2, funct3=000, rd=x1, opcode=0110011
# Binary: 00000000001100010000000010110011
# Hex: 0x003100B3

# addi x1, x2, 100 encoding:
# I-type: imm=100, rs1=x2, funct3=000, rd=x1, opcode=0010011
# Binary: 00000110010000010000000010010011
# Hex: 0x06410093
```

### 6.3 Basic Processor Pipeline
- **5-stage pipeline: Fetch, Decode, Execute, Memory, Writeback**
- **Hazards: data, control, structural**
- **Forwarding and stalling mechanisms**

**Lab 5:** Hand-decode RISC-V instructions and understand pipeline behavior

---

## Part V: Practical Applications (Weeks 7-8)

### Week 7: C to Assembly Translation

#### 7.1 Compiler Output Analysis
```c
// C code
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

```assembly
# Corresponding RISC-V assembly
factorial:
    addi sp, sp, -16
    sw   ra, 12(sp)
    sw   s0, 8(sp)
    addi s0, sp, 16
    sw   a0, -12(s0)     # Save parameter n
    
    lw   t0, -12(s0)     # Load n
    li   t1, 1
    bge  t0, t1, .L2     # if (n > 1) goto .L2
    
    li   a0, 1           # Return 1
    j    .L3
    
.L2:
    lw   t0, -12(s0)     # Load n
    addi a0, t0, -1      # n - 1
    call factorial       # Recursive call
    
    lw   t0, -12(s0)     # Load n
    mul  a0, t0, a0      # n * factorial(n-1)
    
.L3:
    lw   ra, 12(sp)
    lw   s0, 8(sp)
    addi sp, sp, 16
    jalr zero, ra, 0
```

#### 7.2 Optimization Techniques
- **Register allocation strategies**
- **Loop unrolling and strength reduction**
- **Common subexpression elimination**

### Week 8: Processor Development Basics

#### 8.1 Simple CPU Design
- **Datapath components: ALU, register file, memory**
- **Control unit design**
- **Single-cycle vs. multi-cycle implementation**

#### 8.2 Performance Considerations
- **CPI (Cycles Per Instruction) analysis**
- **Memory hierarchy impact**
- **Branch prediction basics**

#### 8.3 RISC-V Extensions
- **M extension: Multiplication and division**
- **F/D extensions: Floating-point**
- **Custom extensions for specific applications**

**Final Project:** Implement a simple RISC-V processor simulator or design a custom instruction extension

---

## Assessment Strategy

### Continuous Assessment (60%)
- **Weekly programming labs (40%)**
- **Midterm exam covering C and basic RISC-V (20%)**

### Final Assessment (40%)
- **Final project: Processor simulator or custom extension (25%)**
- **Final exam: Comprehensive RISC-V and processor concepts (15%)**

---

## Required Tools and Resources

### Software Tools
- **GCC RISC-V cross-compiler toolchain**
- **RISC-V simulator (RARS or Venus)**
- **Text editor with assembly syntax highlighting**
- **GDB for debugging**

### Reference Materials
- **RISC-V User-Level ISA Specification**
- **"Computer Organization and Design RISC-V Edition" by Patterson & Hennessy**
- **Online RISC-V assembly reference cards**

### Hardware (Optional)
- **RISC-V development boards (HiFive1, etc.)**
- **FPGA boards for processor implementation**

---

## Additional Learning Resources

### Online Simulators
- **RARS (RISC-V Assembler and Runtime Simulator)**
- **Venus RISC-V simulator**
- **RISC-V Online Assembler**

### Practice Problems
- **Assembly programming challenges**
- **Instruction encoding exercises**
- **Performance analysis case studies**

### Extended Topics (Optional)
- **RISC-V privileged architecture**
- **Operating system interface**
- **Multicore and parallel processing**
- **Hardware-software interface design**