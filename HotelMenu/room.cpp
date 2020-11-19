#include "room.h"

bool Room::getUsed() const
{
    return used;
}

bool Room::getCleaned() const
{
    return cleaned;
}

Suit::suitTypes Room::getApartment() const
{
    return apartment;
}

void Room::setCleaned()
{
    cleaned=true;
}

void Room::setDirty()
{
    cleaned=false;
}

void Room::setFree()
{
    used=false;
}

void Room::setUsed()
{
    used=true;
}

void Room::setReservation(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime,Serving:: servingTypes _serving)
{
    activeReservation=Reservation(_userename,_apartment,_startTime,_endTime,_serving);
    used=true;
}

void Room::setReservation(Reservation oneRes)
{
    activeReservation= oneRes;
    used=true;
}

void Room::deleteReservation()
{
    activeReservation=Reservation();
    used=false;
}

std::string Room::getApartmentInString() const
{
    return suitToString(apartment);
}


Room::~Room()
{

}

int Room::getRoomid() const
{
    return roomid;
}

Room::Room()
{

}

Room::Room(Suit::suitTypes _apartment, int _roomid, bool _cleaned)
{
    apartment=_apartment;
    roomid=_roomid;
    cleaned=_cleaned;
}

Room::Room(Suit::suitTypes _apartment, int _roomid, bool _cleaned,std::string _userename,Suit::suitTypes,date _startTime,date _endTime,Serving::servingTypes _serving)
    :activeReservation(_userename,_apartment,_startTime,_endTime,_serving)
{
    apartment=_apartment;
    roomid=_roomid;
    cleaned=_cleaned;
}
