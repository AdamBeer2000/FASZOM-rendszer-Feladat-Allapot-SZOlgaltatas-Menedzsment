#include "reservationcontainer.h"

ReservationContainer::ReservationContainer()
{

}

ReservationContainer::ReservationContainer(std::list<Reservation> _res)
{
    for(auto r : _res)
    {
        reservations.insert(std::pair<std::string,Reservation>(r.getUserename(),r));
    }
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
    else
    {
        throw NoReservationFound(guestName);
    }
}

void ReservationContainer::bookRoom(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving)
{
    reservations.insert(std::pair<std::string,Reservation>(_userename,Reservation(_userename,_apartment,_startTime,_endTime,_serving)));
}

Reservation ReservationContainer::getReservation(std::string guestName)
{
    if(reservations.find(guestName)!=reservations.end())
    {
        return reservations.find(guestName)->second;
    }
    else
    {
        throw NoReservationFound(guestName);
    }
}

Reservation ReservationContainer::popReservation(std::string guestName)
{
    if(reservations.find(guestName)!=reservations.end())
    {
        Reservation ret=reservations.find(guestName)->second;
        deleteReservation(guestName);
        return ret;
    }
    else
    {
        throw NoReservationFound(guestName);
    }
}
