#ifndef CHARACTER_H
#define CHARACTER_H
#include "crossbow.h"

struct Character
{
    virtual void Attack() = 0;
    virtual void Reload() = 0;
};

class Warrior : public Character
{
public:
    void Attack();
    void Reload();
};

class Mage : public Character
{
public:
    void Attack();
    void Reload();
};

class Dogge : public Character
{
public:
    void Attack();
    void Reload();
};

class Archer : public Character
{
    CbState* cbstate;
    bool ready_to_shoot;
public:
    Archer();
    void Attack();
    void Reload();
};

#endif