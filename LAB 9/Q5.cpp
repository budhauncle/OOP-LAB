#include <iostream>

using namespace std;

class Activity
{
public:
    virtual ~Activity() {}
    virtual void calculateCaloriesBurned() = 0;
};

class Running : public Activity
{
private:
    double distance;
    double time;

public:
    Running(double dist, double t)
        : distance(dist), time(t)
    {
    }

    void calculateCaloriesBurned() override
    {
        double calories = (distance * 0.063) * time;
        cout << "\nCalories burned running: " << calories << " kcal";
    }
};

class Cycling : public Activity
{
private:
    double speed;
    double time;

public:
    Cycling(double spd, double t)
        : speed(spd), time(t)
    {
    }

    void calculateCaloriesBurned() override
    {
        double calories = (speed * 0.049) * time;
        cout << "\nCalories burned cycling: " << calories << " kcal";
    }
};

int main()
{
    Running run(5.0, 30);  // 5 km in 30 minutes
    Cycling cycle(20.0, 1);  // 20 km/h for 1 hour

    cout << "\n--- Activity Calories Burned ---";
    run.calculateCaloriesBurned();
    cycle.calculateCaloriesBurned();

    return 0;
}
