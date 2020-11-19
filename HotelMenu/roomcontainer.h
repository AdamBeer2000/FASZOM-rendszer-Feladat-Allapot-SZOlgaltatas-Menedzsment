#ifndef ROOMCONTAINER_H
#define ROOMCONTAINER_H
#include "room.h"
#include "map"
#include "reservation.h"
class RoomContainer
{
    std::map<int,Room>hotelRooms;
public:
    RoomContainer();
    void add(Suit::suitTypes _apartment,int _roomid,bool cleaned);
    void setRoomFree(int roomId);
    void setRoomUsed(int roomId);
    void cleanRoom(int roomId);
    void setReservation(int roomId,Reservation oneres);
    void deleteReservation(int roomId);

    bool isFree(int roomId)const;
    bool isUsed(int roomId)const;
    bool isCleaned(int roomId)const;
    bool isDirty(int roomId)const;

    Suit::suitTypes getSuitType(int roomId);


};

#endif // ROOMCONTAINER_H
