#ifndef WORKER_H
#define WORKER_H

#include <iostream>
using namespace std;

class Worker
{
private:
    string workerName;
    double baseSalary;
    double taxRate;

public:
    void inputData();
    double calculateSalaryAfterTax();
    void changeTaxRate(double newTaxRate);
    void showSalary();
};

#endif
