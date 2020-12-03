#include "datacommunicationcenter.h"
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::instance=nullptr;

void DataCommunicationCenter::readReservationFile()
{
    /*
    std::string userename;
    Suit::suitTypes apartment=Suit::NotSetSuit;
    date endTime;
    Serving::servingTypes serving=Serving::NotSetServing;
    */
   std::ifstream read("Reservation_Data.txt");
   if(read.is_open())
   {
       std::string temp;
       std::string oneline;

       std::string userename;
       Suit::suitTypes apartment;
       date startTime;
       date endTime;
       Serving::servingTypes serving;

       while(getline (read, oneline))
       {
           try
           {
               temp=oneline.substr(0,oneline.find(','));
               std::string userename=oneline.substr(0,oneline.find(','));
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               apartment=Suit::stringToServing(temp);
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               startTime=startTime.stringToDate(temp);
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               endTime=endTime.stringToDate(temp);
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               serving=Serving::stringToServing(oneline.substr(0,oneline.find(',')));
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               reservation_cont.bookRoom(userename,apartment,startTime,endTime,serving);
               //std::cout<<oneline<<std::endl;
           }
           catch(std::exception &e)
           {
               std::cout<<e.what()<<std::endl;
           }

       }
   }

}

void DataCommunicationCenter::readRoomFile()
{

}

//------------------------------------------------------------------------------------------
//SINGLETON FUNCTION
DataCommunicationCenter::DataCommunicationCenter()
{
    readReservationFile();
}

DataCommunicationCenter::DataCommunicationCenter(const DataCommunicationCenter &other)
{

}

std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::getInstance()
{
    if(instance == nullptr)
    {
        instance = std::shared_ptr<DataCommunicationCenter>(new DataCommunicationCenter());
    }
    return instance;
}

void DataCommunicationCenter::createReservationRequest(Reservation &newres)
{
    reservation_cont.addReservation(newres);
}


//------------------------------------------------------------------------------------------

void DataCommunicationCenter::accepptReservation(std::string taskid, int room_id, Reservation res)
{
    room_cont.setReservation(room_id,res);
    reservation_cont.deleteReservation(res.getUserename());

    Logs::LogReservation temp(res,room_id);
    user_man.logTask(taskid,&temp);
}

void DataCommunicationCenter::denyReservation(std::string taskid, std::string username)
{
    reservation_cont.deleteReservation(username);
    user_man.setTaskStatusDone(findTask(taskid),taskid);
}

Tasks::Task DataCommunicationCenter::generateTask(Users::jobs job_id, const std::string &username, const std::string &todo)
{
    std::string current_id = "";
    current_id = generateTaskId(job_id);
    //Lehet, hogy hasznosabb, ha itt validálom az employee nevet és a típust
    auto builder = new Tasks::Task::TaskBuilder(current_id);
    auto task = builder->withEmployee(username)
            .withTodo(todo)
            .withStatus(false)
            .build();

    task_list.insert({task->getTaskId(), username});
    //delete nem biztos, hogy ide kell
    return *task;
    //delete task;
    //delete builder;
}

std::string DataCommunicationCenter::generateTaskId(Users::jobs job_id)
{
    std::string generated_id = "";
    try
    {
        switch(job_id)
        {
            case Users::jobs::JAN:
                generated_id = "JAN";
                break;
            case Users::jobs::CLE:
                generated_id = "CLE";
                break;
            case Users::jobs::REC:
                generated_id = "REC";
                break;
            default:
                generated_id = "ERR"; //Error
                throw InvalidDataException("[INVALID TASK ID DATA]: Employee type");
                break;
        }
    }
    catch(InvalidDataException& e)
    {
        std::cout << e.what() << std::endl;
    }

    int num_code = rand() % 100000;

    if(num_code < 10000)
    {
        generated_id += "0";

        if(num_code < 1000)
        {
            generated_id += "0";

            if(num_code < 100)
            {
                generated_id += "0";
                if(num_code < 10)
                {
                    generated_id += "0";
                }
            }
        }
    }

    generated_id += std::to_string(num_code);

    auto it = task_list.find(generated_id);
    if(it != task_list.end())
    {
        generateTaskId(job_id);
    }
    return generated_id;
}

void DataCommunicationCenter::login(std::string username, std::string password)
{
    user_man.loginWith(username,password);
}

void DataCommunicationCenter::logOut()
{
    user_man.logout();
}

void DataCommunicationCenter::createUser(std::string username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password)
{
    user_man.addUser(username, first_name, last_name, birth_date,position,card_id, password);
}

void DataCommunicationCenter::deleteUser(std::string username)
{
    user_man.deleteUser(username);
}

void DataCommunicationCenter::addLostItem(std::string desc)
{
    lost_items.push_back(desc);
}

void DataCommunicationCenter::printLostItem() const
{
    std::cout << "Lost items: " << std::endl;
    for(auto cit : lost_items)
    {
        std::cout << cit << std::endl;
    }
    std::cout << std::endl;
}

Users::jobs DataCommunicationCenter::returnLoggedJob()
{
    return user_man.getLoggedJob();
}


std::string DataCommunicationCenter::findTask(std::string task_id)
{
    return task_list.find(task_id)->second;
}

void DataCommunicationCenter::printRes()
{
    reservation_cont.printall();
}


