#include "date.h"

int Date::getYear() const
{
    return year;
}

void Date::setYear(int value)
{
    year = value;
}

int Date::getMonth() const
{
    return month;
}

void Date::setMonth(int value)
{
    month = value;
}

int Date::getDay() const
{
    return day;
}

void Date::setDay(int value)
{
    day = value;
}

int Date::getHour() const
{
    return hour;
}

void Date::setHour(int value)
{
    hour = value;
}

int Date::getMin() const
{
    return min;
}

void Date::setMin(int value)
{
    min = value;
}

int Date::getSec() const
{
    return sec;
}

void Date::setSec(int value)
{
    sec = value;
}

Date::Date()
{

}

std::string Date::clockMode()
{
    std::string converted = "";

    if(hour < 10)
    {
        converted += "0" + std::to_string(hour);
    }
    else
    {
        converted += std::to_string(hour);
    }
    converted += ":";

    if(min < 10)
    {
        converted += "0" + std::to_string(min);
    }
    else
    {
        converted += std::to_string(min);
    }
    converted += ":";

    if(sec < 10)
    {
        converted += "0" + std::to_string(sec);
    }
    else
    {
        converted += std::to_string(sec);
    }

    return converted;
}

std::string Date::calendarMode()
{
    std::string converted = "";

    converted += std::to_string(year) + ".";

    if(month < 10)
    {
        converted += "0" + std::to_string(month);
    }
    else
    {
        converted += std::to_string(month);
    }
    converted += ".";

    if(day < 10)
    {
        converted += "0" + std::to_string(day);
    }
    else
    {
        converted += std::to_string(day);
    }

    //EASTER EGG----------------------------
    if(year == 2020 && month && 11&& day == 16)
    {
        Rogie();
    }
    //--------------------------------------

    return converted;
}

double Date::dateDiff(Date other)
{
    double diff=0;
    diff+=abs((this->year-other.year))*365;
    diff+=abs((this->month-other.month))*30;
    diff+=abs((this->day-other.day));
    return diff;
}
