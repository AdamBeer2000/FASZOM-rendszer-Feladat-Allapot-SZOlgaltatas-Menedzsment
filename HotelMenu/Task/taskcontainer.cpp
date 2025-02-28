#include "taskcontainer.h"

//CONSTRUCTOR
TaskContainer::TaskContainer()
{

}

//FUNCTIONS
void TaskContainer::addTask(Tasks::Task _task)
{
    Tasks::Task debug(_task);
    task_list.insert({_task.getTaskId(), debug});
}

void TaskContainer::deleteTask(std::string _task_id)
{
    task_list.erase(_task_id);
}

void TaskContainer::printAllTask() const
{
    for(auto it = task_list.begin(); it != task_list.end(); it++)
    {
        (*it).second.printTask();
    }
}

void TaskContainer::printAllLog() const
{
    for(auto it = task_list.begin(); it != task_list.end(); it++)
    {
        (*it).second.printLog();
    }
}

void TaskContainer::setLog(std::string task_id_l, Logs::Log *one_log)
{
    auto it = task_list.find(task_id_l);
    try
    {
        if(taskExists(task_id_l))
        {
            it->second.setLog(one_log);
        }
        else
        {
            Tasks::Task::InvalidTaskException("[TASK DOES NOT EXISTS]: Task could not be found!\n[ID: "+ task_id_l + "]");
        }
    }
    catch (Tasks::Task::InvalidTaskException& e)
    {

        std::cout << e.what() << std::endl;
    }
}

bool TaskContainer::taskExists(std::string task_id_e)
{
    auto it = task_list.find(task_id_e);
    return it != task_list.end() ? true : false;
}

int TaskContainer::getActiveTasksNumber() const
{
    int result = 0;

    for(auto it = task_list.begin(); it != task_list.end(); it++)
    {
        if(it->second.isActive())
        {
            result++;
        }
    }
    return result;
}

Tasks::Task TaskContainer::getTask(std::string task_id)
{
    return task_list.find(task_id)->second;
}

int TaskContainer::getRoomId(std::string taskid)
{
    return task_list.find(taskid)->second.getRoomid();
}

void TaskContainer::setStatusDone(std::string task_id_st)
{
    auto it = task_list.find(task_id_st);
    try
    {
        if(taskExists(task_id_st))
        {
            it->second.setStatus(true);
        }
        else
        {
            Tasks::Task::InvalidTaskException("[TASK DOES NOT EXISTS]: Task could not be found!\n[ID: "+ task_id_st + "]");
        }
    }
    catch (Tasks::Task::InvalidTaskException& e)
    {

        std::cout << e.what() << std::endl;
    }
}

//+FUNCTIONS
int TaskContainer::containerSize()
{
    return task_list.size();
}

Reservation TaskContainer::getReserv(std::string task_id)
{
    return task_list.find(task_id)->second.getRes();
}

void TaskContainer::saveStuff(std::ofstream & myesfile)
{
    for(auto task:task_list)
    {
        task.second.backupSaveStream(myesfile);
    }
}

bool TaskContainer::ContainerIsEmpty()
{
    return this->containerSize() == 0 ? true : false;
}
