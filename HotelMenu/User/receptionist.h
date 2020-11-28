#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include "User.h"
#include "enumSuit.h"
#include "enumServing.h"

namespace Users
{
    class Receptionist : public Users::User
    {
    public:
        Receptionist(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password);

        void logReservation(std::string& taskID , int roomID , std::string& name , Suit::suitTypes apartment , Serving::servingTypes serving , double cost , date startTime , date endTime);

        void printTasks() const;

        void printLogs() const;

        ~Receptionist();
    };
}

#endif // RECEPTIONIST_H
