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
        time_t start_date;
        time_t end_date;

    public:
        LogFix(int room_id_c, std::string item_c, std::string cause_of_failure_c, double cost_c, time_t start, time_t end);
        virtual void printLog() const;

        int getRoomID() const;
        std::string getItem() const;
        std::string getCauseOfFailure() const;
        double getCost() const;
        time_t getStartDate() const;
        time_t getEndDate() const;
    };
}// eof Logs
#endif // LOGFIX_H
