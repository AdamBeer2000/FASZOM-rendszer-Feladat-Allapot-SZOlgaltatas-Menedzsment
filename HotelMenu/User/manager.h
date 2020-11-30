#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <list>
#include <algorithm>
#include <cstdlib>

#include "User/user.h"
#include "Task/task.h"

namespace Users
{
    class Manager: public User
    {
    private:
        std::string username = "manager";
        std::string password = "admin";
        std::list<std::string> task_ids;

        //EXCEPTION CLASS
        class InvalidInputException: public std::exception
        {
        private:
            std::string msg;

        public:
            InvalidInputException(const std::string& msg_c): msg(msg_c) {}
            virtual ~InvalidInputException(){}

            virtual const char* what() const noexcept override
            {
                return msg.c_str();
            }
        };

    public:
        Manager(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password);
        ~Manager();

        //FUNCTIONS
        Tasks::Task generateTask(jobs job_id, const std::string& employee_name, const std::string& todo);

        std::string generateTaskId(jobs job_id);

        void setTaskStatus(std::string taskID);

        void printTasks() const;

        void printLogs() const;

    };

} // eof Users

#endif // MANAGER_H
