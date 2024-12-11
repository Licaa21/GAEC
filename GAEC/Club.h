#pragma once
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class Club {
public:
	string Nume, Tip, Facultate;

	Club() : Nume(""), Tip(""), Facultate("") {}
	void display() const;
};