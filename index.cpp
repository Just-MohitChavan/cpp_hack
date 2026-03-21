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
        string author;
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

int main(){
    vector<Book*> bookVec;

    return 0;
}
