#include "janitor.h"

Users::Janitor::Janitor(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
    Users::User::User(_firstName , _lastName , _username, _birthDate , _jobID , _cardID , _password)
    {
        this->firstName = _firstName;
        this->lastName = _lastName;
        this->username = _username;
        this->birthDate = _birthDate;
        this->jobID = _jobID;
        this->cardID = _cardID;
    this->password = _password;
}

void Users::Janitor::logFixStuff(std::string &item, int roomId, std::string &reason, double cost, std::string &date, time_t startTime, time_t endTime) const
{

}

void Users::Janitor::logReplaceStuff(std::string &item, int roomId, std::string &reason, double cost, std::string &date) const
{

}

void Users::Janitor::logDoneTask(std::string &taskId, std::string &data) const
{

}

void Users::Janitor::printTasks() const
{

}

void Users::Janitor::printLogs() const
{

}

Users::Janitor::~Janitor()
{

}
