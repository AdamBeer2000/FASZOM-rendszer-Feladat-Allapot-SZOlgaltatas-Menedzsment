#include "Login.h"

Login::Login(std::list<User>&_users):logged_user(User())
{
    userloggeed=false;
    users=_users;
}

void Login::LogInWith(std::string username, std::string password)
{
    std::list<User>::iterator it;
    std::vector<User> tempUsers(users.begin(),users.end());
    bool userfound=false;
    unsigned int k=0;
    if(userloggeed)
    {
        throw AlrreadyLoged();
    }
    while (userfound!=true&&k<users.size())
    {
        if(tempUsers[k].getUsername()==username)
        {
            if(tempUsers[k].getPassword()==password)
            {
                userfound=true;
                userloggeed=true;
                logged_user= tempUsers[k];
                std::cout<<"Logged in"<<std::endl;
            }
            else
            {
                throw WrongPasswordException();
            }
        }
        k++;
    }
    if(userfound!=true)
    {
        throw NotExistingUsernameException(username);
    }

}

void Login::logOut()
{
    if(userloggeed)
    {
        logged_user=User();
        userloggeed=false;
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
