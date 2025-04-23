#include <iostream>
#include <string>
using namespace std;
class SmartDevice
{
public:
    virtual ~SmartDevice() {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() const = 0;
};
class LightBulb : public SmartDevice
{
private:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(100) {}

    void turnOn() override
    {
        isOn = true;
        cout << "\nLightBulb is turned ON";
    }

    void turnOff() override
    {
        isOn = false;
        cout << "\nLightBulb is turned OFF";
    }

    void setBrightness(int level)
    {
        if (level >= 0 && level <= 100)
            brightness = level;
    }

    void getStatus() const override
    {
        cout << "\nLightBulb Status: " << (isOn ? "ON" : "OFF")<< "\nBrightness: " << brightness << "%";
    }
};
class Thermostat : public SmartDevice
{
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(22.0) {}

    void turnOn() override
    {
        isOn = true;
        cout << "\nThermostat is turned ON";
    }

    void turnOff() override
    {
        isOn = false;
        cout << "\nThermostat is turned OFF";
    }

    void setTemperature(double temp)
    {
        temperature = temp;
    }

    void getStatus() const override
    {
        cout << "\nThermostat Status: " << (isOn ? "ON" : "OFF")<<"\nTemperature: " << temperature << "°C";
    }
};

int main()
{
    const int s=2;
    SmartDevice* devices[s];
    devices[0] = new LightBulb();
    devices[1] = new Thermostat();
    devices[0]->turnOn();
    devices[1]->turnOn();
    devices[0]->getStatus();
    devices[1]->getStatus();
    devices[0]->turnOff();
    devices[1]->turnOff();
    devices[0]->getStatus();
    devices[1]->getStatus();
    for (int i = 0; i < s; ++i)
    {
        delete devices[i];
    }

    return 0;
}
