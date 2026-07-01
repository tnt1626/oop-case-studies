#include <iostream>
#include <list>
#include <string>

using namespace std;

class CustomerRecord;

class Car {
    string model;
    string brand;
    string licensePlate;
    CustomerRecord *record;
public:
    Car(string model, string brand, string licensePlate);
    Car(string licensePlate);

    string getModel();
    string getBrand();
    string getLicensePlate();
    CustomerRecord *getRecord();

    void setModel(string model);
    void setBrand(string brand);
    void setLicensePlate(string licensePlate);
    void attachCustomerRecord(CustomerRecord *record = nullptr);
    void detachCustomerRecord();

    bool isAvailable();

    void display();
};

Car::Car(string model, string brand, string licensePlate) {
    this->setModel(model);
    this->setBrand(brand);
    this->setLicensePlate(licensePlate);
    this->attachCustomerRecord();
}

Car::Car(string licensePlate) : Car("Model 1", "Brand 2", licensePlate) {}

string Car::getBrand() { return this->brand; }
string Car::getModel() { return this->model; }
string Car::getLicensePlate() { return this->licensePlate; }
CustomerRecord *Car::getRecord() { return this->record; }

void Car::setModel(string model) { this->model = model; }
void Car::setBrand(string brand) { this->brand = brand; }
void Car::setLicensePlate(string licensePlate) { this->licensePlate = licensePlate; }

bool Car::isAvailable() {
    return this->getRecord() == nullptr;
}

void Car::attachCustomerRecord(CustomerRecord *record) {
    this->record = record;
}

void Car::detachCustomerRecord() {
    this->record = nullptr;
}

void Car::display() {
    cout << "Model: " << this->getModel() << endl;
    cout << "Brand: " << this->getBrand() << endl;
    cout << "License Plate: " << this->getLicensePlate() << endl;
}


class CustomerRecord {
    string name;
    list<Car *> cars;
public:
    CustomerRecord(string name);
    CustomerRecord();

    string getName();
    void setName(string name);

    void attachCar(Car *car);
    void detachCar(Car *car);

    void display();
};

CustomerRecord::CustomerRecord(string name) {
    this->setName(name);
}

CustomerRecord::CustomerRecord() : CustomerRecord("Customer HCMUS") {}

string CustomerRecord::getName() { return this->name; }
void CustomerRecord::setName(string name) { this->name = name; }

void CustomerRecord::attachCar(Car *car) {
    this->cars.push_back(car);
}

void CustomerRecord::detachCar(Car *car) {
    this->cars.remove(car);
}

void CustomerRecord::display() {
    cout << "Name: " << this->getName() << endl;
}


class RentalStore {
    string name;
    list<CustomerRecord *> records;
    list<Car *> stock;
public:
    RentalStore(string name);
    RentalStore();

    string getName();
    void setName(string name);
    void registerOneCustomer(string name);
    void addOneCar(Car *car);
    void displayAvailabelCars();
    void displayRentedCars();
    void rentOneCar(string name, string licensePlate);
    void returnOneCar(string licensePlate);

    ~RentalStore();
};

RentalStore::RentalStore(string name) {
    this->setName(name);
}

RentalStore::RentalStore() : RentalStore("Customer HCMUS") {}

string RentalStore::getName() { return this->name; }
void RentalStore::setName(string name) { this->name = name; }

void RentalStore::registerOneCustomer(string name) {
    CustomerRecord *record = new CustomerRecord(name);
    this->records.push_back(record);
}

void RentalStore::addOneCar(Car *car) {
    this->stock.push_back(car);
}

void RentalStore::displayAvailabelCars() {
    cout << "=== Available Cars ===\n";
    for (auto car : this->stock) {
        if(car->isAvailable()) {
            car->display();
            cout << "================\n";
        }   
    }
}

void RentalStore::displayRentedCars() {
    cout << "=== Rented Cars ===\n";
    for (auto car : this->stock) {
        if(!car->isAvailable()) {
            car->display();
            cout << "================\n";
        }   
    }
}

void RentalStore::rentOneCar(string name, string licensePlate) {
    Car *current_car = nullptr;
    for (auto car : this->stock) {
        if(car->getLicensePlate() == licensePlate) {
            current_car = car;
            break;
        }
    }
    if(current_car == nullptr) {
        cout << "Car with license plate " << licensePlate << " not found!\n";
        return;
    }
    
    if(!current_car->isAvailable()) {
        cout << "Car with license plate " << licensePlate << " is rented!\n";
        return;
    }

    CustomerRecord *current_record = nullptr;
    for (auto record : this->records) {
        if(record->getName() == name) {
            current_record = record;
            break;
        }
    }
    if(current_record == nullptr) {
        cout << "Customer Record with name " << name << " not found!\n";
        return;
    }

    current_car->attachCustomerRecord(current_record);
    current_record->attachCar(current_car);
    cout << "Customer with name " << name << " rent Car " << licensePlate << " successfully\n";
}

void RentalStore::returnOneCar(string licensePlate) {
    Car *current_car = nullptr;
    for (auto car : this->stock) {
        if(car->getLicensePlate() == licensePlate) {
            current_car = car;
            break;
        }
    }
    if(current_car == nullptr) {
        cout << "Car with license plate " << licensePlate << " not found!\n";
        return;
    }
    
    if(current_car->isAvailable()) {
        cout << "Car with license plate " << licensePlate << " is not rented!\n";
        return;
    }

    current_car->detachCustomerRecord();
    cout << "Return Car " << licensePlate << " successfully\n";
}

RentalStore::~RentalStore() {
    this->stock.clear();
    for (auto record : this->records) {
        delete(record);
    }
    this->records.clear();
}

int main() {
    RentalStore *store = new RentalStore("Big Boi");
    cout << "========= RENTAL STORE BIG BOI =========\n";
    Car *car1 = new Car("V1", "Toyota", "123");
    Car *car2 = new Car("V2", "Toyota", "456");
    Car *car3 = new Car("V3", "Toyota", "789");


    store->addOneCar(car1);
    store->addOneCar(car2);
    store->addOneCar(car3);
    store->registerOneCustomer("Thao");
    store->registerOneCustomer("Luong");
    store->rentOneCar("Luong", "123");

    store->rentOneCar("Thao", "345");
    store->rentOneCar("Thao", "123");
    store->rentOneCar("Big Foot", "789");
    store->rentOneCar("Thao", "789");

    store->returnOneCar("345");
    store->returnOneCar("456");
    store->returnOneCar("123");
    
    delete(store);
    delete(car1);
    delete(car2);
    delete(car3);
    return 0;
}
