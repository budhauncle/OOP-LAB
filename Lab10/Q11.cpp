#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("article.txt");
    ofstream reportFile("report.txt");

    if (!inputFile)
    {
        cout << "\nError: Unable to open the input file.";
        return 1;
    }
    if (!reportFile)
    {
        cout << "\nError: Unable to open the report file.";
        return 1;
    }

    string line;
    int chars = 0;
    int words = 0;
    int lines = 0;
    int punctuation = 0;

    while (getline(inputFile, line))
    {
        lines++;
        chars += line.length() + 1;

        bool inWord = false;
        for (char c : line)
        {
            if (isspace(c))
            {
                if (inWord)
                {
                    words++;
                    inWord = false;
                }
            }
            else
            {
                if (!inWord) inWord = true;
                if (ispunct(c)) punctuation++;
            }
        }
        if (inWord) words++;
    }

    reportFile << "Quality metrics report\n";
    reportFile << "Total characters: " << chars << "\n";
    reportFile << "Total words: " << words << "\n";
    reportFile << "Total lines: " << lines << "\n";
    reportFile << "Punctuation marks count: " << punctuation << "\n";

    inputFile.close();
    reportFile.close();

    return 0;
}
