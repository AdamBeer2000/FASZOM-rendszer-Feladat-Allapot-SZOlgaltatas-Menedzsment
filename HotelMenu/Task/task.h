#ifndef TASK_H
#define TASK_H

#include <exception>
#include <iostream>
#include <string>
#include "Log/log.h"
#include "Log/logcleaning.h"
#include "Log/logreplace.h"
#include "Log/logreservation.h"
#include "Log/logfix.h"

namespace Tasks
{

    class Task
    {
    private:

        //VARIABLES
        std::string employee;
        std::string task_id; //UNIQUE
        std::string todo;
        bool status;
        Logs::Log* log;


    public:
        //EXCEPTION CLASS
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

        //BUILDER PATTERN
        class TaskBuilder
        {
        private:
            std::string employee = "";
            std::string task_id;
            std::string todo = "";
            bool status = false;
            Logs::Log* log = nullptr;

            friend class Task;

        public:

            //CONSTRUCTOR
            TaskBuilder(const std::string& task_id_c)
            {
                this->task_id = task_id_c;
            }

            //FUNCTIONS
            TaskBuilder& withEmployee(const std::string& employee_opt)
            {
                try
                {
                    if(Task::isValid(employee_opt))
                    {
                        this->employee = employee_opt;
                    }
                    else
                    {
                        throw InvalidTaskException("[SET EMPLOYEE EXCEPTION]: Invalid input detected!");
                    }
                }
                catch (InvalidTaskException& e)
                {
                    std::cout << e.what() << std::endl;
                }

                return *this;
            }

            TaskBuilder& withTodo(const std::string& todo_opt)
            {
                try
                {
                    if(Task::isValid(todo_opt))
                    {
                        this->todo = todo_opt;
                    }
                    else
                    {
                        throw InvalidTaskException("[SET TODO EXCEPTION]: Invalid todo");
                    }
                }
                catch (InvalidTaskException& e)
                {
                    std::cout << e.what() << std::endl;
                }

                return *this;
            }

            TaskBuilder& withStatus(bool status_opt)
            {
                this->status = status_opt;
                return *this;
            }

            TaskBuilder& withLog(Logs::Log* log)
            {
                this->log = log;
                return *this;
            }

            //BUILD
            Task* build()
            {
                return new Task(*this);
            }

        };

        //CONSTRUCTORS
        Task(TaskBuilder &builder);

        //DESTRUCTOR
        ~Task();

        //FUNCTIONS
        static bool isValid(const std::string& data);
        static bool isValidId(const std::string& task_id_v);
        void printTask() const;
        std::string statusToString(bool stat) const;
        bool isActive() const;
        bool isActive();
        void printLog() const;
        void backupSaveStream(std::ofstream& stream);

        //GETTERS
        std::string getEmployee() const;
        std::string getTaskId() const;
        std::string getTodo() const;
        bool getStatus() const;

        //SETTERS
        void setStatus(bool value);
        void setLog(Logs::Log* log);
    };
} // eof Tasks
#endif // TASK_H
