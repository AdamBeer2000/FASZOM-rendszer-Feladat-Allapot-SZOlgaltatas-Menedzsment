#include "manager.h"

Users::Manager::Manager(const std::string& username_c, const std::string& password_c): User(username_c, password_c)
{

}

Users::Manager::~Manager()
{

}

void Users::Manager::generateTask(const std::string& employee_type, const std::string& employee_name, const std::string& todo)
{
    std::string current_id = "";
    current_id = generateTaskId(employee_type);
//Lehet, hogy hasznosabb, ha itt validálom az employee nevet és a típust
    auto builder = new Tasks::Task::TaskBuilder(current_id);
    auto task = builder->withEmployee(employee_name)
            .withTodo(todo)
            .withStatus(false)
            .build();

    //add to task list
    //add to file
    //delete nem biztos, hogy ide kell
    delete task;
    delete builder;
}

std::string Users::Manager::generateTaskId(const std::string& employee_type)
{
    std::string generated_id = "";
    try
    {
        if(employee_type.compare("JANITOR") == 0)
        {
            generated_id = "JA";
        }
        else if(employee_type.compare("RECEPTIONIST") == 0)
        {
            generated_id = "RE";
        }
        else if(employee_type.compare("CLEANER") == 0)
        {
            generated_id = "CL";
        }
        else
        {
            generated_id = "ER"; //Error
            throw InvalidInputException("[INVALID INPUT]: Employee type");
        }
    }
    catch(InvalidInputException& e)
    {
        std::cout << e.what() << std::endl;
    }


    int num_code = rand() % 10000;

    if(num_code < 1000)
    {
        generated_id += "0";

        if(num_code < 100)
        {
            generated_id += "0";

            if(num_code < 10)
            {
                generated_id += "0";
            }
        }
    }

    generated_id += std::to_string(num_code);

    auto it = find(task_ids.begin(), task_ids.end(), generated_id);
    if(it != task_ids.end())
    {
        generateTaskId(employee_type);
    }
    return generated_id;
}

void Users::Manager::deleteTask(const std::string& task_id_remove)
{
    auto it = find(task_ids.begin(), task_ids.end(), task_id_remove);
    if(it != task_ids.end())
    {
        task_ids.remove(task_id_remove);
        //task torlese
        //mentes
    }
}
