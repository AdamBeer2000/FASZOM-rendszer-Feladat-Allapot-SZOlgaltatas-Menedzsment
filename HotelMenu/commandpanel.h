#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include <map>
#include <algorithm>
#include "login.h"
#include "task.h"

class CommandPanel
{
private:

    std::map<std::string, Tasks::Task> rename_this_please;
    void logIn(); //Egy felhasználó bejelentkezését valósítja meg
    Login logger;
public:

    CommandPanel(std::list<Users::User*> users);
    void doStuff();//gyakorlatilag egy main

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
        cExit,
    };
    Commands resolveOption(std::string input) {
        if( input == "login" ) return cLogin;
        if( input == "logout" ) return cLogout;
        if( input == "exit" ) return cExit;
        return Invalid;
     }
};

#endif // COMMANDPANEL_H
