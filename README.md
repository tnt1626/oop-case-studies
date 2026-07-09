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
*   **Gym Membership Application (Quản lý phòng Gym):**
    *   Vị trí: [Review/GymMembership/](./Review/GymMembership)
    *   Mã nguồn C++: [main.cpp](./Review/GymMembership/main.cpp)
    *   Tài liệu đặc tả: [GYM_MEMBERSHIP_APPLICATION.md](./Review/GymMembership/GYM_MEMBERSHIP_APPLICATION.md)
    *   Các lớp chính: `Package`, `MemberRecord`, `Gym`.
    *   Nội dung: Quản lý đăng ký thành viên phòng gym và các gói dịch vụ đi kèm.
*   **Car Rental Application (Quản lý thuê xe ô tô):**
    *   Vị trí: [Review/CarRental/](./Review/CarRental)
    *   Mã nguồn C++: [car_main.cpp](./Review/CarRental/car_main.cpp)
    *   Tài liệu đặc tả: [CAR_RENTAL_APPLICATION.md](./Review/CarRental/CAR_RENTAL_APPLICATION.md)
    *   Các lớp chính: `Car`, `CustomerRecord`, `RentalStore`.
    *   Nội dung: Quản lý thuê xe ô tô và hồ sơ thuê xe của khách hàng.
*   **Ticket Booking System (Hệ thống đặt vé sự kiện):**
    *   Vị trí: [Review/Ticket/](./Review/Ticket)
    *   Mã nguồn C++: [main.cpp](./Review/Ticket/main.cpp)
    *   Tài liệu đặc tả: [description.md](./Review/Ticket/description.md)
    *   Các lớp chính: `Person`, `Attendee`, `Event`, `Session`, `Ticket`, `TicketWallet`.
    *   Nội dung: Thiết kế hệ thống đặt vé xem biểu diễn nghệ thuật/sự kiện, quản lý ví vé của khách hàng và trạng thái check-in.
*   **Composite Tree Structure (Cấu trúc cây phân cấp):**
    *   Vị trí: [Review/Tree/](./Review/Tree)
    *   Mã nguồn C++: [main.cpp](./Review/Tree/main.cpp)
    *   Các lớp chính: `Node`, `Leaf`, `Tree`.
    *   Nội dung: Áp dụng mẫu thiết kế Composite để thiết kế cấu trúc cây gồm các nút lá và nút nhánh, hỗ trợ tính toán tổng giá trị đệ quy.
*   **Web Page Composite Structure (Cấu trúc trang Web):**
    *   Vị trí: [Review/Web/](./Review/Web)
    *   Mã nguồn C++: [main.cpp](./Review/Web/main.cpp)
    *   Các lớp chính: `Object`, `Image`, `Audio`, `HTMLFile`.
    *   Nội dung: Áp dụng mẫu thiết kế Composite để thiết kế cấu trúc phân cấp các thành phần trong một trang web (HTMLFile chứa các Image, Audio, và các HTMLFile con khác).

### 3. Lab 2: Software House (Nhà phát triển Phần mềm)
Nằm trong thư mục `Lab2_SoftwareHouse/`. Thư mục này chia làm các cấp độ thiết kế tăng dần:
*   [Employee_Programmer/](./Lab2_SoftwareHouse/Employee_Programmer/): Kế thừa đơn giản giữa Nhân viên (`Employee`) và Lập trình viên (`Programmer`).
*   [Employee_Programmer_ProjectLeader/](./Lab2_SoftwareHouse/Employee_Programmer_ProjectLeader/): Kế thừa đa cấp (thêm Trưởng nhóm dự án `ProjectLeader`) và quan hệ quản lý đội nhóm.
*   [Polymorphism/](./Lab2_SoftwareHouse/Polymorphism/): Thực hành đa hình (Polymorphism) qua việc quản lý danh sách nhân sự đa dạng.
*   [Interface/](./Lab2_SoftwareHouse/Interface/): Sử dụng lớp trừu tượng (abstract class) để thiết kế các giao diện lớp độc lập.

### 4. Lab 3: Hệ thống Đăng ký Học phần (Course Registration System)
*   **Vị trí:** [Lab3/](./Lab3)
*   **Mã nguồn:** [main.cpp](./Lab3/main.cpp)
*   **Các lớp chính:** `TranscriptEntry`, `Transcript`, `Course`, `Section`, `Person`, `Professor`, `Student`.
*   **Nội dung:** Mô hình hóa các mối quan hệ lớp học phần (`Section`), môn học (`Course`), điều kiện tiên quyết (prerequisites), kết quả học tập (`TranscriptEntry`), và kiểm tra điều kiện đăng ký của sinh viên.

### 5. Exam: Các bài kiểm tra (Exam Case Studies)
Nằm trong thư mục `Exam/`:
*   **Test 1: CyberCore Rental System (Hệ thống thuê máy CyberCore)**
    *   Vị trí: [Exam/Test1/](./Exam/Test1)
    *   Mã nguồn C++: [test_1.cpp](./Exam/Test1/test_1.cpp)
    *   Các lớp chính: `Computer`, `CustomerRecord`, `Company`.
    *   Nội dung: Chương trình mô phỏng hệ thống cho thuê máy tính tại CyberCore, bao gồm các hoạt động mượn/trả máy và hiển thị thông tin thực thi.
*   **Test 2: Car Rental Showroom (NhaTrungBay - Nhà Trưng Bày Xe Ô tô)**
    *   Vị trí: [Exam/Test2/](./Exam/Test2)
    *   Mã nguồn C++: [main.cpp](./Exam/Test2/main.cpp)
    *   Các lớp chính: `Oto`, `OtoHangSang`, `OtoTheThao`, `NhaTrungBay`, `KhachHang`, `LichSuThueXe`.
    *   Nội dung: Chương trình mô phỏng quản lý thuê ô tô hạng sang và ô tô thể thao, lưu lịch sử thuê xe và quản lý khách hàng tại showroom.

---

## 🛠️ Hướng dẫn Biên dịch và Chạy Chương trình

Mỗi thư mục dự án chứa một file chương trình chính chứa hàm `main()` để kiểm thử độc lập.

Bạn có thể biên dịch bằng trình biên dịch `g++` hỗ trợ chuẩn C++11 trở lên:

### Biên dịch một file đơn lẻ (ví dụ Lab 3):
```bash
g++ Lab3/main.cpp -o lab3_program
./lab3_program
```

### Biên dịch dự án nhiều file (ví dụ LibraryApp):
```bash
g++ LibraryApp/*.cpp -o library_app
./library_app
```

---

## 🎯 Mục tiêu Học tập
- Hiểu sâu về thiết kế Hướng đối tượng: Trừu tượng hóa (Abstraction), Đóng gói (Encapsulation), Kế thừa (Inheritance), và Đa hình (Polymorphism).
- Thực hành phân tích và chuyển đổi từ đặc tả yêu cầu sang biểu đồ lớp (Class Diagram) và mã nguồn C++.
- Xử lý các mối quan hệ lớp phổ biến: Association, Aggregation, Composition, Generalization.
- Áp dụng các mẫu thiết kế hướng đối tượng phổ biến (như mẫu thiết kế Composite).

---

## 📝 Lưu ý
*   **Mục đích học tập:** Tất cả các lời giải trong kho lưu trữ này chỉ mang tính chất tham khảo và phục vụ mục đích học tập. Nghiêm cấm sử dụng các tài liệu này cho bất kỳ mục đích thương mại nào.
*   **Trạng thái:** Môn học này hiện đã kết thúc.
