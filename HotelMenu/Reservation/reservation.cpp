#include "reservation.h"

std::string Reservation::getUserename() const
{
    return userename;
}

Suit::suitTypes Reservation::getApartment() const
{
    return apartment;
}

date Reservation::getStartTime() const
{
    return startTime;
}

date Reservation::getEndTime() const
{
    return endTime;
}

Serving::servingTypes Reservation::getServing() const
{
    return serving;
}

double Reservation::getStyaingTime()
{
    return startTime.dateDiff(endTime);
}

std::string Reservation::getApartmentInString() const
{
    return suitToString(apartment);
}

std::string Reservation::getServingInString() const
{
    return servingToString(serving);
}

std::string Reservation::getRes_id() const
{
    return res_id;
}

Reservation::Reservation()
{

}

Reservation::Reservation(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime,Serving:: servingTypes _serving)
{
     userename=_userename;
     apartment=_apartment;
     startTime=_startTime;
     endTime=_endTime;
     serving=_serving;
}
Reservation::Reservation(std::string _res_id,std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime,Serving:: servingTypes _serving)
{
     userename=_userename;
     apartment=_apartment;
     startTime=_startTime;
     endTime=_endTime;
     serving=_serving;
     res_id=_res_id;
}
