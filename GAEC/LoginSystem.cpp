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
	ifstream userFile("users.txt");
	string line;
	while (getline(userFile, line))
	{
		istringstream ss(line);
		string existingUsername, existingPassword;
		int status;
		ss >> existingUsername >> existingPassword >> status;

		if ((existingUsername == username) || (existingUsername == username && existingPassword == password))
		{
			system("cls");
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Utilizator sau parola deja folosite, incercati din nou." << '\n';
			userFile.close();
			cin.ignore();
			cin.get();
			system("cls");
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Utilizator: ";
			string newUsername;
			cin >> newUsername;
			cout << "Parola: ";
			string newPassword;
			cin >> newPassword;
			inregistrare(newUsername, newPassword);
			return;
		}
	}
	userFile.close();

	if (users.find(username) != users.end())
	{
		cout << "Numele de utilizator deja exista!" << '\n';
		return;
	}

	User* newUser = new Userobisnuit(username, password);
	users[username] = newUser;

	ofstream outFile("users.txt", ios::app);
	if (outFile)
	{
		outFile << username << " " << password << " " << "0" << '\n';
		cout << "Utilizatorul a fost inregistrat cu succes!" << '\n';
	}
	else
	{
		cerr << "S-a produs o eroare" << '\n';
	}
}


void LoginSystem::updateUserStatus(const string& username, int status)
{
	fstream file("users.txt", ios::in | ios::out);

	if (!file)
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}
	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		istringstream ss(line);
		string user, password;
		int currentStatus;

		ss >> user >> password >> currentStatus;

		if (user == username)
		{
			ostringstream updatedLine;
			updatedLine << user << " " << password << " " << status;
			lines.push_back(updatedLine.str());
		}
		else
		{
			lines.push_back(line);
		}
	}
	
	file.close();
	file.open("users.txt",ios::out | ios::trunc);

	for (const string& updatedLine : lines)
	{
		file << updatedLine << '\n';
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
	updateUserStatus(enteredUsername, 1);

	return user;
}

void LoginSystem::seeUserDetails()
{
	ifstream file("users.txt");
	string loggedInUsername;
	string line1;
	bool found = false;

	while (getline(file, line1))
	{
		istringstream ss(line1);
		string username, password;
		int status;
		ss >> username >> password >> status;

		if (status == 1)
		{
			loggedInUsername = username;
			found = true;
			break;
		}
	}
	file.close();

	if (found)
	{
		ifstream o("Studenti.txt");
		bool statusstudent = false;
		string line2;

		while (getline(o, line2))
		{
			istringstream ss(line2);
			string nume, prenume, facultate, varsta, user;
			ss >> nume >> prenume >> facultate >> varsta >> user;

			if (user == loggedInUsername)
			{
				statusstudent = true;
				break; 
			}
		}
		o.close();


		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nume de utilizator: " << loggedInUsername << '\n';
		cout << '\n';
		cout << "Student inscris: " << (statusstudent ? "Da" : "Nu") << '\n';
		cout << '\n';
	}
	else
	{
		cout << "No logged-in user found.\n";
	}
}


void LoginSystem::loadUsersFromFile(const string& filename)
{
	ifstream userFile(filename);

	if (!userFile)
	{
		cerr << "S-a produs o eroare." << '\n';
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
