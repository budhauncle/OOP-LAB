#include <iostream>
using namespace std;

class Character
{
    protected:
        int health,damage;

    public:
        Character(int h, int d) : health(h), damage(d) {}

        void displayC()
        {
            cout<<"\nHealth:"<<health;
            cout<<"\nDamage:"<<damage;
        }
};

class Player : public Character
{
    public:
        Player(int h, int d) : Character(h, d) {}

        void displayP()
        {
            cout<<"\nHealth:"<<health;
            cout<<"\nDamage:"<<damage;
        }
};

class Enemy : public Character
{
    public:
        Enemy(int h,int d) : Character(h, d) {}

        void displayE()
        {
            cout<<"\nHealth:"<<health;
            cout<<"\nDamage:"<<damage;
        }
};

class Wizard : public Player
{
    int magic;

    public:
        Wizard(int h, int d, int m) : Player(h,d), magic(m) {}

        void displayW()
        {
            cout<<"\nHealth:"<<health;
            cout<<"\nDamage:"<<damage;
            cout<<"\nMagic:"<<magic;
        }
};

int main()
{
    Character c1(200,30);
    Player p1(160,20);
    Enemy e1(100,15);
    Wizard w1(80,15,45);
    c1.displayC();
    p1.displayP();
    e1.displayE();
    w1.displayW();
    return 0;
}
