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
        //BUILDER PATTERN
        class TaskBuilder
        {
        private:
            std::string employee = "";
            std::string task_id; // AA0000 -> for example: TA0001 (takarító) or RE0001 (recepciós) etc..
            std::string todo = "";
            bool status = false;

            friend class Task;

        public:
            TaskBuilder(const std::string& task_id_c)
            {
                this->task_id = task_id_c;
            }

            TaskBuilder& withEmployee(const std::string& employee_opt)
            {
                this->employee = employee_opt;
                return *this;
            }

            TaskBuilder& withTodo(const std::string& todo_opt)
            {
                this->todo = todo_opt;
                return *this;
            }

            TaskBuilder& withStatus(bool status_opt)
            {
                this->status = status_opt;
                return *this;
            }

            Task* build()
            {
                return new Task(*this);
            }

        };

        //CONSTRUCTORS
        Task(std::string employee_c, std::string task_id_c);
        Task(TaskBuilder &builder);

        //FUNCTIONS
        bool isValid(const std::string& data);
        bool isValidId(const std::string& task_id_v);
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
