#include "commandpanel.h"

void CommandPanel::reportLostItem()
{

}

void CommandPanel::printMyTasks()
{

}

void CommandPanel::registration()
{

}

void CommandPanel::bookRoom()
{

}

void CommandPanel::rating()
{

}

void CommandPanel::createTask()
{

}

void CommandPanel::deleteTask()
{

}

void CommandPanel::createEmployee()
{

}

void CommandPanel::emploYeet()
{

}

void CommandPanel::printAllTasks()
{

}

void CommandPanel::printAllLogs()
{

}

void CommandPanel::fix()
{

}

void CommandPanel::replace()
{

}

void CommandPanel::cleanroom()
{

}

void CommandPanel::acceptReservation()
{

}

void CommandPanel::denyReservation()
{

}

void CommandPanel::printLostItems()
{

}

void CommandPanel::changeRoomStatus()
{

}

CommandPanel::CommandPanel(std::list<Users::User*> users)
{

}

void CommandPanel::seudoMain()
{

    std::string command;
    std::cout<<"Udvozlet a FASZ rendszerben"<<std::endl;
    do
    {
        try
        {
            /*
            if(logger.isLoggedIn())
            {
                std::cout<<logger.getLoggedUsername()<<":>";
            }
            else
            {
                std::cout<<"Guest:>";
            }
            */

            std::cin>>command;
            switch (resolveOption(command))
            {
                case Invalid:throw CommandNotFoundException(command.c_str());break;
                case cLogin:login();break;
                //case cLogout:logger.logOut();break;
                case cExit:;break;
                default:throw CommandNotFoundException(command);
            }
        }
        catch (std::exception &e)
        {
             std::cout<<e.what()<<std::endl;
        }
    }
    while (command!="exit"&&command!="Exit");
}
void CommandPanel::login()
{
    /*
    if(logger.isLoggedOut())
    {
        std::string tempUserName;
        std::string tempPasword;
        std::string input;


        std::getline(std::cin,input);
        int poz=-1;
        poz=input.find(" ");
        if(poz==-1)
        {
            std::cout<<"Username:";
            std::cin>>tempUserName;
            std::cout<<"Pasword:";
            std::cin>>tempPasword;
        }
        else
        {
            std::string trimed = input.substr(input.find(" ")+1);

            tempUserName = trimed.substr(0,trimed.find(" "));

            tempPasword = trimed.substr(trimed.find(" ")+1,input.length());
            std::cout<<"pass:"<<tempPasword<<std::endl;
            if(tempPasword==" "||tempPasword==""||tempPasword==tempUserName)
            {
                throw Login::NoPasswordException();
            }
        }

        logger.LogInWith(tempUserName,tempPasword);
        if(logger.isLoggedIn())
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
        throw Login::AlrreadyLoged();
    }
    */
}

void CommandPanel::logout()
{

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
