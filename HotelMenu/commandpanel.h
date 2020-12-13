#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include "Login.h"
#include "Task/task.h"
#include "datacommunicationcenter.h"
#include "User/usermanager.h"//KIVENNI
#include "User/user.h"//KIVENNI
class CommandPanel
{
private:
    enum Commands {
        Invalid,
        cLogin,             //login
        cLogout,            //logout
        cExit,              //exit
        cReportLostItem,    //report lost          report l
        cReportDirtyRoom,   //report dirty         report d
        cPrintMyTask,       //print task            print t
        cReg,               //registrate
        cBook,              //book
        cRate,              //rate
        cCreateTask,        //create task           create t
        cDeleteTask,        //delete task           delete t
        cCreateEmployee,    //create employee       create e
        cEmploYeet,         //delete employee       create e
        cPrintAllTask,      //print all task        print at
        cPrintAllLogs,      //print all log         print al
        cFix,               //fix
        cReplace,           //replace
        cTakeClean,         //take clean            take c
        cLogClean,          //log clean             log c
        cAcceptRes,         //accept reservation    accept r
        cDenyRes,           //deny reservation      deny r
        cPrintLostItems,    //print lost            print l
        cChangeRoomStatus,  //change room
        cCheckhOut,         //checkout
    };
    //Egy felhasználó bejelentkezését valósítja meg
    //Login logger;

    //all
    void login();
    void logout();
    void reportLostItem();
    void exit();
    void registration();

    //all worker
    void printMyTasks();

    //guest
    void bookRoom();
    void rating();
    void reportDeartyRoom();
    void checkhOut();

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
    void takeCleanroom();
    void logCleanroom();

    //recepcionist
    void acceptReservation();
    void denyReservation();
    void printLostItems();
    void changeRoomStatus();



    bool permissionCheck(Commands a);
    std::shared_ptr<DataCommunicationCenter> data_com;

public:
    CommandPanel():data_com(DataCommunicationCenter::getInstance())
    {
    }
    CommandPanel(std::list<Users::User*> users);
    void pseudoMain();//gyakorlatilag egy main

    void TEST()
    {
        Tasks::Task t3 = data_com->generateTask(Users::jobs::JAN, Users::taskdata::FIX ,"Elon Musk", "Mars");
        Tasks::Task t4 = data_com->generateTask(Users::jobs::CLE, Users::taskdata::CLN,"George Soros", "Soros terv");
        Tasks::Task t5 = data_com->generateTask(Users::jobs::CLE, Users::taskdata::CLN,"Gyurcsany Ferenc", "Elbaszni, nem kicsit, nagyon");
        Tasks::Task t6 = data_com->generateTask(Users::jobs::JAN, Users::taskdata::REP,"George Soros", "Soros terv");
        TaskContainer t = TaskContainer();
        UserManager u = UserManager();
        DateBuilder builder = DateBuilder();

        date d;
        d.day = 2;
        d.month = 9;
        d.year = 2000;

        Users::User *jozsi = new Users::Cleaner("Jozsef","Gyurcsany","jozsi",builder.build(2000, 10, 25), Users::jobs::CLE,5,"password");
        u.addUser("Feri","Ferenc","Gyurcsany",builder.build(2000,11,16),Users::jobs::CLE,69420,"pass");
        u.addUser(jozsi);

        u.addTask("Feri",t3);
        u.addTask("Feri",t4);
        u.addTask(jozsi->getUsername(),t5);
        u.printAllTask();
    }

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

    class NoPermissonException:public std::exception
    {
        std::string massage;
        public:
        NoPermissonException(Commands command)//Jogosulatlan próbálkozás
        {
            std::stringstream ss;
            switch (command)
            {
                case cPrintMyTask:ss<<"you have no perrmison to printing your tasks";break;
                case cReg:ss<< "you have no acces to registracion or are you already logged in";break;
                case cBook:ss<< "you have no perrmisson to boking rooms";break;
                case cRate:ss<< "placeholder";break;
                case cCreateTask:ss<< "placeholder";break;
                case cDeleteTask:ss<< "placeholder";break;
                case cCreateEmployee:ss<< "placeholder";break;
                case cEmploYeet:ss<< "placeholder";break;
                case cPrintAllTask:ss<< "placeholder";break;
                case cPrintAllLogs:ss<< "placeholder";break;
                case cFix:ss<< "placeholder";break;
                case cReplace:ss<< "placeholder";break;
                case cTakeClean:ss<< "placeholder";break;
                case cLogClean:ss<< "placeholder";break;
                case cAcceptRes:ss<< "placeholder";break;
                case cDenyRes:ss<< "placeholder";break;
                case cPrintLostItems:ss<< "placeholder";break;
                case cChangeRoomStatus:ss<< "placeholder";break;
                default:ss<<"NoPermissonException";break;
            }
            massage=ss.str();
        }
        NoPermissonException()
        {
            massage="no permisson";
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };


    Commands resolveOption(std::string input)
    {
        std::string originalinput=input;
        std::string temp;
        std::string inputs[3]={"","",""};
        std::transform(input.begin(), input.end(), input.begin(),[](unsigned char c){ return std::tolower(c);});
        //data_dom.permissionCheck();
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
        if( inputs[0] == "checkout")return cCheckhOut;
        if( inputs[0] == "fix" ) return cFix;
        if( inputs[0] == "replace" ) return cReplace;
        if( inputs[0] == "registrate" ) return cReg;
        if( inputs[0] == "book" ) return cBook;
        if( inputs[0] == "rate" ) return cRate;
        if( inputs[0] == "exit" ) return cExit;

        if( inputs[0] == "report" )
        {
            if( inputs[1]=="lost")return cReportLostItem;
            if( inputs[1]=="l")return cReportLostItem;
            if( inputs[1]=="dirty")return cReportDirtyRoom;
            if( inputs[1]=="d")return cReportDirtyRoom;
            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }

        if(inputs[0]=="take")
        {
            if( inputs[1] == "clean" )return cTakeClean;
            if( inputs[1] == "c")return cTakeClean;
            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }
        if(inputs[0]=="log")
        {
            if( inputs[1] == "clean" )return cLogClean;
            if( inputs[1] == "c")return cLogClean;
            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }
        if(inputs[0]=="print")
        {
            if( inputs[1] == "tasks" )return cPrintMyTask;
            if( inputs[1] == "t" ) return cPrintMyTask;
            if( inputs[1] == "at" ) return cPrintAllTask;
            if( inputs[1]  == "al" ) return cPrintAllLogs;

            if(inputs[1]=="all")
            {
                if( inputs[2] == "task" )return cPrintAllTask;
                if( inputs[2] == "log" ) return cPrintAllLogs;
                if(inputs[2]==inputs[1])
                {
                    throw IncompleteCommandException(originalinput);
                }
                else
                {
                    if(originalinput!=""&&originalinput!=" ")
                    throw CommandNotFoundException(originalinput);
                }
            }
            if(inputs[1]=="lost")
            {
                return cPrintLostItems;
            }
            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }

        if(inputs[0]=="create")
        {
            if( inputs[1] == "task" ) return cCreateTask;
            if( inputs[1] == "t" ) return cCreateTask;

            if( inputs[1] == "employee" ) return cCreateEmployee;
            if( inputs[1] == "e" ) return cCreateEmployee;

            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }

        if(inputs[0]=="delete")
        {
            if( inputs[1] == "task" ) return cDeleteTask;
            if( inputs[1] == "t" ) return cDeleteTask;

            if( inputs[1] == "employee" ) return cEmploYeet;
            if( inputs[1] == "e" ) return cEmploYeet;

            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }

        if(inputs[0]=="accept")
        {
            if( inputs[1] == "reservation" ) return cAcceptRes;
            if( inputs[1] == "r" ) return cAcceptRes;

            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }

        if(inputs[0]=="deny")
        {
            if( inputs[1] == "reservation" ) return cDenyRes;
            if( inputs[1] == "r" ) return cDenyRes;

            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }

        if(inputs[0]=="change")
        {
            if( inputs[1] == "room") return cChangeRoomStatus;

            if(inputs[1]==inputs[0])
            {
                throw IncompleteCommandException(originalinput);
            }
            else
            {
                if(originalinput!=""&&originalinput!=" ")
                throw CommandNotFoundException(originalinput);
            }
        }
        if(originalinput!=""&&originalinput!=" ")
        {
            throw CommandNotFoundException(originalinput);
        }
        return Invalid;
     }
};

#endif // COMMANDPANEL_H
