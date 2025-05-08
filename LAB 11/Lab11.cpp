#include <iostream>
#include <string>
using namespace std;

// Task 01
template <typename T>
void swapValues(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void Task1()
{
    cout << "\nTask 1: Swapping variables\n";
    int a = 5, b = 10;
    cout << "\nBefore: a = " << a << ", b = " << b;
    swapValues(a, b);
    cout << "\nAfter: a = " << a << ", b = " << b;

    float x = 3.5f, y = 7.8f;
    cout << "\nBefore: x = " << x << ", y = " << y;
    swapValues(x, y);
    cout << "\nAfter: x = " << x << ", y = " << y;

    char c = 'A', d = 'B';
    cout << "\nBefore: c = " << c << ", d = " << d;
    swapValues(c, d);
    cout << "\nAfter: c = " << c << ", d = " << d << "\n";
}

// Task 02
void Task2()
{
    cout << "\nTask 2: Division with error checking\n";
    int num, den;
    cout << "\nEnter numerator: ";
    cin >> num;
    cout << "\nEnter denominator: ";
    cin >> den;

    try {
        if (den == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }
        cout << "\nResult is: " << num / den << "\n";
    } catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << "\n";
    }
}

// Task 03
template <typename T1, typename T2>
class Pair
{
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    void display()
    {
        cout << "\nPair => (" << first << ", " << second << ")";
    }
};

void Task3()
{
    cout << "\nTask 3: Generic Pair class\n";
    Pair<int, string> p1(1, "Hello");
    p1.display();

    Pair<double, char> p2(3.14, 'A');
    p2.display();
    cout << "\n";
}

// Task 04
class InsufficientFundsException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Insufficient funds in the account.";
    }
};

class BankAccount
{
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount)
    {
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "\nWithdraw successful. New balance: " << balance;
    }

    void showBalance() const
    {
        cout << "\nCurrent balance: " << balance;
    }
};

void Task4()
{
    cout << "\nTask 4: BankAccount withdrawal\n";
    BankAccount account(500);
    account.showBalance();

    try {
        double amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        account.withdraw(amount);
    } catch (const InsufficientFundsException& e) {
        cout << "\nError: " << e.what();
    }
    cout << "\n";
}

// Task 05
template <typename T>
T findMax(T arr[], int size)
{
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void Task5()
{
    cout << "\nTask 5: Finding maximum value\n";
    int intArr[] = {1, 2, 3, 4, 5};
    cout << "\nMax (int): " << findMax(intArr, 5);

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "\nMax (double): " << findMax(doubleArr, 5);

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    cout << "\nMax (char): " << findMax(charArr, 5) << "\n";
}

// Task 06
class InvalidAgeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "age must be between 1 and 120.";
    }
};

class InvalidSalaryException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "salary must be greater than 0.";
    }
};

class InvalidHeightException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "height must be greater than 0.";
    }
};

void Task6()
{
    cout << "\nTask 6: Validating user profile\n";

    try {
        int age;
        cout << "\nEnter age: ";
        cin >> age;
        if (age < 1 || age > 120) {
            throw InvalidAgeException();
        }

        double salary;
        cout << "\nEnter salary: ";
        cin >> salary;
        if (salary <= 0) {
            throw InvalidSalaryException();
        }

        double height;
        cout << "\nEnter height: ";
        cin >> height;
        if (height <= 0) {
            throw InvalidHeightException();
        }

        cout << "\nProfile validation passed.";
    } catch (InvalidAgeException& e) {
        cout << "\nInvalid age: " << e.what();
    } catch (InvalidSalaryException& e) {
        cout << "\nInvalid salary: " << e.what();
    } catch (InvalidHeightException& e) {
        cout << "\nInvalid height: " << e.what();
    }

    cout << "\n";
}

// Task 07
class OutoFBoundsException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Index out of bounds.";
    }
};

template <typename T>
class SmartArray
{
    T* arr;
    int size;

public:
    SmartArray(int s) : size(s)
    {
        arr = new T[size];
    }

    ~SmartArray()
    {
        delete[] arr;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= size) {
            throw OutoFBoundsException();
        }
        return arr[index];
    }
};

void Task7()
{
    cout << "\nTask 7: Using SmartArray\n";
    int size = 5;
    SmartArray<int> arr(size);

    cout << "\nEnter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    try {
        cout << "\nElement at index 2: " << arr[2];
        cout << "\nElement at index 5: " << arr[5]; // Will trigger exception
    } catch (OutoFBoundsException& e) {
        cout << "\nAccess error: " << e.what();
    }

    cout << "\n";
}

int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
    Task6();
    Task7();
    return 0;
}
