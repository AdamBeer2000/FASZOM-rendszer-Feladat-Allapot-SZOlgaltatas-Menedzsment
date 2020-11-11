#ifndef TASK_H
#define TASK_H

#include <exception>
#include <iostream>
#include <string>

namespace Tasks
{

    class Task
    {
    private:
        std::string employee;
        std::string task_id; // AA0000 -> for example: CL0001 (cleaner) or JA0001 (janitor) etc..
        std::string todo;
        bool status;

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

    public:
        //BUILDER PATTERN
        class TaskBuilder
        {
        private:
            std::string employee = "";
            std::string task_id;
            std::string todo = "";
            bool status = false;

            friend class Task;

        public:
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

            //BUILD
            Task* build()
            {
                return new Task(*this);
            }

        };

        //CONSTRUCTORS
        Task(std::string employee_c, std::string task_id_c);
        Task(TaskBuilder &builder);

        //FUNCTIONS
        static bool isValid(const std::string& data);
        static bool isValidId(const std::string& task_id_v);
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
    };
} // eof Tasks
#endif // TASK_H
