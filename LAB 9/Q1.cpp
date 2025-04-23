#include <iostream>
#include <string>
using namespace std;
class Vehicle 
{
protected:
    string model;
    double rate;
public:
    Vehicle(const string& model, double rate) : model(model), rate(rate) {}
    virtual ~Vehicle() {}
    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;
};
class Car : public Vehicle 
{
public:
    Car(const string& model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() const override 
    {
        return rate;
    }

    void displayDetails() const override
    {
        cout << "\nCar Model: " << model << "\n Daily Rate:" << getDailyRate();
    }
};
class Bike : public Vehicle 
{
public:
    Bike(const string& model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() const override
    {
        return rate;
    }

    void displayDetails() const override
    {
        cout << "\nBike Model: " << model << "\nDaily Rate:" << getDailyRate();
    }
};
int main() 
{
    const int s = 2;
    Vehicle* rentals[s];
    rentals[0] = new Car("Audi R8", 200.0);
    rentals[1] = new Bike("Suzuki Hayabusa", 50.0);
    for (int i = 0; i < s; ++i) 
    {
        rentals[i]->displayDetails();
    }
    for (int i = 0; i < s; ++i)
    {
        delete rentals[i];
    }
    return 0;
}
