#include "datebuilder.h"

DateBuilder::DateBuilder()
{

}

date DateBuilder::build(int _year, int _month, int _day)
{
    date ret;
    ret.year = _year;
    ret.month = _month;
    ret.day = _day;
    ret.hour = 0;
    ret.min = 0;
    ret.sec = 0;
    return ret;
}

date DateBuilder::build(int _year, int _month, int _day, int _hour, int _min, int _sec)
{
    date ret;
    ret.year = _year;
    ret.month = _month;
    ret.day = _day;
    ret.hour = _hour;
    ret.min = _min;
    ret.sec = _sec;
    return ret;
}

date DateBuilder::build(std::string sdate)
{
    std::string temp;
    date ret;
    std::stringstream stream;

    temp=sdate.substr(0,sdate.find('.'));
    stream << temp;
    stream >> ret.year;
    stream.clear();

    sdate=sdate.substr(sdate.find('.')+1,sdate.size());

    temp=sdate.substr(0,sdate.find('.'));
    stream << temp;
    stream >> ret.month;
    stream.clear();

    sdate=sdate.substr(sdate.find('.')+1,sdate.size());

    temp=sdate.substr(0,sdate.find('.'));
    stream << temp;
    stream >> ret.day;
    stream.clear();

    sdate=sdate.substr(sdate.find('.')+1,sdate.size());
    ret.hour = 0;
    ret.min = 0;
    ret.sec = 0;

    return ret;
}
