#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "User.h"

namespace Users
{
    class Manager: public User
    {
    private:
        std::string username = "manager";
        std::string password = "admin";

    public:
        Manager(const std::string& username_c, const std::string& password_c);
        ~Manager();

    };

} // eof Users

#endif // MANAGER_H
