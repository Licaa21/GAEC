#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student {
public:
    string Nume, Prenume, Facultate, Varsta;

    Student() : Nume(""), Prenume(""), Facultate(""), Varsta("") {}
    void display() const;
};

