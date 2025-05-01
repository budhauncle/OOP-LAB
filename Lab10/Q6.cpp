#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("secret.txt");
    if (!file)
    {
        cout << "\nError: Unable to open the secret file.";
        return 1;
    }

    char ch;
    int count = 0;
    while (file.get(ch))
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            count++;
        }
    }

    file.close();
    cout << "\nNumber of signals: " << count << "\n";

    return 0;
}
