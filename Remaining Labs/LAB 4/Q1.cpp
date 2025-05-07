#include <iostream>
#include <string>
using namespace std;

class Novel
{
private:
    string bookTitle;
    string bookAuthor;
    double bookPrice;

public:
    Novel() : bookTitle("Untitled"), bookAuthor("Anonymous"), bookPrice(0.0) {}
    Novel(string t, string a, double p) : bookTitle(t), bookAuthor(a), bookPrice(p) {}
    Novel(const Novel &other) : bookTitle(other.bookTitle), bookAuthor(other.bookAuthor), bookPrice(other.bookPrice) {}

    void displayDetails() const
    {
        cout << "Title: " << bookTitle << " | Author: " << bookAuthor << " | Price: $" << bookPrice << endl;
    }
};

int main()
{
    Novel n1;
    cout << "Default Constructor:\n";
    n1.displayDetails();

    Novel n2("Fire and Blood", "RR MARTIN", 10.99);
    cout << "\nParameterized Constructor:\n";
    n2.displayDetails();

    Novel n3(n2);
    cout << "\nCopy Constructor:\n";
    n3.displayDetails();

    return 0;
}
