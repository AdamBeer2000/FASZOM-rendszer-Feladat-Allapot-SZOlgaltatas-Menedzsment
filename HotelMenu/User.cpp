#include "User.h"

std::string Users::User::getFirstName() const
{
    return firstName;
}

std::string Users::User::getLastName() const
{
    return lastName;
}

std::string Users::User::getUsername() const
{
    return username;
}

date Users::User::getBirthDate() const
{
    return birthDate;
}

Users::jobs Users::User::getJobID() const
{
    return jobID;
}

int Users::User::getCardID() const
{
    return cardID;
}

std::string Users::User::getPassword() const
{
    return password;
}

Users::User::User()
{

}

Users::User::User(const std::string &_firstName, const std::string &_lastName, const std::string &_username, date _birthDate, Users::jobs _jobID, int _cardID, const std::string &_password):
    firstName(_firstName),
    lastName(_lastName),
    username(_username),
    birthDate(_birthDate),
    jobID(_jobID),
    cardID(_cardID),
    password(_password)
{
}

Users::User::~User()
{
}
