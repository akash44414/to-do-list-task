#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& description) : description(description), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    std::string getDescription() const {
        return description;
    }

private:
    std::string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
    }

    void viewTasks() const {
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << (i + 1) << "] ";
            if (tasks[i].isCompleted()) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].getDescription() << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].markCompleted();
            std::cout << "Task marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int index;
                toDoList.viewTasks();
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                toDoList.markTaskCompleted(index);
                break;
            }
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);

    return 0;
}

