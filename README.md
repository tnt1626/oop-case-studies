# OOP Case Studies Repository

Chào mừng bạn đến với kho lưu trữ các bài tập thực hành thiết kế hướng đối tượng (OOP Case Studies) bằng C++. Kho lưu trữ này chứa các ca nghiên cứu (case studies) từ cơ bản đến nâng cao để rèn luyện kỹ năng mô hình hóa lớp, thiết kế mối quan hệ giữa các thực thể và áp dụng các nguyên lý OOP.

## 📁 Cấu trúc thư mục và Các Ca Nghiên Cứu

### 1. Hệ thống Quản lý Thư viện (Library Management System)
*   **Vị trí:**
    *   `main.cpp` (Root) - Phiên bản gom chung trong một file duy nhất.
    *   `LibraryApp/` - Phiên bản hoàn chỉnh, tách các lớp thành file header (`.hpp`) và source (`.cpp`) riêng biệt.
*   **Các lớp chính:** `Book`, `BorrowerRecord`, `Library`.
*   **Nội dung:** Mô hình hóa mối quan hệ liên kết hai chiều (bi-directional association) giữa Sách (`Book`) và Người mượn (`BorrowerRecord`), quản lý kho sách bởi Thư viện (`Library`).

### 2. Các Bài Tập Ôn Tập (Review Case Studies)
Nằm trong thư mục `Review/`:
*   **Gym Membership Application:**
    *   Mã nguồn C++: `main.cpp`
    *   Tài liệu đặc tả: `GYM_MEMBERSHIP_APPLICATION.md`
    *   Các lớp chính: `Package`, `MemberRecord`, `Gym`.
*   **Car Rental Application:**
    *   Mã nguồn C++: `car_main.cpp`
    *   Tài liệu đặc tả: `CAR_RENTAL_APPLICATION.md`
    *   Các lớp chính: `Car`, `CustomerRecord`, `RentalStore`.

### 3. Lab 2: Software House (Nhà phát triển Phần mềm)
Nằm trong thư mục `Lab2_SoftwareHouse/`. Thư mục này chia làm các cấp độ thiết kế tăng dần:
*   `Employee_Programmer/`: Kế thừa đơn giản giữa Nhân viên (`Employee`) và Lập trình viên (`Programmer`).
*   `Employee_Programmer_ProjectLeader/`: Kế thừa đa cấp (thêm Trưởng nhóm dự án `ProjectLeader`) và quan hệ quản lý đội nhóm.
*   `Polymorphism/`: Thực hành đa hình (Polymorphism) qua việc quản lý danh sách nhân sự đa dạng.
*   `Interface/`: Sử dụng lớp trừu tượng (abstract class) để thiết kế các giao diện lớp độc lập.

### 4. Lab 3: Hệ thống Đăng ký Học phần (Course Registration System)
*   **Vị trí:** `Lab3/`
*   **Mã nguồn:** `main.cpp`
*   **Các lớp chính:** `TranscriptEntry`, `Transcript`, `Course`, `Section`, `Person`, `Professor`, `Student`.
*   **Nội dung:** Mô hình hóa các mối quan hệ lớp học phần (`Section`), môn học (`Course`), điều kiện tiên quyết (prerequisites), kết quả học tập (`TranscriptEntry`), và kiểm tra điều kiện đăng ký của sinh viên.

### 5. Exam: Bài tập Kiểm tra (CyberCore Rental System)
*   **Vị trí:** `Exam/`
*   **Mã nguồn:** `test_1.cpp`
*   **Các lớp chính:** `Computer`, `CustomerRecord`, `Company`.
*   **Nội dung:** Chương trình mô phỏng hệ thống cho thuê máy tính tại CyberCore, bao gồm các hoạt động mượn/trả máy và hiển thị thông tin thực thi.

---

## 🛠️ Hướng dẫn Biên dịch và Chạy Chương trình

Mỗi thư mục dự án chứa một file chương trình chính chứa hàm `main()` để kiểm thử độc lập.

Bạn có thể biên dịch bằng trình biên dịch `g++` hỗ trợ chuẩn C++11 trở lên:

### Biên dịch một file đơn lẻ (ví dụ Lab 3):
```bash
g++ -std=c++11 Lab3/main.cpp -o lab3_program
./lab3_program
```

### Biên dịch dự án nhiều file (ví dụ LibraryApp):
```bash
g++ -std=c++11 LibraryApp/*.cpp -o library_app
./library_app
```

---

## 🎯 Mục tiêu Học tập
- Hiểu sâu về thiết kế Hướng đối tượng: Trừu tượng hóa (Abstraction), Đóng gói (Encapsulation), Kế thừa (Inheritance), và Đa hình (Polymorphism).
- Thực hành phân tích và chuyển đổi từ đặc tả yêu cầu sang biểu đồ lớp (Class Diagram) và mã nguồn C++.
- Xử lý các mối quan hệ lớp phổ biến: Association, Aggregation, Composition, Generalization.
