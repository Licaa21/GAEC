#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Club.h"

using namespace std;

class ClubManager
{
private:
	vector<Club> cluburi;
	const string filename = "cluburi.txt";

	void loadFromFile();
	void saveToFile() const;

public:
	ClubManager();
	void Inregistrare();
	void Afisaretext();
	bool isEmpty();
	void join();
};

