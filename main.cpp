#include "Priority.h"
#include "Project.h"
#include "RecurringTask.h"
#include "Status.h"
#include "Task.h"

#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string readLine(const std::string& message) {
    std::string value;
    std::cout << message;
    std::getline(std::cin, value);
    return value;
}

int readInt(const std::string& message) {
    int value;

    while (true) {
        std::cout << message;
        if (std::cin >> value) {
            clearInput();
            return value;
        }

        std::cout << "Invalid number. Try again.\n";
        clearInput();
    }
}

Priority readPriority() {
    std::cout << "Choose priority:\n"
              << "1. Low\n"
              << "2. Medium\n"
              << "3. High\n";

    int choice = readInt("Choice: ");
    switch (choice) {
        case 1:
            return Priority::Low;
        case 2:
            return Priority::Medium;
        case 3:
            return Priority::High;
        default:
            std::cout << "Invalid choice. Medium priority selected.\n";
            return Priority::Medium;
    }
}

Status readStatus() {
    std::cout << "Choose status:\n"
              << "1. Not Started\n"
              << "2. In Progress\n"
              << "3. Completed\n";

    int choice = readInt("Choice: ");
    switch (choice) {
        case 1:
            return Status::NotStarted;
        case 2:
            return Status::InProgress;
        case 3:
            return Status::Completed;
        default:
            std::cout << "Invalid choice. Not Started selected.\n";
            return Status::NotStarted;
    }
}

std::vector<std::string> readTags() {
    std::vector<std::string> tags;
    std::string tagLine = readLine("Tags separated by commas (or leave empty): ");
    std::string currentTag;

    for (char ch : tagLine) {
        if (ch == ',') {
            if (!currentTag.empty()) {
                tags.push_back(currentTag);
                currentTag.clear();
            }
        } else if (ch != ' ') {
            currentTag += ch;
        }
    }

    if (!currentTag.empty()) {
        tags.push_back(currentTag);
    }

    return tags;
}

std::shared_ptr<Project> findProjectById(std::vector<std::shared_ptr<Project>>& projects, int projectId) {
    for (std::shared_ptr<Project>& project : projects) {
        if (project->getId() == projectId) {
            return project;
        }
    }

    return nullptr;
}

void displayMenu() {
    std::cout << "\n===== Task and Project Manager =====\n"
              << "1. Create project\n"
              << "2. Display projects\n"
              << "3. Add task to project\n"
              << "4. Change task status\n"
              << "5. Display tasks by priority\n"
              << "6. Display tasks by status\n"
              << "7. Show project summary\n"
              << "8. Display all tasks in a project\n"
              << "0. Exit\n";
}

int main() {
    std::vector<std::shared_ptr<Project>> projects;
    int nextProjectId = 1;
    int nextTaskId = 1;

    while (true) {
        displayMenu();
        int choice = readInt("Choose an option: ");

        if (choice == 0) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (choice == 1) {
            std::string title = readLine("Project title: ");
            std::string description = readLine("Project description: ");
            std::string createdDate = readLine("Created date (YYYY-MM-DD): ");
            std::string deadline = readLine("Project deadline (YYYY-MM-DD): ");

            projects.push_back(std::make_shared<Project>(
                nextProjectId, title, description, createdDate, deadline));
            std::cout << "Project created with ID " << nextProjectId << ".\n";
            nextProjectId++;
        } else if (choice == 2) {
            if (projects.empty()) {
                std::cout << "No projects created yet.\n";
            } else {
                for (const std::shared_ptr<Project>& project : projects) {
                    std::cout << "------------------------\n";
                    project->display();
                }
            }
        } else if (choice == 3) {
            int projectId = readInt("Project ID: ");
            std::shared_ptr<Project> project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            std::string title = readLine("Task title: ");
            std::string description = readLine("Task description: ");
            std::string createdDate = readLine("Created date (YYYY-MM-DD): ");
            Priority priority = readPriority();
            std::string assignee = readLine("Assignee: ");
            std::vector<std::string> tags = readTags();
            std::string deadline = readLine("Deadline (YYYY-MM-DD): ");
            int recurringChoice = readInt("Is this a recurring task? (1 = yes, 0 = no): ");

            if (recurringChoice == 1) {
                std::string recurrence = readLine("Recurrence (example: daily, weekly, monthly): ");
                project->addTask(std::make_shared<RecurringTask>(
                    nextTaskId, title, description, createdDate, deadline, priority, assignee, tags, recurrence));
            } else {
                project->addTask(std::make_shared<Task>(
                    nextTaskId, title, description, createdDate, deadline, priority, assignee, tags));
            }

            std::cout << "Task added with ID " << nextTaskId << ".\n";
            nextTaskId++;
        } else if (choice == 4) {
            int projectId = readInt("Project ID: ");
            std::shared_ptr<Project> project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            int taskId = readInt("Task ID: ");
            std::shared_ptr<Task> task = project->findTaskById(taskId);

            if (task == nullptr) {
                std::cout << "Task not found.\n";
                continue;
            }

            task->setStatus(readStatus());
            std::cout << "Task status updated.\n";
        } else if (choice == 5) {
            int projectId = readInt("Project ID: ");
            std::shared_ptr<Project> project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasksByPriority(readPriority());
        } else if (choice == 6) {
            int projectId = readInt("Project ID: ");
            std::shared_ptr<Project> project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasksByStatus(readStatus());
        } else if (choice == 7) {
            int projectId = readInt("Project ID: ");
            std::shared_ptr<Project> project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            std::string currentDate = readLine("Current date (YYYY-MM-DD): ");
            project->showSummary(currentDate);
        } else if (choice == 8) {
            int projectId = readInt("Project ID: ");
            std::shared_ptr<Project> project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasks();
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
