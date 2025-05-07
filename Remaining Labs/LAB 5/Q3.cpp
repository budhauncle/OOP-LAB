#include <iostream>
using namespace std;

class MenuItem
{
public:
    string name;
    double price;

    MenuItem() {}
    MenuItem(string n, double p) : name(n), price(p) {}
};

class Menu
{
    MenuItem items[10];
    int ic; // item counter

public:
    Menu() : ic(0) {}

    void additem(const string &n, double p)
    {
        if (ic < 10)
        {
            items[ic++] = MenuItem(n, p);
        }
        else
        {
            cout << "Menu full" << endl;
        }
    }

    void displayMenu() const
    {
        for (int i = 0; i < ic; i++)
        {
            cout << i + 1 << "." << items[i].name << "-Rs" << items[i].price << endl;
        }
    }

    MenuItem getitem(int i) const
    {
        if (i >= 0 && i < ic)
        {
            return items[i];
        }
        return MenuItem(); // Return default object if index is invalid
    }
};

class Payment
{
    double amount;

public:
    Payment(double a) : amount(a) {}

    void displayPayment() const
    {
        cout << "Total Payment : Rs" << amount << endl;
    }
};

class Order
{
    MenuItem orderitems[10];
    int oc;       // order counter
    double total; // total cost

public:
    Order() : oc(0), total(0) {}

    void additem(const MenuItem &item)
    {
        if (oc < 10)
        {
            orderitems[oc++] = item;
            total += item.price;
        }
        else
        {
            cout << "Order Full" << endl;
        }
    }

    void displayOrder() const
    {
        cout << "Order Details:" << endl;
        for (int i = 0; i < oc; i++)
        {
            cout << orderitems[i].name << " - Rs" << orderitems[i].price << endl;
        }
        Payment pay(total);
        pay.displayPayment();
    }
};

int main()
{
    Menu m;
    m.additem("Burger", 700);
    m.additem("Pizza", 1000);
    m.additem("Fries", 300);

    cout << "Menu: " << endl;
    m.displayMenu();

    Order o;
    o.additem(m.getitem(0)); // Burger
    o.additem(m.getitem(1)); // Pizza

    o.displayOrder();

    return 0;
}
