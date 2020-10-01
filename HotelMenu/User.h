#ifndef RIGHTSANDCOMMANDS_H
#define RIGHTSANDCOMMANDS_H
#include "map"
#include "string"

class User
{
    std::string username;
    std::string password;

public:
    User();
    User(std::string _username,std::string _password);
    std::string getPassword() const;
    std::string getUsername() const;
};

#endif // RIGHTSANDCOMMANDS_H
