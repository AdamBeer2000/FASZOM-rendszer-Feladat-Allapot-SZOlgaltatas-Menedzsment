#include "manager.h"

Users::Manager::Manager(const std::string& username_c, const std::string& password_c): User(username_c, password_c)
{

}

Users::Manager::~Manager()
{

}

void Users::Manager::generateTask()
{
    std::string generated_id = "";
    std::string current_todo = "";
    std::string current_employee = "";
    auto builder = new Tasks::Task::TaskBuilder(generated_id);
    auto task = builder->withEmployee(current_employee)
            .withTodo(current_todo)
            .withStatus(false)
            .build();

    //add to task list
    //add to file
    //delete nem biztos, hogy ide kell
    delete task;
    delete builder;
}
