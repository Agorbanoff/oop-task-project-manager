#include "RecurringTask.h"

#include <iostream>

RecurringTask::RecurringTask(int id,
                             const std::string& title,
                             const std::string& description,
                             const std::string& createdDate,
                             const std::string& deadline,
                             Priority priority,
                             const std::string& assignee,
                             const std::vector<std::string>& tags,
                             const std::string& recurrenceRule,
                             const std::string& nextOccurrenceDate)
    : Task(id, title, description, createdDate, deadline, priority, assignee, tags),
      recurrenceRule(recurrenceRule),
      nextOccurrenceDate(nextOccurrenceDate) {
}

std::string RecurringTask::getRecurrenceRule() const {
    return recurrenceRule;
}

std::string RecurringTask::getNextOccurrenceDate() const {
    return nextOccurrenceDate;
}

void RecurringTask::setRecurrenceRule(const std::string& recurrenceRule) {
    this->recurrenceRule = recurrenceRule;
}

void RecurringTask::setNextOccurrenceDate(const std::string& nextOccurrenceDate) {
    this->nextOccurrenceDate = nextOccurrenceDate;
}

void RecurringTask::display() const {
    std::cout << "[Recurring Task]\n";
    Task::display();
    std::cout << "Recurrence rule: " << recurrenceRule << '\n'
              << "Next occurrence date: " << nextOccurrenceDate << '\n';
}
