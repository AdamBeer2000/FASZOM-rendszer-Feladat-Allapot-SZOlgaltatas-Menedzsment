#include "cleaner.h"

Users::Cleaner::Cleaner(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
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

void Users::Cleaner::logDoneTask(std::string &taskId, std::string &data) const
{

}

void Users::Cleaner::logCleanedRoom(int roomid) const
{

}

void Users::Cleaner::logCleanedRoomWithLostItem(int roomID, std::string &item, time_t date) const
{

}

void Users::Cleaner::printTasks() const
{

}

void Users::Cleaner::printLogs() const
{

}

Users::Cleaner::~Cleaner()
{

}
