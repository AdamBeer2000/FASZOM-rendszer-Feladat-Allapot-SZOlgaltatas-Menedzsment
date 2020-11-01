#ifndef TASK_H
#define TASK_H

#include <exception>
#include <string>
#include <list>
#include <algorithm>

namespace Tasks
{

    class Task
    {
    private:
         std::string employee;
         std::string task_id; // AA0000 -> for example: TA0001 (takarító) or RE0001 (recepciós) etc..
         std::list<std::string> todo;
         bool status;

         class InvalidTaskException: public std::exception
         {
         private:
             std::string msg;

         public:
             InvalidTaskException(const std::string& msg_c): msg(msg_c) {}
             virtual ~InvalidTaskException(){}

             virtual const char* what() const noexcept override
             {
                 return msg.c_str();
             }
         };

    public:
        Task(std::string employee_c, std::string task_id_c);

        void addToDo(std::string todo_add);
        void removeToDo(std::string todo_remove);

        std::string getEmployee() const;
        std::string getTaskId() const;
        bool getStatus() const;
        void setStatus(bool value);
    };
} // eof Tasks
#endif // TASK_H
