#ifndef RIGHTSANDCOMMANDS_H
#define RIGHTSANDCOMMANDS_H
#include "map"
#include "string"
#include "date.h"
#include "taskcontainer.h"
#include "log.h"

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
    protected:
        std::string firstName;
        std::string lastName;
        std::string username;
        struct date birthDate;
        jobs jobID;
        int cardID;
        std::string password;
        TaskContainer taskCont;
    public:
        User();
        User(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getUsername() const;
        date getBirthDate() const;
        jobs getJobID() const;
        int getCardID() const;
        std::string getPassword() const;

        void setLog(const std::string& task_id , Logs::Log* onelog);

        virtual void doWork()const=0;
        virtual User * clone()const=0;
        virtual ~User();


    };
} // eof Users


#endif // RIGHTSANDCOMMANDS_H
