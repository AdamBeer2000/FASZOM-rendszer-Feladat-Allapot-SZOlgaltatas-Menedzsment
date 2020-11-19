#ifndef RESERVATIONCONTAINER_H
#define RESERVATIONCONTAINER_H
#include "map"
#include "reservation.h"

class ReservationContainer
{
    std::map<std::string,Reservation>reservations;
public:
    ReservationContainer();
    void addReservation(Reservation newRes);
    void deleteReservation(std::string guestName);
    void bookRoom(std::string _userename,Suit::suitTypes _apartment,date _startTime,date _endTime,Serving::servingTypes _serving);

    Reservation getReservation(std::string guestName);



};

#endif // RESERVATIONCONTAINER_H
