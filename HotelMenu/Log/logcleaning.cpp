#include "logcleaning.h"

//CONSTRUCTORS
Logs::LogCleaning::LogCleaning(date date_of_cleaning): Log(), cleaning_date(date_of_cleaning) {}

Logs::LogCleaning::LogCleaning(std::string item_c, date date_of_cleaning): Log(), lost_item(item_c), cleaning_date(date_of_cleaning)
{
    setLostItemExists(true);
}

//DESTRUCTOR
Logs::LogCleaning::~LogCleaning() {}

//PRIVATE SETTERS
void Logs::LogCleaning::setLostItemExists(bool condition)
{
    lost_item_exists = condition;
}

//FUNCTIONS
void Logs::LogCleaning::printLog() const
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "CLEANING: "<< std::endl;

    if(getLostItemExists())
    {
        std::cout << "Lost Item: " << getLostItem() << std::endl;
    }

    std::cout << "Date:" << std::endl;
    std::cout << ""<<  getCleaningDate().calendarMode() << "\t[" << getCleaningDate().clockMode() << "]" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

std::string Logs::LogCleaning::toString() const
{
    std::string result = "";
    std::stringstream stream;

    stream << "-----------------------------------" << std::endl;
    stream << "CLEANING: "<< std::endl;

    if(getLostItemExists())
    {
        stream << "Lost Item: " << getLostItem() << std::endl;
    }

    stream << "Date:" << std::endl;
    stream << ""<<  getCleaningDate().calendarMode() << "\t[" << getCleaningDate().clockMode() << "]" << std::endl;
    stream << "-----------------------------------" << std::endl;

    result += stream.str();
    return result;
}

void Logs::LogCleaning::saveStream(std::ofstream &stream) const
{
    if(getLostItemExists())
    {
        stream << "CLF#";
    }
    else
    {
        stream << "CLN#";
    }
    stream << getCleaningDate().calendarMode() << "#" << getCleaningDate().clockMode();
    if(getLostItemExists())
    {
        stream << "#" << getLostItem();
    }
    stream << "\n";
}

//GETTERS
std::string Logs::LogCleaning::getLostItem() const
{
    return lost_item;
}

bool Logs::LogCleaning::getLostItemExists() const
{
    return lost_item_exists;
}

date Logs::LogCleaning::getCleaningDate() const
{
    return cleaning_date;
}
