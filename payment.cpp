#include<iostream>
#include <string>
#include <ctime>
#include"member.cpp"
using namespace std;

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

    void processPayment(float fine_amount, string payment_type) {
        amount = fine_amount;
        type = payment_type;
        transaction_time = time(0);

        cout << "Payment Processed: " << endl;
        cout << "Amount: " << amount << endl;
        cout << "Type: " << type << endl;
        cout << "Transaction Time: " << ctime(&transaction_time);
    }
};