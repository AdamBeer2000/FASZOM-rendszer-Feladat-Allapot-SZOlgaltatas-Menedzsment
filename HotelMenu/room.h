#ifndef ROOM_H
#define ROOM_H
#include "reservation.h"

class Room
{
public:

    Suit::suitTypes apartment;
    bool used=false;
    int roomid;
    bool cleaned;
    Reservation activeReservation;
    Room();
    Room(Suit::suitTypes _apartment,int _roomid,bool cleaned);//szoba aktív foglalás nélkül
    Room(Suit::suitTypes _apartment,int _roomid,bool _cleaned,std::string _userename,Suit::suitTypes,date _startTime,date _endTime,Serving::servingTypes _serving);//szoba aktív foglalással

    int getRoomid() const;
    bool getUsed() const;//foglalva van
    bool getCleaned() const;//takarítva van? ha igen true ha nem false
    Suit::suitTypes getApartment() const; //vissza adja a lakosztájtipust

    void setCleaned();//kitakarítja
    void setDirty();//koszosra álítja

     //egy foglalást add hozá adatok segítséggével
    void setReservation(std::string _userename,Suit::suitTypes _apartment,date _startTime,date _endTime,Serving::servingTypes _serving);

    //egy db foglalást-t hozzátársít a szobához
    void setReservation(Reservation & oneRes);

    //törli a foglalást
    void deleteReservation();

    std::string getApartmentInString() const;

    ~Room();


};

#endif // ROOM_H
