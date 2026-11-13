# MiniShell – Linux Command Line Shell in C

## 📌 Project Overview

MiniShell is a custom command-line shell developed using C programming in Linux. It provides an interactive environment to execute commands and demonstrates fundamental Linux system programming concepts such as process creation, inter-process communication, signal handling and job control.

The shell provides a custom `msh>` prompt and supports both built-in and external commands.

## 🛠️ Technologies Used

- Programming Language: C
- Operating System: Linux
- System Programming
- Linux System Calls
- Process Management
- Inter-Process Communication (IPC)

## ⚙️ Features

- Custom command-line prompt (`msh>`).
- Execution of built-in and external commands.
- Process creation using `fork()`.
- Program execution using `execvp()`.
- Process synchronization using `waitpid()`.
- Multiple command pipelines using `pipe()` and `dup2()`.
- Signal handling using `SIGINT`, `SIGTSTP` and `SIGCHLD`.
- Background and foreground job management.
- Job control commands:
  - `jobs`
  - `fg`
  - `bg`
- Linked-list-based management of stopped processes.

## 🏗️ Architecture

The shell follows the below execution flow:

1. Read user input.
2. Scan and parse the entered command.
3. Identify whether the command is built-in or external.
4. Execute built-in commands within the shell.
5. Create child processes using `fork()` for external commands.
6. Execute external programs using `execvp()`.
7. Use `waitpid()` to manage foreground process execution.
8. Handle signals and background jobs.

## 📂 Project Structure

```text
MiniShell/
├── main.c
├── scan_input.c
├── get_cmd.c
├── check_cmd_type.c
├── extract_ext_cmd.c
├── execute_internal_cmd.c
├── execute_external_cmd.c
├── n_pipe.c
├── signal.c
├── link_list.c
└── headers.h
```

## 🚀 Compilation and Execution

### Compile

```bash
gcc *.c -o minishell
```

### Run

```bash
./minishell
```

The custom shell prompt will appear:

```text
msh>
```

Enter commands to execute them.

## 📚 Concepts Learned

- Linux process management.
- Process creation and execution.
- Parent-child process relationships.
- Inter-process communication using pipes.
- File descriptor duplication.
- Signal handling.
- Foreground and background processes.
- Job control and process synchronization.
- Dynamic memory management and linked lists.

## 👩‍💻 Author

Sneha B.

C Programming | Linux System Programming | Operating Systems
