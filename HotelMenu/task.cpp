#include "task.h"

using namespace Tasks;

Task::Task(std::string employee_c, std::string task_id_c):
    employee(employee_c), task_id(task_id_c)
{
    setStatus(false);
}

bool Task::getStatus() const
{
    return status;
}

void Task::setStatus(bool value)
{
    status = value;
}

std::string Task::getEmployee() const
{
    return employee;
}

std::string Task::getTaskId() const
{
    return task_id;
}

void Task::addToDo(std::string todo_add)
{
    todo.push_back(todo_add);
}

void Task::removeToDo(std::string todo_remove)
{
    auto it =find(todo.begin(), todo.end(), todo_remove);

    if(it != todo.end())
    {
        todo.remove(todo_remove);
    }
    else
    {
        throw InvalidTaskException("[REMOVE EXCEPTION]: TASK DOES NOT EXIST");
    }
}
