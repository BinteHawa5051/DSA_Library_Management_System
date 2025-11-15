#include "Library.h"
#include "Utility.h"
#include <iostream>
using namespace std;
Library::Library() {
    booksHead = nullptr;
    usersHead = nullptr;
    txHead = nullptr;
    nextUserId = 1;
    nextTxId = 1;
}
Library::~Library() {
    while (booksHead) { Book* tmp = booksHead->next; 
        delete booksHead; 
        booksHead = tmp; 
    }
    while (usersHead) {
         User* tmp = usersHead->next;
          delete usersHead;
           usersHead = tmp; }
    while (txHead) {
         Transaction* tmp = txHead->next;
          delete txHead;
           txHead = tmp; }
}

void Library::addBook(const string& title, const string& author, const string& isbn) {
    if (findBookByISBN(isbn)) {
         cout << "Book already exists."<<endl; 
         return; }
    Book* b = new Book(title, author, isbn);
    b->next = booksHead;
    booksHead = b;
    cout << "Book added: " << title << endl;
}

bool Library::removeBookByISBN(const string& isbn) {
    Book *cur = booksHead, *prev = nullptr;
    while (cur) {
        if (cur->isbn == isbn) {
            if (prev) prev->next = cur->next;
            else booksHead = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void Library::listAllBooks() const {
    if (!booksHead) {
         cout << "BOOK UNAVAILABLE"<<endl; 
         return; }
    for (Book* cur = booksHead; cur; cur = cur->next) {
        cur->printSummary();
        cout << "----------------"<<endl;
    }
}

void Library::searchBooksByTitle(const string& title) const {
    bool found = false;
    string lowq = toLower(title);
    for (Book* cur = booksHead; cur; cur = cur->next) {
        if (toLower(cur->title).find(lowq) != string::npos) {
            cur->printSummary(); cout << "----------------\n"; found = true;
        }
    }
    if (!found) cout << "NO MATCHING BOOKS"<<endl;
}

void Library::searchBooksByAuthor(const string& author) const {
    bool found = false;
    string lowq = toLower(author);
    for (Book* cur = booksHead; cur; cur = cur->next) {
        if (toLower(cur->author).find(lowq) != string::npos) {
            cur->printSummary(); 
            cout << "----------------"<<endl; 
            found = true;
        }
    }
    if (!found) cout << "NO MATCHING BOOKS"<<endl;
}

void Library::searchBookByISBN(const string& isbn) const {
    Book* b = findBookByISBN(isbn);
    if (b) b->printSummary();
    else cout <<  "NO MATCHING BOOKS"<<endl;
}

int Library::addUser(const string& name) {
    User* u = new User(nextUserId++, name);
    u->next = usersHead;
    usersHead = u;
    cout << "User added: " << name << " (ID: " << u->id << ")"<<endl;
    return u->id;
}

void Library::listAllUsers() const {
    if (!usersHead) { 
        cout << "USERS NTO FOUND"; 
        return;
     }
    for (User* u = usersHead; u; u = u->next) {
        u->printSummary();
        cout << "----------------"<<endl;
    }
}

Book* Library::findBookByISBN(const string& isbn) const {
    for (Book* cur = booksHead; cur; cur = cur->next)
        if (cur->isbn == isbn) return cur;
    return nullptr;
}

User* Library::findUserById(int id) const {
    for (User* u = usersHead; u; u = u->next)
        if (u->id == id)
         return u;
    return nullptr;
}

bool Library::borrowBook(int userId, const string& isbn) {
    User* u = findUserById(userId);
    Book* b = findBookByISBN(isbn);
    if (!u || !b) { 
        cout << "USER OR BOOK NOT FOUND"<<endl; 
        return false; }
    if (!b->available) { 
        cout << "BOOK ALREADY BORROWED "<<endl; 
        return false; }
    if (!u->borrowBook(isbn)) {
         cout << "USER CANNOT BORROW MORE BOOKS"<<endl;
          return false; }

    b->available = false;
    string ts = getTimestamp();
    Transaction* t = new Transaction(nextTxId++, isbn, userId, 'B', ts);
    t->next = txHead; txHead = t;
    cout << "BOOK BORROWED SUCCESFULLY"<<endl;
    return true;
}

bool Library::returnBook(int userId, const string& isbn) {
    User* u = findUserById(userId);
    Book* b = findBookByISBN(isbn);
    if (!u || !b) {
         cout << "USER OR BOOK NOT FOUND"<<endl;
          return false; }
    if (!u->returnBook(isbn)) { 
        cout << "USER DIDN'T BORROW THIS BOOK"<<endl;
         return false; }

    b->available = true;
    string ts = getTimestamp();
    Transaction* t = new Transaction(nextTxId++, isbn, userId, 'R', ts);
    t->next = txHead; txHead = t;
    cout << "BOOK RETURNED SUCCESSFULLY";
    return true;
}

void Library::listTransactions() const {
    if (!txHead) {
         cout << "NO TRANSACTIONS"; 
         return; }
    for (Transaction* t = txHead; t; t = t->next)
     t->printSummary();
}

void Library::seedSampleData() {
    addBook("M&S", "MUHAMMAD SAAD BIN MAZHAR", "123456789");
    addBook("URDU", "HUSSNAIN ASKARI", "123456798");
    addBook("Introduction to Algorithms", "Cormen et al.", "123456780");
    int u1 = addUser("Alice");
    int u2 = addUser("Bob");
    borrowBook(u1, "9780132350884");
}

void Library::sortBooksByTitle() {
    if (!booksHead || !booksHead->next) return;

    bool swapped;
    do {
        swapped = false;
        Book* cur = booksHead;
        Book* prev = nullptr;

        while (cur && cur->next) {
            if (toLower(cur->title) > toLower(cur->next->title)) {
                Book* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;

                if (prev) prev->next = tmp;
                else booksHead = tmp;

                swapped = true;
                prev = tmp;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
    } while (swapped);

    cout << "BOOKS SORTED BY TITLE"<<endl;
}
