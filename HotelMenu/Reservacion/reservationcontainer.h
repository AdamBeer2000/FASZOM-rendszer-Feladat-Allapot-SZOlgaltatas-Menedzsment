#ifndef RESERVATIONCONTAINER_H
#define RESERVATIONCONTAINER_H
#include "map"
#include "reservation.h"
#include "exception"
#include "sstream"
class ReservationContainer
{
    std::map<std::string,Reservation>reservations;
public:
    ReservationContainer();
    void addReservation(Reservation newRes);
    void deleteReservation(std::string guestName);
    void bookRoom(std::string _userename,Suit::suitTypes _apartment,date _startTime,date _endTime,Serving::servingTypes _serving);

    Reservation getReservation(std::string guestName);//kikér egy foglalást
    Reservation popReservation(std::string guestName);//ki kér egy foglalást és asztán törli

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


};

#endif // RESERVATIONCONTAINER_H
