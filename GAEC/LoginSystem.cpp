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

void LoginSystem::updateeventstatus(const string& username, int statuseveniment)
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
		int currentstatus = 0, clubID = 0, eventstatus=0;

		ss >> user >> password >> currentstatus >> clubID >> eventstatus;

		if (user == username)
		{
			ostringstream updatedLine;
			updatedLine << user << " " << password << " " << currentstatus << " " << clubID << " " << statuseveniment;
			lines.push_back(updatedLine.str());

		}
		else
		{
			lines.push_back(line);
		}
	}

	file.close();
	file.open("users.txt", ios::out | ios::trunc);

	for (const string& updatedLine : lines)
	{
		file << updatedLine << '\n';
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
		int currentStatus =0, clubID = 0;
		int eventstatus;

		ss >> user >> password >> currentStatus >> clubID >> eventstatus;

		if (user == username)
		{
			ostringstream updatedLine;
			updatedLine << user << " " << password << " " << status << " " << clubID << " " << eventstatus;
			lines.push_back(updatedLine.str());
		}
		else
		{
			lines.push_back(line);
		}
	}

	file.close();
	file.open("users.txt", ios::out | ios::trunc);

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
		cout << "Parola este gresita pentru utilizatorul: " << enteredUsername << '\n';
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
	int numarclub;

	while (getline(file, line1))
	{
		istringstream ss(line1);
		string username, password;
		int status;
		ss >> username >> password >> status >> numarclub;

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

		ifstream f("cluburi.txt");
		bool statusclub = false;
		string line3;

		while (getline(f, line3))
		{
			istringstream ss(line3);
			string Nume, Tip, Facultate, user;
			ss >> Nume >> Tip >> Facultate >> user;

			if (user == loggedInUsername)
			{
				statusclub = true;
				break;
			}
		}
		f.close();
	
		ifstream s("cluburi.txt");
		vector<string> clubs;
		string Nume, Tip, Facultate, Utilizator;
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';

		while (s >> Nume >> Tip >> Facultate >> Utilizator)
		{
			clubs.push_back("Nume: Clubul " + Nume + ", Tip: " + Tip + ", Facultate: " + Facultate + ", Creator: " + Utilizator);
		}
		s.close();	
		string numeclub = "Nu faci parte din niciun club.";
		if (numarclub > 0 && numarclub <= (int)clubs.size())
		{
			numeclub = clubs[numarclub - 1];
		}
		int statussclub;
		if (numeclub == "Nu faci parte din niciun club.")
		{
			statussclub = false;
		}
		else
		{
			statussclub = true;
		}
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
		cout << "Creator de club: " << (statusclub ? "Da" : "Nu") << '\n';
		cout << '\n';
		cout << "Membru intr-un club: "<< (statussclub ? "Da" : "Nu")<<'\n';
		if (statussclub == true)
		{
			cout << " (" << numeclub << ")"<<'\n';
		}
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		
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
int countLines(const string& filename)
{
	ifstream file(filename);
	int linecount = 0;
	string line;
	while (getline(file, line))
	{
		++linecount;
	}
	file.close();
	return linecount;
}
void LoginSystem::seeAdministration()
{
	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Statisticile programului" << '\n';
	cout << '\n';
	cout << "A.Cluburi create: " << countLines("cluburi.txt") << '\n';
	cout << '\n';
	cout << "B.Studenti inscrisi: " << countLines("Studenti.txt") << '\n';
	cout << '\n';
	cout << "C.Conturi create: " << countLines("users.txt") << '\n';
	cout << '\n';
	cin.ignore();
	cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
	cout << '\n';
}
