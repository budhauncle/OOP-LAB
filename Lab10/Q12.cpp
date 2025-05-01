#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("debug_target.txt", ios::in | ios::binary);

    if (!file)
    {
        cout << "\nError: Unable to open the file.";
        return 1;
    }

    while (true)
    {
        cout << "\nEnter a byte offset to inspect (type -1 to exit): ";
        streamoff offset;
        cin >> offset;

        if (offset == -1)
        {
            cout << "\nDone debugging.";
            break;
        }

        file.clear();
        file.seekg(0, ios::end);
        streamoff fileSize = file.tellg();

        if (offset < 0 || offset >= fileSize)
        {
            cout << "\nInvalid offset. The file is " << fileSize << " bytes long. Try again.";
            continue;
        }

        file.seekg(offset, ios::beg);
        streamoff positionBefore = file.tellg();

        char buffer[101] = {0};
        file.read(buffer, 100);
        streamoff positionAfter = file.tellg();

        cout << "\nReading 100 bytes starting at offset " << offset;
        cout << "\nPointer before read: " << positionBefore;
        cout << "\nPointer after read: " << positionAfter;
        cout << "\nContent at this position:\n";

        cout.write(buffer, file.gcount());
    }

    file.close();
    return 0;
}
