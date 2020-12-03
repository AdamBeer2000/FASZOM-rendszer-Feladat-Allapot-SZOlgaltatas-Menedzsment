#include "commandpanel.h"

void CommandPanel::login()
{

    std::cout<<"login"<<std::endl;
}

void CommandPanel::logout()
{

    std::cout<<"logout"<<std::endl;
}

void CommandPanel::reportLostItem()
{
    std::cout<<"reportLostItem"<<std::endl;
}

void CommandPanel::printMyTasks()
{
    std::cout<<"printMyTasks"<<std::endl;
}

void CommandPanel::registration()
{
    std::cout<<"registration"<<std::endl;
}

void CommandPanel::bookRoom()
{
    std::cout<<"bookRoom"<<std::endl;
}

void CommandPanel::rating()
{
    std::cout<<"rating"<<std::endl;
}

void CommandPanel::createTask()
{
    std::cout<<"createTask"<<std::endl;
}

void CommandPanel::deleteTask()
{
    std::cout<<"deleteTask"<<std::endl;
}

void CommandPanel::createEmployee()
{
    std::cout<<"createEmployee"<<std::endl;
}

void CommandPanel::emploYeet()
{
    std::cout<<"emploYeet"<<std::endl;
}

void CommandPanel::printAllTasks()
{
    std::cout<<"printAllTasks"<<std::endl;
}

void CommandPanel::printAllLogs()
{
    std::cout<<"printAllLogs"<<std::endl;
}

void CommandPanel::fix()
{
    std::cout<<"fix"<<std::endl;
}

void CommandPanel::replace()
{
    std::cout<<"replace"<<std::endl;
}

void CommandPanel::cleanroom()
{
    std::cout<<"cleanroom"<<std::endl;
}

void CommandPanel::acceptReservation()
{
    std::cout<<"acceptReservation"<<std::endl;
}

void CommandPanel::denyReservation()
{
    std::cout<<"denyReservation"<<std::endl;
}

void CommandPanel::printLostItems()
{
    std::cout<<"printLostItems"<<std::endl;
}

void CommandPanel::changeRoomStatus()
{
    std::cout<<"changeRoomStatus"<<std::endl;
}

bool CommandPanel::permissionCheck(CommandPanel::Commands reqvestedCommand)
{
    Users::jobs userPermisson=data_com->returnLoggedJob();

    switch (reqvestedCommand)
    {
        case cLogin:;return true;
        case cLogout:;return true;
        case cReport:;return true;
        case cExit:;return true;
        case cReg:;return true;
        default:;
    }

    switch (userPermisson)
    {
        case Users::jobs::CLE: if(reqvestedCommand==cClean)return true;break;
        case Users::jobs::GUE: if(reqvestedCommand==cBook||reqvestedCommand==cRate)return true;break;
        case Users::jobs::JAN: if(reqvestedCommand==cFix||reqvestedCommand==cReplace)return true;break;
        case Users::jobs::MAN: if(reqvestedCommand==cCreateTask||reqvestedCommand==cDeleteTask||reqvestedCommand==cCreateEmployee||reqvestedCommand==cEmploYeet||reqvestedCommand==cPrintAllLogs||reqvestedCommand==cPrintAllTask)return true;break;
        case Users::jobs::REC: if(reqvestedCommand==cAcceptRes||reqvestedCommand==cDenyRes||reqvestedCommand==cPrintLostItems||reqvestedCommand==cChangeRoomStatus)return true;break;
        default:throw  NoPermissonException(reqvestedCommand);break;
    }
    return false;
}


void CommandPanel::seudoMain()
{

    std::string command;
    std::cout<<"Udvozlet a FASZ rendszerben"<<std::endl;
    do
    {
        try
        {
            std::cout<<":>";
            std::getline(std::cin, command);
            if(permissionCheck(resolveOption(command)))
            {
                switch (resolveOption(command))
                {
                    case Invalid:throw CommandNotFoundException(command.c_str());break;
                    case cLogin:login();break;
                    case cLogout:logout();break;
                    case cExit:;break;
                    case cReport:reportLostItem();break;
                    case cPrintMyTask:printMyTasks();break;
                    case cReg:registration();break;
                    case cBook:bookRoom();break;
                    case cRate:rating();break;
                    case cCreateTask:createTask();break;
                    case cDeleteTask:deleteTask();break;
                    case cCreateEmployee:createEmployee();break;
                    case cEmploYeet:emploYeet();break;
                    case cPrintAllTask:printAllTasks();break;
                    case cPrintAllLogs:printAllLogs();break;
                    case cFix:fix();break;
                    case cReplace:replace();break;
                    case cClean:cleanroom();break;
                    case cAcceptRes:acceptReservation();break;
                    case cDenyRes:denyReservation();break;
                    case cPrintLostItems:printLostItems();break;
                    case cChangeRoomStatus:changeRoomStatus();break;
                }
            }
        }
        catch (std::exception &e)
        {
             std::cout<<e.what()<<std::endl;
        }
    }
    while (command!="exit"&&command!="Exit");
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
