#include <iostream>
using namespace std;

class Airport
{
public:
    string name;
    string location;

    Airport() {}
    Airport(string n, string l) : name(n), location(l) {}

    void display() const
    {
        cout << name << " (" << location << ")" << endl;
    }
};

class Flight
{
    string flightno;
    Airport origin;
    Airport destination;
    Airport stops[5];
    int sc; // stops array counter

public:
    Flight(string fn, Airport o, Airport d) : flightno(fn), origin(o), destination(d), sc(0) {}

    void addStop(const Airport &stop)
    {
        if (sc < 5)
        {
            stops[sc++] = stop;
        }
        else
        {
            cout << "Maximum stopovers reached" << endl;
        }
    }

    void takeoff() const
    {
        cout << "Flight " << flightno << " is taking off from ";
        origin.display();
    }

    void land(const Airport &location) const
    {
        cout << "Flight " << flightno << " is landing at ";
        location.display();
    }

    void display() const
    {
        cout << "Flight number: " << flightno << endl;
        cout << "Origin: ";
        origin.display();
        cout << "Destination: ";
        destination.display();
        cout << "Stopovers: " << endl;
        for (int i = 0; i < sc; i++)
        {
            stops[i].display();
        }
    }
};

int main()
{
    Airport karachi("Jinnah", "Karachi");
    Airport islamabad("Islamabad International", "Islamabad");
    Airport london("Heathrow", "London");

    Flight pk303("PK 303", karachi, london);

    pk303.takeoff();
    pk303.addStop(islamabad);
    pk303.land(islamabad);
    pk303.land(london);

    cout << "\nFlight Details:" << endl;
    pk303.display();

    return 0;
}
