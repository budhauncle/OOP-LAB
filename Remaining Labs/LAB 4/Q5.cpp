#include <iostream>
#include <string>
using namespace std;

class FootballPlayer {
private:
    string playerName;
    string position;
    int goalCount;

public:
    FootballPlayer() : playerName("Unknown Player"), position("Benchwarmer"), goalCount(0) {}

    FootballPlayer(string name, string pos, int goals) : playerName(name), position(pos), goalCount(goals) {}

    FootballPlayer(const FootballPlayer &player) : playerName(player.playerName), position(player.position), goalCount(player.goalCount) {}

    FootballPlayer(string name) : playerName(name), position("Midfielder"), goalCount(10) {}

    void boostGoals(int addGoals) {
        goalCount += addGoals;
        cout << playerName << " just scored " << addGoals << " more goals! Total goals now: " << goalCount << endl;
    }

    void showProfile() const {
        cout << "\n🏆 Player Profile 🏆" << endl;
        cout << "Name: " << playerName << endl;
        cout << "Position: " << position << endl;
        cout << "Goals: " << goalCount << endl;
        cout << "Commentary: " << playerName << " is on fire! 🔥" << endl;
    }
};

int main() {
    FootballPlayer p1;
    p1.showProfile();

    FootballPlayer messi("Messi", "Forward", 800);
    messi.showProfile();

    FootballPlayer neymar("Neymar");
    neymar.showProfile();

    FootballPlayer messiClone(messi);
    cout << "\n🚀 Cloning Messi...\n";
    messiClone.showProfile();

    messi.boostGoals(5);
    messi.showProfile();

    return 0;
}
