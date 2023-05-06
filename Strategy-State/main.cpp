#include <iostream>

using namespace std;

struct Character
{
    virtual void Attack() = 0;
    virtual void Reload() = 0;
};

class Warrior : public Character
{
    public:
        void Attack()
        {
            cout << "The enemy lost 10 hp from a sword slash" << endl;
        }
        void Reload(){}
};

class Mage : public Character
{
    public:
        void Attack()
        {
            cout << "The enemy lost 15 hp from a fireball" << endl;
        }
        void Reload(){}
};

class Dogge : public Character
{
    public:
        void Attack()
        {
            cout << "The enemy lost 9999999999 hp from the Dogge's bark" << endl;
        }
        void Reload(){}
};

class CbState
{
    public:
        virtual void Reload() = 0;
};

class ArmedCrossbow : public CbState
{
    public:

        static ArmedCrossbow* GetInstance()
        {
            static ArmedCrossbow m_pArmed;
            return &m_pArmed;
        }

        virtual void Reload()
        {
            cout << "Crossbow is already armed" << endl;
        }
};

class UnarmedCrossbow : public CbState
{
    public:
        static UnarmedCrossbow* GetInstance()
        {
            static UnarmedCrossbow m_pUnarmed;
            return &m_pUnarmed;
        }

        virtual void Reload()
        {
            cout << "Crossbow has been reloaded" << endl;
        }
};

class Archer : public Character
{
    CbState* cbstate = ArmedCrossbow::GetInstance();
    public:
        void Attack()
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

        void Reload()
        {
            cbstate->Reload();
            ready_to_shoot = true;
            cbstate = ArmedCrossbow::GetInstance();
        }

    private:
        bool ready_to_shoot = true;
};

class Player
{
    private:
        Character *charctr;
    public:
        Player(Character *ch) : charctr(ch) {}

        ~Player() {delete this ->charctr;}

        void set_character(Character *ch)
        {
            delete this ->charctr;
            this ->charctr = ch;
        }

        void Attack()
        {
            this->charctr->Attack();
        }

        void Reload()
        {
            this->charctr->Reload();
        }
};



int main()
{

    Player *player = new Player(new Warrior);
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
    return 0;
}
