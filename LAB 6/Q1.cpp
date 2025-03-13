#include <iostream>
using namespace std;

class Book
{
    protected:
        string author,title,publisher;

    public:
        Book(string t, string a, string p) : title(t), author(a), publisher(p) {}

        void display()
        {
            cout<<"\nAuthor:"<<author;
            cout<<"\nTitle:"<<title;
            cout<<"\nPublisher:"<<publisher;
        }
};

class FictionBook : public Book
{
    string genre, protag;

    public:
        FictionBook(string t, string a, string pub, string g, string pr) : Book(t,a,pub)
        {
            genre = g;
            protag = pr;
        }

        void display()
        {
            Book::display();
            cout<<"\nGenre:"<<genre;
            cout<<"\nProtagonist:"<<protag;
        }
};

int main()
{
    FictionBook b1("The Alchemist","Paulo Coelho","Harper Collins","Adventure","Santiago");
    b1.display();
    return 0;
}