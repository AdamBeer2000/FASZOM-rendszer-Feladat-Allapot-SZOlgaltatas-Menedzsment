#ifndef TASKCONTAINER_H
#define TASKCONTAINER_H

#include <map>
#include <algorithm>
#include "task.h"

class TaskContainer
{
private:
    std::map<std::string, Tasks::Task> task_list;
public:
    TaskContainer();

    void addTask(Tasks::Task _task);
    void removeTask(std::string _task_id);

    void printAllTask();
};

#endif // TASKCONTAINER_H
