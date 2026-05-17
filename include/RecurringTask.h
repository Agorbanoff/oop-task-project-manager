#ifndef RECURRINGTASK_H
#define RECURRINGTASK_H

#include "Task.h"

#include <string>

class RecurringTask : public Task {
private:
    std::string recurrence;

public:
    RecurringTask(int id,
                  const std::string& title,
                  const std::string& description,
                  const std::string& createdDate,
                  const std::string& deadline,
                  Priority priority,
                  const std::string& assignee,
                  const std::vector<std::string>& tags,
                  const std::string& recurrence);

    std::string getRecurrence() const;
    void setRecurrence(const std::string& recurrence);

    void display() const override;
};

#endif
