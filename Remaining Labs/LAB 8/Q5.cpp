#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student
{
    string name;
    int grades[3];

public:
    Student(string n, int g1, int g2, int g3)
    {
        name = n;
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    friend class Teacher;
    friend float average(const Student& s);

    void display() const
    {
        cout << "Student: " << name << endl;
        cout << "Grades: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Grade " << i + 1 << ": " << grades[i] << endl;
        }
    }
};

float average(const Student& s)
{
    return (s.grades[0] + s.grades[1] + s.grades[2]) / 3.0f;
}

class Teacher
{
public:
    void update(Student& s, int i, int newgrade)
    {
        if (i >= 0 && i < 3)
        {
            s.grades[i] = newgrade;
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }
};

int main()
{
    Student s("Hanzala", 100, 90, 80);
    s.display();
    cout << "Average: " << average(s) << endl;

    Teacher t;
    t.update(s, 1, 20); // Corrected the index to a valid one (0, 1, or 2)

    s.display();
    cout << "New Average: " << average(s) << endl;

    return 0;
}
