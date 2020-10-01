#include "User.h"
std::string User::getPassword() const
{
    return password;
}

std::string User::getUsername() const
{
    return username;
}

User::User()
{

}

User::User(std::string _username, std::string _password)
{
    username=_username;
    password=_password;
}
