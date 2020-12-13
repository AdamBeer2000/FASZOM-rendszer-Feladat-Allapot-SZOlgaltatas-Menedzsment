#ifndef TASKCONTAINER_H
#define TASKCONTAINER_H

#include <map>
#include <algorithm>
#include "task.h"
#include "datebuilder.h"

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

    Tasks::Task getTask(std::string task_id);
    int getRoomId(std::string taskid);

    //+FUNCTIONS
    bool ContainerIsEmpty();
    int containerSize();
    Reservation getReserv(std::string task_id);

    void saveStuff(std::ofstream & myesfile);

};

#endif // TASKCONTAINER_H
