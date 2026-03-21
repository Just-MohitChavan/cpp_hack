#include<iostream>
#include<fstream> 
#include<sstream>
#include<vector>
#include"book.cpp"

//#include"book_load.cpp"
//#include"copy_load.cpp"
using namespace std;

int menuList(void){
    cout<<"***************************"<<endl;
    int choice; 
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Book And Copy"<<endl;
    cout<<"2. Display All Books"<<endl;
    cout<<"3. Check Copy Status"<<endl;
    cout<<"4. Delete Book"<<endl;
    cout<<"Enter your choice - ";
    cin>>choice; 
    cout<<"***************************"<<endl;
    return choice; 
}

int main(){
    vector<Copy*> copyVec;
    int choice;
    
    while((choice=menuList( ))!=0)
    {
     
        switch(choice)
        {
            case 1: 
            {

                Copy *copy = new Copy( );
                copy->input( );
                copyVec.push_back(copy);
            }
            break; 
            case 2: 
            {
                for(int i = 0 ; i < bookVec.size( ) ; i++)
                {
                    cout<<"Book "<<i+1<<" : "<<endl;
                    cout<<"Id : "<<bookVec[i]->getBookId( )<<endl;
                    cout<<"Title : "<<bookVec[i]->getBookTitle( )<<endl;
                    cout<<"Author : "<<bookVec[i]->getBookAuthor( )<<endl;
                    cout<<"Subject : "<<bookVec[i]->getBookSubject( )<<endl;
                    cout<<"ISBN : "<<bookVec[i]->getBookIsbn( )<<endl;
                    cout<<"Price : "<<bookVec[i]->getBookPrice( )<<endl;
                }
            }
            break;
        }
    }

    return 0;
}
