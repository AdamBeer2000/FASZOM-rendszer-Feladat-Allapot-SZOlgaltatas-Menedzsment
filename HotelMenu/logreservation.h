#ifndef LOGRESERVATION_H
#define LOGRESERVATION_H

#include "log.h"
#include "reservation.h"
#include "enumServing.h"
#include "enumSuit.h"

namespace Logs
{
    class LogReservation: public Log
    {
    private:
        //VARIABLES
        std::string guest_name;
        date start_date;
        date end_date;
        bool status;
        double cost;
        Suit::suitTypes apartment;
        Serving::servingTypes serving;

    public:
        //CONSTRUCTOR
        LogReservation(int room_id_c, std::string guest_name_c, Suit::suitTypes apartment_c, Serving::servingTypes serving_c, bool cost_c ,date start, date end);

        //FUNCTIONS
        virtual void printLog() const;

        //GETTERS
        int getRoomID() const;
        std::string getGuestName() const;
        double getCost() const;
        Suit::suitTypes getApartment() const;
        Serving::servingTypes getServing() const;
        date getStartDate() const;
        date getEndDate() const;
    };
}// eof Logs
#endif // LOGRESERVATION_H
