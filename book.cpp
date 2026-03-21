#include<iostream>
using namespace std;

class Book{
    int id;
    string title;
    string author;
    string subject;
    string isbn;
    float price;

    public:
        Book(void): id(0), title(""), author(""), subject(""), isbn(""), price(0.0){}
        
        Book(int id, string title, string author, string subject, string isbn, float price): id(id), title(title), author(author), subject(subject), isbn(isbn), price(price){}

        virtual void input(){
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter title: ";
            cin>>title;
            cout<<"Enter author: ";
            cin>>author;
            cout<<"Enter subject: ";
            cin>>subject;
            cout<<"Enter isbn: ";
            cin>>isbn;
            cout<<"Enter price: ";
            cin>>price;
        }

        int getBookId() {
            return id;
        }

        string getBookTitle() {
            return title;
        }

        string getBookAuthor(){
            return author;
        }

        string getBookSubject() {
            return subject;
        }

        string getBookIsbn() {
            return isbn;
        }

        float getBookPrice() {
            return price;
        }

};