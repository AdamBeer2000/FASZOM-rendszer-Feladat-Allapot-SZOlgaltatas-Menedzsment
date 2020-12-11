#include "roomcontainer.h"

RoomContainer::RoomContainer(std::list<Room> _hotelRooms)
{
    for(auto room : _hotelRooms)
    {
        hotelRooms.insert(std::pair<int,Room>(room.getRoomid(),room));
    }
}

RoomContainer::RoomContainer()
{

}

void RoomContainer::add(Suit::suitTypes _apartment, int _roomid, bool cleaned)
{
    hotelRooms.insert(std::pair<int,Room>(_roomid,Room(_apartment,_roomid,cleaned)));
}

void RoomContainer::add(Room oneroom)
{
    hotelRooms.insert(std::pair<int,Room>(oneroom.getRoomid(),oneroom));
}

void RoomContainer::setRoomFree(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setFree();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::setRoomUsed(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setUsed();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::cleanRoom(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setCleaned();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::setReservation(int roomId, Reservation oneres)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).setReservation(oneres);
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::deleteReservation(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        hotelRooms.at(roomId).deleteReservation();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

bool RoomContainer::isFree(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return !hotelRooms.at(roomId).getUsed();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

bool RoomContainer::isUsed(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getUsed();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

bool RoomContainer::isCleaned(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getCleaned();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

bool RoomContainer::isDirty(int roomId) const
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return !hotelRooms.at(roomId).getCleaned();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return false;//to do excepcion
}

Suit::suitTypes RoomContainer::getSuitType(int roomId)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        return hotelRooms.at(roomId).getApartment();
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
    return Suit::ERROR;
}
void RoomContainer::loadContent(std::string file_name)
{
    std::ifstream read(file_name);
    if(read.is_open())
    {
        std::string temp;
        std::string oneline;

        Suit::suitTypes apartment;
        bool used=false;
        int roomid;
        bool cleaned;

        std::string userename;
        date startTime;
        date endTime;
        Serving::servingTypes serving;

        while(getline (read, oneline))
        {
            try
            {
                temp=oneline.substr(0,oneline.find(','));
                apartment=Suit::stringToSuit(temp);
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                if(temp=="0")
                {
                    used=false;
                }
                else
                {
                    used=true;
                }
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                roomid=stoi(temp);
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                temp=oneline.substr(0,oneline.find(','));
                if(temp=="0")
                {
                    cleaned=false;
                }
                else
                {
                    cleaned=true;
                }
                oneline=oneline.substr(oneline.find(',')+1,oneline.size());
                std::cout<<Suit::suitToString(apartment)<<","<<used<<","<<roomid<<","<<cleaned<<"\n";
                if(!used)
                {
                    hotelRooms.insert({roomid,Room(apartment,roomid,cleaned)});
                }
                else
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

                    ;

                    hotelRooms.insert({roomid,Room(apartment,roomid,cleaned,userename,apartment,startTime,endTime,serving)});
                    std::cout<<Suit::suitToString(apartment)<<","
                            <<used<<","<<roomid<<","<<cleaned<<","<<userename<<","<<apartment<<","
                            <<startTime.calendarMode()<<","<<endTime.calendarMode()<<","<<Serving::servingToString(serving)<<"\n";
                }
                //std::cout<<oneline<<std::endl;
            }
            catch(std::exception &e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
    }
}
