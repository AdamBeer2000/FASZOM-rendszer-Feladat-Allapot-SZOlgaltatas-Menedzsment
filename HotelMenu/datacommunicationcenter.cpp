#include "datacommunicationcenter.h"
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::instance=nullptr;

DataCommunicationCenter::DataCommunicationCenter()
{

}
//------------------------------------------------------------------------------------------
//SINGLETON FUNCTION
std::shared_ptr<DataCommunicationCenter> DataCommunicationCenter::getInstance()
{
    if(instance == nullptr)
    {
        instance = std::shared_ptr<DataCommunicationCenter>(new DataCommunicationCenter());
    }
    return instance;
}
//------------------------------------------------------------------------------------------
