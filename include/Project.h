#ifndef PROJECT_H
#define PROJECT_H

#include "Priority.h"
#include "RecurringTask.h"
#include "Status.h"
#include "Task.h"
#include "WorkItem.h"

#include <string>
#include <vector>

class Project : public WorkItem {
private:
    std::vector<Task> tasks;
    std::vector<RecurringTask> recurringTasks;

public:
    Project(int id,
            const std::string& title,
            const std::string& description,
            const std::string& createdDate,
            const std::string& deadline);

    void addTask(const Task& task);
    void addRecurringTask(const RecurringTask& task);
    int getTaskCount() const;
    Task* findTaskById(int taskId);
    Task* findTaskByIndex(int taskNumber);
    bool deleteTaskByIndex(int taskNumber);

    void display() const override;
    void displayTasks() const;
    void displayTasksByStatus(Status status) const;
    void displayTasksByPriority(Priority priority) const;
    void displayTasksByTag(const std::string& tag) const;
    void searchTasksByTitle(const std::string& searchText) const;
    void showSummary() const;
};

#endif
