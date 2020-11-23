#ifndef GUEST_H
#define GUEST_H
#include "User.h"

namespace Users
{
    class Guest : public Users::User
    {
    public:
        Guest(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password);

        void printTasks() const;
        void printLogs() const;
        ~Guest();
    };
}



#endif // GUEST_H
