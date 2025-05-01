#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name, email;
    char choice;

    ofstream signupfile("signup.txt", ios::app);
    if (!signupfile.is_open())
    {
        cout << "\nError: could not open the signup file.";
        return 1;
    }

    do
    {
        cout << "\nPlease enter your full name: ";
        getline(cin, name);

        cout << "\nNow enter your email address: ";
        getline(cin, email);

        signupfile << "\nName: " << name << ", Email: " << email;

        cout << "\nRegister another participant? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    signupfile.close();

    return 0;
}
