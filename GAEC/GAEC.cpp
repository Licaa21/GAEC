#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
    bool succes = false;
    bool backToLogin = false;
    User* loggedInUser = nullptr;

    while (!succes)
    {
        loggedInUser = Login(succes);

        if (loggedInUser)
        {
            backToLogin = false;
            if (dynamic_cast<Admin*>(loggedInUser))
            {
                FirstMenu(backToLogin);
            }
            else if (dynamic_cast<Userobisnuit*>(loggedInUser))
            {
                FirstUserMenu(backToLogin);
            }

            if (backToLogin)
            {
                succes = false;
            }
        }
    }

    return 0;
}
