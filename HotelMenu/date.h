#ifndef DATE_H
#define DATE_H

#include <string>
#include <math.h>
#include <iostream>

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

    //EASTER EGG-------------------------------------------------------------------
    void Rogie()
    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Jo kutya voltal, Roger, baratom.. [2020/11/16]" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
    }
    //-----------------------------------------------------------------------------
};

#endif // DATE_H
