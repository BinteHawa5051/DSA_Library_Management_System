#ifndef USER_H
#define USER_H

#include <string>
using namespace std;   

const int MAX_BORROW = 10;

class User {
public:
    int id;
    string name;
    string borrowedISBNs[MAX_BORROW];
    int borrowedCount;
    User* next;
 
    User();
    User(int _id, const string& _name);

   
    bool borrowBook(const string& isbn);
    bool returnBook(const string& isbn);
 
    void printSummary() const;
};

#endif
