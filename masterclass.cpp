#include<iostream>
using namespace std;
#include <vector>

class Copy{
    int id;
    int book_id;
    string rack;
    string status;

    public:
        Copy(void): id(0), book_id(0), rack(""), status(""){}
        
        Copy(int id, int book_id, string rack, string status): id(id), book_id(book_id), rack(rack), status(status){}

        void input(){
            //cout<<"Enter id: ";
            //cin>>id;
            //cout<<"Enter book_id: ";
            // cin>>book_id;
            cout<<"Enter rack: ";
            cin>>rack;
            cout<<"Enter status: ";
            cin>>status;
        }

        int getCopyId() {
            return id;
        }

        void setCopyStatus(string newStatus) {
            status = newStatus;
        }

        int getBookId() {
            return book_id;
        }

        void setBookId(int newBookId) {
            book_id = newBookId;
        }
        void setCopyId(int newId) {
            id = newId;
        }
        string getCopyRack() {
            return rack;
        }

        string getCopyStatus(){
            return status;
        }
};


class Book{
    int id;
    string title;
    string author;
    string subject;
    string isbn;
    float price;
    vector<Copy *> copies;

    public:
        Book(void): id(0), title(""), author(""), subject(""), isbn(""), price(0.0){}
        
        Book(int id, string title, string author, string subject, string isbn, float price): id(id), title(title), author(author), subject(subject), isbn(isbn), price(price){}

        void input(){
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter title: ";
            cin>>title;
            cout<<"Enter author: ";
            cin>>author;
            cout<<"Enter subject: ";
            cin>>subject;
            cout<<"Enter isbn: ";
            cin>>isbn;
            cout<<"Enter price: ";
            cin>>price;
        }
        
        void editDetails() {
            cout<<"Enter new title: ";
            cin>>title;
            cout<<"Enter new author: ";
            cin>>author;
            cout<<"Enter new subject: ";
            cin>>subject;
            cout<<"Enter new isbn: ";
            cin>>isbn;
            cout<<"Enter new price: ";
            cin>>price;
        }
        int getBookId() {
            return id;
        }

        string getBookTitle() {
            return title;
        }

        string getBookAuthor(){
            return author;
        }

        string getBookSubject() {
            return subject;
        }

        string getBookIsbn() {
            return isbn;
        }

        float getBookPrice() {
            return price;
        }

        void addCopy(Copy *copy)
    {
        copies.push_back(copy);
    }
    vector<Copy *> &getCopies()
    {
        return copies;
    }
};


class payment {
private:
    int paymentId;
    float amount;
    string type;
    time_t transaction_time;

public:
    payment(void) : paymentId(0), amount(0.0), type(""), transaction_time(0) {}

    payment(int paymentId, float amount, string type, time_t transaction_time)
        : paymentId(paymentId), amount(amount), type(type), transaction_time(transaction_time) {}
    void acceptPaymentDetails() {
        cout << "Enter Payment ID: ";
        cin >> paymentId;
        cout << "Enter Amount: ";
        cin >> amount;
        cout << "Enter Payment Type: ";
        cin >> type;
    }

    void setAmount(float newAmount) {
        amount = newAmount;
    }
    float get_Amount() {
        return amount;
    }

    void processPayment(float payment_amount, string payment_type) {
        amount = payment_amount;
        type = payment_type;
        transaction_time = time(0);

        cout << "Payment Processed: " << endl;
        cout << "Amount: " << amount << endl;
        cout << "Type: " << type << endl;
        cout << "Transaction Time: " << ctime(&transaction_time);
    }
};


class member{
    private:
    int memberId;
    string memberName;
    string memberemail;
    string memberPhone;
    time_t nextpayment_duedate;
    bool paid_satatus;
    payment paymentDetails;



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

    void editMemberDetails() {
        cout<<"Enter new Member Name : "; 
        cin>>memberName; 
        cout<<"Enter new Member Email : "; 
        cin>>memberemail; 
        cout<<"Enter new Member Phone : "; 
        cin>>memberPhone; 
    }
    void printMemberDetails()
    {
        cout<<"Member Id : "<<memberId<<endl; 
        cout<<"Member Name : "<<memberName<<endl; 
        cout<<"Member Email : "<<memberemail<<endl; 
        cout<<"Member Phone : "<<memberPhone<<endl;
    }

    void checkPaidMembership() {
        if (get_paid_status()) {
            cout <<"The member ID "<<memberId<<" With the name "<<memberName<< " Has Active Membership." << endl;
        }
    }

     void checkPaymentStatus() {
        if (get_paid_status()) {
            cout << "Payment Status : Paid" << endl;
        } else {
            float temp;
            cout << "Payment Status : Not Paid" << endl;
            cout<<"Please make the payment(100) to proceed." << endl;
            cout<<"Enter payment amount : ";
            cin>>temp;
            validatepayment(temp, "membership Payment");
                      
        }
    }
    void validatepayment(float amount, string payment_type) {
        if ( amount >= 100) {
            cout << "Payment successful. You can proceed with issuing the book." << endl;
            paymentDetails.processPayment(amount, payment_type);
            set_paid_status(true); 
        } else {
            cout << "Payment failed. Please pay the full amount to proceed." << endl;
            set_paid_status(false); 
        }
        
    }
};


class issueRecord : public member, public Copy {
private:
    int issueId;
    time_t issueDate;
    time_t return_date;
    time_t return_duedate;
    float fine_ammount;
    int memberId;
    int copyId;

public:
    issueRecord(void)
        : issueId(0), issueDate(0), return_date(0),
          return_duedate(0), fine_ammount(0.0), memberId(0), copyId(0) {}

    issueRecord(int issueId, time_t issueDate, time_t return_date,
                time_t return_duedate, float fine_ammount)
        : issueId(issueId), issueDate(issueDate),
          return_date(return_date),
          return_duedate(return_duedate),
          fine_ammount(fine_ammount), memberId(0), copyId(0) {}

    void set_MemberId(int id) {
        memberId = id;
    }
    void set_CopyId(int id) {
        copyId = id;
    }
    int get_MemberId() {
        return memberId;
    }
    int get_CopyId() {
        return copyId;
    }
    float get_FineAmount() {
        return fine_ammount;
    }
    void issueBook() {

        
        issueDate = time(0);
        // Add 7 days 
        return_duedate = issueDate + (10);
        member::set_nextpayment_duedate(return_duedate); // settiing due date for payment in member class
        cout << "Book Issued on: " << ctime(&issueDate);
        cout << "Return Due Date: " << ctime(&return_duedate);

    }

    // sets return date + fine
    void returnBook() {

        return_date = time(0);

        cout << "Book Returned on: " << ctime(&return_date);

        if (return_date > return_duedate) {
            int lateDays = (return_date - return_duedate) / ( 1);
            fine_ammount = lateDays * 5; 
        } else {
            fine_ammount = 0;
        }

        cout << "Fine Amount: " << fine_ammount << endl;
    }


    void checkOverdue() {
        time_t current_time = time(0);
        if (current_time > return_duedate) {
            cout << "The book "<<getBookId()<<" with copy ID "<<get_CopyId() <<" is overdue." << endl;
        } else {
            cout << "The book is not overdue." << endl;
        }
    }

    // void checkBookStatus(){
    //     cout<<"Checking status for Book ID "<<getBookId()<<" with Copy ID "<<get_CopyId()<<" status: "<<Copy::getCopyStatus()<<endl;
    //     if(Copy::getCopyStatus() == "issued"){
    //         cout<<"The book "<<getBookId()<<" with copy ID "<<get_CopyId()<<" is currently issued."<<endl;
    //     }
    // }

    void checkPaymentStatus() {
        if (member:: get_paid_status()) {
            cout << "Payment Status : Paid" << endl;
            //issueBook();
            //searchAvailableCopy();
        } else {
            cout << "Payment Status : Not Paid" << endl;
        }
    }

    
};

