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
class Transcript;
class TranscriptEntry;


// ------------------------------------------------------
//      TranscriptEntry
// ------------------------------------------------------
class TranscriptEntry {
    Section *section;
    double grade;

    void setSection(Section *section);
    void setGrade(double grade);

public:
    TranscriptEntry(Section *section, double grade);
    Section *getSection();
    double getGrade();
};

TranscriptEntry::TranscriptEntry(Section *section, double grade) {
    this->setSection(section);
    this->setGrade(grade);
}

void TranscriptEntry::setSection(Section *section) {
    this->section = section;
}

void TranscriptEntry::setGrade(double grade) {
    this->grade = grade;
}

Section *TranscriptEntry::getSection() {
    return this->section;
}

double TranscriptEntry::getGrade() {
    return this->grade;
}


// ------------------------------------------------------
//      Transcript
// ------------------------------------------------------
class Transcript {
    list<TranscriptEntry *> entries;
public:
    Transcript();   
    ~Transcript();

    void addEntry(TranscriptEntry *entry);
};

Transcript::Transcript() {}

void Transcript::addEntry(TranscriptEntry *entry) {
    entries.push_back(entry);
}

Transcript::~Transcript() {
    for (auto entry : this->entries) {
        delete entry;
    }
    this->entries.clear();
}


// ------------------------------------------------------
//      Course
// ------------------------------------------------------
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
    bool hasPrerequisites();

    void display();

    ~Course();
};


// ------------------------------------------------------
//      Section
// ------------------------------------------------------
class Section {
    string sectionNo;
    string dayOfWeek;
    string timeOfDay;
    string room;
    int seatingCapacity;
    list<Student *> students;
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

    void enroll(Student *student);
    void drop(Student *student);
    void postGrade(Student *student, double grade);
    bool confirmSeatAvailable();

    void display();
};


// ------------------------------------------------------
//      Person
// ------------------------------------------------------
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


// ------------------------------------------------------
//      Professor
// ------------------------------------------------------
class Professor : public Person {
    string title;
    string department;

public:
    Professor(string title, string department, string ssn, string name);

    string getTitle();
    string getDepartment();

    void setTitle(string title);
    void setDepartment(string department);

    virtual void display();
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


// ------------------------------------------------------
//      Student
// ------------------------------------------------------
class Student : public Person {
    string major;
    string degree;
    list<Section *> sections;
    Transcript *transcript;
    
    void setMajor(string major);
    void setDegree(string degree);
public:
    Student(string major, string degree, string ssn, string name);

    Transcript *getTranscript();
    string getMajor();
    string getDegree();

    void setTranscript(Transcript *transcript);
    void addEntry(Section *section, double grade);
    void addSection(Section *section);
    void dropSection(Section *section);
    bool isEnrolledIn(Section *section);

    virtual void display();
    ~Student();
};

Student::Student(
    string major, string degree, string ssn, string name
) : Person(ssn, name) {
    this->setMajor(major);
    this->setDegree(degree);
    this->transcript = new Transcript();
}

Transcript* Student::getTranscript() {
    return this->transcript;
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

void Student::setTranscript(Transcript *transcript) {
    this->transcript = transcript;
}

void Student::addEntry(Section *section, double grade) {
    TranscriptEntry *entry = new TranscriptEntry(section, grade);
    this->transcript->addEntry(entry);
}

void Student::addSection(Section *section) {
    this->sections.push_back(section);
}

void Student::dropSection(Section *section) {
    this->sections.push_back(section);
}

bool Student::isEnrolledIn(Section *section) {
    bool isEnrolled = false;
    string sectionNumber = section->getSectionNo();
    for (auto current : this->sections) {
        if (current->getSectionNo() == sectionNumber) {
            isEnrolled = true;
            break;
        }
    }
    return isEnrolled;
}

void Student::display() {
    cout << "-------------Student-------------" << endl;
    cout << "Ssn: " << this->getSsn() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Major: " << this->getMajor() << endl;
    cout << "Degree: " << this->getDegree() << endl;
}

Student::~Student() {
    delete this->transcript;
}

// ------------------------------------------------------
//      Section
// ------------------------------------------------------
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

void Section::enroll(Student *student) {
    // Testcase 1: No seat available
    if (!this->confirmSeatAvailable()) {
        cout << "Section " << this->getSectionNo() << " has no seat available !!! \n";
        return;
    }

    // Testcase 2: Haven't passed the prerequisites yet

    // Testcase 3: Already enrolled
    string ssn = student->getSsn();
    for (auto currentStudent : this->students) {
        if (currentStudent->getSsn() == ssn) {
            cout << "Student " << ssn << " already enrolled Section " << this->getSectionNo() << endl;
            return;
        }
    }

    // Testcase 4: Enroll successfully
    this->students.push_back(student);
    cout << "Student " << ssn << " enrolled Section " << this->getSectionNo() << " successfully" << endl;
}


void Section::drop(Student *student) {
    bool found = false;
    string ssn = student->getSsn();
    for (auto current : this->students) {
        if (current->getSsn() == ssn) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student " << ssn << " not found in the Section " << this->getSectionNo() << endl;
        return;
    }
    this->students.remove(student);
    cout << "Removed Student " << ssn << " in the Section " << this->getSectionNo() << " successfully" << endl;
}

void Section::postGrade(Student *student, double grade) {
    bool found = false;
    string ssn = student->getSsn();
    for (auto current : this->students) {
        if (current->getSsn() == ssn) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student " << ssn << " not found in the Section " << this->getSectionNo() << endl;
        return;
    }
    student->addEntry(this, grade);
    cout << "Grade " << grade << " posted for Student " << ssn << " studying in Section " << this->getSectionNo() << " successfully\n";
}

bool Section::confirmSeatAvailable() {
    return this->students.size() < this->getSeatingCapacity();
}

void Section::display() {
    cout << "-------------Section-------------" << endl;
    cout << "Section Number: " << this->getSectionNo() << endl;
    cout << "Day of Week: " << this->getDayOfWeek() << endl;
    cout << "Time of Day: " << this->getTimeOfDay() << endl;
    cout << "Room: " << this->getRoom() << endl;
    cout << "Seating Capacity: " << this->getSeatingCapacity() << endl;
    cout << "Students: \n";
    for (auto student : this->students) {
        cout << "\t- Student Ssn: " << student->getSsn() << endl;
    }
    cout << "Course Name: " << this->course->getCourseName() << endl;
}

// ------------------------------------------------------
//      Course
// ------------------------------------------------------
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
    return section;
}

bool Course::hasPrerequisites() {
    return !this->prerequistes.empty();
}

void Course::display() {
    cout << "-------------Course-------------" << endl;
    cout << "Course Number: " << this->getCourseNo() << endl;
    cout << "Course Name: " << this->getCourseName() << endl;
    cout << "Credits: " << this->getCredits() << endl;
    cout << "Prerequisites: \n";
    for (auto prerequisite : this->prerequistes) {
        cout << "\t- Course Name: " << prerequisite->getCourseName() << endl;
    }
    cout << "Sections: \n";
    for (auto pair : this->sections) {
        cout << "\t- Section Number: " << pair.second->getSectionNo() << endl;
    }
}

Course::~Course() {
    for(auto& pair : sections) {
        delete(pair.second);
    }
    sections.clear();
}



// ------------------------------------------------------
//      MAIN
// ------------------------------------------------------
int main() {
    Course oop("MTH10407", "OOP", 4);
    Course dsa("MTH10405", "DSA", 4);
    Course ai ("MTH10410", "AI",  3);

    dsa.addPrerequisite(&oop);
    ai.addPrerequisite(&oop);
    ai.addPrerequisite(&dsa);
    ai.display();

    Student alice("001", "Alice", "Maths",    "Bachelor");
    Student bob  ("002", "Bob",   "Computer", "Bachelor");
    Student carol("003", "Carol", "Physics",  "Bachelor");
    Student dave ("004", "Dave",  "Maths",    "Bachelor");
    alice.display();

    Section* oopSec = oop.scheduleSection("OOP-24-25-2", "Tue", "8:00AM",  "F202",  3);
    Section* dsaSec = dsa.scheduleSection("DSA-24-25-2", "Wed", "8:00AM",  "E202A", 30);
    Section* aiSec  = ai.scheduleSection ("AI-24-25-2",  "Thu", "10:00AM", "B101",  30);
    oopSec->display();
    oop.display();

    return 0;
}