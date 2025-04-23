#include <iostream>
#include <string>

using namespace std;

class PaymentMethod
{
public:
    virtual ~PaymentMethod() {}
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod
{
private:
    string cardNumber;

public:
    CreditCard(const string& number)
        : cardNumber(number)
    {
    }

    void processPayment(double amount) override
    {
        if (cardNumber.length() == 16)
        {
            cout << "\nProcessing credit card payment of $" << amount;
            cout << "\nPayment successful using card ending in " << cardNumber.substr(12, 4);
        }
        else
        {
            cout << "\nInvalid credit card number. Payment failed.";
        }
    }
};

class DigitalWallet : public PaymentMethod
{
private:
    double balance;

public:
    DigitalWallet(double initialBalance)
        : balance(initialBalance)
    {
    }

    void processPayment(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "\nDigital wallet payment of $" << amount << " processed successfully";
            cout << "\nRemaining balance: $" << balance;
        }
        else
        {
            cout << "\nInsufficient funds in digital wallet. Payment failed.";
        }
    }
};

int main()
{
    CreditCard visa("1234567812345678");
    DigitalWallet wallet(150.0);

    cout << "\n--- Credit Card Transaction ---";
    visa.processPayment(50.0);

    cout << "\n\n--- Digital Wallet Transaction (Success) ---";
    wallet.processPayment(75.0);

    cout << "\n\n--- Digital Wallet Transaction (Failure) ---";
    wallet.processPayment(100.0);

    return 0;
}
