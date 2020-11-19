#include "receptionist.h"

Users::Receptionist::Receptionist(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
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

void Users::Receptionist::logReservation(std::string &name, Suit::suitTypes apartment, Serving::servingTypes serving, time_t startTime, time_t endTime) const
{

}

void Users::Receptionist::logDoneTask(std::string &taskId, std::string &data) const
{

}

void Users::Receptionist::printTasks() const
{

}

void Users::Receptionist::printLogs() const
{

}

Users::Receptionist::~Receptionist()
{

}
