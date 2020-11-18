#include "guest.h"


Users::Guest::Guest(const std::string &_username, const std::string &_password, jobs _job):Users::User(_username, _password, jobs::GUE)
{

}

void Users::Guest::doWork() const
{

}

Users::User *Users::Guest::clone() const
{
    return new Guest(*this);
}


