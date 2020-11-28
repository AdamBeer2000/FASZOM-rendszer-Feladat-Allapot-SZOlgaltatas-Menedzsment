#ifndef DATACOMMUNICATIONCENTER_H
#define DATACOMMUNICATIONCENTER_H

#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <algorithm>
#include "Task/taskcontainer.h"
#include "Reservacion/reservation.h"
#include "Reservacion/reservationcontainer.h"
#include "User/user.h"
#include "User/usermanager.h"
#include "Room/roomcontainer.h"

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

    //CONSTRUCTOR
    DataCommunicationCenter();
    DataCommunicationCenter(const DataCommunicationCenter& other);

    //SINGLETON VARIABLE
    static std::shared_ptr<DataCommunicationCenter> instance;

public:
    static std::shared_ptr<DataCommunicationCenter> getInstance();

    //FUNCTIONS
    void processTask(std::string task_id_arg, std::string data_arg);

    void createReservationRequest(std::string data_res);

    void accepptReservation(int room_id, Reservation res);

    void denyReservation(std::string username);
    void registration(std::string username, std::string password);
    void addRating(int rate, std::string comment);
    //generateTask //átemelni a managerből
    //generateUniqueTaskID //átemelni --||--
    void login(std::string username, std::string password);
    //loadData() //soon
    //saveData() //soon
    void createUser(std::string first_name, std::string last_name, date birth_date, Users::jobs position, int card_id, std::string password);
    void deleteUser(std::string username); //employeet
    void addLostItem(std::string desc);
    void printLostItem() const;
    bool permissionCheck(std::string task_type);

};

#endif // DATACOMMUNICATIONCENTER_H
