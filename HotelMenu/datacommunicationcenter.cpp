#include "datacommunicationcenter.h"
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::instance=nullptr;

void DataCommunicationCenter::readReservationFile()
{
    /*
    std::string userename;
    Suit::suitTypes apartment=Suit::NotSetSuit;
    date endTime;
    Serving::servingTypes serving=Serving::NotSetServing;
    */
   std::ifstream read("Reservation_Data.txt");
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
               std::string userename=oneline.substr(0,oneline.find(','));
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               apartment=Suit::stringToServing(temp);
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               startTime=startTime.stringToDate(temp);
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               endTime=endTime.stringToDate(temp);
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               temp=oneline.substr(0,oneline.find(','));
               serving=Serving::stringToServing(oneline.substr(0,oneline.find(',')));
               oneline=oneline.substr(oneline.find(',')+1,oneline.size());

               reservation_cont.bookRoom(userename,apartment,startTime,endTime,serving);
               //std::cout<<oneline<<std::endl;
           }
           catch(std::exception &e)
           {
               std::cout<<e.what()<<std::endl;
           }

       }
   }

}

//------------------------------------------------------------------------------------------
//SINGLETON FUNCTION
DataCommunicationCenter::DataCommunicationCenter()
{
    readReservationFile();
}

DataCommunicationCenter::DataCommunicationCenter(const DataCommunicationCenter &other)
{

}

std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::getInstance()
{
    if(instance == nullptr)
    {
        instance = std::shared_ptr<DataCommunicationCenter>(new DataCommunicationCenter());
    }
    return instance;
}
//------------------------------------------------------------------------------------------

void DataCommunicationCenter::accepptReservation(int room_id, Reservation res)
{
    room_cont.setReservation(room_id,res);
    reservation_cont.deleteReservation(res.getUserename());
}

void DataCommunicationCenter::printRes()
{
    reservation_cont.printall();
}


