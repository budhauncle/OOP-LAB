#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name, message;

    cout << "\nPlease enter the name: ";
    getline(cin, name);

    cout << "\nWrite a short message: ";
    getline(cin, message);

    ofstream outFile("greeting.txt");

    if (outFile.is_open())
    {
        outFile << "\nDear " << name << ",";
        outFile << "\n" << message;
        outFile << "\nBest Regards!";
        outFile.close();
    }
    else
    {
        cout << "\nCould not open the file.";
    }

    return 0;
}
