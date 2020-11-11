#include "manager.h"

Users::Manager::Manager(const std::string& username_c, const std::string& password_c): User(username_c, password_c, jobs::MAN)
{

}

Users::Manager::~Manager()
{

}

Tasks::Task Users::Manager::generateTask(jobs job_id, const std::string& employee_name, const std::string& todo)
{
    std::string current_id = "";
    current_id = generateTaskId(job_id);
//Lehet, hogy hasznosabb, ha itt validálom az employee nevet és a típust
    auto builder = new Tasks::Task::TaskBuilder(current_id);
    auto task = builder->withEmployee(employee_name)
            .withTodo(todo)
            .withStatus(false)
            .build();

    task_ids.push_back(task->getTaskId());
    //közös task listához hozzáadás
    //delete nem biztos, hogy ide kell
    return *task;
    //delete task;
    //delete builder;
}

std::string Users::Manager::generateTaskId(jobs job_id)
{
    std::string generated_id = "";
    try
    {
        switch(job_id)
        {
            case Users::jobs::JAN:
                generated_id = "JAN";
                break;
            case Users::jobs::CLE:
                generated_id = "CLE";
                break;
            case Users::jobs::REC:
                generated_id = "REC";
                break;
            default:
                generated_id = "ERR"; //Error
                throw InvalidInputException("[INVALID INPUT]: Employee type");
                break;
        }
    }
    catch(InvalidInputException& e)
    {
        std::cout << e.what() << std::endl;
    }


    int num_code = rand() % 100000;

    if(num_code < 10000)
    {
        generated_id += "0";

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
    }

    generated_id += std::to_string(num_code);

    auto it = find(task_ids.begin(), task_ids.end(), generated_id);
    if(it != task_ids.end())
    {
        generateTaskId(job_id);
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

void Users::Manager::doWork() const
{

}

Users::User *Users::Manager::clone() const
{
    return new Manager(*this);
}
