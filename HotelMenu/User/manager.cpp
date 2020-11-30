#include "manager.h"

Users::Manager::Manager(const std::string& _firstName , const std::string& _lastName , const std::string& _username , struct date _birthDate , jobs _jobID , int _cardID , const std::string& _password):
    Users::User::User(_firstName , _lastName , _username, _birthDate , _jobID , _cardID , _password)
    {
        this->firstName = _firstName;
        this->lastName = _lastName;
        this->username = _username;
        this->birthDate = _birthDate;
        this->jobID = _jobID;
        this->cardID = _cardID;
        this->password = _password;
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

void Users::Manager::setTaskStatus(std::string taskID)
{
    //NE LEGYEN ABSZTRAKT
}

void Users::Manager::printTasks() const
{
    //NE LEGYEN ABSZTRAKT
}

void Users::Manager::printLogs() const
{
    //NE LEGYEN ABSZTRAKT
}

