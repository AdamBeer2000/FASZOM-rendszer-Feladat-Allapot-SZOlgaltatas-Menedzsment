#ifndef RIGHTSANDCOMMANDS_H
#define RIGHTSANDCOMMANDS_H
#include "map"
#include "string"
#include "date.h"
#include "Task/taskcontainer.h"
#include "Log/log.h"

namespace  Users
{
    enum jobs {
        CLE,
        MAN,
        JAN,
        REC,
        GUE,
        ERR,
        ADM,
        Unlogged,
    };

    enum taskdata {
        FIX,
        REP,
        RES,
        CLF,//with talált tárgy
        CLN, //without talált tárgy
        ER2
    };

    inline jobs stringToJobID(std::string onejobid)
    {
        if(onejobid=="CLE") return CLE;
        if(onejobid=="MAN") return MAN;
        if(onejobid=="JAN") return JAN;
        if(onejobid=="REC") return REC;
        if(onejobid=="GUE") return REC;
        //todo excepcion
    }
    inline std::string JobIDToString(jobs job)
    {
        if(job==CLE) return "CLE";
        if(job==MAN) return "MAN";
        if(job==JAN) return "JAN";
        if(job==REC) return "REC";
        if(job==REC) return "REC";
        //todo excepcion
    }

    inline taskdata stringToTaskdata(std::string onetastdata)
    {
        if(onetastdata=="FIX") return FIX;
        if(onetastdata=="REP") return REP;
        if(onetastdata=="RES") return RES;
        if(onetastdata=="CLF") return CLF;
        if(onetastdata=="CLN") return CLN;
        //todo exc
    }
    inline std::string taskdataToString(taskdata onetastdata)
    {
        if(onetastdata==FIX) return "FIX";
        if(onetastdata==REP) return "REP";
        if(onetastdata==RES) return "RES";
        if(onetastdata==CLF) return "CLF";
        if(onetastdata==CLN) return "CLN";
        //todo exc
    }

//todo excepcion


    class User
    {
    protected:

        std::string firstName;
        std::string lastName;
        std::string username;
        date birthDate;
        jobs jobID;
        int cardID;
        std::string password;
        TaskContainer taskCont = TaskContainer();

    public:
        User();
        User(const std::string& _firstName , const std::string& _lastName , const std::string& _username , date _birthDate , jobs _jobID , int _cardID , const std::string& _password);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getUsername() const;
        date getBirthDate() const;
        jobs getJobID() const;
        int getCardID() const;
        std::string getPassword() const;

        int getRoomId(std::string taskid);

        Tasks::Task getTask(std::string taskId);
        Reservation getReserv(std::string task_id);

        int getNumberOfTasks() const;

        void setLog(const std::string& task_id , Logs::Log* onelog);

        void addTask(Tasks::Task oneTask);

        void deleteTask(std::string& TaskId);

        virtual void setTaskStatus(std::string taskID) = 0;

        virtual void printTasks()const = 0;

        //virtual void printLogs()const = 0;

        virtual void printLogs() const=0;

        virtual ~User();

        void saveAlltask(std::ofstream & myesfile);


    };
} // eof Users


#endif // RIGHTSANDCOMMANDS_H
