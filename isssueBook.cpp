#include<iostream>
#include <string>
using namespace std;
class Date
{
    private: 
    int day; 
    int month; 
    int year; 
    public: 
    Date( void ) : day(0) , month(0) , year(0)
    {   }
    Date(int day, int month , int year) : day(day) , month(month) , year(year)
    {   }
    void acceptDate(void )
    {
        cout<<"Day : "; 
        cin>>day;
        cout<<"Month : "; 
        cin>>month; 
        cout<<"Year : "; 
        cin>>year;
    }
    void printDate( void )
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl; 
    }
}; 
class member{
    private:
    int memberId;
    string memberName;
    string memberemail;
    string memberPhone;
    Date nextpayment_duedate;
    bool paid_satatus;

    public:
    member ( void ) : memberId(0) , memberName("") , memberemail("") , memberPhone("") , paid_satatus(false)
    {   }
    member (int memberId , string memberName , string memberemail , string memberPhone , Date nextpayment_duedate , bool paid_satatus) : memberId(memberId) , memberName(memberName) , memberemail(memberemail) , memberPhone(memberPhone) , nextpayment_duedate(nextpayment_duedate) , paid_satatus(paid_satatus)
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

class issueRecord : public member{
    private:
    int issueId;
    Date issueDate;
    Date return_date;
    Date return_duedate;
    float fine_ammount;

    public:

    void paymentStatus()
    {
        if(get_paid_status())
        {
            cout<<"Payment Status : Paid"<<endl; 
        }
        else
        {
            cout<<"Payment Status : Not Paid"<<endl; 
        }
    }
    

    
};