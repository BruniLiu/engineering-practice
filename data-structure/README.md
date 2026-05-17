# Data Structures and C Practice

This module contains C programming exercises for building a reliable foundation in procedural programming, arrays, pointers, linked structures, and algorithmic problem solving.

The emphasis is on writing small programs that are easy to compile, trace, and revise. Each file is intentionally focused on one concept or one exercise pattern.

## Directory Structure

```text
data-structure/
|-- array-algorithm-training-in-c/
|   |-- level1_basic/
|   `-- level2_counting/
|-- final-preparation/
|-- lecture_practice/
`-- test-c-prctice/
```

## Contents

| Folder | Purpose |
| --- | --- |
| `array-algorithm-training-in-c/level1_basic/` | Basic array traversal, summation, minimum search, condition checks |
| `array-algorithm-training-in-c/level2_counting/` | Counting logic, threshold comparison, range calculation |
| `lecture_practice/` | Class practice for arrays, linked lists, and simple structured data |
| `test-c-prctice/` | Dated practice files for short C drills |
| `final-preparation/` | Review exercises for exam preparation |

## Quick Start

Compile and run a single exercise:

```bash
gcc array-algorithm-training-in-c/level1_basic/sum_array.c -o sum_array
./sum_array
```

On Windows PowerShell:

```powershell
gcc array-algorithm-training-in-c\level1_basic\sum_array.c -o sum_array.exe
.\sum_array.exe
```

## Practice Focus

- Reading input safely and validating assumptions.
- Traversing arrays with clear loop invariants.
- Separating computation logic from `main` when useful.
- Understanding pointer behavior through linked list practice.
- Building confidence with small, repeatable exercises before moving into larger implementations.

## File Naming

- Concept exercises use descriptive names such as `sum_array.c` or `count_odds.c`.
- Dated practice files use the `testYYMMDD_N.c` pattern.
- Final review files are grouped alphabetically to match the current preparation sequence.

## Roadmap

- Add stack, queue, tree, and graph implementations.
- Add short complexity notes for each algorithm family.
- Add sample input/output blocks for important exercises.
- Introduce a small test harness for repeatable checks.
