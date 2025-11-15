#include "User.h"
#include <iostream>
using namespace std;  
 
User::User() {
    id = 0;
    name = "";
    borrowedCount = 0;
    next = nullptr;
    for (int i = 0; i < MAX_BORROW; ++i)
        borrowedISBNs[i] = "";
}
 
User::User(int _id, const string& _name) {
    id = _id;
    name = _name;
    borrowedCount = 0;
    next = nullptr;
    for (int i = 0; i < MAX_BORROW; ++i)
        borrowedISBNs[i] = "";
}
 
bool User::borrowBook(const string& isbn) {
    if (borrowedCount >= MAX_BORROW) return false;

    for (int i = 0; i < MAX_BORROW; ++i) {
        if (borrowedISBNs[i] == "") {
            borrowedISBNs[i] = isbn;
            borrowedCount++;
            return true;
        }
    }
    return false;
}
 
bool User::returnBook(const string& isbn) {
    for (int i = 0; i < MAX_BORROW; ++i) {
        if (borrowedISBNs[i] == isbn) {
            borrowedISBNs[i] = "";
            borrowedCount--;
            return true;
        }
    }
    return false;
}

 
void User::printSummary() const {
    cout << "USER ID: " <<id<<endl;
    cout << "NAME: " <<name<<endl;
    cout << "BORROWED (" << borrowedCount << "): ";
    if (borrowedCount == 0) cout << "NONE"<<endl;
    else {
        for (int i = 0; i < MAX_BORROW; ++i)
            if (borrowedISBNs[i] != "")
                cout << borrowedISBNs[i] << " ";
        cout << "\n";
    }
}
