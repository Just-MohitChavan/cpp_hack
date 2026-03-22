#include<iostream>
#include<fstream> 
#include<sstream>
#include <string>
#include <ctime>
#include<vector>
#include"masterclass.cpp"

//#include"book_load.cpp"
//#include"copy_load.cpp"
using namespace std;



int menuList(void){
    cout<<"***************************"<<endl;
    int choice; 
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Book And Copy"<<endl;
    cout<<"2. Display All Books"<<endl;
    cout<<"3. Add member"<<endl;
    cout<<"4. Issue Book"<<endl;
    cout<<"5. Display issues"<<endl;
    cout<<"6. Return Book"<<endl;
    cout<<"7. Edit Book Details"<<endl;
    cout<<"8. Edit Member Details"<<endl;
    cout<<"9. Display Members"<<endl;
    cout<<"***************************"<<endl;
    cout<<"Enter your choice - ";
    cin>>choice; 
    cout<<"***************************"<<endl;
    return choice; 
}

int searchBookById(vector<Book*> &bookVec, int id) {
    for (int i = 0; i < bookVec.size(); i++) {
        if (bookVec[i]->getBookId() == id) {
            
            return i; 
        }
    }
    return -1;
}

bool validateCopyID(vector<Copy*> &copyVec, int copyId) {
    for (int i = 0; i < copyVec.size(); i++) {
        if (copyVec[i]->getCopyId() == copyId) {
            cout<<"Copy ID already exists. Please enter a unique copy ID."<<endl;
            return true; 
        }
    }
    return false;
}

int searchMemberById(vector<member*> &memberVec, int memberId) {
    for (int i = 0; i < memberVec.size(); i++) {
        if (memberVec[i]->get_memberId() == memberId) {
            return i; 
        }
    }
    return -1;
}

int searchIssueRecord(vector<issueRecord*> &issueRecordVec, int memberId, int copyId) {
    for (int i = 0; i < issueRecordVec.size(); i++) {
        if (issueRecordVec[i]->get_MemberId() == memberId &&  issueRecordVec[i]->get_CopyId() == copyId) {
            return i; 
        }
    }
    return -1;
}

void calculateTotalFine(vector<issueRecord*> &issueRecordVec) {
    float totalFine = 0.0;
    for (int i = 0; i < issueRecordVec.size(); i++) {
        if (issueRecordVec[i]->get_FineAmount() > 0) {
            totalFine += issueRecordVec[i]->get_FineAmount();
        }
    }
    cout<<"Total Fine Collected : "<<totalFine<<endl;
}

void CheckBookStatus(vector<Book*> bookVec){
    for(int i = 0 ; i < bookVec.size( ) ; i++)
    {
        vector<Copy *> copies = bookVec[i]->getCopies();
        for (int j = 0; j < copies.size(); j++) {
                if (copies[j]->getCopyStatus() == "issued") {
                    cout<<"The book "<<bookVec[i]->getBookId()<<" with copy ID "<<copies[j]->getCopyId()<<" is currently issued."<<endl;
                }
            }
    }
}

int main(){
    cout<<"Welcome to Library Management System"<<endl;
     string username;
     string password;
    cout<<"Enter useranme : ";
   
    cin>>username;
    cout<<"Enter password : ";
    
    cin>>password;

    if(username != "admin" || password != "admin123")
    {
        cout<<"Invalid username or password. Exiting..."<<endl;
        return 0;
    }
    vector<Copy*> copyVec;
    vector<issueRecord*> issueRecordVec;
    int choice;
    int bookCopiesCount = 0;
    vector<Book*> bookVec;
    vector<member*> memberVec;
    while((choice=menuList( ))!=0)
    {
     
        switch(choice)
        {
            case 1: 
            {
                Book *book = new Book( );
                book->input( );
                bookVec.push_back(new Book(book->getBookId(), book->getBookTitle(), book->getBookAuthor(), book->getBookSubject(), book->getBookIsbn(), book->getBookPrice()));
                cout<<"Enter number of copies for the book: ";
                cin>>bookCopiesCount;
                for(int i = 0 ; i < bookCopiesCount ; i++)
                {
                    int tempCopyId ;
                    do {
                        
                        cout<<"Enter Unique copyID: ";
                        cin>>tempCopyId;
                    } while (validateCopyID(copyVec, tempCopyId));
                
                
                Copy *copy = new Copy( );
                copy->input( );
                copy->setCopyId(tempCopyId);

                copyVec.push_back(new Copy(copy->getCopyId(), book->getBookId(), copy->getCopyRack(), copy->getCopyStatus()));
                bookVec.back()->addCopy(copyVec.back());
                copy=nullptr;
                }
                book=nullptr;
                
                
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

                    vector<Copy *> copies = bookVec[i]->getCopies();
                    for (int j = 0; j < copies.size(); j++) {
                        cout << "  Copy " << j + 1 << " :" << endl;
                        cout << "    Id : " << copies[j]->getCopyId() << endl;
                        cout << "    Rack : " << copies[j]->getCopyRack() << endl;
                        cout << "    Status : " << copies[j]->getCopyStatus() << endl;
                    }
                }
            }
            break;
            case 3: 
            {
                member *mem = new member( );
                mem->acceptMemberDetails( );
                memberVec.push_back(mem);
                mem->printMemberDetails( );
            }
            
            break;
            case 4: 
            {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;

                int memberIndex = searchMemberById(memberVec, memberId);
                int bookIndex = searchBookById(bookVec, bookId);

                if (memberIndex != -1 && bookIndex != -1) {

                    if (!memberVec[memberIndex]->get_paid_status()) {
                        memberVec[memberIndex]->checkPaymentStatus();
                    }
                    if (!memberVec[memberIndex]->get_paid_status()) {
                       cout << "Member has not paid the dues. Cannot proceed with book issue." << endl;
                        break; 
                    } 
                    
                    cout << "Member has paid the dues. Proceeding with book issue." << endl;
                    vector<Copy *> copies = bookVec[bookIndex]->getCopies();
                    int copyIndex = -1;
                    for (int i = 0; i < copies.size(); i++) {
                        if (copies[i]->getCopyStatus() == "available") {
                            copyIndex = i;
                            issueRecord *issue = new issueRecord();
                            issue->set_MemberId(memberId);
                            issue->set_CopyId(copies[i]->getCopyId());
                            issue->Copy::setBookId(bookId);
                            issue->issueBook();
                            issueRecordVec.push_back(issue);
                            copies[i]->setCopyStatus("issued"); // Update copy status to issued
                            //issue->checkPaymentStatus();
                            break;
                        }
                    }
                    if (copyIndex == -1) {
                         cout << "No available copy for the book." << endl;
                    }
                } else {
                    cout << "Invalid Member ID or Book ID." << endl;
                }
            }
            break;
            case 5:
            {
                for (int i = 0; i < issueRecordVec.size(); i++) {
                    cout << "Issue Record " << i + 1 << " :" << endl;
                    cout << "  Member ID: " << issueRecordVec[i]->get_MemberId() << endl;
                    cout<< "  Book ID: " << issueRecordVec[i]->Copy::getBookId() << endl;
                    cout << "  Copy ID: " << issueRecordVec[i]->get_CopyId() << endl;
                    issueRecordVec[i]->checkOverdue();
                
                }
            }
            break;

            case 6:
            {   
                int memberId, copyId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Copy ID: ";
                cin >> copyId;

                int memberIndex = searchMemberById(memberVec, memberId);
                //int bookIndex = searchBookById(bookVec, bookId);
                int copyIndex = searchIssueRecord(issueRecordVec, memberId, copyId); // We can ignore bookId here as we are searching by copyId in issue records
                if (memberIndex != -1 && copyIndex != -1) {
                    issueRecordVec[copyIndex]->returnBook();
                    int bookId = issueRecordVec[copyIndex]->Copy::getBookId();
                    // Update the copy status to available
                    for (int i = 0; i < bookVec.size(); i++) {
                        if (bookVec[i]->getBookId() == bookId) {
                            vector<Copy *> copies = bookVec[i]->getCopies();
                            for (int j = 0; j < copies.size(); j++) {
                                if (copies[j]->getCopyId() == copyId) {
                                    copies[j]->setCopyStatus("available");
                                    cout << "Copy ID " << copyId << " is now available." << endl;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                } else {
                    cout << "Invalid Member ID or Copy ID." << endl;
                }
            }
            break;
            case 7:
            {
                cout<<"Edit Book Details - "<<endl;
                int bookId;
                cout<<"Enter Book ID to edit: ";
                cin>>bookId;
                int bookIndex = searchBookById(bookVec, bookId);
                if(bookIndex != -1)
                {
                    bookVec[bookIndex]->editDetails();
                    cout<<"Book details updated successfully."<<endl;
                }
                else
                {
                    cout<<"Book ID not found."<<endl;
                }
            }
            break;
            case 8:
            {
                cout<<"Edit Member Details - "<<endl;
                int memberId;
                cout<<"Enter Member ID to edit: ";
                cin>>memberId;
                int memberIndex = searchMemberById(memberVec, memberId);
                if(memberIndex != -1)
                {
                    memberVec[memberIndex]->editMemberDetails();
                    cout<<"Member details updated successfully."<<endl;
                }
                else
                {
                    cout<<"Member ID not found."<<endl;
                }
            }
            break;

            case 9:
            {
                cout << "Displaying Members:" << endl;
                for (int i = 0; i < memberVec.size(); i++) {
                    memberVec[i]->printMemberDetails();
                    cout << endl;
                }
            }
            break;
            default:
            {
                cout<<"Invalid choice. Please try again."<<endl;
            }
        }
    }
    cout<<"******************************"<<endl;
    cout<<"Reports For the Day :"<<endl;
    cout<<"Status Of Books : "<<endl;
    CheckBookStatus(bookVec);
    cout<<"Overdue Books : "<<endl;
    for(int i = 0 ; i < issueRecordVec.size( ) ; i++)
    {
        issueRecordVec[i]->checkOverdue();
    }
    cout<<"Members with Paid Membership : "<<endl;
    for(int i = 0 ; i < memberVec.size( ) ; i++)    {
        memberVec[i]->checkPaidMembership();
    }
    calculateTotalFine(issueRecordVec);

    return 0;
}
