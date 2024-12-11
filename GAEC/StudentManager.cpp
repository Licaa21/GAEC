#include "LoginSystem.h"
#include "StudentManager.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

StudentManager::StudentManager()
{
	loadFromFile();
}

void StudentManager::loadFromFile()
{
	ifstream file(filename);
	if (!file.is_open()) return;

	students.clear();
	string line;
	while (getline(file, line))
	{
		istringstream ss(line);
		Student s;
		ss >> s.Nume >> s.Prenume >> s.Facultate >> s.Varsta;
		students.push_back(s);
	}
}
void StudentManager::saveToFile() const
{
	ofstream file(filename);
	if (!file.is_open()) return;
	for (const auto& student : students)
	{
		file << student.Nume << " " << student.Prenume << " " << student.Facultate << " " << student.Varsta << '\n';
	}
}
void StudentManager::Inregistrare()
{
	system("cls");
	ofstream o("Studenti.txt", std::ios::app);
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
	Student s;
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Numele:";
	cin >> s.Nume;
	o << s.Nume << " ";
	cout << "Prenumele:";
	cin >> s.Prenume;
	o << s.Prenume << " ";
	cout << "Facultatea:";
	cin >> s.Facultate;
	o << s.Facultate << " ";
	cout << "Varsta:";
	cin >> s.Varsta;
	o << s.Varsta << " ";
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

bool StudentManager::isEmpty()
{
	ifstream file(filename);
	if (!file)
	{
		cerr << "Error: Could not open file." << endl;
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
void StudentManager::Afisaretext() // Fa sa apara mai frumos cu prenume nume facultate etc..
{
	system("cls");
	ifstream file("Studenti.txt");
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
		cout << "Nu exista niciun student inscris in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}
	else
	{
		string line;
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		while (getline(file, line))
		{
			cout << line << '\n';
		}
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	file.close();
}

void StudentManager::Changedata()
{
	system("cls");
	ifstream file("Studenti.txt");
	if (!file.is_open())
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}
	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	file.close();

	if (isEmpty() == true)
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu exista niciun student inscris in program." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista studentilor inscrisi:" << '\n';
	for (size_t i = 0; i < lines.size(); i++)
		cout << i + 1 << ". " << lines[i] << '\n';

	int nrstudent;
	cout << "Introduceti numarul studentului pe care doriti sa il modificati. ( 0 pentru a iesi ):" << '\n';
	cin >> nrstudent;

	if (!cin || nrstudent < 0 || static_cast<size_t>(nrstudent) > lines.size())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << '\n';
		cout << "Optiune invalida. Incercati din nou." << '\n';
		return;
	}

	string nume, prenume, facultate, varsta;
	istringstream ss(lines[nrstudent - 1]);
	ss >> nume >> prenume >> facultate >> varsta;

	int a;
	do
	{
		system("cls");
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Student selectat: " << nume << " " << prenume << " " << facultate << " " << varsta << "." << '\n';
		cout << '\n';
		cout << "Ce doriti sa schimbati ?" << '\n';
		cout << '\n';
		cout << "1. Numele." << '\n';
		cout << "2. Prenumele." << '\n';
		cout << "3. Facultatea." << '\n';
		cout << "4. Varsta." << '\n';
		cout << "5. Finalizare modificari." << '\n';
		cout << '\n';
		cout << "Alegeti un numar pentru a continua. (1-5)" << '\n';

		cin >> a;
		switch (a)
		{
		case 1:
			cout << "Introduceti noul nume: " << '\n';
			cin >> nume;
			break;
		case 2:
			cout << "Introduceti noul prenume: " << '\n';
			cin >> prenume;
			break;
		case 3:
			cout << "Introduceti noua faculate: " << '\n';
			cin >> facultate;
			break;
		case 4:
			cout << "Introduceti noua varsta: " << '\n';
			cin >> varsta;
			break;
		case 5:
			cout << "Modificarile au fost salvate." << '\n';
			cout << '\n';
			cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
			break;
		default:
			cout << "Optiune invalida. Incercati din nou." << '\n';
			break;
		}
	} while (a != 5);

	ostringstream updatedLine;
	updatedLine << nume << " " << prenume << " " << facultate << " " << varsta;
	lines[nrstudent - 1] = updatedLine.str();

	ofstream outFile("Studenti.txt");
	if (!outFile.is_open())
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}
	for (const auto& l : lines)
	{
		outFile << l << endl;
	}
	outFile.close();
}
void StudentManager::StergereStudent()
{
	system("cls");
	ifstream file("Studenti.txt");
	if (!file.is_open())
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}

	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	file.close();

	if (lines.empty())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Nu este niciun student inscris in programul nostru." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Lista de studenti: " << '\n';
	for (size_t i = 0; i < lines.size(); i++)
	{
		cout << i + 1 << ". " << lines[i] << '\n';
	}
	int nrstudent;
	cout << "Numarul studentului pe care doriti sa-l stergeti. ( 0 pentru a iesi )" << '\n';
	cin >> nrstudent;
	if (nrstudent == 0)
	{
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	if (nrstudent < 1 || nrstudent > lines.size())
	{
		cout << '\n';
		cout << "===============================" << '\n';
		cout << "=         GAEC PROGRAM        =" << '\n';
		cout << "===============================" << '\n';
		cout << '\n';
		cout << "Numarul studentului este invalid." << '\n';
		cout << '\n';
		cout << "Apasati tasta enter pentru a reveni la meniul anterior." << '\n';
		return;
	}

	lines.erase(lines.begin() + nrstudent - 1);

	ofstream outFile("Studenti.txt");
	if (!outFile.is_open())
	{
		cerr << "S-a produs o eroare." << '\n';
		return;
	}
	for (const auto& l : lines)
	{
		outFile << l << endl;
	}
	outFile.close();
	system("cls");
	cout << '\n';
	cout << "===============================" << '\n';
	cout << "=         GAEC PROGRAM        =" << '\n';
	cout << "===============================" << '\n';
	cout << '\n';
	cout << "Studentul a fost sters din program." << '\n';
}
