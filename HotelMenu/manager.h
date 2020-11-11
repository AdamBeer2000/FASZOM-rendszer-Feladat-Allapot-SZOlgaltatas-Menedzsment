#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <list>
#include <algorithm>
#include <cstdlib>

#include "user.h"
#include "task.h"

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
        Manager(const std::string& username_c, const std::string& password_c);
        ~Manager();

        //FUNCTIONS
        void generateTask(jobs job_id, const std::string& employee_name, const std::string& todo);
        std::string generateTaskId(jobs job_id);
        //void sendTask(); //file-ba ír
        void deleteTask(const std::string& task_id_remove);

        //FUNCTIONS FROM ABSTRACT USER
        virtual void doWork() const;
        virtual User* clone() const;

    };

} // eof Users

#endif // MANAGER_H
