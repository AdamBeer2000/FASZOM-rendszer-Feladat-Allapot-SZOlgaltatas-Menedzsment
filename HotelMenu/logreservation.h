#ifndef LOGRESERVATION_H
#define LOGRESERVATION_H

#include "log.h"
//#include "reservation.h"

namespace Logs
{
    class LogReservation: public Log
    {
    private:
        std::string guest_name;
        date start_date;
        date end_date;
        bool status;
        double cost;
        //suitTypes apartment
        //servingTypes serving

    public:
        //LogReservation(int room_id_c, std::string guest_name_c, suitTypes apartment_c, servingTypes serving_c, bool cost_c ,date start, date end);
        virtual void printLog() const;

        int getRoomID() const;
        std::string getGuestName() const;
        double getCost() const;
        //getApartment() const;
        //getServing(); const
        date getStartDate() const;
        date getEndDate() const;
    };
}// eof Logs
#endif // LOGRESERVATION_H
