#ifndef CLEANER_H
#define CLEANER_H
#include "User.h"

namespace Users
{
    class Cleaner : public Users::User
    {
    public:
        Cleaner(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password);
        void logDoneTask(std::string& taskId , std::string& data) const;
        void logCleanedRoom(int roomid) const;
        void logCleanedRoomWithLostItem(int roomID , std::string& item , time_t date) const;
        void printTasks() const;
        void printLogs() const;
        ~Cleaner();
    };
}
#endif // CLEANER_H
