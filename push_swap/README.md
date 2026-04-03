# 🔢 Push Swap


*Sort smarter, not harder.*

A custom algorithmic sorting project written in **C**, developed as part of the **42 School curriculum**. The goal is to sort a stack of integers using a limited set of operations with the **lowest possible number of moves**.

---

## 📌 Overview

Push Swap challenges you to implement an efficient sorting algorithm under strict constraints:

- Two stacks: **A** and **B**
- A limited set of allowed operations
- Optimize for the **minimum number of instructions**

This project emphasizes algorithm design, optimization, and complexity analysis.

---

## 🚀 Features

### Mandatory
- Sort integers using only allowed operations
- Handle multiple input formats
- Error management (duplicates, invalid input)
- Efficient algorithm for large datasets

### Bonus
- Checker program to validate operations
- Visualizer compatibility
- Advanced optimizations for move reduction

---

## 🧠 Allowed Operations

### Swap
```
sa  -> swap top two elements of stack A
sb  -> swap top two elements of stack B
ss  -> sa and sb at the same time
```

### Push
```
pa  -> push top element from B to A
pb  -> push top element from A to B
```

### Rotate
```
ra  -> shift all elements of A up by 1
rb  -> shift all elements of B up by 1
rr  -> ra and rb at the same time
```

### Reverse Rotate
```
rra -> shift all elements of A down by 1
rrb -> shift all elements of B down by 1
rrr -> rra and rrb at the same time
```

---

## ⚙️ Algorithm Strategy

Different strategies can be used depending on input size:

### Small Inputs (≤ 5)
- Hardcoded optimal solutions
- Minimal moves using simple comparisons

### Medium / Large Inputs
- **Indexing / Normalization** (map values to ranks)
- **Radix Sort (Binary)**
- Chunk-based sorting
- Greedy insertion strategies

---

## 🛠️ Installation

### Requirements
- GCC
- Make

### Clone Repository
```
git clone https://github.com/faizanmkhan/42_Warsaw.git
cd 42_Warsaw/push_swap
```

### Compile
```
make
```

---

## ▶️ Usage

### Run push_swap
```
./push_swap 3 2 1 6 5 8
```

### Example Output
```
pb
pb
sa
pa
pa
```

---

## 🧪 Checker (Bonus)

### Run checker
```
./checker 3 2 1
```

Provide instructions via stdin:
```
pb
pb
sa
pa
pa
```

### Output
```
OK
```
or
```
KO
```

---

## 🧱 Project Structure

```
push_swap/
├── src/
│   ├── main.c
│   ├── parse.c
│   ├── operations.c
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   ├── reverse_rotate.c
│   ├── radix_sort.c
│   └── utils.c
├── include/
│   └── push_swap.h
├── libft/
├── Makefile
└── README.md
```

---

## ⚡ Performance Goals

Typical evaluation benchmarks:

| Input Size | Target Moves |
|------------|-------------|
| 3 numbers  | ≤ 3 moves   |
| 5 numbers  | ≤ 12 moves  |
| 100 nums   | ≤ 700 moves |
| 500 nums   | ≤ 5500 moves|

---

## 🧠 Key Concepts

- Stack data structures
- Sorting algorithms
- Time complexity (O(n log n), O(n))
- Memory management in C
- Optimization under constraints

---

## 📈 Learning Outcomes

- Algorithm optimization mindset
- Writing efficient and clean C code
- Debugging complex logic
- Handling edge cases



