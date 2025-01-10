#include "ClubManager.h"
#include <iostream>
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
	ifstream file("users.txt");
	string loggedInUsername;
	string line;
	int clubid = 0;
	bool found = false;

	while (getline(file, line))
	{
		istringstream ss(line);
		string username, password;
		int status;
		ss >> username >> password >> status >> clubid;

		if (status == 1)
		{
			loggedInUsername = username;
			found = true;
			break;
		}
	}
	ifstream p("Studenti.txt");
	bool statusstudent = false;
	string line2;
	while (getline(p, line2))
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
	file.close();
	p.close();
	ifstream w("cluburi.txt");
	bool statuslider = false;
	string nume, tip, facultate, lider;
	string line3;
	while (getline(w,line3))
	{
		istringstream pp(line3);
		pp >> nume >> tip >> facultate >> lider;
		if (lider == loggedInUsername)
		{
			statuslider = true;
			break;
		}
	}
	w.close();
	if (statuslider)
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu poti crea mai mult de un club."<<'\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cout << '\n';
		cin.ignore();
	}
	else if (statusstudent == true)
	{
		system("cls");
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
		o.close();
		ifstream club("cluburi.txt");
		int linec = 0;
		string temp;
		while (getline(club, temp))
		{
			++linec;
		}
		club.close();
		clubid = linec;
		fstream user("users.txt", ios::in | ios::out);
		string file;
		while (getline(user, line))
		{
			istringstream ss(line);
			string username, password;
			int status, existingClubid;
			ss >> username >> password >> status >> existingClubid;
			if (username == loggedInUsername)
			{
				file += username + " " + password + " " + to_string(status) + " " + to_string(clubid) + "\n";
			}
			else
			{
				file += line + "\n";
			}
		}
		user.clear();
		user.seekp(0, ios::beg);
		user << file;
		user.close();
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Club creat cu succes, apasati enter pentru a reveni la meniul anterior." << '\n';
		
	}
	else
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista un student inscris pentru contul tau." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cin.ignore();
	}
	
}

bool ClubManager::isEmpty()
{
	ifstream file(filename);
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
		while (file >> Nume >> Tip >> Facultate >> Utilizator)
		{
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
	ifstream f("users.txt", std::ios::in | std::ios::out);
	string loggedInUsername;
	string linef;
	vector<string> users;
	bool found = false;
	int idclub = 0;

	while (getline(f, linef))
	{
		istringstream ss(linef);
		string username, password;
		int status, clubID;
		ss >> username >> password >> status >> clubID;

		if (status == 1 && !found)
		{
			loggedInUsername = username;
			found = true;
			idclub = clubID;
		}
	}
	bool statusstudent = false;
	if (found)
	{
		ifstream p("Studenti.txt");
		
		string line2;
		while (getline(p, line2))
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
	}
	else
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "S-a produs o eroare." << '\n';
	}
	vector<string> clubs;
	string Nume, Tip, Facultate, Utilizator;
	string line;
	int number = 1;
	if (idclub != 0)
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Deja sunteti intr-un club." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cout << '\n';
		cin.ignore();
	}
	else if (statusstudent == true && idclub==0)
	{
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
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Ati fost adaugat cu succes in clubul selectat!" << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';

		file.close();
		s.close();
	}
	else
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista un student inscris pentru contul tau." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
	}
}
void ClubManager::StergereClub()
{
	system("cls");
	ifstream file("cluburi.txt");
	vector<string> clubLines;
	string line;
	while (getline(file, line))
	{
		clubLines.push_back(line);
	}
	file.close();

	if (clubLines.empty())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu este niciun club creat in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista de cluburi: " << '\n';
	for (size_t i = 0; i < clubLines.size(); i++)
	{
		cout << i + 1 << ". " << clubLines[i] << '\n';
	}

	int nrclub;
	cout << "Numarul clubului pe care doriti sa-l stergeti. ( 0 pentru a iesi )" << '\n';
	cin >> nrclub;
	if (nrclub == 0)
	{
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	if (nrclub < 1 || nrclub > clubLines.size())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Numarul clubului este invalid." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	string selectedClub = clubLines[nrclub - 1];
	istringstream iss(selectedClub);
	string clubName, type, university, clubLeader;
	iss >> clubName >> type >> university >> clubLeader;

	clubLines.erase(clubLines.begin() + nrclub - 1);

	ofstream outFile("cluburi.txt");
	for (const auto& l : clubLines)
	{
		outFile << l << endl;
	}
	outFile.close();

	ifstream userFile("users.txt");
	vector<string> userLines;
	while (getline(userFile, line))
	{
		istringstream userStream(line);
		string username, password, status;
		int userClubId;
		userStream >> username >> password >> status >> userClubId;

		if (userClubId == nrclub)
		{
			userClubId = 0;
		}
		else if (userClubId > nrclub)
		{
			userClubId--;
		}

		ostringstream updatedUser;
		updatedUser << username << " " << password << " " << status << " " << userClubId;
		userLines.push_back(updatedUser.str());
	}
	userFile.close();
	ofstream updatedUserFile("users.txt");
	for (const auto& l : userLines)
	{
		updatedUserFile << l << endl;
	}
	updatedUserFile.close();

	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Clubul a fost sters din program cu succes." << '\n';
}
void ClubManager::StergereClubUser(const string& currentUsername)
{
	system("cls");
	ifstream file("cluburi.txt");


	vector<string> clubLines;
	string line;
	while (getline(file, line))
	{
		clubLines.push_back(line);
	}
	file.close();

	if (clubLines.empty())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu este niciun club creat in programul nostru." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista cluburilor pe care le conduceti: " << '\n';
	vector<int> leaderClubs;
	int displayIndex = 1;
	for (size_t i = 0; i < clubLines.size(); i++)
	{
		istringstream iss(clubLines[i]);
		vector<string> tokens((istream_iterator<string>(iss)), istream_iterator<string>());

		if (!tokens.empty() && tokens.back() == currentUsername)
		{
			leaderClubs.push_back(i);
			cout << displayIndex << ". " << clubLines[i] << '\n';
		}
	}

	if (leaderClubs.empty())
	{
		cout << '\n';
		cout << "Niciun club. (Trebuie sa fiti lider de club)" << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	int nrclub;
	cout << "Numarul clubului pe care doriti sa-l stergeti. ( 0 pentru a iesi )" << '\n';
	cin >> nrclub;

	if (nrclub == 0)
	{
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	if (nrclub < 1 || static_cast<size_t>(nrclub) > leaderClubs.size())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Numarul clubului este invalid." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	int actualClubIndex = leaderClubs[nrclub - 1];

	clubLines.erase(clubLines.begin() + actualClubIndex);

	ofstream outFile("cluburi.txt");

	for (const auto& l : clubLines)
	{
		outFile << l << endl;
	}
	outFile.close();

	ifstream userFile("users.txt");


	vector<string> userLines;
	while (getline(userFile, line))
	{
		istringstream userStream(line);
		string username, password, status;
		int userClubId;
		userStream >> username >> password >> status >> userClubId;


		if (userClubId == actualClubIndex + 1)
		{
			userClubId = 0;
		}
		else if (userClubId > actualClubIndex + 1)
		{
			userClubId--; 
		}


		ostringstream updatedUser;
		updatedUser << username << " " << password << " " << status << " " << userClubId;
		userLines.push_back(updatedUser.str());
	}
	userFile.close();


	ofstream updatedUserFile("users.txt");
	if (!updatedUserFile.is_open())
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}
	for (const auto& l : userLines)
	{
		updatedUserFile << l << endl;
	}
	updatedUserFile.close();

	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Clubul a fost sters din program cu succes." << '\n';
}


void ClubManager::ChangeData()
{
	system("cls");
	ifstream file("cluburi.txt");
	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	if (isEmpty() == true)
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun club inscris in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}
	file.close();

	ifstream f("users.txt", std::ios::in | std::ios::out);
	string loggedInUsername;
	string linef;
	vector<string> users;
	bool found = false;
	int clubID;

	while (getline(f, linef))
	{
		istringstream ss(linef);
		string username, password;
		int status;
		ss >> username >> password >> status >> clubID;

		if (status == 1 && !found)
		{
			loggedInUsername = username;
			found = true;
		}
	}

	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista cluburilor create:" << '\n';
	for (size_t i = 0; i < lines.size(); i++)
	{
		cout << i + 1 << ". " << lines[i] << '\n';
	}

	int nrclub;
	cout << "Introduceti numarul clubului pe care doriti sa il modificati. ( 0 pentru a iesi ):" << '\n';
	cin >> nrclub;

	if (!cin || nrclub < 0 || static_cast<size_t>(nrclub) > lines.size())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << '\n';
		cout << "Optiune invalida. Incercati din nou." << '\n';
		return;
	}

	if (nrclub == 0)
	{
		return;
	}

	string nume, tip, facultate, user;
	istringstream ss(lines[nrclub - 1]);
	ss >> nume >> tip >> facultate >> user;

	bool clublider = (loggedInUsername == user);

	if (clublider)
	{
		int a;
		do
		{
			system("cls");
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Student selectat: " << nume << " " << tip << " " << facultate << " Creator: " << user << "." << '\n';
			cout << '\n';
			cout << "Ce doriti sa schimbati ?" << '\n';
			cout << '\n';
			cout << "1. Numele." << '\n';
			cout << "2. Tipul." << '\n';
			cout << "3. Facultatea." << '\n';
			cout << "4. Finalizare modificari." << '\n';
			cout << '\n';
			cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
			cout << '\n';
			cin >> a;

			switch (a)
			{
			case 1:
				cout << '\n';
				cout << "Introduceti noul nume: " << '\n';
				cin >> nume;
				break;
			case 2:
				cout << '\n';
				cout << "Introduceti noul tip: " << '\n';
				cin >> tip;
				break;
			case 3:
				cout << '\n';
				cout << "Introduceti noua facultate: " << '\n';
				cin >> facultate;
				break;
			case 4:
				system("cls");
				cout << '\n';
				cout << "===============================" << '\n';
				cout << "=         GAEC PROGRAM        =" << '\n';
				cout << "===============================" << '\n';
				cout << '\n';
				cout << "Modificarile au fost salvate." << '\n';
				cout << '\n';
				cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
				cout << '\n';
				break;
			default:
				cout << "Optiune invalida. Incercati din nou." << '\n';
				break;
			}
		} while (a != 4);

		ostringstream updatedLine;
		updatedLine << nume << " " << tip << " " << facultate << " " << user;
		lines[nrclub - 1] = updatedLine.str();

		ofstream outFile("cluburi.txt");
		for (const auto& l : lines)
		{
			outFile << l << endl;
		}
		outFile.close();
	}
	else
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu aveti acces ca sa modificati datele clubului" << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cout << '\n';
	}
}

void ClubManager::ChangeDataAdmin()
{
	system("cls");
	ifstream file("cluburi.txt");
	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	if (isEmpty() == true)
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun club inscris in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cout << '\n';
		return;
	}
	file.close();
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista cluburilor create:" << '\n';
	for (size_t i = 0; i < lines.size(); i++)
	{
		cout << i + 1 << ". " << lines[i] << '\n';
	}

	int nrclub;
	cout << "Introduceti numarul clubului pe care doriti sa il modificati. ( 0 pentru a iesi ):" << '\n';
	cin >> nrclub;

	if (!cin || nrclub < 0 || static_cast<size_t>(nrclub) > lines.size())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << '\n';
		cout << "Optiune invalida. Incercati din nou." << '\n';
		return;
	}

	if (nrclub == 0)
	{
		return;
	}

	string nume, tip, facultate, user;
	istringstream ss(lines[nrclub - 1]);
	ss >> nume >> tip >> facultate >> user;
	{
		int a;
		do
		{
			system("cls");
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Club selectat: " << '\n';
			cout << "Nume: " << nume << " " << "Tip: " << tip << " " << "Facultate: " << facultate << " " << " Creator: " << user << "." << '\n';
			cout << '\n';
			cout << "Ce doriti sa schimbati ?" << '\n';
			cout << '\n';
			cout << "1. Numele." << '\n';
			cout << "2. Tipul." << '\n';
			cout << "3. Facultatea." << '\n';
			cout << "4. Finalizare modificari." << '\n';
			cout << '\n';
			cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
			cout << '\n';
			cin >> a;

			switch (a)
			{
			case 1:
				cout << '\n';
				cout << "Introduceti noul nume: " << '\n';
				cin >> nume;
				break;
			case 2:
				cout << '\n';
				cout << "Introduceti noul tip: " << '\n';
				cin >> tip;
				break;
			case 3:
				cout << '\n';
				cout << "Introduceti noua facultate: " << '\n';
				cin >> facultate;
				break;
			case 4:
				system("cls");
				cout << '\n';
				cout << "===============================" << '\n';
				cout << "=         GAEC PROGRAM        =" << '\n';
				cout << "===============================" << '\n';
				cout << '\n';
				cout << "Modificarile au fost salvate." << '\n';
				cout << '\n';
				cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
				cout << '\n';
				break;
			default:
				cout << "Optiune invalida. Incercati din nou." << '\n';
				break;
			}
		} while (a != 4);

		ostringstream updatedLine;
		updatedLine << nume << " " << tip << " " << facultate << " " << user;
		lines[nrclub - 1] = updatedLine.str();

		ofstream outFile("cluburi.txt");
		for (const auto& l : lines)
		{
			outFile << l << endl;
		}
		outFile.close();
	}
}
