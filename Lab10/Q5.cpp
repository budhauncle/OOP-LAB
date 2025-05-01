#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("story.txt");
    if (!file)
    {
        cout << "\nError: Unable to open the file.";
        return 1;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            cout << word << "\n";
        }
    }

    file.close();
    return 0;
}
