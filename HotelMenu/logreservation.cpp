#include "logreservation.h"

//CONSTRUCTOR


//FUNCTIONS
void Logs::LogReservation::printLog() const
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "RESERVATION: "<< std::endl;
    std::cout << "Room: " << getRoomID() << std::endl;
    std::cout << "Replace cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    std::cout << "Guest: " << getGuestName() << std::endl;
    //std::cout << "Suit/Apartment: "<< getApartment() << std::endl;
    //std::cout << "Serving: "<< getServing() << std::endl;
    std::cout << "Date [from-to]:" << std::endl;
    std::cout << ""<<  getStartDate().calendarMode() << "\t[" << getStartDate().clockMode() << "]"  << std::endl << getEndDate().calendarMode() << "\t[" << getEndDate().clockMode() << "]" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

//GETTERS
int Logs::LogReservation::getRoomID() const
{
    return room_id;
}

std::string Logs::LogReservation::getGuestName() const
{
    return guest_name;
}

double Logs::LogReservation::getCost() const
{
    return cost;
}

date Logs::LogReservation::getStartDate() const
{
    return start_date;
}

date Logs::LogReservation::getEndDate() const
{
    return end_date;
}
