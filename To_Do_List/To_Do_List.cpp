#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// Build a simple To - Do List application that runs in the terminal, lets you add, view, and delete tasks, and saves them to a file so they persist after closing.

class Tasks {
public:
    Tasks(int taskId, string titleTask, string desc, bool comp)
    {
        id = taskId;
        title = titleTask;
        description = desc;
        completed = comp;

    }; // initialising list

    void displayTask()
    {
        string myTasks;
        ifstream taskFile("TasksList.txt");
        while (getline(taskFile, myTasks)) 
        {
            cout << myTasks;
        }
    }
 
    void addTask()
    {
        ofstream taskFile("TasksList.txt");
        taskFile << "Test 123";
        taskFile.close();
    }
private:
    int id;
    string title;
    string description;
    bool completed;
};


int main()
{
    cout << "//////////////////////////" << endl;
    cout << "TO DO LIST" << endl;
    Tasks task(1, "first", "working class", false);
    task.addTask();
    task.displayTask();
    


}

