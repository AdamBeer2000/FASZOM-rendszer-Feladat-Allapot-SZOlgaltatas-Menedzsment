#ifndef DATACOMMUNICATIONCENTER_H
#define DATACOMMUNICATIONCENTER_H

#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <algorithm>
#include "Task/taskcontainer.h"
#include "Reservation/reservation.h"
#include "Reservation/reservationcontainer.h"
#include "User/user.h"
#include "User/usermanager.h"
#include "Room/roomcontainer.h"
#include "ostream"
#include "istream"
#include "sstream"

class DataCommunicationCenter
{
private:
    //VARIABLES
    std::map<std::string, std::string> task_list;
    std::list<std::pair<int, std::string>> ratings;
    std::list<std::string> lost_items;

    UserManager user_man;

    ReservationContainer reservation_cont;

    RoomContainer room_cont;



    //EXCEPTION CLASS
    class InvalidDataException: public std::exception
    {
    private:
        std::string msg;

    public:
        InvalidDataException(const std::string& msg_c): msg(msg_c) {}
        virtual ~InvalidDataException(){}

        virtual const char* what() const noexcept override
        {
            return msg.c_str();
        }
    };

    //CONSTRUCTOR
    DataCommunicationCenter();
    DataCommunicationCenter(const DataCommunicationCenter& other);

    //SINGLETON VARIABLE
    static std::shared_ptr<DataCommunicationCenter> instance;

public:
    static std::shared_ptr<DataCommunicationCenter> getInstance();

    //FUNCTIONS
    //void processTask(std::string task_id_arg, std::string data_arg); //commandpanelban lekezeljük

    void createReservationRequest(Reservation & newres);

    void accepptReservation(std::string taskid, int room_id);
    void denyReservation(std::string taskid, std::string username);
    void registration(std::string username,std::string first_name,std::string last_name, std::string password);
    void addRating(int rate, std::string comment);
    Tasks::Task generateTask(Users::jobs job_id, Users::taskdata type, const std::string& employee_name, const std::string& todo);
    Tasks::Task generateTaskReservation(Users::jobs job_id, Users::taskdata type, const std::string& employee_name, Reservation& reservation);
    std::string generateTaskId(Users::jobs job_id, Users::taskdata type);
    void login(std::string username, std::string password);
    void logOut();
    void loadData() const; //soon
    void saveData() const;//soon
    void createUser(std::string username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password);
    void createUser(Users::User * newuser);
    void deleteUser(std::string username); //employeet
    void addLostItem(std::string desc);
    void printLostItem() const;
    void printAllTask();
    void printAllLog();
    bool isExistTask(std::string task_id);
    Users::jobs returnLoggedJob();
    std::string findTask(std::string task_id);
    void addTask(Tasks::Task task);
    void deleteTask(std::string task_id);
    std::map<std::string, std::string> showTasks();
    void setTaskStatus(std::string user, std::string task_id);

    void bookRoom(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving);

    void printMyTasks();
    //test
    void printRes();

    //jobs
    void logTask(std::string task_id,Logs::Log * one_log);
    void logTask(std::string username,std::string task_id,Logs::Log * one_log);
    void addCleaningLog(std::string task_id,date date_of_cleaning);//talalt targyal
    void addCleaningLog(std::string task_id, std::string item_c, date date_of_cleaning);//talalt targy nelkul


    //egy munkát adnak a legkevésbbé terhelt munkásnak
    void cleanRoom(std::string username,std::string task_id,Logs::Log * one_log);
    void takeCleaningTask(int roomID);
    void LogCleaningTask(std::string task_id,date clean_date);
    void LogCleaningTask(std::string task_id,std::string item,date clean_date);



    void fixItemReqest(int szobaID , std::string item);
    void reservacionReq(Tasks::Task resTask);//todo

    Tasks::Task getTask(std::string username,std::string taskId);
    Tasks::Task getTask(std::string taskId);

};

#endif // DATACOMMUNICATIONCENTER_H
