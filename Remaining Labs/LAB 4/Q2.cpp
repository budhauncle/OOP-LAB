#include <iostream>
#include <string>
using namespace std;

class DaysOfWeek
{
private:
    string days[7];
    int currentDay;

public:
    DaysOfWeek()
    {
        string tempDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (int i = 0; i < 7; i++)
        {
            days[i] = tempDays[i];
        }
        currentDay = 0;
    }

    DaysOfWeek(int day)
    {
        string tempDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (int i = 0; i < 7; i++)
        {
            days[i] = tempDays[i];
        }
        currentDay = day % 7;
    }

    string getCurrentDay() const
    {
        return days[currentDay];
    }

    string getNextDay() const
    {
        return days[(currentDay + 1) % 7];
    }

    string getPreviousDay() const
    {
        return days[(currentDay + 6) % 7];
    }

    string getNthDay(int N) const
    {
        return days[(currentDay + N) % 7];
    }
};

int main()
{
    DaysOfWeek today(8);
    cout << "Current Day : " << today.getCurrentDay() << "\n";
    cout << "Next Day : " << today.getNextDay() << "\n";
    cout << "Previous Day : " << today.getPreviousDay() << "\n";
    cout << " Day after 20 days : " << today.getNthDay(20) << "\n";
}
