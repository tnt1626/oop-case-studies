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