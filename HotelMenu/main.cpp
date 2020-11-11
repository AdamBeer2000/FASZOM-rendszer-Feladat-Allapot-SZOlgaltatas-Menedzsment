#include <iostream>
#include "commandpanel.h"
#include "task.h"

using namespace Users;

int main()
{
    //thingthing
    /*User Test1 = User("JAni","123");
    User Test2 = User("Bela","321");
    User Test3 = User("Cica","69420");
    User Test4 = User("RickAstley","kek");
    std::list<User> users;
    users.push_back(Test1);
    users.push_back(Test2);
    users.push_back(Test3);
    users.push_back(Test4);
    Login oneLogin= Login(users);*/

    /*
    oneLogin.LogInWith("JAni","123");//Jó felhasznév jó jelszó
    oneLogin.logOut();
    oneLogin.LogInWith("Motherfucker","123");//Rosz felhasznév
    oneLogin.logOut();
    oneLogin.LogInWith("Cica","123");//Jó felhasznév Rosz jelszó
    oneLogin.logOut();
    oneLogin.LogInWith("Cica","69420");
    oneLogin.LogInWith("Cica","69420");//Már be van jelentkezve
    */

    /*
    CommandPanel OneCommandPanel= CommandPanel(users);
    OneCommandPanel.doStuff();*/

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
}
