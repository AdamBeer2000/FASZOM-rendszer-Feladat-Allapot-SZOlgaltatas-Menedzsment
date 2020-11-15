#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <iomanip>
#include "date.h"

namespace Logs
{
    class Log
    {
    private:
        int room_id;

    public:
        Log(int room_id_c);
        virtual void printLog() const = 0;
    };
} //eof Logs
#endif // LOG_H
