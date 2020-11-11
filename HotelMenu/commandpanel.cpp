#include "commandpanel.h"

CommandPanel::CommandPanel(std::list<Users::User*> users):Login(users)
{

}

void CommandPanel::doStuff()
{
    std::string command;
    std::cout<<"Udvozlet a FASZ rendszerben"<<std::endl;
    do
    {
        try
        {
            if(isLoggedIn())
            {
                std::cout<<getLoggedUsername()<<":>";
            }
            else
            {
                std::cout<<"Guest:>";
            }

            std::cin>>command;
            std::transform(command.begin(), command.end(), command.begin(),
                [](unsigned char c){ return std::tolower(c);});

            switch (resolveOption(command))
            {
                case Invalid:throw CommandNotFoundException(command.c_str());break;
                case cLogin:logIn();break;
                case cLogout:logOut();break;
                case cExit:;break;
            }
        }
        catch (std::exception &e)
        {
             std::cout<<e.what()<<std::endl;
        }
    }
    while (command!="exit"&&command!="Exit");
}
void CommandPanel::logIn()
{
    if(isLoggedOut())
    {
        std::string tempUserName;
        std::string tempPasword;
        std::cout<<"Username:";
        std::cin>>tempUserName;
        std::cout<<"Pasword:";
        std::cin>>tempPasword;
        LogInWith(tempUserName,tempPasword);
        if(isLoggedIn())
        {
            std::cout<<"Hi "<<tempUserName<<std::endl;
        }

        if(tempUserName=="rickastley"||tempUserName=="RickAstley")
        {
            ricroll();
        }
        if(tempPasword=="69"||tempPasword=="420"||tempPasword=="42069"||tempPasword=="69420")
        {
            std::cout<<"\nNice!"<<std::endl;
        }
    }
    else
    {
        throw AlrreadyLoged();
    }
}

void CommandPanel::ricroll()
{
    std::cout<<"We're no strangers to love"<<std::endl;
    std::cout<<"You know the rules and so do I"<<std::endl;
    std::cout<<"A full commitment's what I'm thinking of"<<std::endl;
    std::cout<<"You wouldn't get this from any other guy"<<std::endl;
    std::cout<<"I just wanna tell you how I'm feeling"<<std::endl;
    std::cout<<"Gotta make you understand"<<std::endl;
    std::cout<<"Never gonna give you up"<<std::endl;
    std::cout<<"Never gonna let you down"<<std::endl;
    std::cout<<"Never gonna run around and desert you"<<std::endl;
    std::cout<<"Never gonna make you cry"<<std::endl;
    std::cout<<"Never gonna say goodbye"<<std::endl;
    std::cout<<"Never gonna tell a lie and hurt you...."<<std::endl;
}
