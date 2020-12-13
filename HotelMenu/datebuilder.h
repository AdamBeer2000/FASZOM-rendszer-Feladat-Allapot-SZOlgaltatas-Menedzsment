#ifndef DATEBUILDER_H
#define DATEBUILDER_H
#include "date.h"
#include <sstream>

class DateBuilder
{
public:
    DateBuilder();
    date build(int _year,int _month,int _day);
    date build(int _year,int _month,int _day,int _hour,int _min,int _sec);
    static date build(std::string sdate);
    static date buildWhithClock(std::string sdate);

    class InvalidDateFormat:public std::exception
    {
        std::string massage;
        public:
        InvalidDateFormat()
        {

        }
        InvalidDateFormat(std::string date)
        {
            std::stringstream ss;
            ss<<"Hiba a datum\""<<date<<"\"";
            massage=ss.str();
        }

        InvalidDateFormat(std::string date,int poz)
        {
            std::stringstream ss;
            ss<<"Hiba a datum\""<<date.substr(poz,date.length())<<"\"-reszen.";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
    class InvalidDate:public std::exception
    {
        std::string massage;
        public:
        InvalidDate()
        {

        }
        InvalidDate(std::string date, std::string what,int num)
        {
            std::stringstream ss;
            ss<<"A\""<<date<<"\"-ben nem valos a(z): "<<num<<"."<<what;
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
};

#endif // DATEBUILDER_H
