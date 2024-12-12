#include "ClubManager.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

ClubManager::ClubManager()
{
	loadFromFile();
}

void ClubManager::loadFromFile()
{
	ifstream file(filename);
	if (!file.is_open()) return;

	cluburi.clear();
	string line;
	while (getline(file, line))
	{
		istringstream ss(line);
		Club s;
		ss >> s.Nume >> s.Tip >> s.Facultate;
		cluburi.push_back(s);
	}
}
void ClubManager::saveToFile() const
{
	ofstream file(filename);
	if (!file.is_open()) return;
	for (const auto& club : cluburi)
	{
		file << club.Nume << " " << club.Tip << " " << club.Facultate << " " << '\n';
	}
}
void ClubManager::Inregistrare()
{
	system("cls");
	ofstream o("cluburi.txt", std::ios::app);
	if (!o.is_open())
	{
		cerr << "S-a produs o eroare" << '\n';
		return;
	}
	ifstream file("users.txt");
	string loggedInUsername;
	string line;
	bool found = false;

	while (getline(file, line))
	{
		istringstream ss(line);
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
	Club s;
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Clubul:";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,s.Nume);
	o << s.Nume << " ";
	cout << "Tip:";
	getline(cin, s.Tip);
	o << s.Tip << " ";
	cout << "Facultatea:";
	getline(cin, s.Facultate);
	o << s.Facultate << " ";
	o << loggedInUsername;
	o << '\n';
	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Student inregistrat cu succes, apasati enter pentru a reveni la meniul anterior." << '\n';
	o.close();
}

bool ClubManager::isEmpty()
{
	ifstream file(filename);
	if (!file)
	{
		cerr << "S-a produs o eroare." << endl;
		return false;
	}

	char ch;
	while (file.get(ch))
	{
		if (!isspace(static_cast<unsigned char>(ch)))
		{
			return false;
		}
	}

	return true;
}

void ClubManager::Afisaretext()
{
	system("cls");
	ifstream file("cluburi.txt");
	if (!file.is_open())
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}

	if (isEmpty())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun club creat in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}
	else
	{
		string line;
		string Nume, Tip, Facultate, Utilizator;
		int number = 1;
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		while (getline(file, line))
		{
			file >> Nume >> Tip >> Facultate  >> Utilizator;
			cout << number << ". " << "Nume: Clubul " << Nume << ", " << "Tip: " << Tip << ", " << "Facultate: " << Facultate << ", " << "Utilizator: " << Utilizator << '\n';
			cout << '\n';
			number++;
		}
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	file.close();
}

void ClubManager::join()
{
	ifstream s("cluburi.txt");

	if (isEmpty())
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun club creat in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cin.ignore();
		cin.get();
		return;
	}

	vector<string> clubs;
	string Nume, Tip, Facultate, Utilizator;
	string line;
	int number = 1;
	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';

	while (s >> Nume >> Tip >> Facultate >> Utilizator)
	{
		clubs.push_back(Nume + " " + Tip + " " + Facultate + " " + Utilizator);
		cout << number << ". Nume: Clubul " << Nume << ", Tip: " << Tip << ", Facultate: " << Facultate << ", Creator: " << Utilizator << '\n';
		cout << '\n';
		number++;
	}

	if (clubs.empty())
	{
		cout << "Nu exista cluburi in fisierul cluburi.txt." << '\n';
		return;
	}

	cout << "Alegeti clubul din care doriti sa faceti parte (1-" << clubs.size() << ")." << '\n';

	int n;
	cin >> n;

	if (n < 1 || n >(int)clubs.size())
	{
		cout << "Selectie invalida." << '\n';
		return;
	}

	fstream file("users.txt", std::ios::in | std::ios::out);
	string loggedInUsername;
	vector<string> users;
	bool found = false;

	while (getline(file, line))
	{
		istringstream ss(line);
		string username, password;
		int status, clubID;
		ss >> username >> password >> status >> clubID;

		if (status == 1 && !found)
		{
			loggedInUsername = username;
			found = true;
			clubID = n;
		}

		users.push_back(username + " " + password + " " + to_string(status) + " " + to_string(clubID));
	}

	if (!found)
	{
		cout << "Nu exista utilizatori conectati." << '\n';
		return;
	}

	file.close();
	file.open("users.txt", std::ios::out | std::ios::trunc);

	for (const string& user : users)
	{
		file << user << '\n';
	}

	cout << "Ati fost adaugat cu succes in clubul selectat!" << '\n';

	file.close();
	s.close();
}