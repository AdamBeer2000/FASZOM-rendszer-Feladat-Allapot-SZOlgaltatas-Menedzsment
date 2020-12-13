#include "commandpanel.h"


void CommandPanel::login()
{
    std::string username,password;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout <<"Bejelentkezes" << std::endl;
    std::cout << "Adja meg a felhasznalonevet: " << std::flush;
    std::cin >> username;
    std::cout << "Adja meg a jelszavat: " << std::flush;
    std::cin >> password;
    data_com->login(username,password);
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::logout()
{
    data_com->logOut();
}

void CommandPanel::reportLostItem()
{
    std::string name,description;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout <<"Talalt targy bejelentese" << std::endl;
    std::cout << "Adja meg a targy nevet: " << std::flush;
    std::cin >> name;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    data_com->addLostItem(name);
}

void CommandPanel::printMyTasks()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout<<"Folyamatban levo feladataid:"<<std::endl;
    data_com->printMyTasks();
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::registration()
{
    std::string firstname,lastname,username,password;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout <<"Regisztracio" << std::endl;
    std::cout << "Adja meg keresztnevet: " << std::flush;
    std::cin >> firstname;
    std::cout << "Adja meg csaladnevet: " << std::flush;
    std::cin >> lastname;
    std::cout << "Adja meg felhasznalonevet: " << std::flush;
    std::cin >> username;
    std::cout << "Adja meg jelszavat: " << std::flush;
    std::cin >> password;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    data_com->registration(username,firstname,lastname,password);
}

void CommandPanel::bookRoom()
{
    std::string name,suitType, startDate, endDate, serving;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout <<"Szobafoglalas" << std::endl;
    std::cout << "Adja meg a nevet: " << std::flush;
    std::cin >> name;
    std::cout << "Adja megs a szobaosztalyt: " << std::flush;
    std::cin >> suitType;
    std::cout << "Adja meg mikortol szeretne itt tartozkodni: " << std::flush;
    std::cin >> startDate;
    std::cout << "Adja meg meddig szeretne itt tartozkodni: " << std::flush;
    std::cin >> endDate;
    std::cout << "Adja meg milyen kiszolgalast szeretne: " << std::flush;
    std::cin >> serving;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    DateBuilder db;

    data_com->bookRoom(name,Suit::stringToSuit(suitType),db.build(startDate),db.build(endDate),Serving::stringToServing(serving));
}

void CommandPanel::rating()
{
    std::string rate;
    int stars;
    if(!data_com->isRated())
    {
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout <<"Ertekeles" << std::endl;
        do
        {
            std::cout << "Hany csillagra ertekeli az ellatast [1-5]: " << std::flush;
            std::cin >> stars;
            if(stars < 1 || stars > 5)
            {
                std::cout << "1-5-ig terjedo skalan lehet csak ertekelni!" << std::endl;
            }
        }while(stars < 1 || stars > 5);
        std::cout <<"Hogyan ertekelne az itt toltott idot?" << std::endl;
        std::cin >>  rate;
        data_com->addRating(stars, rate);
        std::cout << "Koszonjuk az ertekelest" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
    }
}

void CommandPanel::fix()
{
    std::string task_id;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Javitas:\nAdja meg a feladat azonositot: " << std::flush;
    std::cin >> task_id;

    if(!data_com->isExistTask(task_id))
    {
        std::cout << "Feladat nem letezik!\nFolyamat megszakitva" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        return;
    }

    std::string item, failure;
    std::cout << "Adja meg a javitando targy nevet: " << std::flush;
    std::cin >> item;
    std::cout << "Adja meg a hiba okat: " << std::flush;
    std::cin >> failure;
    double cost;
    std::cout << "Adja meg a muvelet arat[csak szam]:" << std::flush;
    std::cin >> cost;

    date date1;
    DateBuilder builder = DateBuilder();
    std::string datestring;
    std::cout << "Adja meg az kezdo datumot (pl 2000.1.1 11:20:20): " << std::flush;
    std::getline (std::cin, datestring);
    std::string d1,d2;
    std::cin>>d1;
    std::cin>>d2;

    datestring=d1+" "+d2;
    date1=builder.buildWhithClock(datestring);

    //int year, month, day, hour, min, sec;
    /*
    std::cout << "Adja meg az kezdo evet (pl.: 1980): " << std::flush;
    std::cin >> year;
    std::cout << "Adja meg a kezdo honapot (pl.: 9): " << std::flush;
    std::cin >> month;
    std::cout << "Adja meg a kezdo napot (pl.: 15): " << std::flush;
    std::cin >> day;
    std::cout << "Adja meg az kezdo orat (pl.: 13): " << std::flush;
    std::cin >> hour;
    std::cout << "Adja meg a kezdo percet (pl.: 25): " << std::flush;
    std::cin >> min;
    std::cout << "Adja meg a kezdo masodpercet (pl.: 1): " << std::flush;
    std::cin >> sec;

    date1 = builder.build(year, month, day);
    date1.hour = hour;
    date1.min = min;
    date1.sec = sec;*/

    date date2;
    std::cout << "Adja meg az befejezo datumot (pl 2000.1.1 11:20:20): " << std::flush;
    std::cin >>datestring;
    d1="";d2="";
    std::cin>>d1;
    std::cin>>d2;
    datestring=d1+" "+d2;
    date1=builder.buildWhithClock(datestring);
    //int year2, month2, day2, hour2, min2, sec2;
    /*
    std::cout << "Adja meg az befejezo evet (pl.: 1980): " << std::flush;
    std::cin >> year2;
    std::cout << "Adja meg a befejezo honapot (pl.: 9): " << std::flush;
    std::cin >> month2;
    std::cout << "Adja meg a befejezo napot (pl.: 15): " << std::flush;
    std::cin >> day2;
    std::cout << "Adja meg az befejezo orat (pl.: 13): " << std::flush;
    std::cin >> hour2;
    std::cout << "Adja meg a befejezo percet (pl.: 25): " << std::flush;
    std::cin >> min2;
    std::cout << "Adja meg a befejezo masodpercet (pl.: 1): " << std::flush;
    std::cin >> sec2;


    date2 = builder2.build(year2, month2, day2);
    date2.hour = hour2;
    date2.min = min2;
    date2.sec = sec2;*/

    Logs::Log *log = new Logs::LogFix(item,failure,cost,date1,date2);
    data_com->logTask(task_id, log);

    std::cout<<"Javitas sikeresen befejezodott!"<<std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::replace()
{
    std::string task_id;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Csere:\nAdja meg a feladat azonositot: " << std::flush;
    std::cin >> task_id;

    if(!data_com->isExistTask(task_id))
    {
        std::cout << "Feladat nem letezik!\nFolyamat megszakitva" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        return;
    }

    std::string item, failure;
    std::cout << "Adja meg a cserelendo targy nevet: " << std::flush;
    std::cin >> item;
    std::cout << "Adja meg a hiba okat: " << std::flush;
    std::cin >> failure;
    double cost;
    std::cout << "Adja meg a muvelet arat[csak szam]:" << std::flush;
    std::cin >> cost;

    date date;
    DateBuilder builder = DateBuilder();
    std::string datestring;
    /*
    int year, month, day, hour, min, sec;
    std::cout << "Adja meg az evet (pl.: 1980): " << std::flush;
    std::cin >> year;
    std::cout << "Adja meg a honapot (pl.: 9): " << std::flush;
    std::cin >> month;
    std::cout << "Adja meg a napot (pl.: 15): " << std::flush;
    std::cin >> day;
    std::cout << "Adja meg az orat (pl.: 13): " << std::flush;
    std::cin >> hour;
    std::cout << "Adja meg a percet (pl.: 25): " << std::flush;
    std::cin >> min;
    std::cout << "Adja meg a masodpercet (pl.: 1): " << std::flush;
    std::cin >> sec;

    date = builder.build(year, month, day);
    date.hour = hour;
    date.min = min;
    date.sec = sec;*/

    std::cout << "Adja meg az befejezo datumot (pl 2000.1.1 11:20:20): " << std::flush;
    std::string d1,d2;
    std::cin>>d1;
    std::cin>>d2;

    datestring=d1+" "+d2;
    date=builder.buildWhithClock(datestring);

    Logs::Log *log = new Logs::LogReplace(item,failure,cost,date);
    data_com->logTask(task_id, log);

    std::cout<<"Csere sikeresen befejezodott!"<<std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}
void CommandPanel::takeCleanroom()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    int roomId;
    std::cout<<"Melyik szobat takaritanad ki? " << std::flush;
    std::cin>>roomId;//lehet nem igenyel takaritast,vagy nem letezik a szoba
    data_com->takeCleaningTask(roomId);
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::logCleanroom()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::string task_id;
    std::cout<<"Melyik munkad vegezted el? " << std::flush;
    std::cin>>task_id;//lehet invalid a task

    if(!data_com->isExistTask(task_id))
    {
        std::cout << "Feladat nem letezik!\nFolyamat megszakitva" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        return;//todo excep
    }

    date d;
    DateBuilder db;
    std::string date,d1,d2;

    std::cout<<"Mikor? :" << std::flush;

    std::cin>>d1;
    std::cin>>d2;
    date=d1+" "+d2;
    d=db.buildWhithClock(date);

    std::string talat;
    std::cout<<"Volt talalt targy? (I/N): " << std::flush;
    std::cin>>talat;//mast ad meg

    if(talat=="I"||talat=="i")
    {
        std::cout<<"Micsoda?: " << std::flush;
        std::cin>>talat;
        data_com->LogCleaningTask(task_id,talat,d);
    }
    if(talat=="N"||talat=="n")
    {
        data_com->LogCleaningTask(task_id,d);
    }
}

void CommandPanel::acceptReservation()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::string task_id;
    std::cout<<"Melyik foglalast tszed aktiva?";
    std::cin>>task_id;

    if(!data_com->isExistTask(task_id))
    {
        std::cout << "Feladat nem letezik!\nFolyamat megszakitva" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        return;//todo excep
    }

    int room_id;
    std::cout<<"Melyik szobába?";
    std::cin>>room_id;
    if(room_id < 1 || room_id > 1408)//LENYEG, HOGY BE LEGYEN ALLITVA HOGY CSAK ABBOL A TARTOMANYBOL LEHESSEN SZOBAT VALASZTANI
    {
        std::cout << "Szoba nem letezik!\nFolyamat megszakitva" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        return;//todo excep
    }

    data_com->accepptReservation(task_id,room_id);

    std::cout<<"acceptReservation"<<std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::denyReservation()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::string tasId;
    std::cout<<"Melyik foglalast utasitod el?";
    std::cin>>tasId;//nem letezik a task(foglalas)
    data_com->denyReservation(tasId);
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::printLostItems()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Talalt targyak:\n" << std::endl;
    data_com->printLostItem();
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::changeRoomStatus()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout<<"changeRoomStatus"<<std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}



void CommandPanel::createTask()
{

    std::string username, todo, job_id_raw, task_type_raw, room;
    Users::jobs job_id;
    Users::taskdata task_type;
    int room_id;
    bool wrong_data = false;
    do
    {
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Feladat kiadasa:\n" << std::endl;
        std::cout << "Adja meg az alkalmazott felhasznalonevet: " << std::flush;
        std::cin >> username;
        std::cout << "Adja meg a beosztasat: " << std::flush;
        std::cin >> job_id_raw;
        std::cout << "Adja meg a feladat tipusat: " << std::flush;
        std::cin >> task_type_raw;
        std::cout << "Adja meg melyik szobaban: " << std::flush;
        std::cin >> room;

        std::stringstream s(room);
        s >> room_id;

        if(room_id < 1 || room_id > 1408)//LENYEG, HOGY BE LEGYEN ALLITVA HOGY CSAK ABBOL A TARTOMANYBOL LEHESSEN SZOBAT VALASZTANI
        {
            std::cout << "Szoba nem letezik!\nFolyamat megszakitva" << std::endl;
            std::cout << "-------------------------------------------------------------------" << std::endl;
            return;
        }

        std::cout << "-------------------------------------------------------------------" << std::endl;

        todo = "Szoba: " + room + " [" + task_type_raw + "]";

        if(job_id_raw == "Takarito")
        {
            job_id = Users::jobs::CLE;
        }
        else if(job_id_raw == "Karbantarto")
        {
            job_id = Users::jobs::JAN;
        }
        else if(job_id_raw == "Recepcios")
        {
            job_id = Users::jobs::REC;
        }
        else
        {
            wrong_data = true;
            job_id = Users::jobs::ERR;
        }

        if(task_type_raw == "Takaritas")
        {
            task_type = Users::taskdata::CLN;
        }
        else if(task_type_raw == "Csere")
        {
            task_type = Users::taskdata::REP;
        }
        else if(task_type_raw == "Javitas")
        {
            task_type = Users::taskdata::FIX;
        }
        else if(task_type_raw == "Kiadas")
        {
            task_type = Users::taskdata::RES;
        }
        else
        {
            wrong_data = true;
            task_type = Users::taskdata::ER2;
        }

    }while(wrong_data);

    Tasks::Task task = data_com->generateTask(job_id, task_type, username, todo);

    task.setRoomid(room_id);
    data_com->addTask(task);
    task.printTask();
}

void CommandPanel::deleteTask()
{
    bool wrong_data = false;
    std::string task_id, confirm, sure;
    do
    {
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Feladat torlese:\n" << std::endl;
        std::cout << "Mielott megadna a torlendo feladat azonositojat, nezze meg es " << std::endl;
        std::cout << "gyozodjon meg rola, hogy a feladat letezik!" << std::endl;
        std::cout << "[Osszes feladat listazasa -> olvassa le az azonositot]! " << std::endl;
        std::cout << "Folytatni akarja?\n[igen/nem]: " << std::flush;
        std::cin >> confirm;

        if(confirm == "igen")
        {
            wrong_data = false;
            std::cout << "Adja meg a feladat azonositojat: " << std::endl;
            std::cin >> task_id;

            if(!data_com->isExistTask(task_id))
            {
                std::cout << "Feladat nem letezik!\nFolyamat megszakitva" << std::endl;
                std::cout << "-------------------------------------------------------------------" << std::endl;
                return;
            }

            std::cout << "Biztos torolni kivanja?\n[igen/nem]: " << std::flush;
            std::cin >> sure;

            if(sure == "igen")
            {
                wrong_data = false;
                data_com->deleteTask(task_id);
                std::cout << "Feladat sikeresen torolve!" << std::endl;
            }
            else if(sure == "nem")
            {
                wrong_data = false;
                std::cout << "Torles megszakitva!" << std::endl;
            }
            else
            {
                wrong_data = true;
                std::cout << "Helytelen parancs, probalja ujra!" << std::endl;
            }
        }
        else if(confirm == "nem")
        {
            wrong_data = false;
            std::cout << "Torles megszakitva!" << std::endl;
        }
        else
        {
            wrong_data = true;
            std::cout << "Helytelen parancs, probalja ujra!" << std::endl;
        }
        std::cout << "-------------------------------------------------------------------" << std::endl;
    }while(wrong_data);

}

void CommandPanel::createEmployee()
{
    std::string username, first_name, last_name, password, job_id_raw;
    Users::jobs job_id;
    date birth;
    DateBuilder builder;
    int card_id, year, month, day;
    bool wrong_data = false;
    do
    {
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Alkalmazott hozzaadasa:\n" << std::endl;
        std::cout << "Adja meg az alkalmazottnak szant felhasznalonevet: " << std::flush;
        std::cin >> username;
        std::cout << "Adja meg a beosztasat: " << std::flush;
        std::cin >> job_id_raw;
        std::cout << "Adja meg a belepo kartya szamat: " << std::flush;
        std::cin >> card_id;
        std::cout << "Adja meg a szuletesi evet (pl.: 1980): " << std::flush;
        std::cin >> year;
        std::cout << "Adja meg a szuletesi honapot (pl.: 9): " << std::flush;
        std::cin >> month;
        std::cout << "Adja meg a szuletesi napot (pl.: 15): " << std::flush;
        std::cin >> day;
        birth = builder.build(year, month, day);

        if(job_id_raw == "Takarito")
        {
            job_id = Users::jobs::CLE;
        }
        else if(job_id_raw == "Karbantarto")
        {
            job_id = Users::jobs::JAN;
        }
        else if(job_id_raw == "Recepcios")
        {
            job_id = Users::jobs::REC;
        }
        else
        {
            wrong_data = true;
            job_id = Users::jobs::ERR;
        }

        std::cout << "-------------------------------------------------------------------" << std::endl;
    }while(wrong_data);

    data_com->createUser(username, first_name, last_name, birth, job_id, card_id, password);
}

void CommandPanel::emploYeet()
{
    bool wrong_data = false;

    do
    {
        std::string username, confirm;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout<< "Alkalmazott eltavolitasa:\n" << std::endl;
        std::cout << "Adja meg az eltavolitando szemely felhasznalonevet: " << std::flush;
        std::cin >> username;
        std::cout << "Biztos torolni akarja?\n[igen/nem]: " << std::flush;
        std::cin >> confirm;
        if(confirm == "igen")
        {
            wrong_data = false;
            data_com->deleteUser(username);
            std::cout << "Felhasznalo sikeresen torolve!" << std::endl;
        }
        else if(confirm == "nem")
        {
            wrong_data = false;
            std::cout << "Torles megszakitva!" << std::endl;
        }
        else
        {
            wrong_data = true;
            std::cout << "Helytelen parancs, probalja ujra!" << std::endl;
        }

        std::cout << "-------------------------------------------------------------------" << std::endl;
     }while(wrong_data);
}

void CommandPanel::printAllTasks()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Osszes feladat:\n" << std::endl;
    data_com->printAllTask();
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::printAllLogs()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout<<"Osszes log:\n"<<std::endl;
    data_com->printAllLog();
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void CommandPanel::reportDeartyRoom()
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    data_com->reportDeartyRoom();
    std::cout <<"Koszos szoba jelentve:\n"<<std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}
bool CommandPanel::permissionCheck(CommandPanel::Commands requestedCommand)
{
    Users::jobs userPermisson=data_com->returnLoggedJob();
/*
    switch (requestedCommand)
    {
        case cLogin:;return true;
        case cLogout:;return true;
        case cReport:;return true;
        case cExit:;return true;
        case cReg:;return true;
        default:;
    }

    switch (userPermisson)
    {
        case Users::jobs::CLE: if(reqvestedCommand==cClean||requestedCommand==cPrintMyTask)return true;break;
        case Users::jobs::GUE: if(reqvestedCommand==cBook||requestedCommand==cRate)return true;break;
        case Users::jobs::JAN: if(reqvestedCommand==cFix||requestedCommand==cReplace||reqvestedCommand==cPrintMyTask)return true;break;
        case Users::jobs::MAN: if(reqvestedCommand==cCreateTask||requestedCommand==cDeleteTask||reqvestedCommand==cCreateEmployee||reqvestedCommand==cEmploYeet||reqvestedCommand==cPrintAllLogs||reqvestedCommand==cPrintAllTask)return true;break;
        case Users::jobs::REC: if(reqvestedCommand==cPrintMyTask||requestedCommand==cAcceptRes||reqvestedCommand==cDenyRes||reqvestedCommand==cPrintLostItems||reqvestedCommand==cChangeRoomStatus)return true;break;
        default:throw  NoPermissonException(requestedCommand);break;
    }
    */
    return true;
    //return false;
}
void checkhOut()
{

}


void CommandPanel::pseudoMain()
{

    std::string command;
    std::cout<<"Udvozollek a hotel task rendszereben"<<std::endl;
    do
    {
        try
        {
            std::cout<<":>";
            std::getline(std::cin, command);
            if(permissionCheck(resolveOption(command)))
            {
                switch (resolveOption(command))
                {
                    case Invalid:throw CommandNotFoundException(command.c_str());break;
                    case cLogin:login();break;
                    case cLogout:logout();break;
                    case cExit:;break;
                    case cReport:reportLostItem();break;
                    case cPrintMyTask:printMyTasks();break;
                    case cReg:registration();break;
                    case cBook:bookRoom();data_com->printRes();break;
                    case cRate:rating();break;
                    case cCreateTask:createTask();break;
                    case cDeleteTask:deleteTask();break;
                    case cCreateEmployee:createEmployee();break;
                    case cEmploYeet:emploYeet();break;
                    case cPrintAllTask:printAllTasks();break;
                    case cPrintAllLogs:printAllLogs();break;
                    case cFix:fix();break;
                    case cReplace:replace();break;
                    case cTakeClean:takeCleanroom();break;
                    case cLogClean:logCleanroom();break;
                    case cAcceptRes:acceptReservation();break;
                    case cDenyRes:denyReservation();break;
                    case cPrintLostItems:printLostItems();break;
                    case cChangeRoomStatus:changeRoomStatus();break;
                }
            }
        }
        catch (std::exception &e)
        {
             std::cout<<e.what()<<std::endl;
        }
    }
    while (command!="exit"&&command!="Exit");
}


void CommandPanel::ricroll()
{
    std::cout<<"We're no strangers to love"<<std::endl;
    std::cout<<"You know the rules and so do I"<<std::endl;
    std::cout<<"A full commitment's what I'm thinking of"<<std::endl;
    std::cout<<"You wouldn't get this from any other guy"<<std::endl;
    std::cout<<"I just wanna tell you how I'm feeling"<<std::endl;
    std::cout<<"Gotta make you understand"<<std::endl;
    std::cout<<"Never gonna give you up"<<std::endl;
    std::cout<<"Never gonna let you down"<<std::endl;
    std::cout<<"Never gonna run around and desert you"<<std::endl;
    std::cout<<"Never gonna make you cry"<<std::endl;
    std::cout<<"Never gonna say goodbye"<<std::endl;
    std::cout<<"Never gonna tell a lie and hurt you...."<<std::endl;
}
