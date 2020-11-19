#ifndef JANITOR_H
#define JANITOR_H
#include "User.h"

namespace Users
{
    class Janitor : public Users::User
    {
    public:
        Janitor(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password);
        void logFixStuff(std::string& item , int roomId , std::string& reason , double cost , std::string& date , time_t startTime , time_t endTime) const;
        void logReplaceStuff(std::string& item , int roomId , std::string& reason , double cost , std::string& date) const;
        void logDoneTask(std::string& taskId , std::string& data) const;
        void printTasks() const;
        void printLogs() const;
        ~Janitor();
    };
}

#endif // JANITOR_H
