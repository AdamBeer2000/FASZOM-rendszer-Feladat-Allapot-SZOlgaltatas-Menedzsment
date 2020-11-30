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
    void readReservationFile();

    RoomContainer room_cont;
    void readRoomFile();

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

    void createReservationRequest(std::string data_res);
    void accepptReservation(std::string taskid, int room_id, Reservation res);
    void denyReservation(std::string taskid, std::string username);
    void registration(std::string username, std::string password);
    void addRating(int rate, std::string comment);
    Tasks::Task generateTask(Users::jobs job_id, const std::string& employee_name, const std::string& todo);
    std::string generateTaskId(Users::jobs job_id);
    void login(std::string username, std::string password);
    void loadData(); //soon
    void saveData() const;//soon
    void createUser(std::string username, std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password);
    void deleteUser(std::string username); //employeet
    void addLostItem(std::string desc);
    void printLostItem() const;
    bool permissionCheck(std::string task_type);

    //test
    void printRes();

};

#endif // DATACOMMUNICATIONCENTER_H
