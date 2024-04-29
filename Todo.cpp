#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back({description, false});
        std::cout << "Task added successfully!" << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        std::cout << "\nTasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed)
                std::cout << " - Completed";
            std::cout << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= tasks.size()) {
            std::cout << "Invalid task index." << std::endl;
            return;
        }

        tasks[index].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    }

    void removeTask(size_t index) {
        if (index >= tasks.size()) {
            std::cout << "Invalid task index." << std::endl;
            return;
        }

        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed successfully." << std::endl;
    }
};

int main() {
    TodoList todoList;
    int choice;
    std::string description;
    size_t index;

    do {
        std::cout << "\nMenu:\n"
                     "1. Add Task\n"
                     "2. View Tasks\n"
                     "3. Mark Task as Completed\n"
                     "4. Remove Task\n"
                     "5. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear input buffer
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                todoList.markTaskCompleted(index - 1); // Subtract 1 as indexing starts from 0
                break;
            case 4:
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                todoList.removeTask(index - 1); // Subtract 1 as indexing starts from 0
                break;
            case 5:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
