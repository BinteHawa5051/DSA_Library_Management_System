#include "Transaction.h"
#include <iostream>
using namespace std; 
 
Transaction::Transaction() {
    id = 0;
    isbn = "";
    userId = 0;
    type = 'B';
    timestamp = "";
    next = nullptr;
}

 
Transaction::Transaction(int _id, const string& _isbn, int _userId, char _type, const string& _ts) {
    id = _id;
    isbn = _isbn;
    userId = _userId;
    type = _type;
    timestamp = _ts;
    next = nullptr;
}
 
void Transaction::printSummary() const {
    cout << "[" << id << "] " << (type == 'B' ? "BORROW" : "RETURN")
         << " | ISBN: " << isbn
         << " | UserID: " << userId
         << " | Time: " << timestamp << "\n";
}
