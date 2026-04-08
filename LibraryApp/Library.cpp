#include "Library.hpp"

using namespace std;

Library::Library(string name) {
    this->setName(name);
    this->stock = {};
    this->borrowerRecords = {};
}

Library::Library(): Library("Thu vien HCMUS") {}

void Library::setName(string name) {
    this->name = name;
}

void Library::registerOneBorrower(string borrowerName) {
    BorrowerRecord *borrower = new BorrowerRecord(borrowerName);
    borrowerRecords.push_front(borrower);
}


void Library::addOneBook(Book *book) {
    this->stock.push_front(book);
}


void Library::removeOneBook(Book *book) {
    this->stock.remove(book);
}

void Library::deleteBorrowerRecord(string borrowerName) {
    auto it = find_if(
        this->borrowerRecords.begin(), 
        this->borrowerRecords.end(), 
        [&](BorrowerRecord *record) {
            return record->getName() == borrowerName;
    });
    
    if (it != this->borrowerRecords.end()) {
        delete *it;                      
        this->borrowerRecords.erase(it); 
    }
}

// Xóa hồ sơ người mượn theo con trỏ
void Library::deleteBorrowerRecord(BorrowerRecord *borrower) {
    auto it = find(
        this->borrowerRecords.begin(), 
        this->borrowerRecords.end(), 
        borrower
    );
    
    if (it != this->borrowerRecords.end()) {
        delete *it;                      
        this->borrowerRecords.erase(it); 
    }
}

// Hiển thị kho sách và hồ sơ người mượn của thư viện
void Library::display() {
    cout << "\n=== LIBRARY ===\n";
    cout << "BOOKS IN STOCK:\n";
    for (auto book : this->stock) {
        book->display();
    }
    cout << "=== BORROWER RECORD ===\n";
    for (auto record : this->borrowerRecords) {
        cout << "Name of borrower: " << record->getName() << endl;
    }
}

// Destructor để dọn dẹp các hồ sơ người mượn được cấp phát động
Library::~Library() {
    this->stock.clear();
    for (auto borrowerRecord : this->borrowerRecords) {
        delete(borrowerRecord);
    }
    this->borrowerRecords.clear();
}

void Library::lendOneBook(string number, string name) {
    // testcase 1: number is NA
    Book *book = nullptr;
    for (auto b : this->stock) {
        if (b->getNumber() == number) {
            book = b;
            break;
        }
    }

    if (book == nullptr) {
        cout << "Book number: " << number << " is not found!\n";
        return;
    }
    // testcase 2: book with number is not available
    if (!book->isAvailable()) {
        cout << "Book number: " << number << " is not available!\n";
        return;
    }
    // testcase 3: borrower with name is not found
    BorrowerRecord *borrower = nullptr;
    for (auto br : this->borrowerRecords) {
        if (br->getName() == name) {
            borrower = br;
            break;
        }
    }

    if (borrower == nullptr) {
        cout << "Borrower record name: " << name << " is not available!\n";
        return;
    }

    // testcase 4
    book->attachBorrower(borrower);
    borrower->attachBook(book);
    cout << "Lend book " << number << " to borrower " << name << endl;
}

