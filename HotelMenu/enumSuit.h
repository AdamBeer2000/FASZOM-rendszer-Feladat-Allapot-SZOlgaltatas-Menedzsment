#ifndef ENUMSUIT_H
#define ENUMSUIT_H
#include <string>
#include <sstream>
#include <exception>
#include <iostream>
namespace Suit
{
    class WrongSuitUse:public std::exception
    {
        std::string massage;
        public:

        WrongSuitUse()
        {

        }

        WrongSuitUse(std::string err)
        {
            std::stringstream ss;
            ss<<"No Suiting with: "<<err<<"-name";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
    };
    enum suitTypes
    {
        Luxury,Medium,Notbad,NotSetSuit,ERROR
    };
    inline std::string suitToString(suitTypes oneSuit)
    {
        switch (oneSuit)
        {
            case Luxury:return "Luxury";
            case Medium:return "Medium";
            case Notbad:return "Notbad";
            case NotSetSuit:return "Not Set Suit";
            default:return "ERROR";
        }
    }
    inline enum suitTypes stringToSuit(std::string oneSuit)
    {
        if(oneSuit=="Luxury") return Luxury;
        if(oneSuit=="Medium") return Medium;
        if(oneSuit=="Notbad") return Notbad;
        if(oneSuit=="NotSetSuit") return NotSetSuit;
        throw WrongSuitUse(oneSuit);
        return ERROR;
    }
}
#endif // ENUMSUIT_H
