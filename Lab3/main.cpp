#include <iostream>
#include <string>

using namespace std;

// -------------------Class Person -------------------
class Person {
    string ssn;
    string name;

public:
    Person(string ssn, string name);

    string getSsn();
    string getName();

    void setSsn(string ssn);
    void setName(string name);

    virtual void display() = 0;
};

Person::Person(string ssn, string name) {
    this->setSsn(ssn);
    this->setName(name);
}

string Person::getSsn() {
    return this->ssn;
}

string Person::getName() {
    return this->name;
}

void Person::setSsn(string ssn) {
    this->ssn = ssn;
}

void Person::setName(string name) {
    this->name = name;
}


// -------------------Class Professor -------------------
class Professor : public Person {
    string title;
    string department;

public:
    Professor(string title, string department, string ssn, string name);

    string getTitle();
    string getDepartment();

    void setTitle(string title);
    void setDepartment(string department);

    void display();
};

Professor::Professor(
    string title, string department, string ssn, string name
) : Person(ssn, name) {
    this->setTitle(title);
    this->setDepartment(department);
}

string Professor::getTitle() {
    return this->title;
}

string Professor::getDepartment() {
    return this->department;
}

void Professor::setTitle(string title) {
    this->title = title;
}

void Professor::setDepartment(string department) {
    this->department = department;
}

void Professor::display() {
    cout << "-------------Professor-------------" << endl;
    cout << "Ssn: " << this->getSsn() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Title: " << this->getTitle() << endl;
    cout << "Department: " << this->getDepartment() << endl;
}


// -------------------Class Student -------------------
class Student : public Person {
    string major;
    string degree;

public:
    Student(string major, string degree, string ssn, string name);

    string getMajor();
    string getDegree();

    void setMajor(string major);
    void setDegree(string degree);

    void display();
};

Student::Student(
    string major, string degree, string ssn, string name
) : Person(ssn, name) {
    this->setMajor(major);
    this->setDegree(degree);
}

string Student::getMajor() {
    return this->major;
}

string Student::getDegree() {
    return this->degree;
}

void Student::setMajor(string major) {
    this->major = major;
}

void Student::setDegree(string degree) {
    this->degree = degree;
}

void Student::display() {
    cout << "-------------Student-------------" << endl;
    cout << "Ssn: " << this->getSsn() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Major: " << this->getMajor() << endl;
    cout << "Degree: " << this->getDegree() << endl;
}

int main() {
    Student haha("Computing", "Master", "123", "Haha");
    Professor hihi("Supa supa", "Math", "567", "Hihi");

    haha.display();

    hihi.display();
    return 0;
}