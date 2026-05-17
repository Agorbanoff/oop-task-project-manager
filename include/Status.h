#ifndef STATUS_H
#define STATUS_H

#include <string>

enum class Status {
    NotStarted = 1,
    InProgress,
    Completed
};

inline std::string statusToString(Status status) {
    switch (status) {
        case Status::NotStarted:
            return "Not Started";
        case Status::InProgress:
            return "In Progress";
        case Status::Completed:
            return "Completed";
        default:
            return "Unknown";
    }
}

#endif
