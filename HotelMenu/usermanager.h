#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"

class UserManager
{
private:
    //VARIABLES
    bool userlogged;
    Users::User* loggedUser;

public:
    //CONSTRUCTORS
    UserManager();

    //FUNCTIONS
    bool isLoggedIn() const;
    bool isLoggedOut() const;
    bool loggedPermissionCheck(std::string task_type) const;
    void addUser(std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password);
    void logout();
    void loginWith(std::string username, std::string password);
    void deleteUser(std::string username);
    void addTask(std::string username, Tasks::Task one_task);
    void deleteTask(std::string task_id_del);
    void printMyTask() const;
    void printAllTask() const;
    void printLogs() const;
    void logTask(std::string task_id, std::string data);

};

#endif // USERMANAGER_H
