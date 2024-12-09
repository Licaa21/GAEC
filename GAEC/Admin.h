#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:
	Admin(string u, string p);
	void displayRole() override;
	bool isAdmin() { return true; }
};

#endif