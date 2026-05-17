#include "WorkItem.h"

WorkItem::WorkItem(int id,
                   const std::string& title,
                   const std::string& description,
                   const std::string& createdDate,
                   const std::string& deadline)
    : id(id),
      title(title),
      description(description),
      createdDate(createdDate),
      deadline(deadline),
      status(Status::NotStarted) {
}

WorkItem::~WorkItem() {
}

int WorkItem::getId() const {
    return id;
}

std::string WorkItem::getTitle() const {
    return title;
}

std::string WorkItem::getDescription() const {
    return description;
}

std::string WorkItem::getCreatedDate() const {
    return createdDate;
}

std::string WorkItem::getDeadline() const {
    return deadline;
}

Status WorkItem::getStatus() const {
    return status;
}

void WorkItem::setTitle(const std::string& title) {
    this->title = title;
}

void WorkItem::setDescription(const std::string& description) {
    this->description = description;
}

void WorkItem::setCreatedDate(const std::string& createdDate) {
    this->createdDate = createdDate;
}

void WorkItem::setDeadline(const std::string& deadline) {
    this->deadline = deadline;
}

void WorkItem::setStatus(Status status) {
    this->status = status;
}
