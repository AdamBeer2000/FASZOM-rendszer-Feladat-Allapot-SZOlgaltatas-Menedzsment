#include "logfix.h"

//CONSTRUCTOR
Logs::LogFix::LogFix(std::string item_c, std::string cause_of_failure_c, double cost_c, date start, date end):
    item(item_c), cause_of_failure(cause_of_failure_c), cost(cost_c), start_date(start), end_date(end){}

//DESTRUCTOR
Logs::LogFix::~LogFix()
{
    std::cout<<"dest2\n";
}

//FUNCTIONS
void Logs::LogFix::printLog() const
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "FIX: "<< std::endl;
    std::cout << "Item: " << getItem() << std::endl;
    std::cout << "Failure: " << getCauseOfFailure() << std::endl;
    std::cout << "Repair cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    std::cout << "Date:" << std::endl;
    std::cout << ""<<  getStartDate().calendarMode() << "\t[" << getStartDate().clockMode() << "]"  << std::endl << getEndDate().calendarMode() << "\t[" << getEndDate().clockMode() << "]" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

std::string Logs::LogFix::toString() const
{
    std::string result = "";
    std::stringstream stream;

    stream << "-----------------------------------" << std::endl;
    stream << "FIX: "<< std::endl;
    stream << "Item: " << getItem() << std::endl;
    stream << "Failure: " << getCauseOfFailure() << std::endl;
    stream << "Repair cost: " << std::fixed <<std::setprecision(2) << getCost() << " [EUR]" << std::endl;
    stream << "Date:" << std::endl;
    stream << ""<<  getStartDate().calendarMode() << "\t[" << getStartDate().clockMode() << "]"  << std::endl << getEndDate().calendarMode() << "\t[" << getEndDate().clockMode() << "]" << std::endl;
    stream << "-----------------------------------" << std::endl;

    result += stream.str();
    return result;
}

void Logs::LogFix::saveStream(std::ofstream &stream) const
{
    stream << "FIX#" << getItem() << "#" << getCauseOfFailure() << "#"
    << getStartDate().calendarMode() << "#" << getStartDate().clockMode() << "#"  << std::endl << getEndDate().calendarMode() << "#" << getEndDate().clockMode() << "#"
    << std::fixed <<std::setprecision(2) << getCost() << "\n";
}

//GETTERS
std::string Logs::LogFix::getItem() const
{
    return item;
}

std::string Logs::LogFix::getCauseOfFailure() const
{
    return cause_of_failure;
}

double Logs::LogFix::getCost() const
{
    return cost;
}

date Logs::LogFix::getStartDate() const
{
    return start_date;
}

date Logs::LogFix::getEndDate() const
{
    return end_date;
}
