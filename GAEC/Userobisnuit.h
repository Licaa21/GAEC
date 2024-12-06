#ifndef USEROBISNUIT_H
#define USEROBISNUIT_H

#include "User.h"

class Userobisnuit : public User
{
public:
    Userobisnuit(string u, string p);
    void displayRole() override;
};

#endif