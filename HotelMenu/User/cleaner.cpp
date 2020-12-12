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
        taskCont=TaskContainer();
}

void Users::Cleaner::logCleanedRoom(std::string &taskID, int roomid , date date)
{
    Logs::LogCleaning l = Logs::LogCleaning(date);
    taskCont.setLog(taskID , &l);
    taskCont.setStatusDone(taskID);
}

void Users::Cleaner::logCleanedRoomWithLostItem(std::string& taskID , int roomID, std::string &item, date date)
{
    Logs::LogCleaning l = Logs::LogCleaning(item , date);
    taskCont.setLog(taskID , &l);
}

void Users::Cleaner::setTaskStatus(std::string taskID)
{
    taskCont.setStatusDone(taskID);
}

void Users::Cleaner::printTasks() const
{
    taskCont.printAllTask();
}

void Users::Cleaner::printLogs() const
{
    taskCont.printAllLog();
}

Users::Cleaner::~Cleaner()
{

}
