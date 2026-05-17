#include "Project.h"

#include <iostream>

Project::Project(int id,
                 const std::string& title,
                 const std::string& description,
                 const std::string& createdDate,
                 const std::string& deadline)
    : WorkItem(id, title, description, createdDate, deadline) {
}

void Project::addTask(const std::shared_ptr<Task>& task) {
    tasks.push_back(task);
}

std::shared_ptr<Task> Project::findTaskById(int taskId) {
    for (std::shared_ptr<Task>& task : tasks) {
        if (task->getId() == taskId) {
            return task;
        }
    }

    return nullptr;
}

void Project::display() const {
    std::cout << "Project ID: " << id << '\n'
              << "Title: " << title << '\n'
              << "Description: " << description << '\n'
              << "Created date: " << createdDate << '\n'
              << "Deadline: " << deadline << '\n'
              << "Status: " << statusToString(status) << '\n'
              << "Tasks: " << tasks.size() << '\n';
}

void Project::displayTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks in this project.\n";
        return;
    }

    for (const std::shared_ptr<Task>& task : tasks) {
        std::cout << "------------------------\n";
        task->display();
    }
}

void Project::displayTasksByStatus(Status status) const {
    bool found = false;

    for (const std::shared_ptr<Task>& task : tasks) {
        if (task->getStatus() == status) {
            std::cout << "------------------------\n";
            task->display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No tasks found with this status.\n";
    }
}

void Project::displayTasksByPriority(Priority priority) const {
    bool found = false;

    for (const std::shared_ptr<Task>& task : tasks) {
        if (task->getPriority() == priority) {
            std::cout << "------------------------\n";
            task->display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No tasks found with this priority.\n";
    }
}

void Project::showSummary() const {
    int completedTasks = 0;
    int overdueTasks = 0;
    int highPriorityTasks = 0;

    for (const std::shared_ptr<Task>& task : tasks) {
        if (task->getStatus() == Status::Completed) {
            completedTasks++;
        }

        if (task->isOverdue()) {
            overdueTasks++;
        }

        if (task->getPriority() == Priority::High) {
            highPriorityTasks++;
        }
    }

    std::cout << "Summary for project: " << title << '\n'
              << "Total tasks: " << tasks.size() << '\n'
              << "Completed tasks: " << completedTasks << '\n'
              << "Overdue tasks: " << overdueTasks << '\n'
              << "Urgent/high priority tasks: " << highPriorityTasks << '\n';
}
