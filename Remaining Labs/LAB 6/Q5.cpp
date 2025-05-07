#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string make, model;
    int year;

public:
    Vehicle(string m, string mod, int y) : make(m), model(mod), year(y) {}

    void displayV() const
    {
        cout << "Make : " << make << "\n";
        cout << "Model : " << model << "\n";
        cout << "Year : " << year << "\n";
    }
};

class Car : public Vehicle
{
protected:
    int doors;
    double fuel;

public:
    Car(string m, string mod, int y, int d, double f) : Vehicle(m, mod, y), doors(d), fuel(f) {}

    void displayC() const
    {
        Vehicle::displayV();
        cout << "Number of doors : " << doors << "\n";
        cout << "Fuel Efficiency : " << fuel << "\n";
    }
};

class ElectricCar : public Car
{
    int batterylife;

public:
    ElectricCar(string m, string mod, int y, int d, double f, int b)
        : Car(m, mod, y, d, f), batterylife(b) {}

    void displayEC() const
    {
        Car::displayC();
        cout << "Battery life : " << batterylife << "\n";
    }
};

int main()
{
    ElectricCar e1("Tesla", "Model Y", 2023, 4, 0.0, 12);
    e1.displayEC();

    return 0;
}
