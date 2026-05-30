#ifndef RECURRINGTASK_H
#define RECURRINGTASK_H

#include "Task.h"

#include <string>

class RecurringTask : public Task {
private:
    std::string recurrenceRule;
    std::string nextOccurrenceDate;

public:
    RecurringTask(int id,
                  const std::string& title,
                  const std::string& description,
                  const std::string& createdDate,
                  const std::string& deadline,
                  Priority priority,
                  const std::string& assignee,
                  const std::vector<std::string>& tags,
                  const std::string& recurrenceRule,
                  const std::string& nextOccurrenceDate);

    std::string getRecurrenceRule() const;
    std::string getNextOccurrenceDate() const;

    void setRecurrenceRule(const std::string& recurrenceRule);
    void setNextOccurrenceDate(const std::string& nextOccurrenceDate);

    void display() const override;
};

#endif
