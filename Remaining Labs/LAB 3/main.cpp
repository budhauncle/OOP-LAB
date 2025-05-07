#include "Worker.h"

int main()
{
    Worker w1, w2, w3;

    cout << "\nEnter details for Worker 1:";
    w1.inputData();
    w1.showSalary();

    cout << "\nEnter details for Worker 2:";
    w2.inputData();
    w2.showSalary();

    cout << "\nEnter details for Worker 3:";
    w3.inputData();
    w3.showSalary();

    double updatedTax;
    cout << "\nEnter updated tax rate: ";
    cin >> updatedTax;

    w1.changeTaxRate(updatedTax);
    w1.showSalary();

    w2.changeTaxRate(updatedTax);
    w2.showSalary();

    w3.changeTaxRate(updatedTax);
    w3.showSalary();

    return 0;
}
