# Prompt History

## Project: Task and Project Manager

This document summarizes the important prompts used during the development of
the C++ OOP console application. The prompts are grouped by development step and
written as natural summaries of the requests made during the project.

## 1. Initial Project Creation

The first prompt requested a simple C++17 OOP console application for a school
checkpoint project with the theme **Task and Project Manager**.

The requested files were:

- `Status.h`
- `Priority.h`
- `WorkItem.h` / `WorkItem.cpp`
- `Task.h` / `Task.cpp`
- `RecurringTask.h` / `RecurringTask.cpp`
- `Project.h` / `Project.cpp`
- `main.cpp`
- `README.md`
- `Makefile`

The prompt also required a simple console menu and at least these working
functionalities:

- create and display projects
- add tasks to a project
- change task status
- filter or display tasks by priority/status
- detect overdue tasks
- show project summary

## 2. Project Structure

After the initial version was created, a prompt asked to make the project
structure more professional.

The project was reorganized into:

- `include/` for header files
- `src/` for implementation files
- `build/` for compiled output
- root-level `Makefile`, `.gitignore`, and `README.md`

The Makefile and README were updated to match this structure.

## 3. OOP Class Hierarchy

A prompt asked to review and correct the OOP class hierarchy.

The required hierarchy was:

- `WorkItem` as an abstract class
- `Project` inheriting from `WorkItem`
- `Task` inheriting from `WorkItem`
- `RecurringTask` inheriting from `Task`

The prompt also specified that:

- `WorkItem` should contain common fields such as title, description,
  created date, deadline, and status
- `Task` should contain priority, assignee, and tags
- `Project` should contain a vector of tasks
- protected fields should only be used where child classes need access
- private fields should be used where direct access is not needed

## 4. Console Menu

A prompt requested a simple console menu in `main.cpp`.

The requested menu options were:

1. Add project
2. Show all projects
3. Add task to project
4. Show tasks in a project
5. Change task status
6. Filter tasks by priority
7. Show project summary
8. Exit

The prompt also specified that all data should be stored in memory using
vectors, with no file storage required for the checkpoint.

## 5. Core Functionalities

Several prompts expanded the core functionality of the application.

The project was updated to support:

- adding projects
- displaying projects
- adding tasks to projects
- displaying tasks in a selected project
- changing task status
- filtering tasks by priority
- validating basic user input
- keeping data in memory using vectors

These features formed the basic working version of the console application.

## 6. Overdue Detection and Summary

A prompt requested deadline and overdue functionality.

The requirements were:

- each task has a deadline
- add an `isOverdue()` method
- keep date logic simple
- compare dates in `YYYY-MM-DD` format as strings
- a task is overdue if its deadline is before today's date and it is not
  completed

The project summary was also expanded to include:

- total tasks
- completed tasks
- overdue tasks
- urgent/high priority tasks

## 7. Removing Smart Pointers

A later prompt requested removing smart pointers because they were not required
for the school checkpoint and had not been studied yet.

The requirements were:

- do not use `unique_ptr`, `shared_ptr`, `make_unique`, or raw dynamic memory
- store tasks directly as objects using `std::vector<Task>`
- keep the code simple and beginner-friendly
- make sure the project can still add, display, update, and filter tasks

The project was refactored to use simple vector storage instead of smart
pointers.

## 8. Adding Delete, Edit, Search, and Tag Functionalities

Several prompts added more task and project features.

The requested task features included:

- delete a task by number/index
- edit a task's title, description, deadline, priority, and assignee
- add tags to tasks using `vector<string>`
- display task tags
- filter tasks by tag
- search tasks by title using partial match

The requested project features included:

- edit a project's title, description, deadline, and status
- delete a project by index
- validate invalid indexes

Another prompt requested improving `RecurringTask` so it was actually used in
the project. This added:

- `recurrenceRule`
- `nextOccurrenceDate`
- a menu option to create a recurring task
- different display output for recurring tasks

## 9. README Update

The README was updated more than once during development.

The final README prompt requested:

- project name
- short description
- all working functionalities
- OOP concepts used
- file structure explanation
- how to compile
- how to run
- design changes
- mention that smart pointers were removed
- mention that the project uses separate files for classes

The final README explains that the implementation uses `std::vector<Task>` for
simple beginner-friendly storage and keeps recurring tasks separately as
`std::vector<RecurringTask>`.

## 10. Final Testing

Throughout the development process, the project was compiled and tested from
the terminal.

The main compile command used was:

```powershell
make
```

The program was run with:

```powershell
.\build\task_manager.exe
```

Testing included:

- compiling with C++17
- checking that the Makefile works in Windows PowerShell
- testing invalid menu input
- testing invalid project and task indexes
- creating, editing, deleting, searching, and filtering tasks
- creating recurring tasks
- showing project summaries

The final project compiles and runs successfully from the terminal.
