#include "logreplace.h"

//CONSTRUCTORS
Logs::LogReplace::LogReplace(std::string item_c, std::string cause_of_failure_c, double cost_c, date replace_date_c):
    item(item_c), cause_of_failure(cause_of_failure_c), cost(cost_c), replace_date(replace_date_c) {}

//DESTRUCTOR
Logs::LogReplace::~LogReplace() {}

//FUNCTIONS
void Logs::LogReplace::printLog() const
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "REPLACE: "<< std::endl;
    std::cout << "Item: " << getItem() << std::endl;
    std::cout << "Failure: " << getCauseOfFailure() << std::endl;
    std::cout << "Replace cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    std::cout << "Date:" << std::endl;
    std::cout << ""<<  getReplaceDate().calendarMode() << "\t[" << getReplaceDate().clockMode() << "]" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

std::string Logs::LogReplace::toString() const
{
    std::string result = "";
    std::stringstream stream;

    stream << "-----------------------------------" << std::endl;
    stream << "REPLACE: "<< std::endl;
    stream << "Item: " << getItem() << std::endl;
    stream << "Failure: " << getCauseOfFailure() << std::endl;
    stream << "Replace cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    stream << "Date:" << std::endl;
    stream << ""<<  getReplaceDate().calendarMode() << "\t[" << getReplaceDate().clockMode() << "]" << std::endl;
    stream << "-----------------------------------" << std::endl;

    result += stream.str();
    return result;
}

void Logs::LogReplace::saveStream(std::ofstream &stream) const
{
    stream << "REP#" << getItem() << "#" << getCauseOfFailure() << "#" << getReplaceDate().calendarMode() << "#" << getReplaceDate().clockMode() << "#";
    stream << std::fixed <<std::setprecision(2) << getCost() << "\n";
}

//GETTERS
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
