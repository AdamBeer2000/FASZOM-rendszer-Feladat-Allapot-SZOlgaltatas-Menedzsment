#include "task.h"

using namespace Tasks;

//CONSTRUCTORS
Task::Task(Task::TaskBuilder &builder)
{
    this->employee = builder.employee;
    this->task_id = builder.task_id;
    this->todo = builder.todo;
    this->status = builder.status;
}

//DESTRUCTOR
Task::~Task()
{
    delete log;
}

//GETTERS SETTERS
bool Task::getStatus() const
{
    return status;
}

void Task::setStatus(bool value)
{
    this->status = value;
}

void Task::setLog(Logs::Log *log)
{
    this->log = log;
}

std::string Task::getEmployee() const
{
    return employee;
}

std::string Task::getTaskId() const
{
    return task_id;
}

std::string Task::getTodo() const
{
    return todo;
}

//FUNCTIONS
bool Task::isActive()
{
    return getStatus();
}

void Task::printLog() const
{
    this->log->printLog();
}

void Task::backupSaveStream(std::ofstream& stream)
{
    log->saveStream(stream);
}

bool Task::isValid(const std::string& data)
{
    if(!data.empty())
    {
        return true;
    }
    else if(data != "")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Task::isValidId(const std::string& task_id_v)
{
    if(task_id_v.length() == 11)
    {
        if(task_id_v.substr(0,3).compare("JAN") == 0 || task_id_v.substr(0,3).compare("REC") == 0 || task_id_v.substr(0,3).compare("CLE") == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Task::printTask() const
{
    try
    {
        if(isValid(getTodo()) && isValid(getEmployee()) && isValidId(getTaskId()))
        {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "Task id: " << getTaskId() << std::endl;
            std::cout << "Task: " << getTodo() << std::endl;
            std::cout << "Status: " << statusToString(getStatus()) << std::endl;
            std::cout << "Employee: " << getEmployee() << std::endl;
            std::cout << "-------------------------------" << std::endl;
        }
        else
        {
            throw InvalidTaskException("[CORRUPTED TASK]: Something went wrong!\n[ID: "+ getTaskId() + "]");
        }
    }
    catch(InvalidTaskException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::string Task::statusToString(bool stat) const
{
    if(stat == true)
    {
        return "Finished";
    }
    else
    {
        return "Unfinished";
    }
}

bool Task::isActive() const
{
    if(this->getStatus())
    {
        return true;
    }
    return false;
}

