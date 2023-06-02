#include <iostream>
#include "character.h"
#include "crossbow.h"

using namespace std;

void Warrior::Attack()
{
    cout << "The enemy lost 10 hp from a sword slash" << endl;
}

void Warrior::Reload()
{
}

void Mage::Attack()
{
    cout << "The enemy lost 15 hp from a fireball" << endl;
}

void Mage::Reload()
{
}

void Dogge::Attack()
{
    cout << "The enemy lost 9999999999 hp from the Dogge's bark" << endl;
}

void Dogge::Reload()
{
}

Archer::Archer()
{
    cbstate = ArmedCrossbow::GetInstance();
    ready_to_shoot = true;
}

void Archer::Attack()
{
    if (ready_to_shoot)
    {
        cout << "The enemy lost 10 hp from an arrow" << endl;
        ready_to_shoot = false;
        cbstate = UnarmedCrossbow::GetInstance();
    }
    else
    {
        cout << "Crossbow is not armed" << endl;
    }
}

void Archer::Reload()
{
    cbstate->Reload();
    ready_to_shoot = true;
    cbstate = ArmedCrossbow::GetInstance();
}