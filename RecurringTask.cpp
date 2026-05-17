#include "RecurringTask.h"

#include <iostream>

RecurringTask::RecurringTask(int id,
                             const std::string& title,
                             const std::string& description,
                             Priority priority,
                             const std::string& deadline,
                             const std::string& recurrence)
    : Task(id, title, description, priority, deadline),
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
