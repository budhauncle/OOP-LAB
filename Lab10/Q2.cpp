#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string entry;

    ofstream diary("diary.txt", ios::app);
    if (!diary.is_open())
    {
        cout << "\nUnable to open diary file.";
        return 1;
    }

    cout << "\nBegin writing your diary. Type 'exit' when you're finished:\n";

    while (true)
    {
        getline(cin, entry);
        if (entry == "exit")
        {
            break;
        }
        diary << "\n" << entry;
    }

    diary.close();

    return 0;
}
