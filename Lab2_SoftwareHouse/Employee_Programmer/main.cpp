#include <iostream>
#include <list>
using namespace std;

class Employee {
    string number;
    double salary;
    string name;
public:
    // constructor
    Employee(string number, double salary, string name);

    // getters
    string getNumber();
    double  getSalary();
    string getName();

    // setters
    void setNumber(string number);
    void setSalary(double salary);
    void setName(string name);

    void display();
};

Employee::Employee(string number, double salary, string name) {
    this->setNumber(number);
    this->setSalary(salary);
    this->setName(name);
}

string Employee::getNumber()  { return this->number; }
double Employee::getSalary()  { return this->salary; }
string Employee::getName()  { return this->name; }

void Employee::setNumber(string number) {
    this->number = number; 
}
void Employee::setSalary(double salary) {
    this->salary = salary; 
}
void Employee::setName(string name) {
    this->name = name; 
}

void Employee::display() {
    cout << "Number  : " << this->getNumber() << endl;
    cout << "Salary  : " << this->getSalary() << endl;
    cout << "Name    : " << this->getName() << endl;
}


class Programmer : public Employee {
    string language;
public:
    // constructor
    Programmer(string number, double salary, string name, string language);

    // getters
    string getLanguage();

    // setters
    void setLanguage(string language);

    void display();
};

Programmer::Programmer(
    string number,
    double salary,
    string name,
    string language 
) : Employee(number, salary, name) {
    this->setLanguage(language);
}

string Programmer::getLanguage()  { return this->language; }

void Programmer::setLanguage(string language) {
    this->language = language; 
}

void Programmer::display() {
    cout << "[Programmer]\n";
    Employee::display();
    cout << "Language: " << this->getLanguage() << endl;
}

class SoftwareHouse {
    string name;
    list<Programmer *> programmers;
public:
    // constructor
    SoftwareHouse(string name);

    // getters
    string getName();

    // setters
    void setName(string name);
    void addProgrammer(Programmer *programmer);

    void display();
};

SoftwareHouse::SoftwareHouse(string name) {
    this->setName(name);
}

string SoftwareHouse::getName()  { return this->name; }

void SoftwareHouse::setName(string name) {
    this->name = name; 
}

void SoftwareHouse::addProgrammer(Programmer *programmer) {
    this->programmers.push_back(programmer);
}

void SoftwareHouse::display() {
    cout << "Software House Name: " << this->getName() << endl;
    for (auto programmer : this->programmers) {
        programmer->display();
    }
}

int main() {
    SoftwareHouse sh("DEV CHỈ THẤY VUI KHI DỰ ÁN HOÀN THÀNH");
    Employee e1("001", 10, "Midoriya");
    Programmer p1("002", 10, "Midoriya", "Lua");
    Programmer p2("003", 10, "Doraemon", "Golang");

    sh.addProgrammer(&p1);
    sh.addProgrammer(&p2);

    sh.display();

    return 0;
}