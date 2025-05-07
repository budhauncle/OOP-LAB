#include <iostream>
using namespace std;

class Book
{
protected:
    string title, author, publisher;

public:
    Book(string t, string a, string p) : title(t), author(a), publisher(p) {}

    void display()
    {
        cout << "Book Information: \n";
        cout << "------------------------\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class FictionBook : public Book
{
    string genre, protagonist;

public:
    FictionBook(string t, string a, string p, string g, string pr) : Book(t, a, p)
    {
        genre = g;
        protagonist = pr;
    }

    void display()
    {
        cout << "\nFiction Book Information: \n";
        cout << "----------------------------\n";
        Book::display();  // Calling the base class display
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main()
{
    FictionBook b("Game of Thrones", "George RR Martin", "Crown Publishers", "Fantasy", "Jon Snow");
    b.display();

    return 0;
}
