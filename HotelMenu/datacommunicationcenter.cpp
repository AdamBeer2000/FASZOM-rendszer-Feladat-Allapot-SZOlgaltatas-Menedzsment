#include "datacommunicationcenter.h"
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::instance=nullptr;

//------------------------------------------------------------------------------------------
//SINGLETON FUNCTION
DataCommunicationCenter::DataCommunicationCenter()
{

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

