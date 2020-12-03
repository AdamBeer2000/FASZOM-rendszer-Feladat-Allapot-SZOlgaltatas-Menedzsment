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
    CommandPanel();
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
    class IncompleteCommandException:public std::exception
    {
        std::string massage;
        public:
        IncompleteCommandException(std::string command)//Nem befejezett parancs
        {
            std::stringstream ss;
            ss<<command<<"-is an incomplete command";
            massage=ss.str();
        }
        IncompleteCommandException()
        {
            massage="incomplete commands";
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
    enum Commands {
        Invalid,
        cLogin,             //login
        cLogout,            //logout
        cExit,              //exit
        cReport,            //report
        cPrintMyTask,       //print task    print mt
        cReg,               //registrate
        cBook,              //book
        cRate,              //rate
        cCreateTask,        //create task       create t
        cDeleteTask,        //delete task       delete t
        cCreateEmployee,    //create employee   create e
        cEmploYeet,         //delete employee   create e
        cPrintAllTask,      //print all task    print at
        cPrintAllLogs,      //print all log     print al
        cFix,               //fix
        cReplace,           //replace
        cClean,             //clean
        cAcceptRes,         //accept reservation    accept r
        cDenyRes,           //deny reservation      deny r
        cPrintLostItems,    //print lost            print l
        cChangeRoomStatus   //change room
    };
    Commands resolveOption(std::string input)
    {
        std::string originalinput=input;
        std::string temp;
        std::string inputs[3];
        std::transform(input.begin(), input.end(), input.begin(),[](unsigned char c){ return std::tolower(c);});

        unsigned int i=0;
        while (i<3)
        {
            temp=input.substr(0,input.find(' '));
            inputs[i]=input.substr(0,input.find(' '));
            input=input.substr(input.find(' ')+1,input.size());
            i++;
        }
        if( inputs[0] == "login" ) return cLogin;
        if( inputs[0] == "logout" ) return cLogout;
        if( inputs[0] == "report" ) return cReport;
        if( inputs[0] == "fix" ) return cFix;
        if( inputs[0] == "replace" ) return cReplace;
        if( inputs[0] == "clean" ) return cClean;
        if( inputs[0] == "registrate" ) return cReg;
        if( inputs[0] == "book" ) return cBook;
        if( inputs[0] == "rate" ) return cRate;
        if( inputs[0] == "exit" ) return cRate;

        if(inputs[0]=="print")
        {
            if( inputs[1] == "tasks" ) return cPrintMyTask;
            if( inputs[1] == "t" ) return cPrintMyTask;
            if( inputs[1] == "at" ) return cPrintAllTask;
            if( inputs[1]  == "al" ) return cPrintAllLogs;

            if(inputs[1]=="all")
            {
                if( inputs[2] == "task" ) return cPrintAllTask;
                if( inputs[2] == "log" ) return cPrintAllLogs;

                throw IncompleteCommandException(originalinput);
            }
            if(inputs[1]=="lost")
            {
                return cPrintLostItems;
            }
            throw IncompleteCommandException(originalinput);
        }
        if(inputs[0]=="create")
        {
            if( inputs[1] == "task" ) return cCreateTask;
            if( inputs[1] == "t" ) return cCreateTask;

            if( inputs[1] == "employee" ) return cCreateEmployee;
            if( inputs[1] == "e" ) return cCreateEmployee;
        }

        if(inputs[0]=="delete")
        {
            if( inputs[1] == "task" ) return cDeleteTask;
            if( inputs[1] == "t" ) return cDeleteTask;

            if( inputs[1] == "employee" ) return cEmploYeet;
            if( inputs[1] == "e" ) return cEmploYeet;
            throw IncompleteCommandException(originalinput);
        }

        if(inputs[0]=="accept")
        {
            if( inputs[1] == "reservation" ) return cAcceptRes;
            if( inputs[1] == "r" ) return cAcceptRes;
            throw IncompleteCommandException(originalinput);
        }

        if(inputs[0]=="deny")
        {
            if( inputs[1] == "reservation" ) return cDenyRes;
            if( inputs[1] == "r" ) return cDenyRes;
            throw IncompleteCommandException(originalinput);
        }

        if(inputs[0]=="change")
        {
            if( inputs[1] == "room") return cChangeRoomStatus;
            throw IncompleteCommandException(originalinput);
        }
        throw CommandNotFoundException(originalinput);
        return Invalid;
     }
};

#endif // COMMANDPANEL_H
