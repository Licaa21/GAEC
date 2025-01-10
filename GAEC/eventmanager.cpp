#include "eventmanager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

eventmanager::eventmanager()
{
	loadFromFile();
}

void eventmanager::loadFromFile()
{
	ifstream file(filename);
	if (!file.is_open()) return;

	evenimente.clear();
	string line;
	while (getline(file, line))
	{
		istringstream ss(line);
		eventt s;
		ss >> s.Nume >> s.club >> s.data >> s.ora;
		evenimente.push_back(s);
	}
}
void eventmanager::saveToFile() const
{
	ofstream file(filename);
	if (!file.is_open()) return;
	for (const auto& events : evenimente)
	{
		file << events.Nume << " " << events.club << " " << events.data << " " << events.ora << '\n';
	}
}

bool eventmanager::isEmpty()
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
void eventmanager::stergere()
{
	system("cls");
	ifstream file("evenimente.txt");
	ifstream f("users.txt");
	string line;
	int idclub = 0;
	string loggedusername;


	while (getline(f, line))
	{
		istringstream ss(line);
		string username, password;
		int status, clubid;
		ss >> username >> password >> status >> clubid;

		if (status == 1) 
		{
			loggedusername = username;
			idclub = clubid; 
			break;
		}
	}


	vector<string> eventsForClub;
	string line2;
	while (getline(file, line2))
	{
		istringstream ss(line2);
		string nume1, data, ora;
		int club;
		ss >> nume1 >> club >> data >> ora;

		if (club == idclub)
		{
			eventsForClub.push_back(line2); 
		}
	}

	file.close();


	if (eventsForClub.empty())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista evenimente pentru clubul tau." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}


	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista de evenimente din clubul tau: " << '\n';
	for (size_t i = 0; i < eventsForClub.size(); i++)
	{
		cout << i + 1 << ". " << eventsForClub[i] << '\n';
	}

	int nreveniment;
	cout << "Numarul evenimentului pe care doriti sa-l stergeti (0 pentru a iesi): " << '\n';

	ifstream clubFile("cluburi.txt");
	string clubLine;
	int clubIndex = 1; 


	while (getline(clubFile, clubLine))
	{
		istringstream pp(clubLine);
		string nume2, tip, facultate, lider;
		pp >> nume2 >> tip >> facultate >> lider;


		if (clubIndex == idclub)
		{

			if (lider == loggedusername)
			{
				cin >> nreveniment;
				if (nreveniment == 0)
				{
					cout << '\n';
					cout << "===============================" << '\n';
					cout << "=         GAEC PROGRAM        =" << '\n';
					cout << "===============================" << '\n';
					cout << '\n';
					cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
					return;
				}

				if (nreveniment < 1 || nreveniment > eventsForClub.size())
				{
					system("cls");
					cout << '\n';
					cout << "===============================" << '\n';
					cout << "=         GAEC PROGRAM        =" << '\n';
					cout << "===============================" << '\n';
					cout << '\n';
					cout << "Numarul evenimentului este invalid." << '\n';
					cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
					cin.ignore();
					return;
				}


				ifstream eventFile("evenimente.txt");
				vector<string> allEvents;
				while (getline(eventFile, line))
				{
					allEvents.push_back(line);
				}
				eventFile.close();


				allEvents.erase(allEvents.begin() + nreveniment - 1);


				ofstream outFile("evenimente.txt");
				if (!outFile.is_open())
				{
					cerr << "S-a produs o eroare la deschiderea fisierului." << '\n';
					return;
				}


				for (const auto& event : allEvents)
				{
					outFile << event << endl;
				}

				outFile.close();

				system("cls");
				cout << '\n';
				cout << "===============================" << '\n';
				cout << "=         GAEC PROGRAM        =" << '\n';
				cout << "===============================" << '\n';
				cout << '\n';
				cout << "Evenimentul a fost sters din program." << '\n';
				cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
				cout << '\n';
				cin.ignore();
				return;
			}
			else
			{
				system("cls");
				cout << '\n';
				cout << "===============================" << '\n';
				cout << "=         GAEC PROGRAM        =" << '\n';
				cout << "===============================" << '\n';
				cout << '\n';
				cout << "Nu sunteti liderul clubului pentru a sterge evenimentul." << '\n';
				cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
				cout << '\n';
				cin.ignore();
				return;
			}
		}

		clubIndex++;
	}


	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Nu sunteti liderul clubului pentru a sterge evenimentul." << '\n';
	cout << '\n';
	cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
	cout << '\n';
	cin.ignore();
}


void eventmanager::creare()
{
	system("cls");
	ofstream o("evenimente.txt", std::ios::app);
	if (!o.is_open())
	{
		cerr << "S-a produs o eroare" << '\n';
		return;
	}
	eventt s;
	ifstream file("users.txt");
	string loggedInUsername;
	string line;
	bool found = false;
	int idclub = 0;
	string numeclub;
	string loggedusername;
	while (getline(file, line))
	{
		istringstream ss(line);
		string username, password;
		int status, clubid;
		ss >> username >> password >> status >> clubid;

		if (status == 1)
		{
			loggedusername = username;
			idclub = clubid;
			break;
		}
	}
	ifstream f("evenimente.txt");
	string line2;
	while (getline(f, line2))
	{
		istringstream ss(line2);
		string nume1, data, ora;
		int club;
		ss >> nume1 >> club >> data >> ora;
		ifstream p("cluburi.txt");
		string line3;
		int number = 0;
		while (getline(p, line3))
		{
			number++;
			istringstream pp(line3);
			string nume2, tip, facultate, lider;
			pp >> nume2 >> tip >> facultate >> lider;
			if (lider == loggedusername)
			{
				if (number == club)
				{
					cout << '\n';
					cout << "===============================" << '\n';
					cout << "=         GAEC PROGRAM        =" << '\n';
					cout << "===============================" << '\n';
					cout << '\n';
					cout << "Clubul tau are un eveniment in progres." << '\n';
					cout << '\n';
					cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
					cout << '\n';
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					return;

				}
			}
		}
	}
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Numele: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, s.Nume);
	o << s.Nume << " ";
	o << idclub << " ";
	file.close();
	cout << "Data evenimentul: ";
	getline(cin, s.data);
	o << s.data << " ";
	cout << "Ora evenimentului: ";
	getline(cin, s.ora);
	o << s.ora << " ";
	o << '\n';
	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Eveniment creat cu succes, apasati enter pentru a reveni la meniul anterior." << '\n';
	o.close();
}
void eventmanager::join()
{
	ifstream s("evenimente.txt");

	if (isEmpty())
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun eveniment creat in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cin.ignore();
		return;
	}

	ifstream f("users.txt", std::ios::in | std::ios::out);
	string loggedInUsername;
	string linef;
	vector<string> users;
	bool found = false;
	bool noevent = false;
	int userClubID = -1;

	while (getline(f, linef))
	{
		istringstream ss(linef);
		string username, password;
		int status, clubID, statuseveniment;
		ss >> username >> password >> status >> clubID >> statuseveniment;

		if (status == 1 && !found)
		{
			loggedInUsername = username;
			userClubID = clubID;
			found = true;
			if (statuseveniment == 0)
			{
				noevent = true;
				continue;
			}
			else
			{
				system("cls");
				cout << '\n';
				cout << "===============================" << '\n';
				cout << "=         GAEC PROGRAM        =" << '\n';
				cout << "===============================" << '\n';
				cout << '\n';
				cout << "Esti deja in evenimentul clubului." << '\n';
				cout << '\n';
				cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
				cout << '\n';
				cin.ignore();
				return;
			}
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

	vector<string> evenimente;
	string Nume, club, data, ora;
	string line;
	int number = 1;

	if (statusstudent == true && noevent == true)
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';

		bool eventFoundForClub = false;

		while (s >> Nume >> club >> data >> ora)
		{
			if (stoi(club) == userClubID)
			{
				eventFoundForClub = true;
				evenimente.push_back(Nume + " " + club + " " + data + " " + ora);
				cout << number << ". Nume: " << Nume << ", Clubul: " << club << ", Data: " << data << ", Ora: " << ora << '\n';
				cout << '\n';
				number++;
			}
		}

		if (!eventFoundForClub)
		{
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Nu exista evenimente pentru clubul tau." << '\n';
			cout << '\n';
			cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
			cin.ignore();
			return;
		}

		cout << "Doriti sa va inscrieti la acest eveniment? (0/1)" << '\n';
		string response;
		cin >> response;
		if (response == "1")
		{
			system("cls");
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Ati fost adaugat cu succes in eveniment!" << '\n';
			cout << '\n';
			cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		}
		else
		{
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Ati ales sa nu va inscrieti." << '\n';
			cout << '\n';
			cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		}
		cin.ignore();
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
		cin.ignore();
	}
}

void eventmanager::changedata()
{
	system("cls");
	ifstream eventFile("evenimente.txt");
	vector<string> eventLines;
	string eventLine;

	while (getline(eventFile, eventLine))
	{
		eventLines.push_back(eventLine);
	}

	if (eventLines.empty())
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun eveniment inregistrat." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		cout << '\n';
		return;
	}
	eventFile.close();

	ifstream usersFile("users.txt");
	string userLine;
	string currentUser;
	bool userFound = false;

	while (getline(usersFile, userLine))
	{
		stringstream ss(userLine);
		string username, password, status, clubID, statusEvent;
		ss >> username >> password >> status >> clubID >> statusEvent;

		if (status == "1")
		{
			currentUser = username;
			userFound = true;
			break;
		}
	}

	usersFile.close();

	if (!userFound)
	{
		cout << "Nu sunteti online sau nu exista un utilizator cu acest status." << '\n';
		cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	int userClubID = -1;
	string leaderUser;

	ifstream usersFile2("users.txt");
	while (getline(usersFile2, userLine))
	{
		stringstream ss(userLine);
		string username, password, status, clubID, statusEvent;
		ss >> username >> password >> status >> clubID >> statusEvent;

		if (username == currentUser && status == "1")
		{
			userClubID = stoi(clubID);
			leaderUser = username;
			break;
		}
	}
	usersFile2.close();

	if (userClubID == -1)
	{
		cout << "Nu sunteti online sau nu exista un utilizator cu acest username." << '\n';
		cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	int incheiere = 1;
	while (incheiere != 0)
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Evenimentul clubului tau: " << '\n';

		bool eventFound = false;
		string eventName, eventclubid, eventDate, eventHour;
		for (const string& event : eventLines)
		{
			stringstream ssEvent(event);
			ssEvent >> eventName >> eventclubid >> eventDate >> eventHour;

			if (stoi(eventclubid) == userClubID)
			{
				eventFound = true;
				cout << "Eveniment: " << eventName << " , Id-ul clubului din care face parte: " << eventclubid << " , Data: " << eventDate << " , Ora: " << eventHour << '\n';
				break;
			}
		}

		if (!eventFound)
		{
			cout << "Nu exista un eveniment pentru clubul tau." << '\n';
			cout << "Apasati tasta Enter pentru a reveni." << '\n';
			cin.ignore();
			cin.get();
			break;
		}

		cout << '\n';

		int option = 0;
		cout << "Ce doriti sa schimbati ?" << '\n';
		cout << '\n';
		cout << "1. Numele evenimentului." << '\n';
		cout << "2. Data evenimentului." << '\n';
		cout << "3. Ora evenimentului." << '\n';
		cout << "4. Finalizare modificari." << '\n';
		cout << '\n';

		cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
		cout << '\n';
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Introduceti noul nume al evenimentului: " << '\n';
			cin >> eventName;
			break;
		case 2:
			cout << "Introduceti noua data a evenimentului (ex: 20.05.2064): " << '\n';
			cin >> eventDate;
			break;
		case 3:
			cout << "Introduceti noua ora a evenimentului (ex: 20:00): " << '\n';
			cin >> eventHour;
			break;
		case 4:
			cout << "Modificarile au fost salvate." << '\n';
			incheiere = 0;
			break;
		default:
			cout << "Optiune invalida. Incercati din nou." << '\n';
			break;
		}

		if (option == 1 || option == 2 || option == 3)
		{
			ostringstream updatedEventLine;
			updatedEventLine << eventName << " " << userClubID << " " << eventDate << " " << eventHour;


			for (size_t i = 0; i < eventLines.size(); ++i)
			{
				stringstream ssEvent(eventLines[i]);
				string existingEventName, existingClubID, existingEventDate, existingEventHour;
				ssEvent >> existingEventName >> existingClubID >> existingEventDate >> existingEventHour;

				if (stoi(existingClubID) == userClubID)
				{
					eventLines[i] = updatedEventLine.str();
					break;
				}
			}


			ofstream eventOutFile("evenimente.txt");
			for (const auto& event : eventLines)
			{
				eventOutFile << event << endl;
			}
			eventOutFile.close();
		}
	}
}

void eventmanager::afisare()
{
	system("cls");
	ifstream usersFile("users.txt");
	string userLine;
	string currentUser;
	int userClubID = -1;

	bool userFound = false;


	while (getline(usersFile, userLine))
	{
		stringstream ss(userLine);
		string username, password, status, clubID, statusEvent;
		ss >> username >> password >> status >> clubID >> statusEvent;

		if (status == "1") 
		{
			currentUser = username;
			userClubID = stoi(clubID);
			userFound = true;
			break;
		}
	}

	usersFile.close();

	if (!userFound)
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "S-a creat o eroare si nu sunteti online sau nu exista un utilizator cu acest status." << '\n';
		cout << '\n';
		cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
		cin.ignore();
		return;
	}

	if (userClubID == -1)
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "S-a creat o eraore si nu sunteti online sau nu exista un utilizator cu acest username." << '\n';
		cout << '\n';
		cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
		cin.ignore();
		return;
	}

	ifstream eventFile("evenimente.txt");
	vector<string> eventLines;
	string eventLine;


	while (getline(eventFile, eventLine))
	{
		eventLines.push_back(eventLine);
	}

	if (eventLines.empty())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun eveniment inregistrat." << '\n';
		cout << '\n';
		cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
		cin.ignore();
		return;
	}
	eventFile.close();

	bool eventFound = false;
	ifstream p("users.txt");
	string line;
	string nume, parola, status, statusevent;
	int nrmembri = 0;
	int clubid;
	while (getline(p, line))
	{
		istringstream ss(line);
		ss >> nume >> parola >> status >> clubid >> statusevent;
		
		if (clubid == userClubID)
		{
			nrmembri++;
		}
	}

	for (const string& event : eventLines)
	{
		stringstream ssEvent(event);
		string eventName, eventclubid, eventDate, eventHour;
		ssEvent >> eventName >> eventclubid >> eventDate >> eventHour;


		if (stoi(eventclubid) == userClubID)
		{
			eventFound = true;
			system("cls");
			cout << '\n';
			cout << "===============================" << '\n';
			cout << "=         GAEC PROGRAM        =" << '\n';
			cout << "===============================" << '\n';
			cout << '\n';
			cout << "Evenimentul clubului tau: " << '\n';
			cout << '\n';
			cout << "Eveniment: " << eventName << " , Id-ul clubului din care face parte: " << eventclubid << " , Data: " << eventDate << " , Ora: " << eventHour << " , Membri: " << nrmembri << '\n';
			cout << '\n';
			cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
			cin.ignore();
			break;
		}
	}

	if (!eventFound)
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista un eveniment pentru clubul tau." << '\n';
		cout << '\n';
		cout << "Apasati tasta Enter pentru a reveni la meniul anterior." << '\n';
		cout << '\n';
		cin.ignore();
		return;
	}
}
