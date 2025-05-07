#include <iostream>
using namespace std;

class MarkerTool
{
private:
    string brand;
    string shade;
    bool canRefill;
    bool hasInk;

public:
    string getBrand()
    {
        return brand;
    }

    string getShade()
    {
        return shade;
    }

    bool isRefillable()
    {
        return canRefill;
    }

    bool hasInkAvailable()
    {
        return hasInk;
    }

    void setSpecs(string b, string s, bool refill, bool ink)
    {
        brand = b;
        shade = s;
        canRefill = refill;
        hasInk = ink;
    }

    void makeMark()
    {
        if (hasInk)
        {
            cout << "\nWriting initiated";
            hasInk = false;
        }
        else
        {
            cout << "\nNo ink left";
        }
    }

    void refillMarker()
    {
        if (canRefill)
        {
            hasInk = true;
            cout << "\nRefilled successfully";
        }
        else
        {
            cout << "\nCannot be refilled";
        }
    }
};

int main()
{
    MarkerTool mark1, mark2, mark3;

    mark1.setSpecs("Alpha", "green", true, true);
    mark2.setSpecs("Beta", "orange", false, true);
    mark3.setSpecs("Gamma", "purple", true, false);

    mark1.makeMark();
    mark1.makeMark();
    mark1.refillMarker();
    mark1.makeMark();

    mark2.makeMark();
    mark2.makeMark();
    mark2.refillMarker();

    mark3.makeMark();
    mark3.refillMarker();
    mark3.makeMark();

    return 0;
}
