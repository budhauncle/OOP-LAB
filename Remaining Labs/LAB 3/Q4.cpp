#include <iostream>
using namespace std;

class Shop
{
private:
    string products[100];
    double costs[100];
    int totalItems;

public:
    Shop() : totalItems(0) {}

    void addProduct(string product, double cost)
    {
        if (totalItems < 100)
        {
            products[totalItems] = product;
            costs[totalItems] = cost;
            totalItems++;
        }
        else
        {
            cout << "\nCannot add more products!";
        }
    }

    void listProducts()
    {
        cout << "\nAvailable Products:";
        for (int i = 0; i < totalItems; i++)
        {
            cout << "\n" << i + 1 << ". " << products[i] << " - $" << costs[i];
        }
    }

    void updateCost(int index, double newCost)
    {
        if (index >= 0 && index < totalItems)
        {
            costs[index] = newCost;
            cout << "\nPrice updated.";
        }
        else
        {
            cout << "\nInvalid product index.";
        }
    }

    void printReceipt()
    {
        int quantities[100] = {0};
        double total = 0.0;
        int choice, quantity;

        cout << "\nEnter product number and quantity (0 to finish):";
        while (true)
        {
            cin >> choice;
            if (choice == 0)
                break;
            cin >> quantity;
            if (choice > 0 && choice <= totalItems)
            {
                quantities[choice - 1] += quantity;
            }
            else
            {
                cout << "\nInvalid product number.";
            }
        }

        cout << "\nReceipt:";
        for (int i = 0; i < totalItems; i++)
        {
            if (quantities[i] > 0)
            {
                double cost = quantities[i] * costs[i];
                total += cost;
                cout << "\n" << products[i] << " x " << q
