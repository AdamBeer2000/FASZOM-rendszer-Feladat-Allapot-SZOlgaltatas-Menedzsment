#ifndef ENUMSUIT_H
#define ENUMSUIT_H
#include <string>
namespace Suit
{
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
}
#endif // ENUMSUIT_H
