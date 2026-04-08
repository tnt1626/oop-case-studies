#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "Book.hpp"
#include "BorrowerRecord.hpp"

using namespace std;

class Book;
class BorrowerRecord;

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
    // Cho mượn borrower có name mượn quyển sách có số là number
    void lendOneBook(string number, string name);
    // Trả sách với số là number
    void returnOneBook(string number);
};