#include <iostream>
using namespace std;

class DayOfYear
{
    int day;
    static const int monthlyDays[];
    static const string months[];

public:
    DayOfYear(int d) : day(d) {}

    void print()
    {
        int total = 0;
        for (int i = 0; i < 12; i++)
        {
            if (day <= total + monthlyDays[i])
            {
                cout << months[i] << " " << (day - total) << endl;
                break;
            }
            total += monthlyDays[i];
        }
    }
};

const int DayOfYear::monthlyDays[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
const string DayOfYear::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
    int day;
    cout << "Enter a day between 1 and 365: ";
    cin >> day;

    if (day < 1 || day > 365)
    {
        cout << "Invalid input. Please enter a day between 1 and 365." << endl;
        return 1;
    }

    DayOfYear date(day);
    date.print();

    return 0;
}
