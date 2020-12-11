#ifndef TASKCONTAINER_H
#define TASKCONTAINER_H

#include <map>
#include <algorithm>
#include "task.h"

class TaskContainer
{
private:
    //VARIABLES
    std::map<std::string, Tasks::Task> task_list; // <task_id, task>

public:
    //CONSTRUCTOR
    TaskContainer();

    //FUNCTIONS
    void addTask(Tasks::Task _task);
    void deleteTask(std::string _task_id);
    void printAllTask() const;
    void printAllLog() const;
    void setLog(std::string task_id_l, Logs::Log* one_log);
    void setStatusDone(std::string task_id_st);
    bool taskExists(std::string task_id_e);
    int getActiveTasksNumber() const;

    //+FUNCTIONS
    bool ContainerIsEmpty();
    int containerSize();

};

#endif // TASKCONTAINER_H
