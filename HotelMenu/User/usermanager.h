#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User/user.h"
#include "User/cleaner.h"
#include "User/guest.h"
#include "User/janitor.h"
#include "User/manager.h"
#include "User/receptionist.h"
#include "iterator"
class UserManager
{
private:
    //VARIABLES
    bool userlogged;
    Users::User* loggedUser;   
    std::map<std::string,Users::User*>users;


public:
    //CONSTRUCTORS
    UserManager(std::list<Users::User *>_users);
    UserManager();

    //FUNCTIONS
    bool isLoggedIn() const;
    bool isLoggedOut() const;
    bool loggedPermissionCheck(std::string task_type) const;
    void addUser(std::string& _username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password);

    void logout();
    void loginWith(std::string username, std::string password);
    void deleteUser(std::string username);
    void addTask(std::string username, Tasks::Task one_task);
    void deleteTask(std::string task_id_del);
    void printMyTask() const;
    void printAllTask() const;
    void printLogs() const;
    void logTask(std::string task_id, std::string data);

    class WrongUsernameException:public std::exception
        {
            virtual const char * what() const throw()
            {
                return "Wrong username!";
            }
        };

        class WrongPasswordException:public std::exception
        {
            virtual const char * what() const throw()
            {
                return "Wrong password!";
            }
        };
        class NoPasswordException:public std::exception
        {
            virtual const char * what() const throw()
            {
                return "You have to give your password!";
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

#endif // USERMANAGER_H
