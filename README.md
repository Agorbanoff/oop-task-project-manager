# Task and Project Manager

A simple C++17 OOP console application for managing projects and tasks.
The program uses a console menu and keeps all data in memory.

## Working Functionalities

1. Add a project.
2. Show all projects.
3. Edit a project's title, description, deadline, and status.
4. Delete a project by project number.
5. Add a normal task to a selected project.
6. Add a recurring task with recurrence rule and next occurrence date.
7. Show all tasks in a selected project.
8. Change a task's status.
9. Filter tasks by priority.
10. Filter tasks by tag.
11. Search tasks by title using partial match.
12. Edit a task's title, description, deadline, priority, and assignee.
13. Delete a task by task number.
14. Detect overdue tasks using simple `YYYY-MM-DD` string comparison.
15. Show project summary with total, completed, overdue, and high priority tasks.

No file storage is used. Data is stored only while the program is running.

## OOP Concepts Used

- Inheritance: `Project` and `Task` inherit from `WorkItem`, and `RecurringTask` inherits from `Task`.
- Abstract class: `WorkItem` is abstract because it has a pure virtual `display()` method.
- Encapsulation: class fields are private or protected, with public getters and setters where needed.
- `enum class`: `Status` and `Priority` are implemented as strongly typed enums.
- Virtual methods: `display()` is virtual and overridden in child classes.
- Composition: `Project` contains task objects using vectors.

## File Structure

The project uses separate files for the main classes. Header files are in `include/`,
and implementation files are in `src/`.

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
|-- .gitignore
`-- README.md
```

- `WorkItem` contains common fields and abstract behavior.
- `Task` contains task-specific data such as priority, assignee, and tags.
- `RecurringTask` extends `Task` with recurrence details.
- `Project` contains and manages tasks.
- `main.cpp` contains the console menu.

## How to Compile

Using the Makefile:

```bash
make
```

Manual compile command:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/WorkItem.cpp src/Task.cpp src/RecurringTask.cpp src/Project.cpp -o build/task_manager.exe
```

## How to Run

On Windows PowerShell:

```powershell
.\build\task_manager.exe
```

On Linux/macOS, if compiled without `.exe`:

```bash
./build/task_manager
```

## Design Changes

The original design planned more advanced features such as comments, reports,
subtasks, and users. For the final checkpoint, the implementation focuses on
the required class hierarchy and working console functionalities.

Smart pointers were removed because they are not required for this checkpoint
and have not been studied yet. The implementation now uses `std::vector<Task>`
for simple beginner-friendly task storage. Recurring tasks are stored separately
as `std::vector<RecurringTask>` so their extra fields are preserved.

## Date Format

Deadlines should be entered in this format:

```text
YYYY-MM-DD
```

This allows simple string comparison to check whether a task is overdue.
