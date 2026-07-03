# ĐỀ THI THỰC HÀNH LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG (OOP)

**Thời gian làm bài: 60 phút**

---

## MÔ TẢ BÀI TOÁN

Bạn được yêu cầu xây dựng một phần mềm console quản lý việc đặt vé tham dự sự kiện. 

Hệ thống được thiết kế bám sát nguyên lý hướng đối tượng, bao gồm các thực thể chính: `Person`, `Attendee` (Khách tham dự), `Event` (Sự kiện chính), `Session` (Các suất/buổi diễn thuộc sự kiện), `TicketWallet` (Ví chứa vé của khách) và `Ticket` (Chi tiết một vé).

---

## PHẦN 1: THIẾT KẾ LỚP

Thí sinh dựa vào Lược đồ UML ở cuối đề thi để cài đặt các Class, Thuộc tính và Phương thức tương ứng. Có thể sử dụng ngôn ngữ lập trình tùy chọn (Java, C#, C++, Python...).

**Yêu cầu cài đặt chi tiết:**

1. **Lớp cha `Person`**: Có thuộc tính `id` (mã số), `name` (họ tên).
2. **Lớp `Attendee` kế thừa `Person`**: Có thêm thuộc tính `email` và chứa một đối tượng `TicketWallet` (Ví vé của khách đó).
3. **Lớp `Event`**: Chứa `eventId` (Mã sự kiện), `eventName` (Tên sự kiện), `price` (Giá vé). Có phương thức `createSession(sessionId, time)` để tạo ra một `Session` (suất diễn) mới liên kết với sự kiện hiện tại (Quan hệ 1 chiều).
4. **Lớp `Session`**: Chứa `sessionId` (Mã suất diễn), `time` (thời gian diễn ra), tham chiếu đến `Event` tương ứng, và danh sách khách hàng (`List<Attendee>`) đã đặt vé. Có phương thức `bookTicket(Attendee a)` để thêm khách vào danh sách suất diễn và đồng thời thêm vé vào ví của khách.
5. **Lớp `Ticket`**: Lưu thông tin vé của một suất diễn cụ thể. Gồm tham chiếu đến `Session` và `isCheckIn` (Trạng thái đã check-in hay chưa, mặc định là `false`).
6. **Lớp `TicketWallet`**: Chứa danh sách các `Ticket`. Có phương thức `addTicket(Ticket)` để thêm vé vào ví, phương thức `checkIn(Session)` để cập nhật trạng thái check-in thành công cho suất diễn tương ứng, và phương thức `printWallet()` để in chi tiết các vé đang sở hữu.

---

## PHẦN 2: THỰC THI USE CASE

Trong hàm `main` (hoặc lớp quản lý chính), hãy viết code thực thi tuần tự 5 Use Case sau (sử dụng dữ liệu hard-code):

* **Yêu cầu 1 - Tạo dữ liệu mồi:**
  * Tạo 2 sự kiện (`Event`): 
    * ID "1" - Tên "Black" - Giá "1" 
    * ID "2" - Tên "Pink" - Giá "2"
  * Tạo 3 khách hàng (`Attendee`): 
    * Email "ha@gmail.com", ID "9", Tên "Alice"
    * Email "he@gmail.com", ID "8", Tên "Pop"
    * Email "hi@gmail.com", ID "7", Tên "Pip"

* **Yêu cầu 2 - Mở suất diễn (Session):**
  * Từ sự kiện "Black", gọi `createSession` tạo ra 2 suất diễn mã "3" (10h) và mã "4" (10h).
  * Từ sự kiện "Pink", gọi `createSession` tạo ra suất diễn mã "5" (10h).
  * *In ra màn hình thông tin cơ bản của suất diễn "3".*

* **Yêu cầu 3 - Đặt vé:**
  * Gọi hàm `bookTicket()` để: Khách Alice và Pop đặt vé suất "3". Khách Alice và Pip đặt vé suất "5".
  * *In ra màn hình thông tin chi tiết (gồm cả danh sách khách hàng) của suất "3".*

* **Yêu cầu 4 - Check-in sự kiện:**
  * Từ Ví vé (`TicketWallet`) của khách Alice, gọi hàm check-in để cập nhật trạng thái đã tham gia cho suất diễn "3".

* **Yêu cầu 5 - In Ví vé (Ticket Wallet):**
  * In ra màn hình Ví vé của khách Alice. Yêu cầu hiển thị các thông tin: Tên sự kiện, Giá vé, Mã suất diễn, Trạng thái Check-in.

---

## LƯỢC ĐỒ UML

```mermaid
classDiagram
    Person <|-- Attendee
    Event "1" <-- "*" Session : runs as
    Session "*" o-- "*" Attendee : attended by
    Attendee "1" *-- "1" TicketWallet : owns
    TicketWallet "1" *-- "*" Ticket : contains
    Ticket "*" --> "1" Session : for

    class Person {
        <<abstract>>
        #String id
        #String name
    }

    class Attendee {
        -String email
        -TicketWallet wallet
        +String getEmail()
        +TicketWallet getWallet()
    }

    class Event {
        -String eventId
        -String eventName
        -String price
        +Session createSession(String sessionId, String time)
    }

    class Session {
        -String sessionId
        -String time
        -Event event
        -List~Attendee~ attendees
        +void bookTicket(Attendee a)
        +void display()
    }

    class TicketWallet {
        -List~Ticket~ tickets
        +void addTicket(Ticket t)
        +void checkIn(Session sec)
        +void printWallet()
    }

    class Ticket {
        -Session session
        -boolean isCheckIn
    }