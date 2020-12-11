#include "usermanager.h"

UserManager::UserManager(std::list<Users::User *>_users)
{
    for(auto user : _users)
    {
        users.insert(std::pair<std::string,Users::User*>(user->getUsername(),user));
    }
}

UserManager::UserManager():loggedUser(nullptr)
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

Users::jobs UserManager::getLoggedJob() const
{

    if(loggedUser)
    {
        return loggedUser->getJobID();

    }
    else
    {
        return Users::Unlogged;
    }
}

void UserManager::addUser(std::string username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password)
{
    Users::User * added_user;

    switch(position)
    {
        case Users::jobs::CLE:
            added_user = new Users::Cleaner(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::GUE:
            added_user =new Users::Guest(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::JAN:
            added_user =new Users::Janitor(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::REC:
            added_user =new Users::Receptionist(first_name, last_name, username, birth_date, position,card_id, password);
            break;
        case Users::jobs::MAN:
            added_user =new Users::Manager(first_name, last_name, username, birth_date, position,card_id, password);
            break;
    }
    users.insert({username, added_user});
}

void UserManager::addUser(Users::User *newUser)
{
    users.insert({newUser->getUsername(), newUser});
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
    users.find(loggedUser->getUsername())->second->setTaskStatus(task_id);
}

std::string UserManager::getLeastBusyWorker(Users::jobs jobID)
{
    std::map<std::string , int> temporary;
    for(auto it = users.begin();it != users.end();++it){
        if(it->second->getJobID() == jobID){
            temporary.insert({it->first , it->second->getNumberOfTasks()});


        }
    }
    auto min = temporary.begin();
    for(auto it = temporary.begin();it != temporary.end();++it){
        if(it->second < min->second){
            min = it;
        }
    }
    return min->first;
}
void UserManager::addTask(std::string username, Tasks::Task one_task)
{
    auto it = users.find(username);

    if(it != users.end())
    {
        it->second->addTask(one_task);
    }
}

void UserManager::deleteTask(std::string task_id_del)
{
    for(auto it = users.begin(); it != users.end(); ++it)
    {
        it->second->deleteTask(task_id_del);
    }
}

void UserManager::printMyTask() const
{
    loggedUser->printTasks();
}

void UserManager::logTask(std::string task_id, Logs::Log *onelog)
{
    users.find(loggedUser->getUsername())->second->setLog(task_id,onelog);
    users.find(loggedUser->getUsername())->second->setTaskStatus(task_id);
}

void UserManager::printAllTask() const
{
    for(auto cit = users.cbegin(); cit != users.cend(); ++cit)
    {
        std::cout << cit->first <<"\'s tasks:" <<std::endl;
        cit->second->printTasks();
        std::cout << std::endl;
    }
}

void UserManager::printLogs() const
{
    for(auto cit = users.cbegin(); cit != users.cend(); ++cit)
    {
        std::cout << cit->first <<"\'s logs:" <<std::endl;
        cit->second->printLogs();
        std::cout << std::endl;

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

void UserManager::loadContent(std::string user_file_name,std::string task_file_name)
{
    /*std::string firstName;
        std::string lastName;
        std::string username;
        date birthDate;
        jobs jobID;
        int cardID;
        std::string password;
        TaskContainer taskCont;*/


    std::ifstream readuser(user_file_name);

    std::string temp,oneline;
    std::string firstName,lastName,username,password;
    date birthdate;
    int cardid;
    Users::jobs jobID;

    while(getline (readuser, oneline))
    {
        try
        {
            TaskContainer temp_taskCont;

            temp=oneline.substr(0,oneline.find(','));
            firstName=temp;
            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            temp=oneline.substr(0,oneline.find(','));
            lastName=temp;
            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            temp=oneline.substr(0,oneline.find(','));
            username=temp;
            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            temp=oneline.substr(0,oneline.find(','));
            birthdate=DateBuilder::build(temp);
            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            temp=oneline.substr(0,oneline.find(','));
            jobID=Users::stringToJobID(temp);
            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            temp=oneline.substr(0,oneline.find(','));
            std::stringstream strm(temp);
            strm >> cardid;

            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            temp=oneline.substr(0,oneline.find(','));
            password=temp;
            oneline=oneline.substr(oneline.find(',')+1,oneline.size());

            addUser(username,firstName,lastName,birthdate,jobID,cardid,password);
        }
        catch(std::exception &e)
        {
            std::cout<<e.what()<<std::endl;
        }
    }

    std::ifstream readtask(task_file_name);

    std::string employee;
    std::string task_id;
    std::string todo;
    bool status;

    while(getline (readtask, oneline))
    {
        try
        {
            temp=oneline.substr(0,oneline.find('#'));
            employee=temp;
            oneline=oneline.substr(oneline.find('#')+1,oneline.size());

            temp=oneline.substr(0,oneline.find('#'));
            task_id=temp;
            oneline=oneline.substr(oneline.find('#')+1,oneline.size());

            temp=oneline.substr(0,oneline.find('#'));
            todo=temp;
            oneline=oneline.substr(oneline.find('#')+1,oneline.size());

            temp=oneline.substr(0,oneline.find('#'));
            if(temp=="0")
            {
                status=false;
            }
            else
            {
                status=true;
            }
            oneline=oneline.substr(oneline.find('#')+1,oneline.size());

            if(status)
            {
                using namespace Users;
                temp=oneline.substr(0,oneline.find('#'));
                taskdata tasklogtype=Users::stringTotaskdata(temp);
                oneline=oneline.substr(oneline.find('#')+1,oneline.size());

                Logs::Log * tasklog;

                switch (tasklogtype)
                {
                    case FIX:std::cout<<"FIX"<<std::endl;
                    break;
                    case REP:std::cout<<"REP"<<std::endl;
                    break;
                    case RES:std::cout<<"RES"<<std::endl;
                    break;
                    case CLF:std::cout<<"CLF"<<std::endl;
                    break;
                    case CLN:std::cout<<"CLN"<<std::endl;
                    break;
                    default:break;
                }
                addTask(employee,Tasks::Task(employee,task_id,todo,status));
            }
            else
            {
                addTask(employee,Tasks::Task(employee,task_id,todo,status));
            }
        }
        catch(std::exception &e)
        {
            std::cout<<e.what()<<std::endl;
        }
    }
}

void UserManager::saveContent(std::string user_file_name,std::string task_file_name)
{

}

