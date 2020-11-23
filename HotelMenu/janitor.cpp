#include "janitor.h"

Users::Janitor::Janitor(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
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

void Users::Janitor::logFixStuff(std::string& taskID , std::string &item, int roomId, std::string &reason, double cost, struct date startTime, struct date endTime)
{
    Logs::LogFix l = Logs::LogFix(roomId , item , reason, cost, startTime , endTime);
    taskCont.setLog(taskID , &l);
    taskCont.setStatusDone(taskID);
}

void Users::Janitor::logReplaceStuff(std::string& taskID , std::string &item, int roomId, std::string &reason, double cost, date date)
{
    Logs::LogReplace l = Logs::LogReplace(roomId , item , reason, cost, date);
    taskCont.setLog(taskID , &l);
    taskCont.setStatusDone(taskID);
}

void Users::Janitor::printTasks() const
{
    taskCont.printAllTask();
}

void Users::Janitor::printLogs() const
{
    taskCont.printAllLog();
}

Users::Janitor::~Janitor()
{

}
