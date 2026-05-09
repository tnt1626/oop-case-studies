#include <iostream>
#include <list>
#include <string>

using namespace std;


class CustomerRecord;

class Computer {
    string name;
    string series;
    CustomerRecord *record;
public:
    Computer(string name, string series);
    Computer(string series);

    string getName();
    string getSeries();
    CustomerRecord *getRecord();

    void setName(string name);
    void setSeries(string series);
    void attachRecord(CustomerRecord *record = nullptr);
    void detachRecord();

    bool isAvailable();

    void display();
};

Computer::Computer(string name, string series) {
    this->setName(name);
    this->setSeries(series);
    this->attachRecord();
}

Computer::Computer(string series) : Computer("Computer Unknow", series) {}

string Computer::getName() { return this->name; }
string Computer::getSeries() { return this->series; }
CustomerRecord *Computer::getRecord() {
    return this->record;
}

void Computer::setName(string name) { this->name = name; }
void Computer::setSeries(string series) { this->series = series; }

void Computer::attachRecord(CustomerRecord *record) {
    this->record = record;
}

void Computer::detachRecord() {
    this->record = nullptr;
}

bool Computer::isAvailable() {
    return this->record == nullptr;
}

void Computer::display() {
    cout << "Name: " << this->getName() << endl;
    cout << "Series: " << this->getSeries() << endl;
}


class CustomerRecord {
    string name;
    string id;
    Computer *computer;
public:
    CustomerRecord(string name, string id);
    CustomerRecord(string id);

    string getName();
    string getID();
    Computer *getComputer();

    void attachComputer(Computer *computer = nullptr);
    void detachComputer();

    void setName(string name);
    void setID(string id);

    void display();
};

CustomerRecord::CustomerRecord(string name, string id) {
    this->setName(name);
    this->setID(id);
    this->attachComputer();
}

CustomerRecord::CustomerRecord(string id) : CustomerRecord("Computer Unknow", id) {}

string CustomerRecord::getName() { return this->name; }
string CustomerRecord::getID() { return this->id; }
Computer *CustomerRecord::getComputer() {
    return this->computer;
}

void CustomerRecord::setName(string name) { this->name = name; }
void CustomerRecord::setID(string id) { this->id = id; }

void CustomerRecord::attachComputer(Computer *computer) {
    this->computer = computer;
}

void CustomerRecord::detachComputer() {
    this->computer = nullptr;
}

void CustomerRecord::display() {
    cout << "Name: " << this->getName() << endl;
    cout << "ID: " << this->getID() <<endl;
}


class Company {
    string name;
    string taxCode;
    list<Computer *> computers;
    list<CustomerRecord *> records;
public:
    Company(string name, string taxCode);
    Company(string taxCode);

    string getName();
    string getTaxCode();

    void setName(string name);
    void setTaxCode(string taxCode);

    void addOneComputer(Computer *computer);
    void registerOneCustomer(string name, string id);

    void displayAvailableComputers();
    void displayRentedComputers();

    void rentOneComputer(string id, string series);
    void returnOneComputer(string id);

    void display();
};  

Company::Company(string name, string taxCode) {
    this->setName(name);
    this->setTaxCode(taxCode);
}

Company::Company(string taxCode) : Company("HCMUS", taxCode) {}

string Company::getName() {
    return this->name;
}

string Company::getTaxCode() {
    return this->taxCode;
}

void Company::setName(string name) {
    this->name = name;
}

void Company::setTaxCode(string taxCode) {
    this->taxCode = taxCode;
}

void Company::addOneComputer(Computer *computer) {
    this->computers.push_back(computer);
}

void Company::registerOneCustomer(string name, string id) {
    CustomerRecord *record = new CustomerRecord(name, id);
    this->records.push_back(record); 
}

void Company::displayAvailableComputers() {
    cout << "======Display Available Computers ======\n";
    for (auto computer : this->computers) {
        if(computer->isAvailable()) {
            cout << "Computer: \n";
            computer->display();
            
            cout << "================================\n";
        }
    }
}

void Company::displayRentedComputers() {
    cout << "======Display Rented Computers ======\n";
    for (auto computer : this->computers) {
        if(!computer->isAvailable()) {
            cout << "Computer: \n";
            computer->display();
            cout << "Customer Record: \n";
            computer->getRecord()->display();
            cout << "================================\n";
        }
    }
}

void Company::rentOneComputer(string id, string series) {
    Computer *current_computer = nullptr;
    for (auto computer : this->computers) {
        if(computer->getSeries() == series) {
            current_computer = computer;
            break;
        }
    }
    if(current_computer == nullptr) {
        cout << "Computer with Series = " << series << " not found!\n";
        return;
    }
    if(!current_computer->isAvailable()) {
        cout << "Computer with Seris = " << series << " is rented!\n";
        return;
    }
    CustomerRecord *current_record = nullptr;
    for (auto record : this->records) {
        if(record->getID() == id) {
            current_record = record;
            break;
        }
    }
    if(current_record == nullptr) {
        cout << "Customer Record with ID = " << id << " not found!\n";
        return;
    }
    current_computer->attachRecord(current_record);
    current_record->attachComputer(current_computer);
    cout << "Customer Record with ID " << id << " rent Computer with Series = " << series << " successfully!\n";
}

void Company::returnOneComputer(string id) {
    CustomerRecord *current_record = nullptr;
    for (auto record : this->records) {
        if(record->getID() == id) {
            current_record = record;
            break;
        }
    }
    if(current_record == nullptr) {
        cout << "Customer Record with ID = " << id << " not found!\n";
        return;
    }

    Computer *current_computer = current_record->getComputer();
    if(current_computer == nullptr) {
        cout << "Customer Record with ID = " << id << " doesn't rent any computer!\n";
        return;
    }

    current_computer->detachRecord();
    current_record->detachComputer();
    cout << "Customer Record with ID = " << id << "return Computer with Series " << current_computer->getSeries() << "successfully!\n";
}

void Company::display() {
    cout << "Name: " << this->getName() << endl;
    cout << "Tax Code: " << this->getTaxCode() << endl;
    cout << "======== Customer Records =========\n";
    for (auto record : this->records) {
        record->display();
        cout << "=============================\n";
    }
    cout << "======== Computers =========\n";
    for (auto computer : this->computers) {
        computer->display();
        cout << "=============================\n";
    }
}

int main() {
    Company company = Company("CyberCore", "01234567");

    Computer *computer1 = new Computer("Haha", "123");
    Computer *computer2 = new Computer("Hihi", "456");
    Computer *computer3 = new Computer("Hehe", "789");

    company.addOneComputer(computer1);
    company.addOneComputer(computer2);
    company.addOneComputer(computer3);

    company.registerOneCustomer("HaVanThao", "987");
    company.registerOneCustomer("PhamHuyLam", "654");
    company.display();

    company.rentOneComputer("987", "123");
    company.rentOneComputer("654", "789");
    company.displayRentedComputers();

    company.returnOneComputer("987");
    company.returnOneComputer("987");
    company.rentOneComputer("654", "456");
    company.displayRentedComputers();

    delete(computer1);
    delete(computer2);
    delete(computer3);

    return 0;
}

// Name: CyberCore
// Tax Code: 01234567
// ======== Customer Records =========
// Name: HaVanThao
// ID: 987
// =============================
// Name: PhamHuyLam
// ID: 654
// =============================
// ======== Computers =========
// Name: Haha
// Series: 123
// =============================
// Name: Hihi
// Series: 456
// =============================
// Name: Hehe
// Series: 789
// =============================
// Customer Record with ID 987 rent Computer with Series = 123 successfully!
// Customer Record with ID 654 rent Computer with Series = 789 successfully!
// ======Display Rented Computers ======
// Computer: 
// Name: Haha
// Series: 123
// Customer Record: 
// Name: HaVanThao
// ID: 987
// ================================
// Computer: 
// Name: Hehe
// Series: 789
// Customer Record: 
// Name: PhamHuyLam
// ID: 654
// ================================
// Customer Record with ID = 987return Computer with Series 123successfully!
// Customer Record with ID = 987 doesn't rent any computer!
// Customer Record with ID 654 rent Computer with Series = 456 successfully!
// ======Display Rented Computers ======
// Computer: 
// Name: Hihi
// Series: 456
// Customer Record: 
// Name: PhamHuyLam
// ID: 654
// ================================
// Computer: 
// Name: Hehe
// Series: 789
// Customer Record: 
// Name: PhamHuyLam
// ID: 654
// ================================