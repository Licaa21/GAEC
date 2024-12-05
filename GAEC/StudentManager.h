#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;
class StudentManager
{
private:
	vector<Student> students;
	const string filename = "Studenti.txt";

	void loadFromFile();
	void saveToFile() const;

public:
	StudentManager();
	void Inregistrare();
	void Afisaretext();
	void Changedata();
	void StergereStudent();
	bool isEmpty();
};

