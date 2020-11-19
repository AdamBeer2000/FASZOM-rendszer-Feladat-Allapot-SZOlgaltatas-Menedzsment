#ifndef ENUMSERVING_H
#define ENUMSERVING_H
#include <string>
namespace Serving
{
    enum servingTypes
    {
        Allinclusive,Premium,Default,NotSetServing
    };

    inline std::string servingToString(servingTypes oneServing)
    {
        switch (oneServing)
        {
            case Allinclusive:return "Allinclusive";
            case Premium:return "Premium";
            case Default:return "Default";
            case NotSetServing:return "Not Set Serving";
            default:return "ERROR";
        }
    }
}

#endif // ENUMSERVING_H
