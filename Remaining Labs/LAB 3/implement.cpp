#include "Worker.h"

void Worker::inputData()
{
    cout << "Enter worker name: ";
    cin >> workerName;
    cout << "Enter base salary: ";
    cin >> baseSalary;
    cout << "Enter tax rate: ";
    cin >> taxRate;
}

double Worker::calculateSalaryAfterTax()
{
    return baseSalary * (1 - taxRate / 100);
}

void Worker::changeTaxRate(double newTaxRate)
{
    taxRate = newTaxRate;
    cout << "\nNew tax rate applied!";
}

void Worker::showSalary()
{
    cout << "\nWorker: " << workerName;
    cout << "\nSalary after tax: $" << calculateSalaryAfterTax();
}
