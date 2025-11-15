#include <iostream>
#include "Library.h"
#include "Utility.h"

using namespace std;

int mainMenu() {
    cout << "\n===== LIBRARY MANAGEMENT SYSTEM=====\n";
    cout << "1. Add Book\n2. List All Books\n3. Search Book by Title\n4. Search Book by Author\n";
    cout << "5. Search Book by ISBN\n6. Sort Books by Title\n7. Add User\n8. List Users\n";
    cout << "9. Borrow Book\n10. Return Book\n11. List Transactions\n12. Seed Sample Data\n";
    cout << "0. Exit\nChoose: ";

    int choice;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    cin.ignore(10000, '\n');
    return choice;
}

int main() {
    Library lib;
    string input;

    while (true) {
        int choice = mainMenu();
        if (choice == -1) { 
            cout << "INVALID INPUT"<<endl;
             continue; }
        if (choice == 0) break;

        switch(choice) {
            case 1: {  
                cout << "ENTER TITLE OF THE BOOK";
                string title; 
                getline(cin, title);

                cout << "ENTER AUTHOR OF THE BOOK ";
                string author; 
                getline(cin, author);

                cout << "ENTER ISBN OF THE BOOK ";
                string isbn; 
                getline(cin, isbn);

                lib.addBook(title, author, isbn);
                break;
            }

            case 2: {  
                lib.listAllBooks();
                break;
            }

            case 3: { 
                cout << "ENTER PART OF THE TITLE ";
                string title; 
                getline(cin, title);
                lib.searchBooksByTitle(title);
                break;
            }

            case 4: {  
                cout << "ENTER PART OF THE AUTHOR";
                string author; 
                getline(cin, author);
                lib.searchBooksByAuthor(author);
                break;
            }

            case 5: {  
                cout << "ENTER ISBN OF THE BOOK ";
                string isbn; 
                getline(cin, isbn);
                lib.searchBookByISBN(isbn);
                break;
            }

            case 6: {  
                lib.sortBooksByTitle();
                break;
            }

            case 7: {  
                cout << "ENTER USER NAME ";
                string name;
                getline(cin, name);
                lib.addUser(name);
                break;
            }

            case 8: {  
                lib.listAllUsers();
                break;
            }

            case 9: { 
                cout << "ENTER USER ID ";
                int userId; 
                cin >> userId; 
                cin.ignore(10000, '\n');

                cout << "ENTER ISBNN OF THE BOOK BORROW : ";
                string isbn; 
                getline(cin, isbn);

                lib.borrowBook(userId, isbn);
                break;
            }

            case 10: { 
                cout << "ENTER USER ID ";
                int userId; 
                cin >> userId; 
                cin.ignore(10000, '\n');

                cout << "ENTER ISBN OF THE BOOK TO RETURN ";
                string isbn; 
                getline(cin, isbn);

                lib.returnBook(userId, isbn);
                break;
            }

            case 11: {  
                lib.listTransactions();
                break;
            }

            case 12: {  
                lib.seedSampleData();
                break;
            }

            default:
                cout << "UNKNOWN ";
                break;
        }
    }

    cout << "EXISTING.........................";
    return 0;
}
