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
        if(!hotelRooms.find(roomId)->second.getCleaned())
        {
            hotelRooms.at(roomId).setCleaned();
        }
        throw ThisRoomAlreadyClean(roomId);
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::reportDirtyRoom(std::string loggeduser)
{
    for(auto room:hotelRooms)
    {
        if(room.second.getUsed())
        {
            if(room.second.getActiveReservation().getUserename()==loggeduser)
            {
                room.second.setDirty();
                return;
            }
        }
    }
    throw ReservationContainer::NoReservationFound(loggeduser);
}

void RoomContainer::setReservation(int roomId, Reservation oneres)
{
    if(hotelRooms.find(roomId)!=hotelRooms.end())
    {
        if(!hotelRooms.find(roomId)->second.getUsed())
        {
            hotelRooms.at(roomId).setReservation(oneres);
        }
        throw  AlreadyHasReservation(roomId);
    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }
}

void RoomContainer::deleteReservation(std::string username)
{
    for(auto room:hotelRooms)
    {
        if(room.second.getActiveReservation().getUserename()==username)
        {
            hotelRooms.at(room.second.getRoomid()).deleteReservation();
        }
    }
    throw  YouHaveNoActiveRes();
    /*
    if(.find(roomId)!=hotelRooms.end())
    {

    }
    else
    {
        throw  NotExistingRoomExc(roomId);
    }*/
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
                if(!used)
                {
                    hotelRooms.insert({roomid,Room(apartment,roomid,cleaned)});
                }
                else
                {
                    temp=oneline.substr(0,oneline.find(','));
                    std::string resid=temp;
                    oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                    temp=oneline.substr(0,oneline.find(','));
                    std::string userename=temp;
                    oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                    temp=oneline.substr(0,oneline.find(','));
                    startTime=DateBuilder::build(temp);
                    oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                    temp=oneline.substr(0,oneline.find(','));
                    endTime=DateBuilder::build(temp);
                    oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                    temp=oneline.substr(0,oneline.find(','));
                    serving=Serving::stringToServing(temp);
                    oneline=oneline.substr(oneline.find(',')+1,oneline.size());

                    hotelRooms.insert({roomid,Room(apartment,roomid,cleaned,resid,userename,apartment,startTime,endTime,serving)});
                }
            }
            catch(std::exception &e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
    }
}
void RoomContainer::saveContent(std::string file_name)
{
    /*
    Suit::suitTypes apartment;
    bool used=false;
    int roomid;
    bool cleaned;
    Reservation activeReservation;
    */
    std::ofstream save;
    save.open(file_name);
    for(auto room:hotelRooms)
    {
        save<<room.second.getApartmentInString()<<","
            <<room.second.getUsed()<<","
            <<room.second.getRoomid()<<","
            <<room.second.getCleaned();

        if(room.second.getUsed())
        {
            auto res=room.second.getActiveReservation();

            save<<","<<res.getRes_id()
                <<","<<res.getUserename()
                <<","<<res.getStartTime().calendarMode()
                <<","<<res.getEndTime().calendarMode()
                <<","<<res.getServingInString()
                <<"\n";
        }
        else
        {
            save<<"\n";
        }
    }
    save.close();

}
void RoomContainer::printAllRoom()
{
    for(auto room:hotelRooms)
    {
        std::cout<<room.second.getApartmentInString()<<","
            <<room.second.getUsed()<<","
            <<room.second.getCleaned()<<","
            <<room.second.getCleaned();

        if(room.second.getUsed())
        {
            auto res=room.second.getActiveReservation();

            std::cout<<","<<res.getUserename()<<","
                <<res.getStartTime().calendarMode()<<","
                <<res.getEndTime().calendarMode()<<","
                <<res.getServingInString()
                <<"\n";
        }
        else
        {
            std::cout<<"\n";
        }
    }
}

