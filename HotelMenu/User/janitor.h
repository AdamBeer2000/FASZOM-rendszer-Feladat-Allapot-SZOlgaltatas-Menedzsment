#ifndef JANITOR_H
#define JANITOR_H
#include "User/user.h"
#include "Log/logfix.h"
#include "Log/logreplace.h"

namespace Users
{
    class Janitor : public Users::User
    {
    public:
        Janitor(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password);

        void logFixStuff(std::string& taskID , std::string& item , int roomId , std::string& reason , double cost , struct date startTime , struct date endTime);

        void logReplaceStuff(std::string& taskID , std::string& item , int roomId , std::string& reason , double cost , date date);

        void setTaskStatus(std::string taskID);

        void printTasks() const;

        // printLogs() const;

        ~Janitor();
    };
}

#endif // JANITOR_H
