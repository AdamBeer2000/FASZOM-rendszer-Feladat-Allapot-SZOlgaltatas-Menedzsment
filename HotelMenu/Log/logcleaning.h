#ifndef LOGCLEANING_H
#define LOGCLEANING_H

#include "log.h"

namespace Logs
{
    class LogCleaning: public Log
    {
    private:
        //VARIABLES
        std::string lost_item;
        bool lost_item_exists = false; // default: false
        date cleaning_date;

        //PRIVATE SETTERS
        void setLostItemExists(bool condition);

    public:
        //CONSTRUCTORS
        LogCleaning(int room_id_c, date date_of_cleaning);
        LogCleaning(int room_id_c, std::string item_c, date date_of_cleaning);

        //DESTRUCTOR
        ~LogCleaning();
        //FUNCTIONS
        virtual void printLog() const;
        virtual std::string toString() const;
        virtual void saveStream(std::ofstream& stream) const;

        //GETTERS
        int getRoomID() const;
        std::string getLostItem() const;
        bool getLostItemExists() const;
        date getCleaningDate() const;
    };
}// eof Logs
#endif // LOGCLEANING_H
