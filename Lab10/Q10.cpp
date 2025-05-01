#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream logFile("backup_log.txt", ios::app);

    if (!logFile)
    {
        cout << "\nError: Unable to open the log file.";
        return 1;
    }

    string logEntry;

    while (true)
    {
        cout << "\nEnter log message (or type 'exit' to quit): ";
        getline(cin, logEntry);

        if (logEntry == "exit") break;

        logFile << logEntry << "\n";
        logFile.flush();

        streampos size = logFile.tellp();
        cout << "\nCurrent file size: " << size << " bytes\n";
    }

    logFile.close();
    return 0;
}
