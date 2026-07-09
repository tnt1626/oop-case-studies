#include <iostream>
#include <list>

using namespace std;

class Oto;
class OtoHangSang;
class OtoTheThao;
class NhaTrungBay;
class LichSuThueXe;
class KhachHang;

class NhaTrungBay {
    string name;
    string timeOpen;
    string timeClose;
    list<Oto *> cars;
    list<KhachHang *> customers;
public:
    NhaTrungBay(string name, string timeOpen, string timeClose) {
        this->setName(name);
        this->setTimeOpen(timeOpen);
        this->setTimeClose(timeClose);
    }

    string getName() { return name; }
    string getTimeOpen() { return timeOpen; }
    string getTimeClose() { return timeClose; }

    bool isAvailable(Oto *oto);    

    void addCar(Oto *oto) {
        this->cars.push_back(oto);
    }

    void rentCar(Oto *oto, KhachHang *customer, string dayRent, string dayReturn);

    void setName(string name) {
        this->name = name; 
    }
    void setTimeOpen(string timeOpen) {
        this->timeOpen = timeOpen; 
    }
    void setTimeClose(string timeClose) {
        this->timeClose = timeClose; 
    }

    void display();

    KhachHang* registerCustomer(string name, string phoneNumber);
    ~NhaTrungBay();
};

class LichSuThueXe {
    string dayRent;
    string dayReturn;
    Oto *oto;
public:
    LichSuThueXe(string dayRent, string dayReturn, Oto *oto) {
        this->setDayRent(dayRent);
        this->setDayReturn(dayReturn);
        this->setOto(oto);
    }

    string getDayRent() { return this->dayRent; }
    string getDayReturn() { return this->dayReturn; }
    Oto *getOto() { return this->oto; }

    void setDayRent(string dayRent) {
        this->dayRent = dayRent; 
    }
    void setDayReturn(string dayReturn) {
        this->dayReturn = dayReturn; 
    }
    void setOto(Oto *oto) {
        this->oto = oto;
    }

    void display();
};

class Oto {
    string id;
    int price;
public:
    Oto(string id, int price) {
        this->setId(id);
        this->setPrice(price);
    }

    string getId() { return this->id; }
    int getPrice() { return this->price; }

    void setId(string id) {
        this->id = id; 
    }
    void setPrice(int price) {
        this->price = price; 
    }

    virtual void display() = 0;
};

class OtoHangSang : public Oto {
public:
    OtoHangSang(string id, int price) : Oto(id, price) {}

    virtual void display() {
        cout << "--- Oto Hang Sang ---\n";
        cout << "Id: " << this->getId() << endl;
        cout << "Price: " << this->getPrice() << endl;
    }
};


class OtoTheThao : public Oto {
public:
    OtoTheThao(string id, int price) : Oto(id, price) {}

    virtual void display() {
        cout << "--- Oto The Thao ---\n";
        cout << "Id: " << this->getId() << endl;
        cout << "Price: " << this->getPrice() << endl;
    }
};

class KhachHang {
    string name;
    string phoneNumber;
    list<LichSuThueXe *> histories;
public:
    KhachHang(string name, string phoneNumber) {
        this->setName(name);
        this->setPhoneNumber(phoneNumber);
    }

    string getName() { return this->name; }
    string getPhoneNumber() { return this->phoneNumber; }
    list<LichSuThueXe *> getHistory() { return this->histories; }

    void rentCar(LichSuThueXe *history) {
        this->histories.push_back(history);
    }   

    void addHistory(LichSuThueXe *history) {
        this->histories.push_back(history);
    }

    void setName(string name) {
        this->name = name; 
    }
    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber; 
    }

    void display() {
        cout << "--- Khach Hang ---\n";
        cout << "Name: " << this->getName() << endl;
        cout << "Phone Number: " << this->getPhoneNumber() << endl;
    }
};

KhachHang* NhaTrungBay::registerCustomer(string name, string phoneNumber) {
    KhachHang *khachHang = new KhachHang(name, phoneNumber);
    this->customers.push_back(khachHang);
    return khachHang;
}

NhaTrungBay::~NhaTrungBay() {
    for (auto customer : this->customers) {
        delete customer;
    }
}

void LichSuThueXe::display() {
    cout << "--- Lich Su Thue Xe ---\n";
    cout << "Car ID: " << this->getOto()->getId() << endl;
    cout << "Day Rent: " << this->getDayRent() << endl;
    cout << "Day Return: " << this->getDayReturn() << endl;
}

bool NhaTrungBay::isAvailable(Oto *oto) {
    string id = oto->getId();
    for (auto customer : this->customers) {
        for (auto history : customer->getHistory()) {
            if (history->getOto()->getId() == id) {
                return false;
            }
        }
    }
    return true;
}

void NhaTrungBay::display() {
    cout << "----Nha Trung Bay----\n";
    cout << "Name: " << this->getName() << endl;
    cout << "Time Open: " << this->getTimeOpen() << endl;
    cout << "Time Close: " << this->getTimeClose() << endl;
    cout << "Available Cars:\n";
    for (auto car : this->cars) {
        if (this->isAvailable(car)) {
            car->display();
            cout << "--\n";
        }
    }
    cout << "Customers:\n";
    for (auto customer : this->customers) {
        customer->display();
        cout << "--\n";
    }
}

void NhaTrungBay::rentCar(Oto *oto, KhachHang *customer, string dayRent, string dayReturn) {
    if (!this->isAvailable(oto)) {
        cout << "Car is not available\n";
        return;
    }
    LichSuThueXe *history = new LichSuThueXe(dayRent, dayReturn, oto);
    this->addCar(oto);
    customer->addHistory(history);
}



int main() {
    NhaTrungBay hcmus("HCMUS", "5AM", "10PM");
    OtoHangSang hs1("01", 100);
    OtoHangSang hs2("02", 200);
    OtoHangSang hs3("03", 300);
    OtoTheThao tt1("04", 400);
    OtoTheThao tt2("05", 500);

    hcmus.addCar(&hs1);
    hcmus.addCar(&hs2);
    hcmus.addCar(&hs3);
    hcmus.addCar(&tt1);
    hcmus.addCar(&tt2);

    KhachHang *kh1 = hcmus.registerCustomer("Phong", "123456789");
    KhachHang *kh2 = hcmus.registerCustomer("Sang", "987654321");

    hcmus.display();

    hcmus.rentCar(&hs2, kh1, "04-07-2026", "05-07-2026");
    hcmus.rentCar(&hs2, kh2, "05-07-2026", "07-07-2026");


    return 0;
}