# RISC-V Performance Analyzer

A terminal-based static analysis tool for RISC-V assembly programs. Reads `.asm` files and reports instruction mix, cycle counts, and CPI (Cycles Per Instruction).

Built with C++ as a Computer Organization course final project.

---

## Features

- Parses RISC-V assembly files line by line
- Classifies instructions into 5 types: Arithmetic, Logical, Memory, Branch, Other
- Calculates total cycle count using a predefined CPI table
- Reports instruction mix with percentages
- Reports average CPI

---

## CPI Table

| Instruction Type | Examples | Cycles |
|---|---|---|
| Arithmetic | add, addi, sub, mul, mv | 1 |
| Logical | and, or, xor, sll, srl | 1 |
| Memory | lw, sw, lb, sb, ld, sd | 2 |
| Branch | beq, bne, bge, jal, ret | 3 |
| Other | — | 1 |

---

## Build & Run

Open the project in Xcode and build with ⌘B, or compile manually:

```bash
g++ -o RiscVAnalyzer main.cpp
```

Run with an assembly file as argument:

```bash
./RiscVAnalyzer path/to/program.asm
```

---

## Example Output

```
===== INSTRUCTION MIX =====
Total instruction: 19

ARITHMETIC: 8 piece (42%)
BRANCH: 6 piece (31%)
LOGICAL: 1 piece (5%)
MEMORY: 4 piece (21%)

===== CPI SUMMARY =====
Total cycle : 35
Average CPI : 1.84
=====================
```

---

## Test Files

Three sample programs are included for testing:

| File | Description | Characteristic |
|---|---|---|
| `fibonacci.asm` | Calculates nth Fibonacci number | Arithmetic-heavy |
| `bubble_sort.asm` | Sorts an array using bubble sort | Memory + Branch heavy |
| `linear_search.asm` | Searches for a value in an array | Branch-heavy |

---

## Sample Benchmark

| Program | Instructions | Arithmetic | Branch | Memory | Avg CPI |
|---|---|---|---|---|---|
| fibonacci | 12 | 75% | 25% | 0% | 1.50 |
| linear_search | 14 | 50% | 35% | 7% | 1.79 |
| bubble_sort | 19 | 42% | 31% | 21% | 1.84 |

Bubble sort has the highest CPI because of frequent memory accesses (lw/sw for swapping) and backward branches (loops), which are the most expensive instruction types.

---

## Project Structure

```
RiscVAnalyzer/
├── main.cpp          # Entry point — parsing, classification, output
├── fibonacci.asm     # Test file 1
├── bubble_sort.asm   # Test file 2
├── linear_search.asm # Test file 3
└── README.md
```

---

## Course Info

**Course:** Computer Organization  
**Language:** C++  
**Platform:** macOS / Xcode  
**Author:** Zelal Aydın
