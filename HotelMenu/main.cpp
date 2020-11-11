#include <iostream>
#include "commandpanel.h"
#include "task.h"
#include "guest.h"
#include "manager.h"
#include "taskcontainer.h"

using namespace Users;

int main()
{
    //thingthing

    Guest Test1 = Guest("JAni","123");
    Guest Test2 = Guest("Bela","321");
    Guest Test3 = Guest("Cica","69420");
    Guest Test4 = Guest("RickAstley","kek");
    std::list<User*> users;
    users.push_back(&Test1);
    users.push_back(&Test2);
    users.push_back(&Test3);
    users.push_back(&Test4);
    Login oneLogin= Login(users);
    /*
    Manager Test5 = Manager("Manager", "admin");
    Manager Test6 = Manager("Manager", "admin");

    Test6.generateTask(jobs::JAN, "George Soros", "Soros terv");


    Tasks::Task t1 = Test5.generateTask(jobs::CLE, "Gyurcsany Ferenc", "Elbaszni, nem kicsit, nagyon");
    Tasks::Task t2 = Test6.generateTask(jobs::JAN, "George Soros", "Soros terv");

    TaskContainer task = TaskContainer();
    task.addTask(t1);
    task.addTask(t2);

    task.printAllTask();
    */

    CommandPanel OneCommandPanel= CommandPanel(users);
    OneCommandPanel.doStuff();

}
