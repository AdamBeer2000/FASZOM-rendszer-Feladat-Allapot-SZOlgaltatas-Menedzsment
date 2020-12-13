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
    std::string originalstring=sdate;
    date ret;
    std::stringstream stream;
    ret.hour = 0;
    ret.min = 0;
    ret.sec = 0;

    temp=sdate.substr(0,sdate.find('.'));
    stream << temp;
    stream >> ret.year;
    stream.clear();

    sdate=sdate.substr(sdate.find('.')+1,sdate.size());
    temp=sdate.substr(0,sdate.find('.'));

    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));
    stream << temp;
    stream >> ret.month;
    if(ret.month>12||ret.month<1)
        throw InvalidDate(originalstring,"honap",ret.month);
    stream.clear();

    sdate=sdate.substr(sdate.find('.')+1,sdate.size());
    temp=sdate.substr(0,sdate.find('.'));

    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));

    stream << temp;
    stream >> ret.day;
    if(ret.month>31||ret.month<1)
        throw InvalidDate(originalstring,"nap",ret.day);

    stream.clear();

    return ret;
}
date DateBuilder::buildWhithClock(std::string sdate)
{
    std::string temp;
    std::string originalstring=sdate;

    std::string datepart=sdate.substr(0,sdate.find(' '));

    std::string timepart=sdate.substr(sdate.find(' ')+1,sdate.length());


    date ret;
    std::stringstream stream;

    temp=datepart.substr(0,sdate.find('.'));
    stream << temp;
    stream >> ret.year;
    stream.clear();

    datepart=datepart.substr(datepart.find('.')+1,datepart.size());
    temp=datepart.substr(0,datepart.find('.'));

    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));
    stream << temp;
    stream >> ret.month;
    if(ret.month>12||ret.month<1)
        throw InvalidDate(originalstring,"honap",ret.month);
    stream.clear();

    datepart=datepart.substr(datepart.find('.')+1,datepart.size());
    temp=datepart.substr(0,datepart.find('.'));

    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));

    stream << temp;
    stream >> ret.day;
    if(ret.month>31||ret.month<1)
        throw InvalidDate(originalstring,"nap",ret.day);

    stream.clear();


    temp=timepart.substr(0,timepart.find(':'));
    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));
    stream << temp;
    stream >> ret.hour;
    if(ret.hour>24||ret.hour<0)
        throw InvalidDate(originalstring,"ora",ret.hour);
    stream.clear();

    timepart=timepart.substr(timepart.find(':')+1,timepart.size());
    temp=timepart.substr(0,timepart.find(':'));

    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));
    stream << temp;
    stream >> ret.min;
    if(ret.min>59||ret.min<0)
        throw InvalidDate(originalstring,"perc",ret.min);
    stream.clear();

    timepart=timepart.substr(timepart.find(':')+1,timepart.size());
    temp=timepart.substr(0,timepart.find(':'));

    if(temp.length()>2||temp.length()<1)
        throw InvalidDateFormat(originalstring,originalstring.find(temp));

    stream << temp;
    stream >> ret.sec;
    if(ret.min>59||ret.min<0)
        throw InvalidDate(originalstring,"masodperc",ret.sec);

    stream.clear();



    return ret;



    return ret;
}
