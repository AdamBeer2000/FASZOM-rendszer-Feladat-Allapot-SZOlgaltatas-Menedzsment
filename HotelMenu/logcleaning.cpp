#include "logcleaning.h"

//CONSTRUCTORS
Logs::LogCleaning::LogCleaning(int room_id_c, date date_of_cleaning): Log(room_id_c), cleaning_date(date_of_cleaning) {}

Logs::LogCleaning::LogCleaning(int room_id_c, std::string item_c, date date_of_cleaning): Log(room_id_c), lost_item(item_c), cleaning_date(date_of_cleaning)
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
    std::cout << "Room: " << getRoomID() << std::endl;

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

    return result;
}

void Logs::LogCleaning::saveStream(std::ofstream &stream) const
{
    stream << "-----------------------------------" << std::endl;
    stream << "CLEANING: "<< std::endl;
    stream << "Room: " << getRoomID() << std::endl;

    if(getLostItemExists())
    {
        stream << "Lost Item: " << getLostItem() << std::endl;
    }

    stream << "Date:" << std::endl;
    stream << ""<<  getCleaningDate().calendarMode() << "\t[" << getCleaningDate().clockMode() << "]" << std::endl;
    stream << "-----------------------------------" << std::endl;
}

//GETTERS
int Logs::LogCleaning::getRoomID() const
{
    return room_id;
}

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
