#include "LoginSystem.h"
#include "Admin.h"
#include "User.h"
#include "Userobisnuit.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
LoginSystem::~LoginSystem()
{
	for (auto& pair : users)
	{
		delete pair.second;
	}
}

void LoginSystem::AdaugareUtilizator(User* user)
{
	if (users.find(user->getUsername()) != users.end())
	{
		cerr << "Eroare" << '\n';
		delete user;
		return;
	}
	users[user->getUsername()] = user;
}

void LoginSystem::inregistrare(const string& username, const string& password)
{
	if (users.find(username) != users.end())
	{
		cout << "Numele de utilizator deja exista!" << '\n';
		return;
	}

	User* newUser = new Userobisnuit(username, password);
	users[username] = newUser;

	ofstream userFile("users.txt", ios::app);
	if (userFile)
	{
		userFile << username << " " << password << '\n';
	}
	else
	{
		cerr << "S-a produs o eroare" << '\n';
	}
}

User* LoginSystem::autentificare(const string& enteredUsername, const string& enteredPassword)
{
	if (users.find(enteredUsername) == users.end())
	{
		cout << "Numele de utilizator nu a fost gasit." << '\n';
		return nullptr;
	}
	User* user = users[enteredUsername];
	if (!user)
	{
		cerr << "Eroare" << '\n';
		return nullptr;
	}
	if (!user->login(enteredUsername, enteredPassword))
	{
		cout <<"Parola este gresita pentru utilizatorul: " << enteredUsername << '\n';
		return nullptr;
	}

	return user;
}

void LoginSystem::loadUsersFromFile(const string& filename)
{
	ifstream userFile(filename);

	if (!userFile)
	{
		cerr << "S-a produs o eroare" << '\n';
		return;
	}

	string line;
	while (getline(userFile, line))
	{
		istringstream ss(line);
		string username, password;
		ss >> username >> password;

		if (username.empty() || password.empty())
		{
			cerr << "Eroare." <<'\n';
		}
		if (username == "ADMIN")
		{
			AdaugareUtilizator(new Admin(username, password));
			
			
		}
		else
		{
			AdaugareUtilizator(new Userobisnuit(username, password));

		}
	}
	userFile.close();
}
