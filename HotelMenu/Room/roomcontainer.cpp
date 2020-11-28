#include "roomcontainer.h"

RoomContainer::RoomContainer()
{

}

void RoomContainer::add(Suit::suitTypes _apartment, int _roomid, bool cleaned)
{
    hotelRooms.insert(std::pair<int,Room>(_roomid,Room(_apartment,_roomid,cleaned)));
}

void RoomContainer::add(Room oneroom)
{
    hotelRooms.insert(std::pair<int,Room>(oneroom.getRoomid(),oneroom));
}

void RoomContainer::setRoomFree(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setFree();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::setRoomUsed(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setUsed();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::cleanRoom(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setCleaned();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::setReservation(int roomId, Reservation oneres)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setReservation(oneres);
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::deleteReservation(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).deleteReservation();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

bool RoomContainer::isFree(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return !hotelRooms.at(roomId).getUsed();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

bool RoomContainer::isUsed(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getUsed();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

bool RoomContainer::isCleaned(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getCleaned();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

bool RoomContainer::isDirty(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return !hotelRooms.at(roomId).getCleaned();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

Suit::suitTypes RoomContainer::getSuitType(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getApartment();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return Suit::ERROR;
}
