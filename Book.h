#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
using namespace std;
class Book {
public:
    string title;
    string author;
    string isbn;
    bool available;
    Book* next;   
 
    Book();  
    Book(const string& _title, const string& _author, const string& _isbn);

  
    void printSummary() const;
};

#endif  
