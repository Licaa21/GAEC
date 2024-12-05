#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string u,string p) : User(u,p) {}

void Admin::displayRole()
{
	cout << "Bun venit, Administrator: " << username << '\n';
}
