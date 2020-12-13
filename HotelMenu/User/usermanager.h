#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User/user.h"
#include "User/cleaner.h"
#include "User/guest.h"
#include "User/janitor.h"
#include "User/manager.h"
#include "User/receptionist.h"
#include "iterator"
#include "datebuilder.h"
#include <fstream>
class UserManager
{
private:
    //VARIABLES
    bool userlogged;
    Users::User* loggedUser;   
    std::map<std::string,Users::User*>users;
    std::map<std::string, std::string>tasklink;
public:
    //CONSTRUCTORS
    UserManager(std::list<Users::User *>_users);
    UserManager();
    ~UserManager()
    {
        printAllTask();
    }
    //FUNCTIONS
    bool isLoggedIn() const;
    bool isLoggedOut() const;

    Users::jobs getLoggedJob() const;

    void addUser(std::string _username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password);
    void addUser(Users::User * newUser);

    void loadContent(std::string user_file_name,std::string task_file_name);
    void saveContent(std::string user_file_name,std::string task_file_name);

    void logout();
    void loginWith(std::string username, std::string password);
    void deleteUser(std::string username);
    void addTask(std::string username, Tasks::Task one_task);
    void deleteTask(std::string task_id_del);

    void printMyTask() const;
    void printAllTask() const;
    void printLogs() const;
    void printTasksLogged() const;

    void logTask(std::string task_id, Logs::Log * onelog);
    void logTask(std::string username,std::string task_id, Logs::Log * onelog);

    void setTaskStatusDone(std::string username, std::string task_id);
    void setTaskStatusDone(std::string task_id);
    std::string getLeastBusyWorker(Users::jobs jobID);

    Tasks::Task getTask(std::string user,std::string task_id);
    int getRoomId(std::string username,std::string taskid);
    Users::jobs getJobIdOf(std::string username);

    bool existUser(std::string username);

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

        class AlreadyLoged:public std::exception
        {
            virtual const char * what() const throw()
            {
                return "You are already logged in";
            }
        };

        Users::User *getLoggedUser() const;
        std::map<std::string, std::string> getTasklink() const;
};

#endif // USERMANAGER_H
