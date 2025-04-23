#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string isbn;

public:
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn)
    {
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getISBN() const
    {
        return isbn;
    }
};

int main()
{
    Book book("The Alchemist", "Paulo Coelho", "978-0061122415");

    cout << "\nBook Details:";
    cout << "\nTitle: " << book.getTitle();
    cout << "\nAuthor: " << book.getAuthor();
    cout << "\nISBN: " << book.getISBN();

    return 0;
}
