#include "roomcontainer.h"

RoomContainer::RoomContainer()
{

}

void RoomContainer::add(Suit::suitTypes _apartment, int _roomid, bool cleaned)
{
    hotelRooms.insert(std::pair<int,Room>(_roomid,Room(_apartment,_roomid,cleaned)));
}

void RoomContainer::setRoomFree(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setFree();
    }
}

void RoomContainer::setRoomUsed(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setUsed();
    }
}

void RoomContainer::cleanRoom(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setCleaned();
    }
}

void RoomContainer::setReservation(int roomId, Reservation oneres)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setReservation(oneres);
    }
}

void RoomContainer::deleteReservation(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).deleteReservation();
    }
}

bool RoomContainer::isFree(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return !hotelRooms.at(roomId).getUsed();
    }
    return false;//to do excepcion
}

bool RoomContainer::isUsed(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getUsed();
    }
    return false;//to do excepcion
}

bool RoomContainer::isCleaned(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getCleaned();
    }
    return false;//to do excepcion
}

bool RoomContainer::isDirty(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return !hotelRooms.at(roomId).getCleaned();
    }
    return false;//to do excepcion
}

Suit::suitTypes RoomContainer::getSuitType(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getApartment();
    }
    return Suit::ERROR;
}
