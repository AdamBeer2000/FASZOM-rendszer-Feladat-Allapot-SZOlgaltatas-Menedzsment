#include <iostream>
#include "commandpanel.h"
#include "task.h"
#include "guest.h"
#include "manager.h"
#include "taskcontainer.h"
#include "logfix.h"
#include "date.h"
#include <iomanip> // a kettizedesre allitashoz (kerekít is)

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

    Manager Test5 = Manager("Manager", "admin");
    Manager Test6 = Manager("Manager", "admin");

    Test6.generateTask(jobs::JAN, "George Soros", "Soros terv");


    Tasks::Task t1 = Test5.generateTask(jobs::CLE, "Gyurcsany Ferenc", "Elbaszni, nem kicsit, nagyon");
    Tasks::Task t2 = Test6.generateTask(jobs::JAN, "George Soros", "Soros terv");

    TaskContainer task = TaskContainer();
    task.addTask(t1);
    task.addTask(t2);

    task.printAllTask();


    CommandPanel OneCommandPanel= CommandPanel(users);
    OneCommandPanel.doStuff();


    /*
    date d1;
    d1.day = 15;
    d1.month = 2;
    d1.year = 2020;
    d1.min = 5;
    d1.sec = 23;
    d1.hour = 13;

    date d2;
    d2.day = 5;
    d2.month = 3;
    d2.year = 2021;
    d2.min = 16;
    d2.sec = 3;
    d2.hour = 23;

    Logs::LogFix log = Logs::LogFix(206, "dardas virsli", "eltort", 20.128842, d1, d2);
    log.printLog();
    */
    /*
    double a = 12.3456789;
    std::cout << a << std::endl;
    std::cout << std::fixed <<std::setprecision(2) << a << std::endl;
    */
}
