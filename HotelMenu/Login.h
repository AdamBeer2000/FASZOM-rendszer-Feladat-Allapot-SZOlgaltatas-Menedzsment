#ifndef MENU_H
#define MENU_H
#include "string"
#include "user.h"
#include "list"
#include "algorithm"
#include "vector"
#include "exception"
#include "sstream"
#include "cstring"
#include "iostream"

class Login
{
    std::list<Users::User>users;
    Users::User logged_user;
    bool userloggeed;
public:
    Login(std::list<Users::User>&users);
    void LogInWith(std::string username,std::string password);
    void logOut();
    bool isLoggedIn();
    bool isLoggedOut();
    std::string getLoggedUsername() const;

    class NotExistingUsernameException:public std::exception
    {
        std::string massage;
        public:
        NotExistingUsernameException()
        {

        }
        NotExistingUsernameException(std::string username)
        {
            std::stringstream ss;
            ss<<"No user fund with: '"<<username<<"'-username";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };

    class WrongPasswordException:public std::exception
    {
        virtual const char * what() const throw()
        {
            return "Wrong password!";
        }
    };

    class AlrreadyLoged:public std::exception
    {
        virtual const char * what() const throw()
        {
            return "You are already logged in";
        }
    };

};

#endif // MENU_H
