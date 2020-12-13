#ifndef RESERVATIONCONTAINER_H
#define RESERVATIONCONTAINER_H
#include "map"
#include "reservation.h"
#include "exception"
#include "sstream"
#include "list"
#include "ostream"
#include "istream"
#include <fstream>
#include "sstream"
#include <iostream>
#include "datebuilder.h"

class ReservationContainer
{
    std::map<std::string,Reservation>reservations;
public:
    ReservationContainer();
    ReservationContainer(std::list<Reservation> res);

    void addReservation(Reservation newRes);
    void deleteReservation(std::string guestName);
    void bookRoom(std::string _userename,Suit::suitTypes _apartment,date _startTime,date _endTime,Serving::servingTypes _serving);
    void bookRoom(std::string res_id,std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving);

    void loadContent(std::string file_name);
    void saveContent(std::string file_name);

    Reservation getReservation(std::string guestName);//kikér egy foglalást
    Reservation popReservation(std::string guestName);//ki kér egy foglalást és asztán törli

    Reservation getRes(std::string resid);

    class NoReservationFound:public std::exception
    {
        std::string massage;
        public:
        NoReservationFound()
        {

        }
        NoReservationFound(std::string username)
        {
            std::stringstream ss;
            ss<<"No reservation fund with: '"<<username<<"'-username";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };

    //test

    void printall();

};

#endif // RESERVATIONCONTAINER_H
