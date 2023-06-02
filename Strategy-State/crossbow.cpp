#include <iostream>
#include "crossbow.h"

using namespace std;

ArmedCrossbow* ArmedCrossbow::GetInstance()
{
    static ArmedCrossbow m_pArmed;
    return &m_pArmed;
}

void ArmedCrossbow::Reload()
{
    cout << "Crossbow is already armed" << endl;
}

UnarmedCrossbow* UnarmedCrossbow::GetInstance()
{
    static UnarmedCrossbow m_pUnarmed;
    return &m_pUnarmed;
}

void UnarmedCrossbow::Reload()
{
    cout << "Crossbow has been reloaded" << endl;
}