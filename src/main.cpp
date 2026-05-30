#include "Priority.h"
#include "Project.h"
#include "RecurringTask.h"
#include "Status.h"
#include "Task.h"

#include <iostream>
#include <limits>
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

Project* findProjectById(std::vector<Project>& projects, int projectId) {
    for (Project& project : projects) {
        if (project.getId() == projectId) {
            return &project;
        }
    }

    return nullptr;
}

Project* findProjectByIndex(std::vector<Project>& projects, int projectNumber) {
    if (projectNumber < 1 || projectNumber > static_cast<int>(projects.size())) {
        return nullptr;
    }

    return &projects[projectNumber - 1];
}

void showProjects(const std::vector<Project>& projects) {
    if (projects.empty()) {
        std::cout << "No projects created yet.\n";
        return;
    }

    for (size_t i = 0; i < projects.size(); i++) {
        std::cout << "------------------------\n";
        std::cout << "Project number: " << i + 1 << '\n';
        projects[i].display();
    }
}

void displayMenu() {
    std::cout << "\n===== Task and Project Manager =====\n"
              << "1. Add project\n"
              << "2. Show all projects\n"
              << "3. Edit project\n"
              << "4. Delete project\n"
              << "5. Add task to project\n"
              << "6. Add recurring task to project\n"
              << "7. Show tasks in a project\n"
              << "8. Change task status\n"
              << "9. Filter tasks by priority\n"
              << "10. Filter tasks by tag\n"
              << "11. Search tasks by title\n"
              << "12. Edit task in project\n"
              << "13. Delete task from project\n"
              << "14. Show project summary\n"
              << "15. Exit\n";
}

int main() {
    std::vector<Project> projects;
    int nextProjectId = 1;
    int nextTaskId = 1;

    while (true) {
        displayMenu();
        int choice = readInt("Choose an option: ");

        if (choice == 15) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (choice == 1) {
            std::string title = readLine("Project title: ");
            std::string description = readLine("Project description: ");
            std::string createdDate = readLine("Created date (YYYY-MM-DD): ");
            std::string deadline = readLine("Project deadline (YYYY-MM-DD): ");

            projects.push_back(Project(nextProjectId, title, description, createdDate, deadline));
            std::cout << "Project created with ID " << nextProjectId << ".\n";
            nextProjectId++;
        } else if (choice == 2) {
            showProjects(projects);
        } else if (choice == 3) {
            showProjects(projects);
            int projectNumber = readInt("Project number to edit: ");
            Project* project = findProjectByIndex(projects, projectNumber);

            if (project == nullptr) {
                std::cout << "Invalid project number. No project was edited.\n";
                continue;
            }

            std::string title = readLine("New project title: ");
            std::string description = readLine("New project description: ");
            std::string deadline = readLine("New project deadline (YYYY-MM-DD): ");
            Status status = readStatus();

            project->setTitle(title);
            project->setDescription(description);
            project->setDeadline(deadline);
            project->setStatus(status);

            std::cout << "Project edited successfully.\n";
        } else if (choice == 4) {
            showProjects(projects);
            int projectNumber = readInt("Project number to delete: ");

            if (projectNumber < 1 || projectNumber > static_cast<int>(projects.size())) {
                std::cout << "Invalid project number. No project was deleted.\n";
                continue;
            }

            projects.erase(projects.begin() + projectNumber - 1);
            std::cout << "Project deleted successfully.\n";
        } else if (choice == 5) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

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
            project->addTask(Task(nextTaskId, title, description, createdDate, deadline, priority, assignee, tags));

            std::cout << "Task added with ID " << nextTaskId << ".\n";
            nextTaskId++;
        } else if (choice == 6) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            std::string title = readLine("Recurring task title: ");
            std::string description = readLine("Recurring task description: ");
            std::string createdDate = readLine("Created date (YYYY-MM-DD): ");
            Priority priority = readPriority();
            std::string assignee = readLine("Assignee: ");
            std::vector<std::string> tags = readTags();
            std::string deadline = readLine("Deadline (YYYY-MM-DD): ");
            std::string recurrenceRule = readLine("Recurrence rule (example: daily, weekly, monthly): ");
            std::string nextOccurrenceDate = readLine("Next occurrence date (YYYY-MM-DD): ");

            project->addRecurringTask(RecurringTask(nextTaskId,
                                                    title,
                                                    description,
                                                    createdDate,
                                                    deadline,
                                                    priority,
                                                    assignee,
                                                    tags,
                                                    recurrenceRule,
                                                    nextOccurrenceDate));

            std::cout << "Recurring task added with ID " << nextTaskId << ".\n";
            nextTaskId++;
        } else if (choice == 7) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasks();
        } else if (choice == 8) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            int taskId = readInt("Task ID: ");
            Task* task = project->findTaskById(taskId);

            if (task == nullptr) {
                std::cout << "Task not found.\n";
                continue;
            }

            task->setStatus(readStatus());
            std::cout << "Task status updated.\n";
        } else if (choice == 9) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasksByPriority(readPriority());
        } else if (choice == 10) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            std::string tag = readLine("Tag to search: ");
            project->displayTasksByTag(tag);
        } else if (choice == 11) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            std::string searchText = readLine("Search title: ");
            project->searchTasksByTitle(searchText);
        } else if (choice == 12) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasks();
            int taskNumber = readInt("Task number to edit: ");
            Task* task = project->findTaskByIndex(taskNumber);

            if (task == nullptr) {
                std::cout << "Invalid task number. No task was edited.\n";
                continue;
            }

            std::string title = readLine("New task title: ");
            std::string description = readLine("New task description: ");
            std::string deadline = readLine("New deadline (YYYY-MM-DD): ");
            Priority priority = readPriority();
            std::string assignee = readLine("New assignee: ");

            task->setTitle(title);
            task->setDescription(description);
            task->setDeadline(deadline);
            task->setPriority(priority);
            task->setAssignee(assignee);

            std::cout << "Task edited successfully.\n";
        } else if (choice == 13) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->displayTasks();
            int taskNumber = readInt("Task number to delete: ");

            if (project->deleteTaskByIndex(taskNumber)) {
                std::cout << "Task deleted successfully.\n";
            } else {
                std::cout << "Invalid task number. No task was deleted.\n";
            }
        } else if (choice == 14) {
            int projectId = readInt("Project ID: ");
            Project* project = findProjectById(projects, projectId);

            if (project == nullptr) {
                std::cout << "Project not found.\n";
                continue;
            }

            project->showSummary();
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
