#ifndef LOGRESERVATION_H
#define LOGRESERVATION_H

#include "log.h"
//#include "logreservation.h"

namespace Logs
{
    class LogReservation: public Log
    {
    private:
        std::string guest_name;
        date start_date;
        date end_date;
        bool status;
        //suitTypes apartment
        //servingTypes serving

    public:
        //LogReservation(int room_id_c, std::string guest_name_c, servingTypes, suitTypes su,date start, date end);
        virtual void printLog() const;

        int getRoomID() const;
        std::string getItem() const;
        std::string getCauseOfFailure() const;
        double getCost() const;
        date getStartDate() const;
        date getEndDate() const;
    };
}// eof Logs
#endif // LOGRESERVATION_H
