#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include "Login.h"
#include "Task/task.h"

class CommandPanel
{
private:

    //std::map<std::string, Tasks::Task> rename_this_please;

    //Egy felhasználó bejelentkezését valósítja meg
    //Login logger;

    //all
    void login();
    void logout();
    void reportLostItem();
    void exit();

    //all worker
    void printMyTasks();

    //guest
    void registration();
    void bookRoom();
    void rating();

    //managger
    void createTask();
    void deleteTask();
    void createEmployee();
    void emploYeet();
    void printAllTasks();
    void printAllLogs();

    //janitor
    void fix();
    void replace();

    //cleaner
    void cleanroom();

    //recepcionist
    void acceptReservation();
    void denyReservation();
    void printLostItems();
    void changeRoomStatus();


public:
    CommandPanel(std::list<Users::User*> users);
    void seudoMain();//gyakorlatilag egy main

    void ricroll();//Rick Roll
    class CommandNotFoundException:public std::exception
    {
        std::string massage;
        public:
        CommandNotFoundException(std::string command)//Nem talált parancs kivétel
        {
            std::stringstream ss;
            ss<<command<<"-is an invalid command";
            massage=ss.str();
        }
        CommandNotFoundException()
        {
            massage="wrong commans";
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
    enum Commands {
        Invalid,
        cLogin,
        cLogout,
        cReport,
        cExit,
        cPrintMyTask,
        cReg,
        cBook,
        cRate,
        cCreateTask,
        cDeleteTask,
        cCreateEmployee,
        cEmploYeet,
        cPrintAllTask,
        cPrintAllLogs,
        cFix,
        cReplace,
        cClean,
        cAcceptRes,
        cDenyRes,
        cPrintLostItems,
        cChangeRoomStatus
    };
    Commands resolveOption(std::string input)
    {
        std::transform(input.begin(), input.end(), input.begin(),[](unsigned char c){ return std::tolower(c);});
        if( input == "login" ) return cLogin;
        if( input == "logout" ) return cLogout;
        if( input == "exit" ) return cExit;
        return Invalid;
     }
};

#endif // COMMANDPANEL_H
