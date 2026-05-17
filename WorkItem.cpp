#include "WorkItem.h"

WorkItem::WorkItem(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description) {
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

void WorkItem::setTitle(const std::string& title) {
    this->title = title;
}

void WorkItem::setDescription(const std::string& description) {
    this->description = description;
}
