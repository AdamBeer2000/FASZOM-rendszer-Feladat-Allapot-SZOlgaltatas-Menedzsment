#include "task.h"

using namespace Tasks;

Task::Task(string employee_c, string task_id_c):
    employee(employee_c), task_id(task_id_c)
{

}

bool Task::getStatus() const
{
    return status;
}

void Task::setStatus(bool value)
{
    status = value;
}

string Task::getEmployee() const
{
    return employee;
}

string Task::getTaskId() const
{
    return task_id;
}

void Task::addToDo(string todo_add)
{
    todo.push_back(todo_add);
}
