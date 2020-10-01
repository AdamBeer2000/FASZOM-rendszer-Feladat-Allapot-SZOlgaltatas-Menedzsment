#include <iostream>
#include "commandpanel.h"

int main()
{

    User Test1 = User("JAni","123");
    User Test2 = User("Bela","321");
    User Test3 = User("Cica","69420");
    User Test4 = User("RickAstley","kek");
    std::list<User> users;
    users.push_back(Test1);
    users.push_back(Test2);
    users.push_back(Test3);
    users.push_back(Test4);
    //Login oneLogin= Login(users);
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

    CommandPanel OneCommandPanel= CommandPanel(users);
    OneCommandPanel.doStuff();

    return 0;
}
