// Hệ thống Quản lý Thư viện
// Chương trình này triển khai một ứng dụng thư viện đơn giản với sách, người mượn và quản lý thư viện.

#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class BorrowerRecord;

// ==========================Book====================
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

    // Methods
    void display();
    void attachBorrower(BorrowerRecord* borrower);
    bool isAvailable();
};

// ========================Book's METHODS=========================
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


// ==========================BorrowerRecord====================
// Lớp BorrowerRecord đại diện cho người mượn và các sách họ đã mượn
class BorrowerRecord {
    private:
    string name;           // Tên của người mượn
    list<Book *> books;    // Danh sách các sách được mượn bởi người này

    public:
    // Constructor với tên
    BorrowerRecord(string name);
    // Constructor mặc định
    BorrowerRecord();
    // Setter cho tên
    void setName(string name); 
    // Getter cho tên
    string getName(); 
    // Thêm một cuốn sách vào danh sách của người mượn
    void attachBook(Book *book);
    // Xóa một cuốn sách khỏi danh sách của người mượn (xóa liên kết khỏi sách)
    void detachBook(Book *book);
};

// ========================BorrowerRecord's METHODS=========================
BorrowerRecord::BorrowerRecord(string name) {
    this->setName(name);
    this->books = {};
}

BorrowerRecord::BorrowerRecord(): BorrowerRecord("An danh") {}

void BorrowerRecord::setName(string name) {
    this->name = name;
}

string BorrowerRecord::getName() {
    return this->name;
}

void BorrowerRecord::attachBook(Book *book) {
    books.push_front(book);
}

void BorrowerRecord::detachBook(Book *book) {
    this->books.remove(book);
}

// ==========================Library====================
// Lớp Library quản lý bộ sưu tập sách và hồ sơ người mượn
class Library {
    private:
    string name;                          // Tên của thư viện
    list<Book *> stock;                   // Danh sách sách có sẵn trong kho
    list<BorrowerRecord *> borrowerRecords; // Danh sách tất cả hồ sơ người mượn

    public:
    // Constructor với tên
    Library(string name);
    // Constructor mặc định
    Library();
    // Setter cho tên
    void setName(string name);
    // Đăng ký người mượn mới
    void registerOneBorrower(string borrowerName);
    // Thêm một cuốn sách vào kho
    void addOneBook(Book *book);
    // Xóa một cuốn sách khỏi kho
    void removeOneBook(Book *book);
    // Xóa hồ sơ người mượn theo tên
    void deleteBorrowerRecord(string borrowerName);
    // Xóa hồ sơ người mượn theo con trỏ
    void deleteBorrowerRecord(BorrowerRecord *borrower);
    // Hiển thị kho sách và hồ sơ người mượn của thư viện
    void display();
    // Destructor để dọn dẹp các hồ sơ người mượn được cấp phát động
    ~Library();
    void lendOneBook(string number, string name);
};

// ========================Library's METHODS=========================
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



// Hàm main với các trường hợp kiểm tra cho hệ thống thư viện
int main() {
    cout <<"The Library Application\n" << endl;
    
    // Tạo một instance thư viện
    Library lib;
    
    // Tạo các instance sách
    Book* first = new Book("000","Aso Haro","Alice in Borderland");    
    Book* gege = new Book("036","Danh","Ban la cau nho cua toi");    
    Book second("001","Ha Van Thao","Co so lap trinh huong doi tuong");
    
    // Kiểm tra thêm sách vào thư viện
    lib.addOneBook(gege);
    lib.addOneBook(first);
    lib.display();
    
    lib.addOneBook(&second);
    lib.display();
    
    // Kiểm tra xóa sách khỏi kho
    lib.removeOneBook(first);
    lib.display();
    
    // Kiểm tra đăng ký người mượn
    lib.registerOneBorrower("Thao");
    lib.registerOneBorrower("Sang");
    lib.display();
    
    // Kiểm tra xóa hồ sơ người mượn
    lib.deleteBorrowerRecord("Thao");
    lib.display();
    
    lib.lendOneBook("067", "Sang"); // test case 1
    lib.lendOneBook("018", "Sang"); // test case 2
    lib.lendOneBook("001", "Thao"); // test case 3
    lib.lendOneBook("001", "Sang"); // test case 4
    lib.lendOneBook("036", "Sang"); // test case 4

    // Dọn dẹp sách được cấp phát động
    lib.removeOneBook(first);
    delete(first);
    delete(gege);

    return 0;
}