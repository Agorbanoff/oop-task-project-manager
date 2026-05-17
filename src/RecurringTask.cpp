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
                             const std::string& recurrence)
    : Task(id, title, description, createdDate, deadline, priority, assignee, tags),
      recurrence(recurrence) {
}

std::string RecurringTask::getRecurrence() const {
    return recurrence;
}

void RecurringTask::setRecurrence(const std::string& recurrence) {
    this->recurrence = recurrence;
}

void RecurringTask::display() const {
    Task::display();
    std::cout << "Recurring: " << recurrence << '\n';
}
