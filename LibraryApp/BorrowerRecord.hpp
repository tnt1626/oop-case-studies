#ifndef BORROWERRECORD_HPP
#define BORROWERRECORD_HPP

#include <iostream>
#include <string>
#include <list>

#include "Book.hpp"
using namespace std;


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

#endif