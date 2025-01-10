#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "eventt.h"
class eventmanager
{
private:
	vector<eventt> evenimente;
	const string filename = "evenimente.txt";

	void loadFromFile();
	void saveToFile() const;

public:
	eventmanager();
	void creare();
	void afisare();
	bool isEmpty();
	void join();
	void stergere();
	void changedata();
};