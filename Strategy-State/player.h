#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player
{
private:
    Character* charctr;
public:
    Player(Character* ch);
    ~Player();
    void set_character(Character* ch);
    void Attack();
    void Reload();
};

#endif