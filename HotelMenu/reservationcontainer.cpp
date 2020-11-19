#include "reservationcontainer.h"

ReservationContainer::ReservationContainer()
{

}

void ReservationContainer::addReservation(Reservation newRes)
{
    reservations.insert(std::pair<std::string,Reservation>(newRes.getUserename(),newRes));
}

void ReservationContainer::deleteReservation(std::string guestName)
{
    if(reservations.find(guestName)!=reservations.end())
    {
        reservations.erase(reservations.find(guestName));
    }
}

void ReservationContainer::bookRoom(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving)
{
    reservations.insert(std::pair<std::string,Reservation>(_userename,Reservation(_userename,_apartment,_startTime,_endTime,_serving)));
}

Reservation ReservationContainer::getReservation(std::string guestName)
{
    return reservations.find(guestName)->second;
}
