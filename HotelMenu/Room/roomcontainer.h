#ifndef ROOMCONTAINER_H
#define ROOMCONTAINER_H
#include "room.h"
#include "map"
#include "Reservation/reservation.h"
#include "exception"
#include "sstream"
#include "list"
#include <fstream>
#include "datebuilder.h"
#include "Reservation/reservationcontainer.h"
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
    void reportDirtyRoom(std::string loggeduser);

    void setReservation(int roomId,Reservation oneres);

    void deleteReservation(std::string username);

    void loadContent(std::string filename);
    void saveContent(std::string file_name);

    void printAllRoom();

    bool isFree(int roomId)const;
    bool isUsed(int roomId)const;
    bool isCleaned(int roomId)const;
    bool isDirty(int roomId)const;

    void printDirtyRooms();

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
    class AlreadyHasReservation:public std::exception
    {
        std::string massage;
        public:
        AlreadyHasReservation()
        {

        }
        AlreadyHasReservation(int roomid)
        {
            std::stringstream ss;
            ss<<roomid<<"'-room already has Active reservacion id";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
    class YouHaveNoActiveRes:public std::exception
    {
        std::string massage;
        public:
        YouHaveNoActiveRes()
        {
            std::stringstream ss;
            ss<<"You have no active reservacion";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
    class ThisRoomAlreadyClean:public std::exception
    {
        std::string massage;
        public:
        ThisRoomAlreadyClean()
        {

        }
        ThisRoomAlreadyClean(int roomid)
        {
            std::stringstream ss;
            ss<<roomid<<"'-room already cleaned";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
};

#endif // ROOMCONTAINER_H
