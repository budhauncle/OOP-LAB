#include <iostream>
using namespace std;

class Bottle
{
private:
    string brand;
    string shade;
    double volumeLiters;
    int volumeMilliliters;

public:
    void setDetails(string b, string s, double volL)
    {
        brand = b;
        shade = s;
        volumeLiters = volL;
        volumeMilliliters = volL * 1000;
    }

    string getBrand() { return brand; }
    string getShade() { return shade; }
    double getVolumeLiters() { return volumeLiters; }
    int getVolumeMilliliters() { return volumeMilliliters; }

    void consumeWater(int amountML)
    {
        if (amountML <= volumeMilliliters)
        {
            volumeMilliliters -= amountML;
            volumeLiters = volumeMilliliters / 1000.0;
            cout << "\nConsumed " << amountML << " ml of water";
        }
        else
        {
            cout << "\nNot enough water remaining";
        }
    }
};

int main()
{
    Bottle b1;
    string brandInput, shadeInput;
    double volumeInput;
    int drinkAmountInput;

    cout << "\nEnter bottle brand: ";
    cin >> brandInput;
    cout << "Enter bottle shade: ";
    cin >> shadeInput;
    cout << "Enter bottle volume in liters: ";
    cin >> volumeInput;

    b1.setDetails(brandInput, shadeInput, volumeInput);

    cout << "\nBottle Information:";
    cout << "\nBrand: " << b1.getBrand();
    cout << "\nShade: " << b1.getShade();
    cout << "\nVolume: " << b1.getVolumeLiters() << " L (" << b1.getVolumeMilliliters() << " ml)";

    cout << "\n\nEnter water to consume (ml): ";
    cin >> drinkAmountInput;
    b1.consumeWater(drinkAmountInput);

    cout << "\nRemaining volume: " << b1.getVolumeLiters() << " L (" << b1.getVolumeMilliliters() << " ml)";

    return 0;
}
