#include "datacommunicationcenter.h"
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::instance=nullptr;
//------------------------------------------------------------------------------------------
//SINGLETON FUNCTION
DataCommunicationCenter::DataCommunicationCenter()
{
    reservation_cont.loadContent("Reservation_Data.txt");
    room_cont.loadContent("Room_Data.txt");
    user_man.loadContent("User_Data.txt","Task_Data.txt","Log_Data.txt");
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

void DataCommunicationCenter::addRating(int rate, std::string comment)
{
    ratings.push_back(std::pair<int,std::string>(rate,comment));
}

Tasks::Task DataCommunicationCenter::generateTask(Users::jobs job_id, Users::taskdata type, const std::string &employee_name, const std::string &todo)
{
    std::string current_id = "";
    current_id = generateTaskId(job_id, type);
    //Lehet, hogy hasznosabb, ha itt validálom az employee nevet és a típust
    auto builder = new Tasks::Task::TaskBuilder(current_id);
    auto task = builder->withEmployee(employee_name)
            .withTodo(todo)
            .withStatus(false)
            .build();

    task_list.insert({task->getTaskId(), employee_name});
    //delete nem biztos, hogy ide kell
    return *task;
    //delete task;
    //delete builder;
}

Tasks::Task DataCommunicationCenter::generateTaskReservation(Users::jobs job_id, Users::taskdata type, const std::string &employee_name, Reservation &reservation)
{
    std::string current_id = "";
    current_id = generateTaskId(job_id, type);
    //Lehet, hogy hasznosabb, ha itt validálom az employee nevet és a típust
    auto builder = new Tasks::Task::TaskBuilder(current_id);
    auto task = builder->withEmployee(employee_name)
            .withStatus(false)
            .withReservation(reservation)
            .build();

    task_list.insert({task->getTaskId(), employee_name});
    //delete nem biztos, hogy ide kell
    return *task;
    //delete task;
    //delete builder;
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
}

void DataCommunicationCenter::logOut()
{
    user_man.logout();
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

void DataCommunicationCenter::addTask(Tasks::Task task)
{
    user_man.addTask(task.getEmployee(), task);
}

void DataCommunicationCenter::printRes()
{
    reservation_cont.printall();
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


