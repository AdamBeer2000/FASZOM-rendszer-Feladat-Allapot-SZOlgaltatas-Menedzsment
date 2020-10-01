#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H
#include "Login.h"

class CommandPanel:public Login
{
    void login();
public:

    CommandPanel(std::list<User>&users);
    void doStuff();//gyakorlatilag egy main
    void logIn(); //Egy felhasználó bejelentkezését valósítja meg
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
