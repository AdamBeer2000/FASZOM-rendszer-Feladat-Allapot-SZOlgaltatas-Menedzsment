#include "usermanager.h"

UserManager::UserManager(std::list<Users::User *>_users)
{
    for(auto user : _users)
    {
        users.insert(std::pair<std::string,Users::User>(user->getUsername(),user));
    }
}

void UserManager::loginWith(std::string username, std::string password)
{
        if(userlogged)
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

void UserManager::logout()
{
    if(userlogged)
    {
        delete loggedUser;
        loggedUser=nullptr;
        userlogged=false;
        std::cout<<"\nLogged out"<<std::endl;
    }
}


