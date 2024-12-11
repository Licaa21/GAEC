#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
    bool succes = false;
    LoginSystem sistem;
    User* loggedInUser = nullptr;
    sistem.loadUsersFromFile("users.txt");
    sistem.AdaugareUtilizator(new Admin("admin", "admin123"));
    while (!succes)
    {
        loggedInUser = Login(sistem,succes);

        if (loggedInUser)
        {
            if (loggedInUser->isAdmin())
            {
                FirstMenu(); 
            }
            else
            {
                FirstUserMenu(sistem,loggedInUser->getUsername());
            }
            succes = false;
        }
    }

    return 0;
}
