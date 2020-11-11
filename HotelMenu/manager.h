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

        void generateTask(const std::string& employee_type, const std::string& employee_name, const std::string& todo);
        std::string generateTaskId(const std::string& employee_type);
        //void sendTask(); //file-ba ír
        void deleteTask(const std::string& task_id_remove);

    };

} // eof Users

#endif // MANAGER_H
