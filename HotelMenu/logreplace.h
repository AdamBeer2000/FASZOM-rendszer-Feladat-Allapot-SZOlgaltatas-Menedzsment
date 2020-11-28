#ifndef LOGREPAIR_H
#define LOGREPAIR_H

#include "log.h"

namespace Logs
{
    class LogReplace: public Log
    {
    private:
        std::string item, cause_of_failure;
        double cost;
        date replace_date;

    public:
        //CONSTRUCTORS
        LogReplace(int room_id_c, std::string item_c, std::string cause_of_failure_c, double cost_c, date replace_date_c);

        //DESTRUCTOR
        ~LogReplace();

        //FUNCTIONS
        virtual void printLog() const;
        virtual std::string toString() const;
        virtual void saveStream(std::ofstream& stream) const;

        //GETTERS
        int getRoomID() const;
        std::string getItem() const;
        std::string getCauseOfFailure() const;
        double getCost() const;
        date getReplaceDate() const;

    };
}// eof Logs
#endif // LOGREPAIR_H
