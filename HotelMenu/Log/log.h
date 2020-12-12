#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <iomanip>
#include <sstream> //ha nem kell, kivenni
#include <fstream>
#include "date.h"

namespace Logs
{
    class Log
    {
    protected:
    public:
        //CONSTRUCTORS
        Log();

        //DESTRUCTOR
        virtual ~Log();

        //FUNCTIONS
        virtual void printLog() const = 0;
        virtual std::string toString() const = 0;
        virtual void saveStream(std::ofstream& stream) const = 0;
    };
} //eof Logs
#endif // LOG_H
