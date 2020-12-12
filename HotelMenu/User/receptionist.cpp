#include "receptionist.h"

Users::Receptionist::Receptionist(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
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

void Users::Receptionist::logReservation(std::string& taskID , int roomID , std::string& name , Suit::suitTypes apartment , Serving::servingTypes serving , double cost , date startTime , date endTime)
{
    Logs::LogReservation l = Logs::LogReservation(name , apartment , serving , cost , startTime, endTime);
    taskCont.setLog(taskID , &l);
    taskCont.setStatusDone(taskID);
}

void Users::Receptionist::setTaskStatus(std::string taskID)
{
    taskCont.setStatusDone(taskID);
}

void Users::Receptionist::printTasks() const
{
    taskCont.printAllTask();
}

//void Users::Receptionist::printLogs() const
//{
//    taskCont.printAllLog();
//}

Users::Receptionist::~Receptionist()
{

}
