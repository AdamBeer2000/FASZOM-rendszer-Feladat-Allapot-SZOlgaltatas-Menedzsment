#ifndef GUEST_H
#define GUEST_H
#include "user.h"

namespace Users
{
    class Guest:public Users::User
    {
    public:
        Guest(const std::string& _username, const std::string& _password);
        void doWork()const;
        User *clone()const;
    };
}



#endif // GUEST_H
