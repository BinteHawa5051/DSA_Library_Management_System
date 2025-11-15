#include "Book.h"


Book::Book() {
    title = "";
    author = "";
    isbn = "";
    available = true;
    next = nullptr; 
}
 
Book::Book(const string& _title, const string& _author, const string& _isbn) {
    title = _title;
    author = _author;
    isbn = _isbn;
    available = true;
    next = nullptr;  
}
 
void Book::printSummary() const {
    cout << "TITLE OF THE BOOK ==>: " << title <<endl;
    cout << "Author OF THE BOOK ==>: " << author << endl;
    cout << "ISBN OF THE BOOK ==>: " << isbn <<endl;
    cout << "Status OF THE BOOK ==>: " << (available ? "Available" : "Borrowed") <<endl;
}
