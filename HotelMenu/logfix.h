#ifndef LOGFIX_H
#define LOGFIX_H

#include "log.h"

namespace Logs
{
    class LogFix: public Log
    {
    private:
        int room_id;
        std::string item, cause_of_failure;
        double cost;
        date start_date;
        date end_date;

    public:
        LogFix(int room_id_c, std::string item_c, std::string cause_of_failure_c, double cost_c, date start, date end);
        virtual void printLog() const;

        int getRoomID() const;
        std::string getItem() const;
        std::string getCauseOfFailure() const;
        double getCost() const;
        date getStartDate() const;
        date getEndDate() const;
    };
}// eof Logs
#endif // LOGFIX_H
