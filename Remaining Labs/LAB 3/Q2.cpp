#include <iostream>
using namespace std;

class Sphere
{
private:
    double diameter;
    const double piValue = 3.14159;

public:
    void setDiameter(double d)
    {
        diameter = d;
    }

    double getDiameter()
    {
        return diameter;
    }

    double getArea()
    {
        return piValue * (diameter / 2) * (diameter / 2);
    }

    double getRadius()
    {
        return diameter / 2;
    }

    double getCircumference()
    {
        return piValue * diameter;
    }
};

int main()
{
    Sphere s1;
    double rInput;

    cout << "\nEnter the radius of the sphere: ";
    cin >> rInput;

    s1.setDiameter(rInput * 2);

    cout << "\nSphere Properties:";
    cout << "\nRadius: " << s1.getRadius();
    cout << "\nArea: " << s1.getArea();
    cout << "\nDiameter: " << s1.getDiameter();
    cout << "\nCircumference: " << s1.getCircumference();

    return 0;
}
