#include <iostream>
using namespace std;

class Character {
protected:
    int health;
    int damage;

public:
    Character(int h, int d) : health(h), damage(d) {}

    void displaychar() const {
        cout << "Current Health: " << health << "\n";
        cout << "Damage Dealt: " << damage << "\n";
    }
};

class Player : public Character {
public:
    Player(int h, int d) : Character(h, d) {}

    void displayplay() const {
        displaychar();
    }
};

class Enemy : public Character {
public:
    Enemy(int h, int d) : Character(h, d) {}

    void displayenem() const {
        displaychar();
    }
};

class Wizard : public Player {
    int magic;

public:
    Wizard(int h, int d, int m) : Player(h, d), magic(m) {}

    void displaywiz() const {
        displayplay();
        cout << "Magic Power: " << magic << "\n";
    }
};

int main() {
    Character c1(150, 20);
    Player p1(130, 25);
    Enemy e1(86, 13);
    Wizard w1(130, 14, 78);

    cout << "Character Information:\n";
    c1.displaychar();
    cout << "\nPlayer Information:\n";
    p1.displayplay();
    cout << "\nEnemy Information:\n";
    e1.displayenem();
    cout << "\nWizard Information:\n";
    w1.displaywiz();

    return 0;
}
