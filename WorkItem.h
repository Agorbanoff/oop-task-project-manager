#ifndef WORKITEM_H
#define WORKITEM_H

#include <string>

class WorkItem {
protected:
    int id;
    std::string title;
    std::string description;

public:
    WorkItem(int id, const std::string& title, const std::string& description);
    virtual ~WorkItem();

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);

    virtual void display() const = 0;
};

#endif
