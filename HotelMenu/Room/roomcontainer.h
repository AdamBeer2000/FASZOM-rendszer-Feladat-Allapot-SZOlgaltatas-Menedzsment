#ifndef ROOMCONTAINER_H
#define ROOMCONTAINER_H
#include "room.h"
#include "map"
#include "Reservation/reservation.h"
#include "exception"
#include "sstream"
#include "list"

class RoomContainer
{
    std::map<int,Room>hotelRooms;
public:
    RoomContainer(std::list<Room> _hotelRooms);
    RoomContainer();

    void add(Suit::suitTypes _apartment,int _roomid,bool cleaned);
    void add(Room oneroom);
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

    class NotExistingRoomExc:public std::exception
    {
        std::string massage;
        public:
        NotExistingRoomExc()
        {

        }
        NotExistingRoomExc(int roomid)
        {
            std::stringstream ss;
            ss<<"No room found with: '"<<roomid<<"'-room id";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
};

#endif // ROOMCONTAINER_H
