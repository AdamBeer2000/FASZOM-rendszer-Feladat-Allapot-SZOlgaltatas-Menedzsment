#ifndef RESERVATION_H
#define RESERVATION_H
#include "date.h"

#include "enumSuit.h"
#include "enumServing.h"


class Reservation
{
    std::string userename;
    Suit::suitTypes apartment=Suit::NotSetSuit;
    date startTime;
    date endTime;
    Serving::servingTypes serving=Serving::NotSetServing;

    std::string res_id;

public:    
    Reservation();
    Reservation(std::string _userename,Suit::suitTypes _apartment,date _startTime,date _endTime,Serving::servingTypes _serving);
    Reservation(std::string res_id,std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving);

    std::string getUserename() const;
    Suit::suitTypes getApartment() const;
    date getStartTime() const;
    date getEndTime() const;
    Serving::servingTypes getServing() const;
    double getStyaingTime();

    std::string getApartmentInString() const;
    std::string getServingInString() const;


    std::string getRes_id() const;
};

#endif // RESERVATION_H
