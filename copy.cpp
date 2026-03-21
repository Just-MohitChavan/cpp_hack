#include<iostream>
#include"book.cpp"
using namespace std;

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