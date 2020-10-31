#ifndef TASK_H
#define TASK_H

#include <string>
#include <list>

using namespace std;

namespace Tasks
{

    class Task
    {
    private:
         string employee;
         string task_id; // AA0000 -> for example: TA0001 (takarító) or RE0001 (recepciós) etc..
         list<string> todo;
         bool status;

    public:
        Task(string employee_c, string task_id_c);

        void addToDo(string todo_add);

        string getEmployee() const;
        string getTaskId() const;
        bool getStatus() const;
        void setStatus(bool value);
    };
} // eof Tasks
#endif // TASK_H
