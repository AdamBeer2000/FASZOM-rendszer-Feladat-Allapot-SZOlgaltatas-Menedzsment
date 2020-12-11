#include <iostream>

#include "Log/log.h"
#include "Log/logcleaning.h"
#include "Log/logfix.h"
#include "Log/logreplace.h"
#include "Log/logreservation.h"


#include "User/usermanager.h"

#include "commandpanel.h"


#include "date.h"

#include <iomanip> // a kettizedesre allitashoz (kerekít is)
#include <memory>

#include <fstream>

#include "datacommunicationcenter.h"

#include "User/usermanager.h"

using namespace Users;

int main()
{
    CommandPanel a=CommandPanel();
    a.seudoMain();

    //datacom->printRes();

    //thingthing

    /*
    date date1;
    date1 = date1.buildDate(2000, 12, 6, 12, 4, 8);
    Guest Test1 = Guest("Janos", "Onosz", "JAni", date1, jobs::GUE, 123456, "123");
    Guest Test2 = Guest("Bela", "Lol", "Bela", date1, jobs::GUE, 69524, "321");
    Guest Test3 = Guest("Van", "Gazdad", "Cica", date1, jobs::GUE, 420558, "69420");
    Guest Test4 = Guest("Rick", "Astley", "RickAstley", date1, jobs::GUE, 988956, "kek");

    date dateBuild;

    Reservation resTest0=Reservation("JAni",Suit::Luxury,dateBuild.buildDate(2022,10,9),dateBuild.buildDate(2022,11,9),Serving::Allinclusive);
    Reservation resTest1=Reservation("Bela",Suit::Medium,dateBuild.buildDate(2022,10,9),dateBuild.buildDate(2022,10,15),Serving::Premium);
    Reservation resTest2=Reservation("Cica",Suit::Notbad,dateBuild.buildDate(2021,10,9),dateBuild.buildDate(2022,11,9),Serving::Default);
    Reservation resTest3=Reservation("nemvotma",Suit::Notbad,dateBuild.buildDate(2021,10,9),dateBuild.buildDate(2022,11,9),Serving::Default);
    Reservation resTest4=Reservation("Rick",Suit::Luxury,dateBuild.buildDate(2022,10,9),dateBuild.buildDate(2022,11,9),Serving::Allinclusive);

    std::list<Reservation>resTest;
    resTest.push_back(resTest0);
    resTest.push_back(resTest1);
    resTest.push_back(resTest2);
    resTest.push_back(resTest3);

    ReservationContainer resContTest;

    std::vector<std::string>users;
    users.push_back("JAni");
    users.push_back("Bela");
    users.push_back("Cica");
    users.push_back("Teljesenkozonsegeskepüno");
    users.push_back("nemvotma");

    for(auto test:resTest)
    {
        resContTest.addReservation(test);
    }

    for(unsigned int k=0;k<users.size();k++)
    {
        try
        {
            Reservation test=resContTest.getReservation(users[k]);
            std::cout<<test.getUserename()<<" "<<test.getApartmentInString()<<" "<<test.getStyaingTime()<<" "<<test.getServingInString()<<std::endl;
        }
        catch (std::exception &e)
        {
            std::cout<<e.what()<<std::endl;
        }

    }
    std::cout<<std::endl;

    RoomContainer roomContTest;
    Room roomTest0=Room(Suit::Luxury,69,true);
    Room roomTest1=Room(Suit::Medium,420,false);
    Room roomTest2=Room(Suit::Notbad,1408,true);

    std::list<Room>roomTest;

    roomTest.clear();
    roomTest.push_back(roomTest0);
    roomTest.push_back(roomTest1);
    roomTest.push_back(roomTest2);

    std::vector<int>szobid;
    szobid.push_back(69);
    szobid.push_back(420);
    szobid.push_back(1408);
    szobid.push_back(70000);

    for(auto test:roomTest)
    {
        roomContTest.add(test);
    }

    for(auto test:szobid)
    {
        try
        {
            std::cout<<test<<" "<<roomContTest.isUsed(test)<<" "<<Suit::suitToString(roomContTest.getSuitType(test))<<" "<<roomContTest.isCleaned(test)<<std::endl;
        }
        catch (std::exception &e)
        {
            std::cout<<e.what()<<std::endl;
        }
    }

    try
    {
        roomContTest.setReservation(69,resTest0);
        roomContTest.setReservation(420,resTest1);
        roomContTest.setReservation(1408,resTest4);
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    */


    /*
    std::list<User*> users;
    users.push_back(&Test1);
    users.push_back(&Test2);
    users.push_back(&Test3);
    users.push_back(&Test4);
    Login oneLogin= Login(users);

    Manager Test5 = Manager("Manager", "admin", jobs::MAN);
    Manager Test6 = Manager("Manager", "admin", jobs::MAN);

    Test6.generateTask(jobs::JAN, "George Soros", "Soros terv");


    Tasks::Task t1 = Test5.generateTask(jobs::CLE, "Gyurcsany Ferenc", "Elbaszni, nem kicsit, nagyon");
    Tasks::Task t2 = Test6.generateTask(jobs::JAN, "George Soros", "Soros terv");

    TaskContainer task = TaskContainer();
    task.addTask(t1);
    task.addTask(t2);

    task.printAllTask();


    CommandPanel OneCommandPanel= CommandPanel(users);
    OneCommandPanel.doStuff();
    */

    //------------------------
    //--- LOG SYSTEM DEBUG ---
    //------------------------

    //ELLENŐRZÉS KELL, HOGY MEGFELELŐ LOGOT MEGFELELŐ TASK-NAK LEHESSEN ADNI (if megegyezik a jobid-vel akkor ok, else nem egyezik akkor err..)
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

    Logs::LogFix log1 = Logs::LogFix(206, "dardas virsli", "eltort", 20.128842, d1, d2);

    Logs::LogCleaning log2 = Logs::LogCleaning(206, d1);

    Logs::LogCleaning log3 = Logs::LogCleaning(206, "dardas virsli", d2);

    Logs::LogReplace log4 = Logs::LogReplace(404, "asztal", "torott lab", 20.36, d1);

    Manager Test7 = Manager("Teszt", "Mihaly", "Manager", d1, jobs::GUE, 988956, "admin");
    Manager Test8 = Manager("Teszt", "Ferenc", "Manager", d2, jobs::GUE, 647656, "admin");
    Manager Test9 = Manager("Teszt", "Matyas", "Manager", d1, jobs::GUE, 875468, "admin");
    Manager Test10 = Manager("Teszt", "Onosz", "Manager", d2, jobs::GUE, 256875, "admin");

    Tasks::Task t3 = Test7.generateTask(jobs::JAN, "Elon Musk", "Mars");
    Tasks::Task t4 = Test8.generateTask(jobs::CLE, "George Soros", "Soros terv");
    Tasks::Task t5 = Test9.generateTask(jobs::CLE, "Gyurcsany Ferenc", "Elbaszni, nem kicsit, nagyon");
    Tasks::Task t6 = Test10.generateTask(jobs::JAN, "George Soros", "Soros terv");
    //REC-nek még nincs task

    t3.setLog(&log4);
    t4.setLog(&log2);
    t5.setLog(&log3);
    t6.setLog(&log1);

    t3.printTask(); //REC
    t3.printLog();  //REC
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    t4.printTask(); //JAN
    t4.printLog(); //JAN
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    t5.printTask(); //CLE
    t5.printLog(); //CLE
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    t6.printTask(); //JAN
    t6.printLog(); //JAN
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

    std::list<Tasks::Task> logs;
    logs.push_back(t3);
    logs.push_back(t4);
    logs.push_back(t5);
    logs.push_back(t6);

    std::ofstream s("savetxttest.txt");
    if (s.is_open())
    {
        for(auto it : logs)
        {
            it.backupSaveStream(s);
        }
        s.close();
    }
    */
    return 0;
}
