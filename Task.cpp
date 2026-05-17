#include "Task.h"

#include <iostream>

Task::Task(int id,
           const std::string& title,
           const std::string& description,
           Priority priority,
           const std::string& deadline)
    : WorkItem(id, title, description),
      status(Status::NotStarted),
      priority(priority),
      deadline(deadline) {
}

Status Task::getStatus() const {
    return status;
}

Priority Task::getPriority() const {
    return priority;
}

std::string Task::getDeadline() const {
    return deadline;
}

void Task::setStatus(Status status) {
    this->status = status;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}

void Task::setDeadline(const std::string& deadline) {
    this->deadline = deadline;
}

bool Task::isOverdue(const std::string& currentDate) const {
    return status != Status::Completed && deadline < currentDate;
}

void Task::display() const {
    std::cout << "Task ID: " << id << '\n'
              << "Title: " << title << '\n'
              << "Description: " << description << '\n'
              << "Priority: " << priorityToString(priority) << '\n'
              << "Status: " << statusToString(status) << '\n'
              << "Deadline: " << deadline << '\n';
}
