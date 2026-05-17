#ifndef TASK_H
#define TASK_H

#include "Priority.h"
#include "Status.h"
#include "WorkItem.h"

#include <string>
#include <vector>

class Task : public WorkItem {
private:
    Priority priority;
    std::string assignee;
    std::vector<std::string> tags;

public:
    Task(int id,
         const std::string& title,
         const std::string& description,
         const std::string& createdDate,
         const std::string& deadline,
         Priority priority,
         const std::string& assignee,
         const std::vector<std::string>& tags);

    Priority getPriority() const;
    std::string getAssignee() const;
    std::vector<std::string> getTags() const;

    void setPriority(Priority priority);
    void setAssignee(const std::string& assignee);
    void setTags(const std::vector<std::string>& tags);

    virtual bool isOverdue() const;
    void display() const override;
};

#endif
