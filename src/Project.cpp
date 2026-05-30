#include "Project.h"

#include <iostream>

Project::Project(int id,
                 const std::string& title,
                 const std::string& description,
                 const std::string& createdDate,
                 const std::string& deadline)
    : WorkItem(id, title, description, createdDate, deadline) {
}

void Project::addTask(const Task& task) {
    tasks.push_back(task);
}

void Project::addRecurringTask(const RecurringTask& task) {
    recurringTasks.push_back(task);
}

Task* Project::findTaskById(int taskId) {
    for (Task& task : tasks) {
        if (task.getId() == taskId) {
            return &task;
        }
    }

    for (RecurringTask& task : recurringTasks) {
        if (task.getId() == taskId) {
            return &task;
        }
    }

    return nullptr;
}

Task* Project::findTaskByIndex(int taskNumber) {
    int totalTasks = static_cast<int>(tasks.size() + recurringTasks.size());

    if (taskNumber < 1 || taskNumber > totalTasks) {
        return nullptr;
    }

    if (taskNumber <= static_cast<int>(tasks.size())) {
        return &tasks[taskNumber - 1];
    }

    int recurringIndex = taskNumber - static_cast<int>(tasks.size()) - 1;
    return &recurringTasks[recurringIndex];
}

bool Project::deleteTaskByIndex(int taskNumber) {
    int totalTasks = static_cast<int>(tasks.size() + recurringTasks.size());

    if (taskNumber < 1 || taskNumber > totalTasks) {
        return false;
    }

    if (taskNumber <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        int recurringIndex = taskNumber - static_cast<int>(tasks.size()) - 1;
        recurringTasks.erase(recurringTasks.begin() + recurringIndex);
    }

    return true;
}

void Project::display() const {
    std::cout << "Project ID: " << id << '\n'
              << "Title: " << title << '\n'
              << "Description: " << description << '\n'
              << "Created date: " << createdDate << '\n'
              << "Deadline: " << deadline << '\n'
              << "Status: " << statusToString(status) << '\n'
              << "Tasks: " << tasks.size() + recurringTasks.size() << '\n';
}

void Project::displayTasks() const {
    if (tasks.empty() && recurringTasks.empty()) {
        std::cout << "No tasks in this project.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << "------------------------\n";
        std::cout << "Task number: " << i + 1 << '\n';
        tasks[i].display();
    }

    for (size_t i = 0; i < recurringTasks.size(); i++) {
        std::cout << "------------------------\n";
        std::cout << "Task number: " << tasks.size() + i + 1 << '\n';
        recurringTasks[i].display();
    }
}

void Project::displayTasksByStatus(Status status) const {
    bool found = false;

    for (const Task& task : tasks) {
        if (task.getStatus() == status) {
            std::cout << "------------------------\n";
            task.display();
            found = true;
        }
    }

    for (const RecurringTask& task : recurringTasks) {
        if (task.getStatus() == status) {
            std::cout << "------------------------\n";
            task.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No tasks found with this status.\n";
    }
}

void Project::displayTasksByPriority(Priority priority) const {
    bool found = false;

    for (const Task& task : tasks) {
        if (task.getPriority() == priority) {
            std::cout << "------------------------\n";
            task.display();
            found = true;
        }
    }

    for (const RecurringTask& task : recurringTasks) {
        if (task.getPriority() == priority) {
            std::cout << "------------------------\n";
            task.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No tasks found with this priority.\n";
    }
}

void Project::displayTasksByTag(const std::string& tag) const {
    bool found = false;

    for (const Task& task : tasks) {
        std::vector<std::string> tags = task.getTags();

        for (const std::string& taskTag : tags) {
            if (taskTag == tag) {
                std::cout << "------------------------\n";
                task.display();
                found = true;
                break;
            }
        }
    }

    for (const RecurringTask& task : recurringTasks) {
        std::vector<std::string> tags = task.getTags();

        for (const std::string& taskTag : tags) {
            if (taskTag == tag) {
                std::cout << "------------------------\n";
                task.display();
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "No tasks found with this tag.\n";
    }
}

void Project::searchTasksByTitle(const std::string& searchText) const {
    bool found = false;

    for (const Task& task : tasks) {
        if (task.getTitle().find(searchText) != std::string::npos) {
            std::cout << "------------------------\n";
            task.display();
            found = true;
        }
    }

    for (const RecurringTask& task : recurringTasks) {
        if (task.getTitle().find(searchText) != std::string::npos) {
            std::cout << "------------------------\n";
            task.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No tasks found with this title.\n";
    }
}

void Project::showSummary() const {
    int completedTasks = 0;
    int overdueTasks = 0;
    int highPriorityTasks = 0;

    for (const Task& task : tasks) {
        if (task.getStatus() == Status::Completed) {
            completedTasks++;
        }

        if (task.isOverdue()) {
            overdueTasks++;
        }

        if (task.getPriority() == Priority::High) {
            highPriorityTasks++;
        }
    }

    for (const RecurringTask& task : recurringTasks) {
        if (task.getStatus() == Status::Completed) {
            completedTasks++;
        }

        if (task.isOverdue()) {
            overdueTasks++;
        }

        if (task.getPriority() == Priority::High) {
            highPriorityTasks++;
        }
    }

    std::cout << "Summary for project: " << title << '\n'
              << "Total tasks: " << tasks.size() + recurringTasks.size() << '\n'
              << "Completed tasks: " << completedTasks << '\n'
              << "Overdue tasks: " << overdueTasks << '\n'
              << "Urgent/high priority tasks: " << highPriorityTasks << '\n';
}
