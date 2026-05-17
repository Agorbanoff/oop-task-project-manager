#ifndef PROJECT_H
#define PROJECT_H

#include "Priority.h"
#include "Status.h"
#include "Task.h"
#include "WorkItem.h"

#include <memory>
#include <string>
#include <vector>

class Project : public WorkItem {
private:
    std::vector<std::shared_ptr<Task>> tasks;

public:
    Project(int id,
            const std::string& title,
            const std::string& description,
            const std::string& createdDate,
            const std::string& deadline);

    void addTask(const std::shared_ptr<Task>& task);
    std::shared_ptr<Task> findTaskById(int taskId);

    void display() const override;
    void displayTasks() const;
    void displayTasksByStatus(Status status) const;
    void displayTasksByPriority(Priority priority) const;
    void showSummary(const std::string& currentDate) const;
};

#endif
