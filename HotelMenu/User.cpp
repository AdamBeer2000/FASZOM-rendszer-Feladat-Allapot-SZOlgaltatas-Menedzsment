#include "user.h"
std::string Users::User::getPassword() const
{
    return password;
}

std::string Users::User::getUsername() const
{
    return username;
}

Users::User::~User()
{

}

Users::User::User()
{

}

Users::User::User(const std::string& _username, const std::string& _password,jobs _jobID)
{
    username=_username;
    password=_password;
    jobID=_jobID;
}
