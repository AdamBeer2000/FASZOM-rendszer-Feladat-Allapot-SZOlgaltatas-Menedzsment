#ifndef DATE_H
#define DATE_H

#include <string>
#include <math.h>

struct date
{
    //VARIABLES
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int min = 0;
    int sec = 0;

    //FUNCTIONS
    std::string clockMode()
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

    std::string calendarMode()
    {
        std::string converted = "";

        converted += std::to_string(year) + "/";

        if(month < 10)
        {
            converted += "0" + std::to_string(month);
        }
        else
        {
            converted += std::to_string(month);
        }
        converted += "/";

        if(day < 10)
        {
            converted += "0" + std::to_string(day);
        }
        else
        {
            converted += std::to_string(day);
        }
        return converted;
    }

    double dateDiff(struct date other)//a hónap az 30 nap,az év 365 nem érdekel xd napokba számol
    {
        double diff=0;
        diff+=abs((this->year-other.year))*365;
        diff+=abs((this->month-other.month))*30;
        diff+=abs((this->day-other.day));
        return diff;
    }

    void setDate(int _year,int _month,int _day)//beálítja év hó nap
    {
        year = _year;
        month = _month;
        day = _day;
    }

    void setDate(int _year,int _month,int _day,int _hour,int _min,int _sec)//beálítja a többit is lusta voltam egyenként :D irogatni
    {
        year = _year;
        month = _month;
        day = _day;
        hour = _hour;
        min = _min;
        sec = _sec;
    }

    date buildDate(int _year,int _month,int _day)//beálítja év hó nap
    {
        year = _year;
        month = _month;
        day = _day;
        return date(*this);
    }

    date buildDate(int _year,int _month,int _day,int _hour,int _min,int _sec)//beálítja a többit is lusta voltam egyenként :D irogatni
    {
        year = _year;
        month = _month;
        day = _day;
        hour = _hour;
        min = _min;
        sec = _sec;
        return date(*this);
    }

};

#endif // DATE_H
