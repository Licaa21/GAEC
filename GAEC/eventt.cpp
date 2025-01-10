#include "eventt.h"
#include <string>
#include <iostream>

using namespace std;

void eventt::display() const {
	cout << Nume << " " << club << " " << data << " " << ora << '\n';
}