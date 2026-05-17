# Task and Project Manager

A simple C++17 OOP console application for a school checkpoint project.

## Theme

Task and Project Manager

## OOP Structure

- `WorkItem` is an abstract base class.
- `Project` inherits from `WorkItem`.
- `Task` inherits from `WorkItem`.
- `RecurringTask` inherits from `Task`.
- `Status` and `Priority` are implemented as `enum class`.

## Features

1. Create and display projects.
2. Add normal or recurring tasks to a project.
3. Change task status.
4. Display tasks by priority or status.
5. Detect overdue tasks using `YYYY-MM-DD` string comparison.
6. Show project summary with total, completed, and overdue tasks.

## Compile and Run

Using the Makefile:

```bash
make
./task_manager
```

Or compile manually with g++:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp WorkItem.cpp Task.cpp RecurringTask.cpp Project.cpp -o task_manager
./task_manager
```

On Windows PowerShell, if you compile with g++ manually:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp WorkItem.cpp Task.cpp RecurringTask.cpp Project.cpp -o task_manager.exe
.\task_manager.exe
```

## Note About Dates

Deadlines should be entered in this format:

```text
YYYY-MM-DD
```

This allows simple string comparison to check whether a task is overdue.
