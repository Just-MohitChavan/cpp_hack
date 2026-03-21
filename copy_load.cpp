#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"book.cpp"
#include"copy.cpp"
using namespace std;

void loadCopies(vector<Copy*> copy) 
{
    ifstream fin("data_store/copy.txt"); 
    string line; 
    while(getline(fin , line))
    {
        stringstream data(line); 
        string id;
        string book_id; 
        string rack;
        string status;
        getline(data,id,',');
        getline(data,book_id,',');
        getline(data,rack,',');
        getline(data,status,',');
        copy.push_back(new Copy(stoi(id),stoi(book_id),rack,status));  
    }
    fin.close( ); 
}

void saveCopies(vector<Copy*> copy)
{
    ofstream fout("data_store/copy.txt"); 
    for(int i = 0 ; i < copy.size( ) ; i++)
    {
        Copy *c; 
        c = copy[i]; 
        fout<<c->getCopyId( )<<","<<c->getBookId()<<","<<c->getCopyRack()<<","<<c->getCopyStatus()<<endl; 
    }
    fout.close( ); 
}
