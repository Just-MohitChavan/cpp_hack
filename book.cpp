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

        void input(){
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


class Copy: public Book{
    int id;
    int book_id;
    string rack;
    string status;

    public:
        Copy(void): id(0), book_id(0), rack(""), status(""){}
        
        Copy(int id, int book_id, string rack, string status): id(id), book_id(book_id), rack(rack), status(status){}

        void input(){
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter book_id: ";
            cin>>book_id;
            cout<<"Enter rack: ";
            cin>>rack;
            cout<<"Enter status: ";
            cin>>status;
        }

        int getCopyId() {
            return id;
        }

        int getBookId() {
           return Book::getBookId();
        }

        string getCopyRack() {
            return rack;
        }

        string getCopyStatus(){
            return status;
        }
};