#include <iostream>
#include <vector>
#include <string>

class Task
{
public:
    Task(const std::string &title, const std::string &description)
        : title(title), description(description), completed(false) {}

    void markAsCompleted()
    {
        completed = true;
    }

    std::string getTitle() const
    {
        return title;
    }

    bool isCompleted() const
    {
        return completed;
    }

    void display() const
    {
        std::cout << "Title: " << title << "\nDescription: " << description;
        if (completed)
        {
            std::cout << "\nStatus: Completed";
        }
        else
        {
            std::cout << "\nStatus: Not Completed";
        }
        std::cout << "\n\n";
    }

private:
    std::string title;
    std::string description;
    bool completed;
};

int main()
{
    std::vector<Task> tasks;

    while (true)
    {
        std::cout << "1. Add Task\n2. Mark Task as Completed\n3. Display Tasks\n4. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::string title, description;
            std::cout << "Enter task title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);

            Task task(title, description);
            tasks.push_back(task);
            std::cout << "Task added!\n";
        }
        else if (choice == 2)
        {
            std::cout << "Enter task title to mark as completed: ";
            std::string titleToComplete;
            std::cin.ignore();
            std::getline(std::cin, titleToComplete);

            for (Task &task : tasks)
            {
                if (task.getTitle() == titleToComplete)
                {
                    task.markAsCompleted();
                    std::cout << "Task marked as completed!\n";
                    break;
                }
            }
        }
        else if (choice == 3)
        {
            std::cout << "Tasks:\n";
            for (const Task &task : tasks)
            {
                task.display();
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
