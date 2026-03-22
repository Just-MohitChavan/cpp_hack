#include<iostream>
#include <string>
#include <ctime>
#include"book.cpp"
#include"member.cpp"
using namespace std;


class issueRecord : public member, public Copy {
private:
    int issueId;
    time_t issueDate;
    time_t return_date;
    time_t return_duedate;
    float fine_ammount;

public:
    issueRecord(void)
        : issueId(0), issueDate(0), return_date(0),
          return_duedate(0), fine_ammount(0.0) {}

    issueRecord(int issueId, time_t issueDate, time_t return_date,
                time_t return_duedate, float fine_ammount)
        : issueId(issueId), issueDate(issueDate),
          return_date(return_date),
          return_duedate(return_duedate),
          fine_ammount(fine_ammount) {}

    //Issue book sets current date + due date
    void issueBook() {

        
        issueDate = time(0);
        // Add 7 days 
        return_duedate = issueDate + (7 * 24 * 60 * 60);
        member::set_nextpayment_duedate(return_duedate); // settiing due date for payment in member class
        cout << "Book Issued on: " << ctime(&issueDate);
        cout << "Return Due Date: " << ctime(&return_duedate);
    }

    // 🔹 Return book → sets return date + fine
    void returnBook() {
        return_date = time(0);

        cout << "Book Returned on: " << ctime(&return_date);

        if (return_date > return_duedate) {
            int lateDays = (return_date - return_duedate) / (24 * 60 * 60);
            fine_ammount = lateDays * 5; // ₹5 per day fine
        } else {
            fine_ammount = 0;
        }

        cout << "Fine Amount: " << fine_ammount << endl;
    }

    void checkPaymentStatus() {
        if (member:: get_paid_status()) {
            cout << "Payment Status : Paid" << endl;
            //searchAvailableCopy();
        } else {
            cout << "Payment Status : Not Paid" << endl;
        }
    }

    
};
