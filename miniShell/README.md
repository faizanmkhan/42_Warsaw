# 🐚 Minishell

> A minimal Unix shell implementation written in C, developed as part of the **42 School curriculum**.

## 📌 Overview

**Minishell** is a simplified implementation of a Unix shell that replicates core behaviors of `bash`.  
The goal of this project is to gain a deep understanding of:

- Process creation and management
- File descriptors and redirections
- Pipes and inter-process communication
- Command parsing and tokenization
- Environment variables
- Signal handling

This project emphasizes **low-level system programming**, correctness, and robustness.

---

## ✨ Features

- Execution of binaries using `$PATH`
- Built-in commands:
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Environment variable expansion (`$VAR`)
- Input/output redirections:
  - `<`, `>`, `>>`
- Pipes (`|`) for command chaining
- Signal handling:
  - `Ctrl-C`, `Ctrl-D`, `Ctrl-\`
- Proper exit status propagation (`$?`)
- Interactive prompt with command history

---

## 🛠️ Technologies & Concepts

- **Language:** C
- **System Calls:** `fork`, `execve`, `pipe`, `dup2`, `waitpid`
- **Libraries:** `readline`
- **OS Concepts:**
  - Processes
  - File descriptors
  - Signals
  - IPC (Inter-Process Communication)

---

## 🧠 Architecture Overview

The shell follows a **multi-stage pipeline**:


Each stage is isolated and focused on a single responsibility.

---

## 🔍 Parsing & Tokenization

Parsing is one of the most critical parts of Minishell.

### 1️⃣ Lexical Analysis (Lexer)

The lexer converts the raw input string into a sequence of tokens:

- **WORD** (command or argument)
- **PIPE** (`|`)
- **REDIRECTION**
  - Input `<`
  - Output `>`
  - Append `>>`
- **ENVIRONMENT VARIABLE** (`$VAR`)

The lexer:
- Respects **quotes** (`'` and `"`)
- Prevents token splitting inside quoted strings
- Identifies operators even without surrounding spaces

Example:
```bash
echo "hello world" | grep hello > out.txt
