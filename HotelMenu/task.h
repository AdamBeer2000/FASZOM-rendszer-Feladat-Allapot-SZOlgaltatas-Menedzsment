#ifndef TASK_H
#define TASK_H

#include <exception>
#include <iostream>
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
         std::string todo;
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
        //CONSTRUCTORS
        Task(std::string employee_c, std::string task_id_c);

        //FUNCTIONS
        bool isValid(const std::string& data);
        void printTask() const;
        std::string statusToString(bool stat) const;

        //GETTERS
        std::string getEmployee() const;
        std::string getTaskId() const;
        std::string getTodo() const;
        bool getStatus() const;
        bool isActive();

        //SETTERS
        void setStatus(bool value);
        void setTodo(const std::string &value);


    };
} // eof Tasks
#endif // TASK_H
