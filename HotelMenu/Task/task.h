#ifndef TASK_H
#define TASK_H

#include <exception>
#include <iostream>
#include <string>
#include "Log/log.h"
#include "Log/logcleaning.h"
#include "Log/logreplace.h"
#include "Log/logreservation.h"
#include "Log/logfix.h"
#include "Reservation/reservation.h"

namespace Tasks
{

    class Task
    {
    private:

        //VARIABLES
        std::string employee;
        std::string task_id; //UNIQUE
        std::string todo;
        bool status=false;
        Logs::Log* log;
        Reservation res;
        int roomid;

    public:
        //EXCEPTION CLASS
        class InvalidTaskException: public std::exception
        {
        private:
            std::string msg;

        public:
            InvalidTaskException(const std::string& msg_c): msg(msg_c) {}
            virtual ~InvalidTaskException(){}

            virtual const char* what() const noexcept override
            {
                return msg.c_str();
            }
        };


        //CONSTRUCTORS
        Task(std::string employee,std::string task_id,std::string todo,bool status);
        Task(std::string _employee, std::string _task_id, Reservation res, bool _status);
        Task(std::string _employee, std::string _task_id, Reservation res,int roomid);

        //DESTRUCTOR
        ~Task();

        //FUNCTIONS
        static bool isValid(const std::string& data);
        static bool isValidId(const std::string& task_id_v);
        void printTask() const;
        std::string statusToString(bool stat) const;
        bool isActive() const;
        bool isActive();
        bool isFinished() const;
        void printLog() const;
        void backupSaveStream(std::ofstream& stream);

        //GETTERS
        std::string getEmployee() const;
        std::string getTaskId() const;
        std::string getTodo() const;
        bool getStatus() const;

        //SETTERS
        void setStatus(bool value);
        void setLog(Logs::Log* log);
        int getRoomid() const;
        void setRoomid(int value);

        Reservation getRes() const;
    };
} // eof Tasks
#endif // TASK_H
