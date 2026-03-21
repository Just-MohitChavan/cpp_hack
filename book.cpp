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

        int getBookId() const{
            return id;
        }

        string getBookTitle() const{
            return title;
        }

        string getBookAuthor() const{
            return author;
        }

        string getBookSubject() const{
            return subject;
        }

        string getBookIsbn() const{
            return isbn;
        }

        float getBookPrice() const{
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
            Book::input();
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter book_id: ";
            cin>>book_id;
            cout<<"Enter rack: ";
            cin>>rack;
            cout<<"Enter status: ";
            cin>>status;
        }

        int getCopyId() const{
            return id;
        }

        int getBookId() const{
            Book::getBookId();
        }

        string getCopyRack() const{
            return rack;
        }

        string getCopyStatus() const{
            return status;
        }
};