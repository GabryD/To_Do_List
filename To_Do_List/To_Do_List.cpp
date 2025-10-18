#include <ctime>
#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// Build a simple To - Do List application that runs in the terminal, lets you add, view, and delete tasks, and saves them to a file so they persist after closing.

class Tasks {
public:

    Tasks() {
    }

    Tasks(int taskId, string titleTask, string desc, bool comp)
    {
        id = taskId;
        title = titleTask;
        description = desc;
        completed = comp;

    }; // initialising list

    int taskCounter()
    {
        ifstream taskFile("TasksList.txt", ios::in);
        if (!taskFile.is_open())
        {
            return 1;
        }
        string lastLine, line;
        while (getline(taskFile, line))
        {
            if (!line.empty())
            {
                lastLine = line;
            }
        }
        taskFile.close();

        if (lastLine.empty())
        {
            return 1;
        }

        stringstream ss(lastLine);
        int lastID;
        ss >> lastID;

        if (ss.fail())
        {
            return 1;
        }

        return lastID + 1;
    }

    void displayTask()
    {
        string myTasks;
        ifstream taskFile("TasksList.txt",ios::in);
        int id;
        string title, desc;
        bool completed;
        cout << "\n========== TO-DO LIST ==========\n";
        cout << left << setw(5) << "ID"
            << setw(20) << "TITLE"
            << setw(30) << "DESCRIPTION"
            << setw(10) << "STATUS" << "\n";
        cout << string(65, '-') << "\n";


        while (taskFile >> id >> title >> desc >> completed) 
        {
            cout << left << setw(5) << id
                << setw(20) << title << setw(30) << desc << setw(10) << (completed ? "Done" : "Pending")
                << "\n";
        }
        taskFile.close();
    }
 
    void addTask()
    {
        ofstream taskFile("TasksList.txt", ios::app);

        taskFile << id << " " << title << " " << description << " " << completed << "\n";


        cout << "\nTask added";
        taskFile.close();
    }
private:
    int id = 0;
    string title = "";
    string description = "";
    bool completed = false;
};


int main()
{
    bool exit = false;
    cout << "//////////////////////////" << endl;
    cout << "TO DO LIST" << endl;
    Tasks count;
    while (exit == false) 
    {
        cout << "\n Add task: y/n: ";
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            cout << "\nEnter Title of task: ";
            string title;
            cin >> title;
            cout << "\nEnter Description of task: ";
            string desc;
            cin >> desc;
            cout << "\nEnter Status of task (y/n): ";
            char comp;
            cin >> comp;
            bool c;
            if (comp == 'y')
            {
                c = true;
            }
            else
            {
                c = false;
            }
            Tasks task(count.taskCounter(), title, desc, c);
            task.addTask();

        }
        else if (choice == 'x')
        {
            exit = true;
        }
        else
        {
            Tasks task(0, "", "", false);
            task.displayTask();
        }
        
    }


}

