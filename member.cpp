#include<iostream>
#include <string>
#include <ctime>
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

    void set_paid_status(bool status)
    {
        paid_satatus = status;
    }

    void set_nextpayment_duedate(time_t due_date)
    {
        nextpayment_duedate = due_date;
    }

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
