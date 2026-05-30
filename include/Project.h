#ifndef PROJECT_H
#define PROJECT_H

#include "Priority.h"
#include "Status.h"
#include "Task.h"
#include "WorkItem.h"

#include <string>
#include <vector>

class Project : public WorkItem {
private:
    std::vector<Task> tasks;

public:
    Project(int id,
            const std::string& title,
            const std::string& description,
            const std::string& createdDate,
            const std::string& deadline);

    void addTask(const Task& task);
    Task* findTaskById(int taskId);
    Task* findTaskByIndex(int taskNumber);
    bool deleteTaskByIndex(int taskNumber);

    void display() const override;
    void displayTasks() const;
    void displayTasksByStatus(Status status) const;
    void displayTasksByPriority(Priority priority) const;
    void showSummary() const;
};

#endif
