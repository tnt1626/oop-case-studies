#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Person;
class Student;
class Professor;
class Course;
class Section;

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

// -------------------Class Section -------------------
class Section {
    string sectionNo;
    string dayOfWeek;
    string timeOfDay;
    string room;
    int seatingCapacity;
    Course *course;

    void setCourse(Course *course);
public:
    Section(
        string sectionNo, string dayOfWeek, string timeOfDay, 
        string room, int seatingCapacity, Course *course
    );

    string getSectionNo();
    string getDayOfWeek();
    string getTimeOfDay();
    string getRoom();
    int getSeatingCapacity();

    void setSectionNo(string sectionNo);
    void setDayOfWeek(string dayOfWeek);
    void setTimeOfDay(string timeOfDay);
    void setRoom(string room);
    void setSeatingCapacity(int seatingCapacity);
};

Section::Section(
    string sectionNo, string dayOfWeek, string timeOfDay, 
    string room, int seatingCapacity, Course *course
) {
    this->setSectionNo(sectionNo);
    this->setDayOfWeek(dayOfWeek);
    this->setTimeOfDay(timeOfDay);
    this->setRoom(room);
    this->setSeatingCapacity(seatingCapacity);
    this->setCourse(course);
}   

string Section::getSectionNo() { return this->sectionNo; }
string Section::getDayOfWeek() { return this->dayOfWeek; }
string Section::getTimeOfDay() { return this->timeOfDay; }
string Section::getRoom() { return this->room; }
int Section::getSeatingCapacity() { return this->seatingCapacity; }

void Section::setCourse(Course *course) {
    this->course = course;
}

void Section::setSectionNo(string sectionNo) {
    this->sectionNo = sectionNo; 
}
void Section::setDayOfWeek(string dayOfWeek) {
    this->dayOfWeek = dayOfWeek; 
}
void Section::setTimeOfDay(string timeOfDay) {
    this->timeOfDay = timeOfDay; 
}
void Section::setRoom(string room) {
    this->room = room; 
}
void Section::setSeatingCapacity(int seatingCapacity) {
    this->seatingCapacity = seatingCapacity; 
}



// -------------------Class Course -------------------
class Course {
    string courseNo;
    string courseName;
    int credits;
    list<Course *> prerequistes;
    map<string, Section *> sections;

public:
    Course(string courseNo, string courseName, int credits);

    string getCourseNo();
    string getCourseName();
    int getCredits();

    void setCourseName(string courseName);
    void setCredits(int credits);
    void setCourseNo(string courseNo);

    void addPrerequisite(Course *course);
    Section* scheduleSection(
        string sectionNo, string dayOfWeek, string timeOfDay, 
        string room, int seatingCapacity
    );

    ~Course();
};

Course::Course(string courseNo, string courseName, int credits) {
    this->setCourseNo(courseNo);
    this->setCourseName(courseName);
    this->setCredits(credits);
}

string Course::getCourseNo() {
    return this->courseNo;
}

string Course::getCourseName() {
    return this->courseName;
}

int Course::getCredits() {
    return this->credits;
}

void Course::setCourseNo(string courseNo) {
    this->courseNo = courseNo;
}

void Course::setCourseName(string courseName) {
    this->courseName = courseName;
}

void Course::setCredits(int credits) {
    this->credits = credits;
}

void Course::addPrerequisite(Course *course) {
    this->prerequistes.push_back(course);
}

Section* Course::scheduleSection(
    string sectionNo, string dayOfWeek, string timeOfDay, 
    string room, int seatingCapacity
) {
    Course *course = this;
    Section *section = new Section(sectionNo, dayOfWeek, timeOfDay, room, seatingCapacity, course);

    this->sections[sectionNo] = section;
}

Course::~Course() {
    for(auto& pair : sections) {
        delete(pair.second);
    }
    sections.clear();
}

int main() {
    Student haha("Computing", "Master", "123", "Haha");
    Professor hihi("Supa supa", "Math", "567", "Hihi");

    haha.display();

    hihi.display();
    return 0;
}