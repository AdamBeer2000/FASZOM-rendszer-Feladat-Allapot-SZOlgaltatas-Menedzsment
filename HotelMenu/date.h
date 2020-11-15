#ifndef DATE_H
#define DATE_H

#include <string>

struct date
{
    //VARIABLES
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;

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
};

#endif // DATE_H
