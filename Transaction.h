#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std; 

class Transaction {
public:
    int id;
    string isbn;
    int userId;
    char type;  
    string timestamp;
    Transaction* next;
 
    Transaction();
    Transaction(int _id, const string& _isbn, int _userId, char _type, const string& _ts);
 
    void printSummary() const;
};

#endif
