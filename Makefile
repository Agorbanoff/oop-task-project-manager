CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = task_manager
SOURCES = main.cpp WorkItem.cpp Task.cpp RecurringTask.cpp Project.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
