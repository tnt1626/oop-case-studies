#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <string>
#include <list>
using namespace std;

// Forward declaration
class BorrowerRecord;

// ======================
// Class Book
// ======================
class Book {
private:
    string number;
    string author;
    string title;
    BorrowerRecord *borrower;

public:
    // Constructor
    Book(string number, string author, string title);
    Book(string number);

    // Setter
    void setNumber(string number);
    void setAuthor(string author);
    void setTitle(string title);
    void setBorrower(BorrowerRecord* borrower = nullptr);

    // Getter
    string getNumber();
    string getAuthor();
    string getTitle();
    BorrowerRecord* getBorrower();

    // Methods
    void display();
    void attachBorrower(BorrowerRecord* borrower);
    void detachBorrower();
    bool isAvailable();
};

#endif