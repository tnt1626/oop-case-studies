#include <iostream>
#include <list>
#include <map>
using namespace std;

// --------------------------------Employee--------------------------------
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

    virtual void display() = 0;
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

// --------------------------------Administrator-----------------------------
class Administrator : public Employee {

public:
    Administrator(string number, double salary, string name);
    virtual void display();
};

Administrator::Administrator(
    string number,
    double salary,
    string name
) : Employee(number, salary, name) {}

void Administrator::display() {
    cout << "[Administratror]\n";
    Employee::display();
}

// --------------------------------Programmer--------------------------------
class Programmer : public Employee {
    string language;
public:
    // constructor
    Programmer(string number, double salary, string name, string language);

    // getters
    string getLanguage();

    // setters
    void setLanguage(string language);

    virtual void display();
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


// --------------------------------ProjectLeader--------------------------------
class ProjectLeader : public Programmer {
    list<Programmer *> team;
public:
    ProjectLeader(string number, double salary, string name, string language);
    void addProgrammer(Programmer *programmer);
    void display();
};

ProjectLeader::ProjectLeader(
    string number, 
    double salary, 
    string name, 
    string language) : Programmer(number, salary, name, language) {}

void ProjectLeader::addProgrammer(Programmer *programmer) {
    this->team.push_back(programmer);
}

void ProjectLeader::display() {
    cout << "[Project Leader]\n";
    Employee::display();
    cout << "Team:\n";
    for (auto programmer : this->team) {
        cout << "Name: " << programmer->getName() << endl;
    }
}


// --------------------------------SoftwareHouse--------------------------------
class SoftwareHouse {
    string name;
    map<string, Employee *> staff;
public:
    // constructor
    SoftwareHouse(string name);

    // getters
    string getName();

    // setters
    void setName(string name);
    void addEmployee(Employee *employee);

    virtual void display();
};

SoftwareHouse::SoftwareHouse(string name) {
    this->setName(name);
}

string SoftwareHouse::getName()  { return this->name; }

void SoftwareHouse::setName(string name) {
    this->name = name; 
}

void SoftwareHouse::addEmployee(Employee *employee) {
    string number = employee->getNumber();
    if(this->staff.count(number)) {
        cout << "Employee with number = " << number << " existed\n";
        return;
    }
    this->staff[employee->getNumber()] = employee;
}

void SoftwareHouse::display() {
    cout << "Software House Name: " << this->getName() << endl;
    cout << "========= STAFF =========\n";
    for (auto const& [number, employee] : this->staff) {
        employee->display();
        cout << "========================\n";
    }
}

int main() {
    SoftwareHouse sh("DEV CHỈ THẤY VUI KHI DỰ ÁN HOÀN THÀNH");
    Programmer p1("002", 10, "Midoriya", "Lua");
    Programmer p2("003", 10, "Doraemon", "Golang");
    Programmer p3("004", 10, "Sizuka", "Nodejs");
    ProjectLeader leader("005", 10, "Asta", "Java");
    Administrator admin("006", 10, "Naruto");

    sh.addEmployee(&p1);
    sh.addEmployee(&p2);
    sh.addEmployee(&p3);
    sh.addEmployee(&leader);
    sh.addEmployee(&admin);

    leader.addProgrammer(&p2);
    leader.addProgrammer(&p3);

    // leader.display();

    sh.display();

    return 0;
}