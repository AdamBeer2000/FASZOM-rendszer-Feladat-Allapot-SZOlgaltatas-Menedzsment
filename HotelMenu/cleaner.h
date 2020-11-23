#ifndef CLEANER_H
#define CLEANER_H
#include "User.h"
#include "logcleaning.h"

namespace Users
{
    class Cleaner : public Users::User
    {
    public:
        Cleaner(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password);

        void logCleanedRoom(std::string& taskID , int roomid , date date);
        void logCleanedRoomWithLostItem(std::string& taskID , int roomID , std::string& item , date date);
        void printTasks() const;
        void printLogs() const;
        ~Cleaner();
    };
}
#endif // CLEANER_H
