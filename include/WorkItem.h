#ifndef WORKITEM_H
#define WORKITEM_H

#include "Status.h"

#include <string>

class WorkItem {
protected:
    int id;
    std::string title;
    std::string description;
    std::string createdDate;
    std::string deadline;
    Status status;

public:
    WorkItem(int id,
             const std::string& title,
             const std::string& description,
             const std::string& createdDate,
             const std::string& deadline);
    virtual ~WorkItem();

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getCreatedDate() const;
    std::string getDeadline() const;
    Status getStatus() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setCreatedDate(const std::string& createdDate);
    void setDeadline(const std::string& deadline);
    void setStatus(Status status);

    virtual void display() const = 0;
};

#endif
