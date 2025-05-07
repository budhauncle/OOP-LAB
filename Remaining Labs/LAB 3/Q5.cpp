#include <iostream>
using namespace std;

class Worker
{
private:
    string workerName;
    double baseSalary;
    double taxRate;

public:
    void inputData()
    {
        cout << "\nEnter worker name: ";
        cin >> workerName;
        cout << "Enter base salary: ";
        cin >> baseSalary;
        cout << "Enter tax rate: ";
        cin >> taxRate;
    }

    double calculateSalaryAfterTax()
    {
        return baseSalary * (1 - taxRate / 100);
    }

    void changeTaxRate(double newTaxRate)
    {
        taxRate = newTaxRate;
        cout << "\nTax rate updated!";
    }

    void showSalary()
    {
        cout << "\nWorker: " << workerName;
        cout << "\nSalary after tax: $" << calculateSalaryAfterTax();
    }
};

int main()
{
    Worker w1;
    w1.inputData();
    w1.showSalary();

    double updatedTax;
    cout << "\nEnter updated tax rate: ";
    cin >> updatedTax;
    w1.changeTaxRate(updatedTax);
    w1.showSalary();

    return 0;
}
