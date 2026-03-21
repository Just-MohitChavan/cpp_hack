#include<iostream>
#include<fstream> 
#include<sstream>
#include<vector>
#include"book.cpp"
#include"copy.cpp"
#include"book_load.cpp"
#include"copy_load.cpp"
using namespace std;


int main(){
    vector<Book*> bookVec;
    loadBooks(bookVec);
    saveBooks(bookVec);

    vector<Copy*> copyVec;
    loadCopies(copyVec);
    saveCopies(copyVec);

    return 0;
}
