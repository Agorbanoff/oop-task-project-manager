#ifndef PRIORITY_H
#define PRIORITY_H

#include <string>

enum class Priority {
    Low = 1,
    Medium,
    High
};

inline std::string priorityToString(Priority priority) {
    switch (priority) {
        case Priority::Low:
            return "Low";
        case Priority::Medium:
            return "Medium";
        case Priority::High:
            return "High";
        default:
            return "Unknown";
    }
}

#endif
