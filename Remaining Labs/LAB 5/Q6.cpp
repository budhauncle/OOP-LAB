#include <iostream>
using namespace std;

class LoanHelper
{
    double loan;
    int months;
    const double interest;

public:
    LoanHelper(double l, int m, double i) : loan(l), months(m), interest(i) {}

    void calculate() const
    {
        // Base repayment without interest
        double basePay = loan / months;

        // Calculate total interest for the loan
        double totalInterest = loan * interest * months;

        // Monthly payment is base pay plus interest
        double monthlyPay = basePay + totalInterest / months;

        cout << "Pay " << monthlyPay << " every month for " << months << " months to repay the loan." << endl;
    }
};

int main()
{
    LoanHelper l1(12000, 12, 0.005);  // Loan of 12000 over 12 months with 0.5% interest per month
    LoanHelper l2(5000, 10, 0.003);   // Loan of 5000 over 10 months with 0.3% interest per month
    LoanHelper l3(10000, 20, 0.01);   // Loan of 10000 over 20 months with 1% interest per month

    l1.calculate();
    l2.calculate();
    l3.calculate();

    return 0;
}
