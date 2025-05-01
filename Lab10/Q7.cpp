#include <iostream>
#include <fstream>
using namespace std;

typedef struct student
{
    char name[50];
    int id;
    float gpa;
} st;

int main()
{
    int n;
    cout << "\nEnter the number of students: ";
    cin >> n;
    cin.ignore();

    st s;

    ofstream outFile("students.dat", ios::binary);
    if (!outFile)
    {
        cout << "\nError: Unable to open file for writing.";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter name: ";
        cin.getline(s.name, 50);
        cout << "Enter ID: ";
        cin >> s.id;
        cout << "Enter GPA: ";
        cin >> s.gpa;
        cin.ignore();
        outFile.write(reinterpret_cast<char*>(&s), sizeof(s));
    }
    outFile.close();

    ifstream inFile("students.dat", ios::binary);
    if (!inFile)
    {
        cout << "\nError: Unable to open file for reading.";
        return 1;
    }

    cout << "\nStudent records:\n";
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s)))
    {
        cout << "Name: " << s.name << "\n";
        cout << "ID: " << s.id << "\n";
        cout << "GPA: " << s.gpa << "\n";
    }

    inFile.close();
    return 0;
}
