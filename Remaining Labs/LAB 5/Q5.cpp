#include <iostream>
using namespace std;

class ValidateString
{
    string instr; // string input

public:
    ValidateString(const string &str) : instr(str) {}

    // This function is declared as 'const' because it does not update values
    // of any class member variables. It ensures that this function only checks 
    // and reports, without causing any side effects.

    bool Validity() const
    {
        if (instr.empty()) // Handling empty strings (optional check)
        {
            return false; // You may choose to return true if empty strings are valid.
        }

        for (char ch : instr)
        {
            // Check if the character is not an alphabet (both lower and upper case).
            if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
            {
                return false;
            }
        }
        return true;
    }

    void print() const
    {
        if (Validity())
        {
            cout << "Valid string" << endl;
        }
        else
        {
            cout << "Invalid string" << endl;
        }
    }
};

int main()
{
    ValidateString s1("Hello");
    ValidateString s2("C++ very bad language!");
    ValidateString s3("12 ka 4 42 ka 1 my name is Lakhan");

    s1.print(); // Should print "Valid string"
    s2.print(); // Should print "Invalid string"
    s3.print(); // Should print "Invalid string"

    return 0;
}
