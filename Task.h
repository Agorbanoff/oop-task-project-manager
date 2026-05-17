#ifndef TASK_H
#define TASK_H

#include "Priority.h"
#include "Status.h"
#include "WorkItem.h"

#include <string>

class Task : public WorkItem {
protected:
    Status status;
    Priority priority;
    std::string deadline;

public:
    Task(int id,
         const std::string& title,
         const std::string& description,
         Priority priority,
         const std::string& deadline);

    Status getStatus() const;
    Priority getPriority() const;
    std::string getDeadline() const;

    void setStatus(Status status);
    void setPriority(Priority priority);
    void setDeadline(const std::string& deadline);

    virtual bool isOverdue(const std::string& currentDate) const;
    void display() const override;
};

#endif
