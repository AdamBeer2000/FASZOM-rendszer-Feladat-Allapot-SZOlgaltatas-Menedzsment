#ifndef RIGHTSANDCOMMANDS_H
#define RIGHTSANDCOMMANDS_H
#include "map"
#include "string"

namespace  Users
{
    class User
    {
        std::string username;
        std::string password;

    public:
        User();
        User(const std::string& _username, const std::string& _password);
        std::string getPassword() const;
        std::string getUsername() const;
    };
} // eof Users


#endif // RIGHTSANDCOMMANDS_H
