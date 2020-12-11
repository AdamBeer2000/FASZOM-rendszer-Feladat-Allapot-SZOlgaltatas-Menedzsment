#include "reservationcontainer.h"

ReservationContainer::ReservationContainer()
{

}

ReservationContainer::ReservationContainer(std::list<Reservation> _res)
{
    for(auto r : _res)
    {
        reservations.insert(std::pair<std::string,Reservation>(r.getUserename(),r));
    }
}

void ReservationContainer::addReservation(Reservation newRes)
{
    reservations.insert(std::pair<std::string,Reservation>(newRes.getUserename(),newRes));
}

void ReservationContainer::deleteReservation(std::string guestName)
{
    if(reservations.find(guestName)!=reservations.end())
    {
        reservations.erase(reservations.find(guestName));
    }
    else
    {
        throw NoReservationFound(guestName);
    }
}

void ReservationContainer::bookRoom(std::string _userename, Suit::suitTypes _apartment, date _startTime, date _endTime, Serving::servingTypes _serving)
{
    reservations.insert(std::pair<std::string,Reservation>(_userename,Reservation(_userename,_apartment,_startTime,_endTime,_serving)));
}

void ReservationContainer::loadContent(std::string file_name)
{
    std::ifstream read(file_name);
    if(read.is_open())
    {
        std::string temp;
        std::string oneline;

        std::string userename;
        Suit::suitTypes apartment;
        date startTime;
        date endTime;
        Serving::servingTypes serving;

        while(getline (read, oneline))
        {
            try
            {
                temp=oneline.substr(0,oneline.find(','));
                std::string userename=temp;
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                apartment=Suit::stringToSuit(temp);
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                startTime=startTime.stringToDate(temp);
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                endTime=endTime.stringToDate(temp);
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                serving=Serving::stringToServing(temp);
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                bookRoom(userename,apartment,startTime,endTime,serving);
                //std::cout<<oneline<<std::endl;
            }
            catch(std::exception &e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
    }
}

void ReservationContainer::saveContent(std::string file_name)
{
    std::ofstream save;
    save.open(file_name);
    for(auto res:reservations)
    {
        save<<res.second.getUserename()<<","
            <<res.second.getApartmentInString()<<","
            <<res.second.getStartTime().calendarMode()<<","
            <<res.second.getEndTime().calendarMode()<<","
            <<res.second.getServingInString()
            <<"\n";
    }
    save.close();
}

Reservation ReservationContainer::getReservation(std::string guestName)
{
    if(reservations.find(guestName)!=reservations.end())
    {
        return reservations.find(guestName)->second;
    }
    else
    {
        throw NoReservationFound(guestName);
    }
}

Reservation ReservationContainer::popReservation(std::string guestName)
{
    if(reservations.find(guestName)!=reservations.end())
    {
        Reservation ret=reservations.find(guestName)->second;
        deleteReservation(guestName);
        return ret;
    }
    else
    {
        throw NoReservationFound(guestName);
    }
}

void ReservationContainer::printall()
{
    for(auto res:reservations)
    {
        std::cout<<res.second.getUserename()<<std::endl;
        std::cout<<res.second.getApartmentInString()<<std::endl;
        std::cout<<res.second.getStartTime().calendarMode()<<std::endl;
        std::cout<<res.second.getEndTime().calendarMode()<<std::endl;
        std::cout<<res.second.getServingInString()<<std::endl;
        std::cout<<std::endl;
    }
}
