#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <iomanip>
#include "date.h"

namespace Logs
{
    class Log
    {
    protected:
        int room_id;

    public:
        //CONSTRUCTORS
        Log(int room_id_c);

        //DESTRUCTOR
        virtual ~Log();

        //FUNCTIONS
        virtual void printLog() const = 0;
    };
} //eof Logs
#endif // LOG_H
