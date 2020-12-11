#include "manager.h"

Users::Manager::Manager(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
    Users::User::User(_firstName , _lastName , _username, _birthDate , _jobID , _cardID , _password)
    {
        this->firstName = _firstName;
        this->lastName = _lastName;
        this->username = _username;
        this->birthDate = _birthDate;
        this->jobID = _jobID;
        this->cardID = _cardID;
        this->password = _password;
        taskCont=TaskContainer();
    }

Users::Manager::~Manager()
{

}

void Users::Manager::setTaskStatus(std::string taskID)
{
    //NE LEGYEN ABSZTRAKT
}

void Users::Manager::printTasks() const
{
    //NE LEGYEN ABSZTRAKT
}

void Users::Manager::printLogs() const
{
    //NE LEGYEN ABSZTRAKT
}

