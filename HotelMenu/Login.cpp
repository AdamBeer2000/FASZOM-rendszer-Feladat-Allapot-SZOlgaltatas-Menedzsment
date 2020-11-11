#include "login.h"

Login::Login(std::list<Users::User>&_users):logged_user(Users::User())
{
    userloggeed=false;
    users=_users;
}

void Login::LogInWith(std::string username, std::string password)
{
    std::list<Users::User>::iterator it;
    std::vector<Users::User> tempUsers(users.begin(),users.end());
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
                std::cout<<"\nLogged in"<<std::endl;
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
        logged_user=Users::User();
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
    return logged_user.getUsername();
}
