#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
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

    void taskCounter()
    {
        string taskCount;
        ifstream taskFile("TasksList.txt", ios::in);
        taskFile.seekg(-1, ios_base::end);
        bool keepLooping = true;
        while (keepLooping) {
            char ch;
            taskFile.get(ch);                            // Get current byte's data

            if ((int)taskFile.tellg() <= 1) {             // If the data was at or before the 0th byte
                taskFile.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if (ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                taskFile.seekg(-2, ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        string lastLine;
        getline(taskFile, lastLine);                      // Read the current line
        cout << "Result: " << lastLine << '\n';     // Display it

        taskFile.close();

    }

    void displayTask()
    {
        string myTasks;
        ifstream taskFile("TasksList.txt",ios::in);
        while (getline(taskFile, myTasks)) 
        {
            cout << myTasks;
        }
        taskFile.close();
    }
 
    void addTask()
    {
        ofstream taskFile("TasksList.txt", ios::app);

        taskFile  << id << " " << title << " " << description << " " << completed << "\n";


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
    count.taskCounter();
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
            Tasks task(1, title, desc, c);
            task.addTask();

        }
        else
        {
            Tasks task(0, "", "", false);
            task.displayTask();
        }
    }


}

