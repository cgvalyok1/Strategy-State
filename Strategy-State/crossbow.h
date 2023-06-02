#ifndef CROSSBOW_H
#define CROSSBOW_H

class CbState
{
public:
    virtual void Reload() = 0;
};

class ArmedCrossbow : public CbState
{
public:
    static ArmedCrossbow* GetInstance();
    void Reload();
};

class UnarmedCrossbow : public CbState
{
public:
    static UnarmedCrossbow* GetInstance();
    void Reload();
};

#endif