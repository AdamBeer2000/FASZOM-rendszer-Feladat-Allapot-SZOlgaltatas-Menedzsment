#ifndef DATEBUILDER_H
#define DATEBUILDER_H
#include "date.h"

class DateBuilder
{
public:
    DateBuilder();
    date build(int _year,int _month,int _day);
    date build(int _year,int _month,int _day,int _hour,int _min,int _sec);
    date build(std::string sdate);
};

#endif // DATEBUILDER_H
