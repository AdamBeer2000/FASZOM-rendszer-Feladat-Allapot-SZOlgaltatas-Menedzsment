#include "taskcontainer.h"

TaskContainer::TaskContainer()
{

}

void TaskContainer::addTask(Tasks::Task _task)
{
    task_list.insert({_task.getTaskId(), _task});
}

void TaskContainer::removeTask(Tasks::Task _task)
{
    task_list.erase(_task.getTaskId());
}

void TaskContainer::printAllTask()
{
    for(auto it = task_list.begin(); it != task_list.end(); it++)
    {
        (*it).second.printTask();
    }
}
