# **Library Management System**
## **Modular C++ Project using Linked Lists and Stacks**

---

## **1. Project Overview**

This Library Management System is developed for the Open-Ended Lab (OEL) under the **Data Structures & Algorithms** course.  
The application demonstrates the use of:

- Object-Oriented Programming (OOP)  
- Linked Lists  
- Stacks  
- Modular Program Architecture  

The system manages **books**, **users**, and **transactions** efficiently.

### **Core Functionalities**
- Book cataloging  
- User registration  
- Borrow and return handling  
- Transaction logging with timestamps  
- Searching and sorting operations  

---

## **2. Features**

### **Book Management**
- Add new books  
- Search by title, author, or ISBN  
- Delete books  
- List all books  
- Sort books alphabetically (by Title)  
- Manage availability status  

### **User Management**
- Add new users  
- List all users  
- Track borrowed books  
- Borrow limit enforcement (max 10 books per user)  

### **Borrow & Return Operations**
- Borrow book  
- Return book  
- Validation checks:  
  - Book availability  
  - User existence  
  - Borrow limit  
  - Ownership verification  

### **Transaction Handling**
- Stack-based transaction history  
- Timestamps for each entry  
- Reverse-chronological display  

---

## **3. Data Structures Used**

### **Linked List**
Used for managing:
- Books  
- Users  
- Transactions  

### **Stack**
Used for:
- Transaction history (LIFO)  

---

## **4. File and Module Structure**

```
LibraryManagementSystem/
│
├── Book.cpp
├── Book.h
├── User.cpp
├── User.h
├── Transaction.cpp
├── Transaction.h
├── Library.cpp
├── Library.h
├── Utility.cpp
├── Utility.h
├── main.cpp
├── settings.json
└── vscode/
```

### **Module Responsibilities**

| File | Purpose |
|------|---------|
| **Book.cpp / Book.h** | Book entity, attributes, linked list node |
| **User.cpp / User.h** | User entity, borrowing logic |
| **Transaction.cpp / Transaction.h** | Transaction record and stack operations |
| **Library.cpp / Library.h** | Core management logic and system operations |
| **Utility.cpp / Utility.h** | Helper utilities (validation, formatting, timestamps) |
| **main.cpp** | Console-based user interface |

---

## **5. Compilation and Execution**

### **Compilation Command**
```bash
g++ main.cpp Library.cpp Utility.cpp Book.cpp User.cpp Transaction.cpp -o main
```

### **Run Program**

#### **Windows**
```bash
.\main.exe
```

#### **Linux/macOS**
```bash
./main
```

---

## **6. Application Menu**

```
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. List All Books
3. Search Book by Title
4. Search Book by Author
5. Search Book by ISBN
6. Sort Books by Title
7. Add User
8. List Users
9. Borrow Book
10. Return Book
11. List Transactions
12. Seed Sample Data
0. Exit
```

---

## **7. Algorithmic Complexity**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Book/User Search | O(n) | Linked list traversal |
| Sorting Books | O(n²) | Bubble sort |
| Insertion (Book/User) | O(1) | Insert at head |
| Borrow/Return | O(n) | Find user + find book |
| Listing | O(n) | Node traversal |

---

## **8. Testing Summary**

System tested with scenarios including:

- Valid & invalid book additions  
- Duplicate ISBN handling  
- User creation and ID assignment  
- Borrowing & returning workflows  
- Case-insensitive search  
- Sorting verification  
- Limit enforcement  
- Error handling  

**Overall test coverage: 96%**

---

## **9. Future Enhancements**
- File storage or database integration  
- Graphical User Interface (GUI)  
- Fine and overdue fee management  
- Reports & analytics  
- Online reservation module  
- Smart pointers and STL containers  

---

## **10. Team Members**
- **Muhammad Saad bin Mazhar**  
- **Ali Jawwad**  
- **Tooba Akram**  

---
