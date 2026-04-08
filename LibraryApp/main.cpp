// Hệ thống Quản lý Thư viện
// Chương trình này triển khai một ứng dụng thư viện đơn giản với sách, người mượn và quản lý thư viện.

#include "Book.hpp"
#include "Library.hpp"

using namespace std;

// Hàm main với các trường hợp kiểm tra cho hệ thống thư viện
int main() {
    cout <<"The Library Application\n" << endl;
    
    // Tạo một instance thư viện
    Library lib;
    
    // Tạo các instance sách
    Book* first = new Book("000","An danh", "Nhung nguoi di hoc vao thu 3");    
    Book* gege = new Book("036","Danh", "Happy Summer");    
    Book second("001","Ha Van Thao", "Pointer is so ezzzzzzz");
    Book hehe("003","Nguyen Hien Luong","Huy diet co so du lieu");
    
    // Kiểm tra thêm sách vào thư viện
    lib.addOneBook(gege);
    lib.addOneBook(first);
    lib.addOneBook(&second);
    lib.addOneBook(&hehe);
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
    
    // Kiểm tra các test cases mượn sách
    lib.lendOneBook("067", "Sang"); // test case 1
    lib.lendOneBook("018", "Sang"); // test case 2
    lib.lendOneBook("001", "Thao"); // test case 3
    lib.lendOneBook("001", "Sang"); // test case 4
    lib.lendOneBook("036", "Sang"); // test case 4

    // Kiểm tra các test cases trả sách
    lib.returnOneBook("002"); // trả sách với number không hợp lệ
    lib.returnOneBook("003"); // trả sách chưa được mượn
    lib.returnOneBook("001"); // Sang trả sách với number 001 thành công

    // Dọn dẹp sách được cấp phát động
    lib.removeOneBook(first);
    delete(first);
    delete(gege);

    return 0;
}