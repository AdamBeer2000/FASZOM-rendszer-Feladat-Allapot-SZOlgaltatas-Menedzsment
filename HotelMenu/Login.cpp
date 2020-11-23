#include "Login.h"

Login::Login(std::list<Users::User*>_users):users(_users),logged_user(nullptr)
{
    userloggeed=false;
}

void Login::LogInWith(std::string username, std::string password)
{
    std::list<Users::User*>::iterator it;
    bool userfound=false;
    unsigned int k=0;
    if(userloggeed)
    {
        throw AlrreadyLoged();
    }
    for(auto user:users)
    {
        if(user->getUsername()==username)
        {
            if(user->getPassword()==password)
            {
                userfound=true;
                userloggeed=true;
                logged_user= user;
                std::cout<<"\nLogged in"<<std::endl;
            }
            else
            {
                throw WrongPasswordException();
            }
        }
    }
    if(isLoggedOut())
    {
        throw WrongUsernameException();
    }
}

void Login::logOut()
{
    if(userloggeed)
    {
        delete logged_user;
        logged_user=nullptr;
        userloggeed=false;
        std::cout<<"\nLogged out"<<std::endl;
    }
}

bool Login::isLoggedIn()
{
    return userloggeed;
}

bool Login::isLoggedOut()
{
    return !userloggeed;
}

std::string Login::getLoggedUsername() const
{
    return logged_user->getUsername();
}
