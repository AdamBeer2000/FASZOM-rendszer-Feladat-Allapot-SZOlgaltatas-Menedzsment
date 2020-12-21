#include "datacommunicationcenter.h"
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::instance=nullptr;
//------------------------------------------------------------------------------------------
//SINGLETON FUNCTION
DataCommunicationCenter::DataCommunicationCenter()
{
    //std::cout<<"RESERVATIONS LOADED:"<<std::endl;
    reservation_cont.loadContent("Reservation_Data.txt");
    //reservation_cont.printall();

    //std::cout<<"ROOMS LOADED:"<<std::endl;
    room_cont.loadContent("Room_Data.txt");
    //room_cont.printAllRoom();

    //std::cout<<"TASKS LOADED:"<<std::endl;
    user_man.loadContent("User_Data.txt","Task_Data.txt");
    //user_man.printAllUser();
    //user_man.printAllTask();

    //std::cout<<"LOGS  LOADING:"<<std::endl;
    //user_man.printLogs();

    task_list=user_man.getTasklink();
    /*
    for(auto task:task_list)
    {
        std::cout<<task.first<<" "<<task.second<<std::endl;
    }*/
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

//------------------------------------------------------------------------------------------

void DataCommunicationCenter::createReservationRequest(Reservation &newres)
{
    std::stringstream fortodo;
    std::string mytodo = fortodo.str();
    std::string username = user_man.getLeastBusyWorker(Users::jobs::REC);
    reservation_cont.addReservation(newres);
    Tasks::Task task = generateTaskReservation(Users::jobs::REC , Users::taskdata::RES , username , newres);
    user_man.addTask(username , task);
}

void DataCommunicationCenter::accepptReservation(std::string taskid, int room_id)
{

    Reservation res=reservation_cont.getReservation(taskid);

    room_cont.setReservation(room_id,res);
    reservation_cont.deleteReservation(taskid);

    Logs::Log * temp=new Logs::LogReservation(res.getUserename(),res.getApartment(),res.getServing(),0,res.getStartTime(),res.getEndTime());
    user_man.logTask(taskid,temp);
}

void DataCommunicationCenter::denyReservation(std::string taskid)
{
    reservation_cont.deleteReservation(taskid);
    user_man.setTaskStatusDone(findTask(taskid), taskid);
}

void DataCommunicationCenter::registration(std::string username, std::string first_name, std::string last_name, std::string password)
{
    DateBuilder db;
    user_man.addUser(username,first_name,last_name,db.build(0,0,0),Users::jobs::GUE,0,password);
}

void DataCommunicationCenter::addRating(int rate, std::string comment)
{
     ratings.insert({user_man.getLoggedUser()->getUsername(), std::pair<int,std::string>(rate,comment)});
}

Tasks::Task DataCommunicationCenter::generateTask(Users::jobs job_id, Users::taskdata type, const std::string &employee_name, const std::string &todo)
{
    std::string current_id = "";
    current_id = generateTaskId(job_id, type);
    Tasks::Task task = Tasks::Task(employee_name, current_id, todo, false);
    task_list.insert({task.getTaskId(), employee_name});
    return task;
}

Tasks::Task DataCommunicationCenter::generateTaskReservation(Users::jobs job_id, Users::taskdata type, const std::string &employee_name, Reservation &reservation)
{
    std::string current_id = "";
    current_id = generateTaskId(job_id, type);
    //Lehet, hogy hasznosabb, ha itt validálom az employee nevet és a típust
    Tasks::Task task = Tasks::Task(employee_name, current_id, reservation, false);


    task_list.insert({task.getTaskId(), employee_name});
    return task;
}

std::string DataCommunicationCenter::generateTaskId(Users::jobs job_id, Users::taskdata type)
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
        switch(type)
        {
            case Users::taskdata::FIX:
                generated_id += "FIX";
                break;
            case Users::taskdata::RES:
                generated_id += "RES";
                break;
            case Users::taskdata::CLN:
                generated_id += "CLN";
                break;
            case Users::taskdata::REP:
                generated_id += "REP";
                break;
            case Users::taskdata::CLF:
                generated_id += "CLF";
                break;
            default:
                generated_id += "ERR"; //Error
                throw InvalidDataException("[INVALID TASK ID DATA]: Log type");
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
        generateTaskId(job_id, type);
    }
    return generated_id;
}

void DataCommunicationCenter::login(std::string username, std::string password)
{
    user_man.loginWith(username,password);
    if(user_man.isLoggedIn())
    {
        std::cout<<"logged in"<<std::endl;
    }
}

void DataCommunicationCenter::logOut()
{
    if(user_man.isLoggedIn())
    {
        user_man.logout();
        std::cout<<"logged out"<<std::endl;
    }
    else
    {
        std::cout<<"nem leptel meg be"<<std::endl;
    }

}

void DataCommunicationCenter::saveData()
{   //_Test.txt"
    room_cont.saveContent("Room_Data.txt");
    reservation_cont.saveContent("Reservation_Datatxt");
    user_man.saveContent("User_Data.txt","Task_Data.txt");
}

void DataCommunicationCenter::createUser(std::string username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password)
{
    user_man.addUser(username, first_name, last_name, birth_date,position,card_id, password);
}

void DataCommunicationCenter::createUser(Users::User *newuser)
{
    user_man.addUser(newuser);
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
    for(auto cit : lost_items)
    {
        std::cout << cit << std::endl;
    }
}

void DataCommunicationCenter::printAllTask()
{
    user_man.printAllTask();
}

void DataCommunicationCenter::printAllLog()
{
    user_man.printLogs();
}

bool DataCommunicationCenter::isExistTask(std::string task_id)
{
    auto it = task_list.find(task_id);
    if(it != task_list.end())
    {
        return true;
    }
    return false;
}

Users::jobs DataCommunicationCenter::returnLoggedJob()
{
    return user_man.getLoggedJob();
}


std::string DataCommunicationCenter::findTask(std::string task_id)
{
    return task_list.find(task_id)->second;
}

void DataCommunicationCenter::addTask(Tasks::Task task)
{
    user_man.addTask(task.getEmployee(), task);
}

void DataCommunicationCenter::deleteTask(std::string task_id)
{
    user_man.deleteTask(task_id);
    //auto it = task_list.find(task_id); //majd lesz
    task_list.erase(task_id);
}

std::map<std::string, std::string> DataCommunicationCenter::showTasks()
{
    return this->task_list;
}

void DataCommunicationCenter::setTaskStatus(std::string user, std::string task_id)
{
    user_man.setTaskStatusDone(user, task_id);
}

bool DataCommunicationCenter::isRated() const
{
    auto it = ratings.find(user_man.getLoggedUser()->getUsername());
    if(it != ratings.end())
    {
        return true;
    }
    return false;
}

bool DataCommunicationCenter::isExistUser(std::string username)
{
    return user_man.existUser(username);
}

Users::jobs DataCommunicationCenter::getJobIdFrom(std::string username)
{
    return user_man.getJobIdOf(username);
}

void DataCommunicationCenter::bookRoom(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving)
{
    std::string _task_id=generateTaskId(Users::REC,Users::taskdata::RES);
    reservation_cont.bookRoom(_task_id,_userename,_apartment,_startTime,_endTime,_serving);
    std::string worker =user_man.getLeastBusyWorker(Users::jobs::REC);
    Tasks::Task temp(worker,_task_id,Reservation(_task_id,_userename,_apartment,_startTime,_endTime,_serving),false);
    user_man.addTask(worker,temp);
}

void DataCommunicationCenter::printDirtyRooms()
{
    room_cont.printDirtyRooms();
}


void DataCommunicationCenter::printMyTasks()
{
    user_man.printTasksLogged();
}

void DataCommunicationCenter::printRes()
{
    reservation_cont.printall();
}

void DataCommunicationCenter::logTask(std::string task_id, Logs::Log *one_log)
{
    user_man.logTask(task_id, one_log);
}

void DataCommunicationCenter::logTask(std::string username, std::string task_id, Logs::Log *one_log)
{
    user_man.logTask(username, task_id, one_log);
}

void DataCommunicationCenter::takeCleaningTask(int roomID)
{
    std::stringstream ss;
    ss<<"Takaritsd ki a "<<roomID<<"-szobat";
    std::string todo=ss.str();
    std::string taskid=generateTaskId(returnLoggedJob(),Users::taskdata::CLN);
    Tasks::Task cTask(user_man.getLoggedUser()->getUsername(),taskid,todo,false);
    cTask.setRoomid(roomID);
    user_man.addTask(user_man.getLoggedUser()->getUsername(),cTask);
    task_list.insert({taskid,user_man.getLoggedUser()->getUsername()});
}

void DataCommunicationCenter::LogCleaningTask(std::string task_id, date clean_date)
{
    room_cont.cleanRoom(user_man.getRoomId(user_man.getLoggedUser()->getUsername(),task_id));

    Logs::Log * temp=new Logs::LogCleaning(clean_date);

    user_man.logTask(task_id,temp);
}

void DataCommunicationCenter::LogCleaningTask(std::string task_id, std::string item, date clean_date)
{
    room_cont.cleanRoom(user_man.getRoomId(user_man.getLoggedUser()->getUsername(),task_id));

    Logs::Log * temp=new Logs::LogCleaning(item,clean_date);

    user_man.logTask(task_id,temp);
}

void DataCommunicationCenter::fixItemReqest(int szobaID, std::string item)
{
    std::stringstream fortodo;
    fortodo << "FIX: " << szobaID << ", " << item;
    std::string mytodo = fortodo.str();
    std::string username = user_man.getLeastBusyWorker(Users::jobs::JAN);
    Tasks::Task task = generateTask(Users::jobs::JAN , Users::taskdata::FIX , username , mytodo);
    user_man.addTask(username , task);
}

Tasks::Task DataCommunicationCenter::getTask(std::string username, std::string taskId)
{
    return user_man.getTask(username,taskId);
}

Tasks::Task DataCommunicationCenter::getTask(std::string taskId)
{
    return user_man.getTask(user_man.getLoggedUser()->getPassword(),taskId);
}

void DataCommunicationCenter::checkhOut()
{
    room_cont.deleteReservation(user_man.getLoggedUser()->getUsername());
}
bool DataCommunicationCenter::isLoggedIn()
{
     return user_man.isLoggedIn();
}
void DataCommunicationCenter::reportDeartyRoom()
{
    room_cont.reportDirtyRoom(user_man.getLoggedUser()->getUsername());
}

