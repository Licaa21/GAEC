#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
    bool succes = false;
    bool backToLogin = false;
    LoginSystem sistem;
    User isAdmin();
    User* loggedInUser = nullptr;
    sistem.loadUsersFromFile("users.txt");
    sistem.AdaugareUtilizator(new Admin("ADMIN", "admin123"));
    while (!succes)
    {
        loggedInUser = Login(sistem,succes);

        if (loggedInUser)
        {
            backToLogin = false;
            if (isAdmin)
            {
                FirstMenu(backToLogin);
            }
            else if (!isAdmin)
            {
                FirstUserMenu(backToLogin);
            }
            else
                succes = false;
            if (backToLogin)
            {
                succes = false;
            }
        }
    }

    return 0;
}
