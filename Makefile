CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude
TARGET = build/task_manager.exe
SOURCES = src/main.cpp src/WorkItem.cpp src/Task.cpp src/RecurringTask.cpp src/Project.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path build | Out-Null"
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

clean:
	powershell -NoProfile -Command "Remove-Item -Recurse -Force build -ErrorAction SilentlyContinue"

.PHONY: all run clean
