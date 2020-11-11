#ifndef RIGHTSANDCOMMANDS_H
#define RIGHTSANDCOMMANDS_H
#include "map"
#include "string"

namespace  Users
{
    enum jobs {
        CLE,
        MAN,
        JAN,
        REC,
        GUE
    };
    class User
    {

        std::string username;
        std::string password;
        jobs jobID;
    public:
        User();
        User(const std::string& _username, const std::string& _password,jobs _jobID);
        std::string getPassword() const;
        std::string getUsername() const;
        virtual void doWork()const=0;
        virtual User * clone()const=0;
        virtual ~User();

    };
} // eof Users


#endif // RIGHTSANDCOMMANDS_H
