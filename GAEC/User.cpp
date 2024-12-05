#include "User.h"

User::User(string u,string p) : username(u), password(p) {}

bool User::login(const string& enteredUsername, const string& enteredPassword)
{
	return(username == enteredUsername && password == enteredPassword);
}

string User::getUsername() const
{
	return username;
}

string User::getPassword() const
{
	return password;
}
