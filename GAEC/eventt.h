#pragma once
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class eventt {
public:
	string Nume, club, data,ora;

	eventt() : Nume(""), club(""), data(""), ora("") {}
	void display() const;
};
