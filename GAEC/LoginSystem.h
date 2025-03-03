#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "User.h"
#include "Admin.h"
#include <unordered_map>
#include <fstream>


class LoginSystem
{
private:
	unordered_map<string, User*> users;

public:
	~LoginSystem();
	void AdaugareUtilizator(User* user);
	void inregistrare(const string& username, const string& password);
	User* autentificare(const string& enteredUsername, const string& enteredPassword);
	void loadUsersFromFile(const string& filename);
	void updateUserStatus(const string& username, int status);
	void seeUserDetails();
	void seeAdministration();
	void updateeventstatus(const string& username, int statuseveniment);
};

#endif

