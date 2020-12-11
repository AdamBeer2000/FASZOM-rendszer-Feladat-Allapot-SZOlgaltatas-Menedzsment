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
};

#endif // DATEBUILDER_H
