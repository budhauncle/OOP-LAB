#include <iostream>
#include <string>
using namespace std;

class Gadget
{
private:
    string gadgetName;
    string gadgetType;
    bool isActive;

public:
    Gadget(string name, string type, bool active)
    {
        gadgetName = name;
        gadgetType = type;
        isActive = active;
        cout << gadgetName << "(" << gadgetType << ") has been powered" << (isActive ? "ON" : "OFF") << "\n";
    }
    ~Gadget()
    {
        cout << gadgetName << "(" << gadgetType << ") is powering down...Goodbye!" << "\n";
    }
};

int main()
{
    Gadget *light = new Gadget("SAGA", "Smart Light", true);
    Gadget *vacuum = new Gadget("REDMI", "Vacuum", false);
    Gadget *coffee = new Gadget("EXPRESSO", "Coffee overlord", true);

    cout << "Devices are running\n";

    delete light;
    delete vacuum;
    delete coffee;

    cout << "All devices powered down\n";

    return 0;
}
