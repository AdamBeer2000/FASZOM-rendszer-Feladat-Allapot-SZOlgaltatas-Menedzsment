#include "logreservation.h"

//CONSTRUCTOR
Logs::LogReservation::LogReservation(int room_id_c, std::string guest_name_c, Suit::suitTypes apartment_c, Serving::servingTypes serving_c, double cost_c, date start, date end)
    :Log(room_id_c), guest_name(guest_name_c), apartment(apartment_c), serving(serving_c), cost(cost_c), start_date(start), end_date(end) {}

//DESTRUCTOR
Logs::LogReservation::~LogReservation() {}

//FUNCTIONS
void Logs::LogReservation::printLog() const
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "RESERVATION: "<< std::endl;
    std::cout << "Room: " << getRoomID() << std::endl;
    std::cout << "Replace cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    std::cout << "Guest: " << getGuestName() << std::endl;
    std::cout << "Suit/Apartment: "<< Suit::suitToString(getApartment()) << std::endl;
    std::cout << "Serving: "<< Serving::servingToString(getServing()) << std::endl;
    std::cout << "Days: " << getStartDate().dateDiff(getEndDate()) << std::endl;
    std::cout << "Date [from-to]:" << std::endl;
    std::cout << ""<<  getStartDate().calendarMode() << std::endl << getEndDate().calendarMode() << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

std::string Logs::LogReservation::toString() const
{
    std::string result = "";

    return result;
}

void Logs::LogReservation::saveStream(std::ofstream &stream) const
{
    stream << "-----------------------------------" << std::endl;
    stream << "RESERVATION: "<< std::endl;
    stream << "Room: " << getRoomID() << std::endl;
    stream << "Replace cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    stream << "Guest: " << getGuestName() << std::endl;
    stream << "Suit/Apartment: "<< Suit::suitToString(getApartment()) << std::endl;
    stream << "Serving: "<< Serving::servingToString(getServing()) << std::endl;
    stream << "Days: " << getStartDate().dateDiff(getEndDate()) << std::endl;
    stream << "Date [from-to]:" << std::endl;
    stream << ""<<  getStartDate().calendarMode() << std::endl << getEndDate().calendarMode() << std::endl;
    stream << "-----------------------------------" << std::endl;
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

Suit::suitTypes Logs::LogReservation::getApartment() const
{
    return apartment;
}

Serving::servingTypes Logs::LogReservation::getServing() const
{
    return serving;
}

date Logs::LogReservation::getStartDate() const
{
    return start_date;
}

date Logs::LogReservation::getEndDate() const
{
    return end_date;
}
