#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
    ofstream logFile("system_log.txt", ios::app);

    if (!logFile.is_open())
    {
        cout << "\nFailed to open system log file.";
        return 1;
    }

    time_t now = time(0);
    char* dt = ctime(&now);

    logFile << "\nSystem started at: " << dt;

    logFile.close();
    return 0;
}
