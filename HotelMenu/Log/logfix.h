#ifndef LOGFIX_H
#define LOGFIX_H

#include "log.h"

namespace Logs
{
    class LogFix: public Log
    {
    private:
        //VARIABLES
        std::string item, cause_of_failure;
        double cost;
        date start_date;
        date end_date;

    public:
        //CONSTRUCTOR
        LogFix(int room_id_c, std::string item_c, std::string cause_of_failure_c, double cost_c, date start, date end);

        //DESTRUCTOR
        ~LogFix();

        //FUNCTIONS
        virtual void printLog() const;
        virtual std::string toString() const;
        virtual void saveStream(std::ofstream& stream) const;

        //GETTERS
        int getRoomID() const;
        std::string getItem() const;
        std::string getCauseOfFailure() const;
        double getCost() const;
        date getStartDate() const;
        date getEndDate() const;
    };
}// eof Logs
#endif // LOGFIX_H
