#include "guest.h"


Users::Guest::Guest(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
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

void Users::Guest::setTaskStatus(std::string taskID)
{
    //NE LEGYEN ABSZTRAKT
}

void Users::Guest::printTasks() const
{
    //NE LEGYEN ABSZTRAKT
}

void Users::Guest::printLogs() const
{
    //NE LEGYEN ABSZTRAKT
}

Users::Guest::~Guest()
{

}

