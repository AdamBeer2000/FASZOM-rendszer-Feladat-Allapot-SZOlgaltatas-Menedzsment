#ifndef LOGRESERVATION_H
#define LOGRESERVATION_H

#include "log.h"
#include "Reservation/reservation.h"
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
        double cost = 0.0;
        Suit::suitTypes apartment;
        Serving::servingTypes serving;

    public:
        //CONSTRUCTOR
        LogReservation(int room_id_c, std::string guest_name_c, Suit::suitTypes apartment_c, Serving::servingTypes serving_c, double cost_c ,date start, date end);

        //DESTRUCTOR
        ~LogReservation();

        //FUNCTIONS
        virtual void printLog() const;
        virtual std::string toString() const;
        virtual void saveStream(std::ofstream& stream) const;

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
