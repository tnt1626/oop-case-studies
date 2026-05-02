# 04 – Case Study – A Gym Membership Application
**OBJECT-ORIENTED PROGRAMMING**

---

## 1. SPECIFICATION (ĐẶC TẢ)
**Phòng Gym (The Gym):**
* **Tên phòng gym** (name).
* **Gói tập (Membership Packages):**
    * Tên gói tập (title).
    * Tên huấn luyện viên phụ trách (author/instructor).
    * Mã số gói tập duy nhất (unique catalogue number).
* **Hội viên (Members):**
    * Tên hội viên (name).
    * Đăng ký một gói tập (borrow/buy a package).
    * Hủy/Trả lại gói tập (return a package).
* **Chức năng hệ thống:**
    * Đăng ký một hội viên mới (register a new borrower).
    * Hiển thị danh sách các gói tập:
        * Đang trống, có sẵn để đăng ký (available for loan).
        * Đã có hội viên đang sử dụng (already out on loan).

---

## 2. USE-CASES (CÁC CA SỬ DỤNG)
* Đăng ký một hội viên mới.
* Thêm một gói tập mới vào danh mục hệ thống.
* Xuất danh sách các gói tập hiện đang trống.
* Xuất danh sách các gói tập đang được hội viên sử dụng.
* Ghi nhận một gói tập đã được hội viên đăng ký thành công.
* Ghi nhận một gói tập đã được hội viên hoàn thành hoặc hủy.

---

## 3. TEST-CASES (KỊCH BẢN KIỂM THỬ)
1. **Register one member:** Một hội viên mới được đăng ký vào hệ thống phòng gym thành công.
2. **Add one package:** Một gói tập mới được thêm vào kho dữ liệu và ở trạng thái sẵn sàng để đăng ký.
3. **Display available packages:** Hiển thị chi tiết từng gói tập đang trống khi hệ thống có từ 0 gói tập trở lên.
4. **Display active packages:** Hiển thị chi tiết các gói tập đang được hội viên sử dụng.
5. **Assign one package:** Một gói tập đang trống được ghi nhận là đang phục vụ cho một hội viên cụ thể và không còn hiển thị trong danh sách trống.
6. **Terminate one package:** Một gói tập đang sử dụng được ghi nhận là đã kết thúc. Gói tập này trở lại trạng thái sẵn sàng để đăng ký mới.

---

## 4. DESIGN - CLASS DIAGRAM DETAILS (CHI TIẾT THIẾT KẾ)

### Lớp Gym (Tương ứng Library)
* **Thuộc tính:** `-theName: String`
* **Phương thức:**
    * `+Gym(String aName)`
    * `+registerOneMember(String aMemberName)`
    * `+addNewPackage(Package aPackage)`
    * `+displayPackagesAvailable()`
    * `+displayPackagesActive()`
    * `+assignPackage(String aPackageID, String aMemberName)`
    * `+terminatePackage(String aPackageID)`

### Lớp Package (Tương ứng Book)
* **Thuộc tính:**
    * `-thePackageID: String`
    * `-theInstructor: String`
    * `-theTitle: String`
* **Phương thức:**
    * `+Package(String id, String title, String instructor)`
    * `+attachMember(MemberRecord aMember)`
    * `+detachMember()`
    * `+display()`

### Lớp MemberRecord (Tương ứng BorrowerRecord)
* **Thuộc tính:** `-theName: String`
* **Phương thức:**
    * `+MemberRecord(String aName)`
    * `+attachPackage(Package aPackage)`
    * `+detachPackage(Package aPackage)`

---

## 5. IMPACT OF CLASSES (TÁC ĐỘNG CỦA CÁC LỚP)
* **Lend/Assign package:** Thực hiện kết nối một đối tượng `MemberRecord` với một đối tượng `Package` và ngược lại.
* **Return/Terminate package:** Ngắt kết nối giữa đối tượng `MemberRecord` và đối tượng `Package`.
* **Check availability:** Một gói tập được coi là sẵn sàng nếu thuộc tính liên kết với `MemberRecord` là `NULL`.# 04 – Case Study – A Gym Membership Application
**OBJECT-ORIENTED PROGRAMMING**

---

## 1. SPECIFICATION (ĐẶC TẢ)
**Phòng Gym (The Gym):**
* **Tên phòng gym** (name).
* **Gói tập (Membership Packages):**
    * Tên gói tập (title).
    * Tên huấn luyện viên phụ trách (author/instructor).
    * Mã số gói tập duy nhất (unique catalogue number).
* **Hội viên (Members):**
    * Tên hội viên (name).
    * Đăng ký một gói tập (borrow/buy a package).
    * Hủy/Trả lại gói tập (return a package).
* **Chức năng hệ thống:**
    * Đăng ký một hội viên mới (register a new borrower).
    * Hiển thị danh sách các gói tập:
        * Đang trống, có sẵn để đăng ký (available for loan).
        * Đã có hội viên đang sử dụng (already out on loan).

---

## 2. USE-CASES (CÁC CA SỬ DỤNG)
* Đăng ký một hội viên mới.
* Thêm một gói tập mới vào danh mục hệ thống.
* Xuất danh sách các gói tập hiện đang trống.
* Xuất danh sách các gói tập đang được hội viên sử dụng.
* Ghi nhận một gói tập đã được hội viên đăng ký thành công.
* Ghi nhận một gói tập đã được hội viên hoàn thành hoặc hủy.

---

## 3. TEST-CASES (KỊCH BẢN KIỂM THỬ)
1. **Register one member:** Một hội viên mới được đăng ký vào hệ thống phòng gym thành công.
2. **Add one package:** Một gói tập mới được thêm vào kho dữ liệu và ở trạng thái sẵn sàng để đăng ký.
3. **Display available packages:** Hiển thị chi tiết từng gói tập đang trống khi hệ thống có từ 0 gói tập trở lên.
4. **Display active packages:** Hiển thị chi tiết các gói tập đang được hội viên sử dụng.
5. **Assign one package:** Một gói tập đang trống được ghi nhận là đang phục vụ cho một hội viên cụ thể và không còn hiển thị trong danh sách trống.
6. **Terminate one package:** Một gói tập đang sử dụng được ghi nhận là đã kết thúc. Gói tập này trở lại trạng thái sẵn sàng để đăng ký mới.

---

## 4. DESIGN - CLASS DIAGRAM DETAILS (CHI TIẾT THIẾT KẾ)

### Lớp Gym (Tương ứng Library)
* **Thuộc tính:** `-theName: String`
* **Phương thức:**
    * `+Gym(String aName)`
    * `+registerOneMember(String aMemberName)`
    * `+addNewPackage(Package aPackage)`
    * `+displayPackagesAvailable()`
    * `+displayPackagesActive()`
    * `+assignPackage(String aPackageID, String aMemberName)`
    * `+terminatePackage(String aPackageID)`

### Lớp Package (Tương ứng Book)
* **Thuộc tính:**
    * `-thePackageID: String`
    * `-theInstructor: String`
    * `-theTitle: String`
* **Phương thức:**
    * `+Package(String id, String title, String instructor)`
    * `+attachMember(MemberRecord aMember)`
    * `+detachMember()`
    * `+display()`

### Lớp MemberRecord (Tương ứng BorrowerRecord)
* **Thuộc tính:** `-theName: String`
* **Phương thức:**
    * `+MemberRecord(String aName)`
    * `+attachPackage(Package aPackage)`
    * `+detachPackage(Package aPackage)`

---

## 5. IMPACT OF CLASSES (TÁC ĐỘNG CỦA CÁC LỚP)
* **Lend/Assign package:** Thực hiện kết nối một đối tượng `MemberRecord` với một đối tượng `Package` và ngược lại.
* **Return/Terminate package:** Ngắt kết nối giữa đối tượng `MemberRecord` và đối tượng `Package`.
* **Check availability:** Một gói tập được coi là sẵn sàng nếu thuộc tính liên kết với `MemberRecord` là `NULL`.