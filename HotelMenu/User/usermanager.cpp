#include "usermanager.h"

UserManager::UserManager(std::list<Users::User *>_users)
{
    for(auto user : _users)
    {
        users.insert(std::pair<std::string,Users::User*>(user->getUsername(),user));
    }
}

UserManager::UserManager()
{

}

bool UserManager::isLoggedIn() const
{
    return loggedUser;
}

bool UserManager::isLoggedOut() const
{
    return loggedUser;
}

void UserManager::addUser(std::string& username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password)
{
    Users::User* added_user;
    switch(position)
    {
        case Users::jobs::CLE:
            *added_user = Users::Cleaner(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::GUE:
            *added_user = Users::Guest(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::JAN:
            *added_user = Users::Janitor(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::REC:
            *added_user = Users::Receptionist(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::MAN:
            *added_user = Users::Manager(first_name, last_name, username, birth_date, position,card_id, password);
            break;
    }

    users.insert({username, added_user});
}

void UserManager::loginWith(std::string username, std::string password)
{
        if(isLoggedIn())
        {
            throw AlrreadyLoged();
        }

        std::map<std::string,Users::User *>::iterator finduser;
        finduser=users.find(username);

        if(finduser!=users.end())
        {
            if(finduser->second->getPassword()==password)
            {
                loggedUser=finduser->second;
                std::cout<<"\nLogged in"<<std::endl;
            }
            else
            {
                throw WrongPasswordException();
            }
        }

        if(isLoggedOut())
        {
            throw WrongUsernameException();
        }
}

void UserManager::deleteUser(std::string username)
{
    users.find(username);
}

void UserManager::setTaskStatusDone(std::string username,std::string task_id)
{
    //users.find(username)->second  wip
}

void UserManager::printMyTask() const
{
    loggedUser->printTasks();
}

void UserManager::logTask(std::string task_id, Logs::Log *onelog)
{
    auto it = users.find(task_id);
    if(it!=users.end())
    {
        users.find(task_id)->second->setLog(task_id,onelog);
    }
    else
    {
        throw Tasks::Task::InvalidTaskException("Nincs task: "+task_id+"-idval");
    }
}

void UserManager::logout()
{
    if(isLoggedIn())
    {
        loggedUser=nullptr;
        std::cout<<"\nLogged out"<<std::endl;
    }
}


