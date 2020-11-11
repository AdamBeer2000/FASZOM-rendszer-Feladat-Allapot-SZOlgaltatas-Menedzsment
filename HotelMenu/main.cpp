#include <iostream>
#include "commandpanel.h"
#include "task.h"
#include "guest.h"
using namespace Users;

int main()
{
    //thingthing

    Guest Test1 = Guest("JAni","123",Users::GUE);
    Guest Test2 = Guest("Bela","321",Users::GUE);
    Guest Test3 = Guest("Cica","69420",Users::GUE);
    Guest Test4 = Guest("RickAstley","kek",Users::GUE);
    std::list<User*> users;
    users.push_back(&Test1);
    users.push_back(&Test2);
    users.push_back(&Test3);
    users.push_back(&Test4);
    Login oneLogin= Login(users);


    CommandPanel OneCommandPanel= CommandPanel(users);
    OneCommandPanel.doStuff();


/*
    //TASK DEBUG
    //A manager class így hozza majd létre:
    auto builder = new Tasks::Task::TaskBuilder("JA3065");
    auto task = builder->withEmployee("Janitor Ferenc")
            .withTodo("todo")
            .withStatus(false)
            .build();

    task->printTask();
    task->setStatus(true);
    task->printTask();
    delete builder;
    delete task;

    auto builder2 = new Tasks::Task::TaskBuilder("JA9175");
    auto task2 = builder->withEmployee("Janitor Ferenc")
            .withTodo("")
            .withStatus(false)
            .build();

    task->printTask();
    delete builder2;
    delete task2;

    auto builder3 = new Tasks::Task::TaskBuilder("RE0862");
    auto task3 = builder->withEmployee("")
            .withTodo("todo")
            .withStatus(false)
            .build();

    task->printTask();
    delete builder3;
    delete task3;
    return 0;
    */
}
