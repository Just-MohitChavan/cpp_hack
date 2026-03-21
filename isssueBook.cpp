#include<iostream>
#include <string>
#include <ctime>
#include"copy.cpp"

using namespace std;


class member{
    private:
    int memberId;
    string memberName;
    string memberemail;
    string memberPhone;
    time_t nextpayment_duedate;
    bool paid_satatus;

    public:
    member ( void ) : memberId(0) , memberName("") , memberemail("") , memberPhone("") , paid_satatus(false)
    {   }
    member (int memberId , string memberName , string memberemail , string memberPhone , time_t nextpayment_duedate , bool paid_satatus) : memberId(memberId) , memberName(memberName) , memberemail(memberemail) , memberPhone(memberPhone) , nextpayment_duedate(nextpayment_duedate) , paid_satatus(paid_satatus)
    {   }

    bool get_paid_status()
    {
        return paid_satatus;
    }
    int get_memberId()
    {
        return memberId;
    }
    
    void acceptMemberDetails()
    {
        cout<<"Enter Member Id : "; 
        cin>>memberId; 
        cout<<"Enter Member Name : "; 
        cin>>memberName; 
        cout<<"Enter Member Email : "; 
        cin>>memberemail; 
        cout<<"Enter Member Phone : "; 
        cin>>memberPhone; 
    }
    void printMemberDetails()
    {
        cout<<"Member Id : "<<memberId<<endl; 
        cout<<"Member Name : "<<memberName<<endl; 
        cout<<"Member Email : "<<memberemail<<endl; 
        cout<<"Member Phone : "<<memberPhone<<endl;
    }
};

class issueRecord : public member, public Copy{
    private:
    int issueId;
    time_t issueDate;
    time_t return_date;
    time_t return_duedate;
    float fine_ammount;

    public:
    issueRecord ( void ) : issueId(0) , issueDate(0) , return_date(0) , return_duedate(0) , fine_ammount(0.0)
    {   }
    issueRecord (int issueId , time_t issueDate , time_t return_date , time_t return_duedate , float fine_ammount) : issueId(issueId) , issueDate(issueDate) , return_date(return_date) , return_duedate(return_duedate) , fine_ammount(fine_ammount)
    {   }

    void checkPaymentStatus()
    {
        if(get_paid_status())
        {
            cout<<"Payment Status : Paid"<<endl; 
            searchAvailableCopy();
        }
        else
        {
            cout<<"Payment Status : Not Paid"<<endl; 
        }
    }
    void searchAvailableCopy () 
    {
        cout<<"Searching for available copy of the book..."<<endl; 
        if(Copy::getCopyStatus()=="available") 
        {
            cout<<"Available copy found. You can issue the book."<<endl; 
            

            
        }
        else
        {
            cout<<"No available copy found. Please try again later."<<endl; 
        }

    }



    
};