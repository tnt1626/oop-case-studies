#include "Book.hpp"

class BorrowerRecord;


Book::Book(string number, string author, string title) {
    this->setNumber(number);
    this->setAuthor(author);
    this->setTitle(title);
    this->setBorrower();
}

// Constructor chỉ với mã số, sử dụng giá trị mặc định cho tác giả và tiêu đề
Book::Book(string number): Book(number, "An danh", "Khong co title") {}

// Các phương thức setter
void Book::setNumber(string number) {
    this->number = number;
}

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setBorrower(BorrowerRecord* borrower) {
    this->borrower = borrower;
}

// Các phương thức getter
string Book::getNumber() {
    return this->number;
}

string Book::getAuthor() {
    return this->author;
}

string Book::getTitle() {
    return this->title;
}

// Hiển thị thông tin sách
void Book::display() {
    cout << "=== Book ===\n";
    cout << "Number: " << this->getNumber() << endl;
    cout << "Author: " << this->getAuthor() << endl;
    cout << "Title: " << this->getTitle() << endl;
}

// Gắn người mượn cho cuốn sách này
void Book::attachBorrower(BorrowerRecord* borrower) {
    this->setBorrower(borrower);
}

bool Book::isAvailable() {
    if (this->borrower != nullptr) {
        return false;
    }
    return true;
}
