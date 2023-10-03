#include <iostream>
#include <vector>

class User {
public:
    User(std::string name) : name(name) {}

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

class Task {
public:
    Task(std::string title, std::string description, User assignee)
        : title(title), description(description), assignee(assignee), completed(false) {}

    void markAsCompleted() {
        completed = true;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getDescription() const {
        return description;
    }

    User getAssignee() const {
        return assignee;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    std::string title;
    std::string description;
    User assignee;
    bool completed;
};

class Team {
public:
    Team(std::string name) : name(name) {}

    void addMember(User user) {
        members.push_back(user);
    }

    void createTask(std::string title, std::string description, User assignee) {
        Task task(title, description, assignee);
        tasks.push_back(task);
    }

    void displayTasks() const {
        std::cout << "Tasks for Team: " << name << "\n";
        for (const Task& task : tasks) {
            std::cout << "Title: " << task.getTitle() << "\n";
            std::cout << "Description: " << task.getDescription() << "\n";
            std::cout << "Assignee: " << task.getAssignee().getName() << "\n";
            std::cout << "Status: " << (task.isCompleted() ? "Completed" : "Incomplete") << "\n\n";
        }
    }

private:
    std::string name;
    std::vector<User> members;
    std::vector<Task> tasks;
};

int main() {
    User user1("Alice");
    User user2("Bob");
    User user3("Charlie");

    Team developmentTeam("Development Team");
    developmentTeam.addMember(user1);
    developmentTeam.addMember(user2);
    developmentTeam.addMember(user3);

    developmentTeam.createTask("Implement feature X", "Implement feature X according to the specifications", user1);
    developmentTeam.createTask("Bug fix in module Y", "Fix the bug in module Y reported by QA", user2);
    developmentTeam.createTask("Code review", "Review the code submitted by team member Z", user3);

    developmentTeam.displayTasks();

    return 0;
}
