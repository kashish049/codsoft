#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Display menu
void showMenu() {
    cout << "\n====== TO-DO LIST MANAGER ======" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Add task
void addTask(vector<Task>& tasks) {
    string taskDesc;
    cin.ignore(); // To clear input buffer
    cout << "Enter task description: ";
    getline(cin, taskDesc);
    tasks.push_back({taskDesc, false});
    cout << "Task added successfully!" << endl;
}

// View tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty." << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? " Completed" : "Pending") << "]" << endl;
    }
}

// Mark task as completed
void markCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << " No tasks to mark." << endl;
        return;
    }

    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << " Invalid task number." << endl;
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    }
}

// Remove task
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }

    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    }
}

// Main function
int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << " Exiting To-Do List Manager. Goodbye!" << endl; break;
            default: cout << " Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
