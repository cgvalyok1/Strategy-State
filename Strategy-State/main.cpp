#include <iostream>
#include "character.h"
#include "crossbow.h"
#include "player.h"

using namespace std;

int main()
{
    Player* player = new Player(new Warrior);
    cout << "Player class was set as Warrior" << endl;
    player->Attack();
    cout << endl;

    player->set_character(new Mage);
    cout << "Player class was set as Mage" << endl;
    player->Attack();
    cout << endl;

    player->set_character(new Dogge);
    cout << "Player class was set as Dogge" << endl;
    player->Attack();
    cout << endl;

    player->set_character(new Archer);
    cout << "Player class was set as Archer" << endl;
    player->Attack();
    player->Attack();
    player->Reload();
    player->Reload();
    player->Attack();

    delete player;
    return 0;
}
