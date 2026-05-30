# Task and Project Manager

A simple C++17 OOP console application for managing school projects and tasks.
The program stores data in memory and uses a console menu.

## Checkpoint 2 Functionalities

The current implementation includes:

1. Add projects.
2. Show all projects.
3. Add tasks to a project.
4. Show tasks in a project.
5. Change task status.
6. Filter tasks by priority.
7. Edit a task in a project by task number.
8. Delete a task from a project by task number.
9. Detect overdue tasks using simple `YYYY-MM-DD` date comparison.
10. Show a project summary with:
   - total tasks
   - completed tasks
   - overdue tasks
   - urgent/high priority tasks

No file storage is used for this checkpoint. All data is kept in memory using vectors.
Projects store tasks directly using `std::vector<Task>`.

## Project Structure

```text
oop-task-project-manager/
|-- include/
|   |-- Priority.h
|   |-- Project.h
|   |-- RecurringTask.h
|   |-- Status.h
|   |-- Task.h
|   `-- WorkItem.h
|-- src/
|   |-- main.cpp
|   |-- Project.cpp
|   |-- RecurringTask.cpp
|   |-- Task.cpp
|   `-- WorkItem.cpp
|-- build/
|-- Makefile
`-- README.md
```

## How to Compile

Using the Makefile:

```bash
make
```

Or compile manually with g++:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/WorkItem.cpp src/Task.cpp src/RecurringTask.cpp src/Project.cpp -o build/task_manager
```

On Windows PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/WorkItem.cpp src/Task.cpp src/RecurringTask.cpp src/Project.cpp -o build/task_manager.exe
```

## How to Run

After compiling with the Makefile on Linux/macOS:

```bash
./build/task_manager
```

After compiling manually on Windows PowerShell:

```powershell
.\build\task_manager.exe
```

## OOP Concepts Used

- `WorkItem` is an abstract base class.
- `Project` inherits from `WorkItem`.
- `Task` inherits from `WorkItem`.
- `RecurringTask` inherits from `Task`.
- `Status` and `Priority` are implemented as `enum class`.
- Fields are private or protected where appropriate.
- Public getters and setters are used for controlled access.
- Virtual methods are used for polymorphic behavior.
- Projects store task objects directly in a vector.

## Design Changes

The original design planned more classes and features such as comments, reports,
subtasks, and users. For checkpoint 2, the implementation focuses on the core
class hierarchy and the first working functionalities. These extra features can
be added later.

## Date Format

Deadlines should be entered in this format:

```text
YYYY-MM-DD
```

This allows simple string comparison to check whether a task is overdue.
