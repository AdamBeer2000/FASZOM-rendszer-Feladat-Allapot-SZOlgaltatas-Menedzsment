#ifndef ENUMSERVING_H
#define ENUMSERVING_H
#include <string>
#include <sstream>
#include <exception>
namespace Serving
{
    enum servingTypes
    {
        Allinclusive,Premium,Default,NotSetServing,ERROR
    };

    class WrongServingUse:public std::exception
    {
        std::string massage;
        public:

        WrongServingUse()
        {

        }

        WrongServingUse(std::string err)
        {
            std::stringstream ss;
            ss<<"No Serving with: "<<err<<"-name";
            massage=ss.str();
        }
        virtual const char * what() const throw()
        {
            return massage.c_str();
        }
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
    inline servingTypes stringToServing(std::string oneServing)
    {
        if(oneServing=="Allinclusive")return Allinclusive;
        if(oneServing=="Premium")return Premium;
        if(oneServing=="Default")return Default;
        if(oneServing=="NotSetServing")return NotSetServing;
        throw WrongServingUse(oneServing);
        return ERROR;
    }


}

#endif // ENUMSERVING_H
