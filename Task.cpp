#include "Task.h"

#include <iostream>

Task::Task(int id,
           const std::string& title,
           const std::string& description,
           const std::string& createdDate,
           const std::string& deadline,
           Priority priority,
           const std::string& assignee,
           const std::vector<std::string>& tags)
    : WorkItem(id, title, description, createdDate, deadline),
      priority(priority),
      assignee(assignee),
      tags(tags) {
}

Priority Task::getPriority() const {
    return priority;
}

std::string Task::getAssignee() const {
    return assignee;
}

std::vector<std::string> Task::getTags() const {
    return tags;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}

void Task::setAssignee(const std::string& assignee) {
    this->assignee = assignee;
}

void Task::setTags(const std::vector<std::string>& tags) {
    this->tags = tags;
}

bool Task::isOverdue(const std::string& currentDate) const {
    return status != Status::Completed && deadline < currentDate;
}

void Task::display() const {
    std::cout << "Task ID: " << id << '\n'
              << "Title: " << title << '\n'
              << "Description: " << description << '\n'
              << "Created date: " << createdDate << '\n'
              << "Priority: " << priorityToString(priority) << '\n'
              << "Assignee: " << assignee << '\n'
              << "Status: " << statusToString(status) << '\n'
              << "Deadline: " << deadline << '\n'
              << "Tags: ";

    if (tags.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < tags.size(); i++) {
            std::cout << tags[i];
            if (i + 1 < tags.size()) {
                std::cout << ", ";
            }
        }
    }

    std::cout << '\n';
}
