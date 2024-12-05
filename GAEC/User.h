#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
protected:
	string username;
	string password;

public:
	User(string u, string p);
	virtual bool login(const string& enteredUsername, const string& enteredPassword);
	virtual void displayRole() = 0;

	string getUsername() const;
	string getPassword() const;
};
#endif