#include <iostream>
#include <string>
using namespace std;

class CricketPlayer
{
private:
    string playerName;
    int shirtNumber;
    float battingAvg;

public:
    CricketPlayer(string name, int number, float avg)
    {
        playerName = name;
        shirtNumber = number;
        battingAvg = avg;
    }
    CricketPlayer &enhanceAvg(int runs)
    {
        battingAvg = (battingAvg + runs) / 2.0;
        return *this;
    }
    void playGame(int runsScored)
    {
        battingAvg = ((battingAvg * (shirtNumber - 1)) + runsScored) / shirtNumber;
        shirtNumber++;
    }
    void showPlayerStats()
    {
        cout << "Player Name : " << playerName << "\n";
        cout << "Shirt Number : " << shirtNumber << "\n";
        cout << "Batting Average : " << battingAvg << "\n";
        cout << "This batting average is more consistent than Karachi's weather!" << "\n";
    }
};

int main()
{
    CricketPlayer babarAzam("Babar Azam", 10, 45.0);
    CricketPlayer rizwan("Muhammad Rizwan", 8, 40.5);
    CricketPlayer saimAyub("Saim Ayub", 15, 30.0);

    babarAzam.playGame(100);
    rizwan.playGame(50);
    saimAyub.playGame(10);

    babarAzam.enhanceAvg(120).enhanceAvg(110);
    rizwan.enhanceAvg(90);
    saimAyub.enhanceAvg(70);

    cout << "\nPlayer Stats After Matches: \n";
    babarAzam.showPlayerStats();
    cout << "\n";
    rizwan.showPlayerStats();
    cout << "\n";
    saimAyub.showPlayerStats();

    return 0;
}
