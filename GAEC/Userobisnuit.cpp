#include "Userobisnuit.h"
#include <iostream>

using namespace std;

Userobisnuit::Userobisnuit(string u, string p) : User(u,p) {}

void Userobisnuit::displayRole()
{
	cout << "Bine ai venit, utilizator: " << username << '\n';
}
