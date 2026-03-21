#include<iostream>
#include<fstream> 
#include<sstream>
#include<vector>
#include"book.cpp"
#include"copy.cpp"
using namespace std;

/*
 int id;
    string title;
    string author;
    string subject;
    string isbn;
    float price;
    */
void loadBooks(vector<Book*> book) 
{
    ifstream fin("book.txt"); 
    string line; 
    while(getline(fin , line))
    {
        stringstream data(line); 
        string id;
        string author; 
        string title;
        string subject;
        string isbn;
        string price;
        getline(data,id,',');
        getline(data,author,',');
        getline(data,title,',');
        getline(data,subject,',');
        getline(data,isbn,',');
        getline(data,price,',');
        book.push_back(new Book(stoi(id),title,author,subject,isbn,stof(price)));  
    }
    fin.close( ); 
}

void saveBooks(vector<Book*> book)
{
    ofstream fout("book.txt"); 
    for(int i = 0 ; i < book.size( ) ; i++)
    {
        Book *b; 
        b = book[i]; 
        fout<<b->getBookId( )<<","<<b->getBookTitle()<<","<<b->getBookAuthor()<<","<<b->getBookSubject()<<","<<b->getBookIsbn()<<","<<b->getBookPrice()<<endl; 
    }
    fout.close( ); 
}

int main(){
    vector<Book*> bookVec;
    loadBooks(bookVec);
    for(int i = 0 ; i < bookVec.size( ) ; i++)
    {
        Book *b; 
        b = bookVec[i]; 
        cout<<b->getBookId( )<<","<<b->getBookTitle()<<","<<b->getBookAuthor()<<","<<b->getBookSubject()<<","<<b->getBookIsbn()<<","<<b->getBookPrice()<<endl; 
    }
    saveBooks(bookVec);

    return 0;
}
