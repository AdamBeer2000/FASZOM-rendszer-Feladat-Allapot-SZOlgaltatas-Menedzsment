#include "logreplace.h"

//CONSTRUCTORS
Logs::LogReplace::LogReplace(int room_id_c, std::string item_c, std::string cause_of_failure_c, double cost_c, date replace_date_c):
    Log(room_id_c), item(item_c), cause_of_failure(cause_of_failure_c), cost(cost_c), replace_date(replace_date_c) {}

//FUNCTIONS
void Logs::LogReplace::printLog() const
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "REPLACE: "<< std::endl;
    std::cout << "Room: " << getRoomID() << std::endl;
    std::cout << "Item: " << getItem() << std::endl;
    std::cout << "Failure: " << getCauseOfFailure() << std::endl;
    std::cout << "Replace cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    std::cout << "Date:" << std::endl;
    std::cout << ""<<  getReplaceDate().calendarMode() << "\t[" << getReplaceDate().clockMode() << "]" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

//GETTERS
int Logs::LogReplace::getRoomID() const
{
    return room_id;
}

std::string Logs::LogReplace::getItem() const
{
    return item;
}

std::string Logs::LogReplace::getCauseOfFailure() const
{
    return cause_of_failure;
}

double Logs::LogReplace::getCost() const
{
    return cost;
}

date Logs::LogReplace::getReplaceDate() const
{
    return replace_date;
}
