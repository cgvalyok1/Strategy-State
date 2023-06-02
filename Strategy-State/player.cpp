#include <iostream>
#include "player.h"

using namespace std;

Player::Player(Character* ch) : charctr(ch)
{
}

Player::~Player()
{
    delete this->charctr;
}

void Player::set_character(Character* ch)
{
    delete this->charctr;
    this->charctr = ch;
}

void Player::Attack()
{
    this->charctr->Attack();
}

void Player::Reload()
{
    this->charctr->Reload();
}