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

std::string Task::getTodo() const
{
    return todo;
}

bool Task::isActive()
{
    return getStatus();
}

void Task::setTodo(const std::string &value)
{
    if(isValid(value))
    {
        todo = value;
    }
    else
    {
        throw InvalidTaskException("[SET TODO EXCEPTION]: Invalid todo");
    }
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

void Task::printTask() const
{
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Task id: " << getTaskId() << std::endl;
    std::cout << "Task: " << getTodo() << std::endl;
    std::cout << "Status: " << statusToString(getStatus()) << std::endl;
    std::cout << "Employee: " << getEmployee() << std::endl;
    std::cout << "-------------------------------" << std::endl;
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
