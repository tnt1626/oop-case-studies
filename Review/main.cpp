#include <iostream>
#include <list>
#include <string>
using namespace std;

class MemberRecord;

// ----------------------------Package----------------------------
class Package {
    string packageID;
    string instructor;
    string title;

    MemberRecord *record;

public:
    Package(string packageID, string instructor, string title);
    Package(string packageID, string instructor);

    string getPackageID();
    string getInstructor();
    string getTitle();
    MemberRecord *getRecord();
    
    bool isAvailable();

    void setPackageID(string packageID);
    void setInstructor(string instructor);
    void setTitle(string title);

    void attachMember(MemberRecord *member);
    void dettachMember();

    void display();
};

// Constructor
Package::Package(string packageID, string instructor, string title) {
    this->setPackageID(packageID);
    this->setInstructor(instructor);
    this->setTitle(title);
    this->record = nullptr;
}   

Package::Package(string packageID, string instructor): Package(packageID, instructor, "") {}

bool Package::isAvailable() {
    return this->record == nullptr;
}

string Package::getPackageID() { return this->packageID; }
string Package::getInstructor() { return this->instructor; }
string Package::getTitle() { return this->title; }
MemberRecord *Package::getRecord() { return this->record; }

void Package::setPackageID(string packageID) {
    this->packageID = packageID; 
}
void Package::setInstructor(string instructor) {
    this->instructor = instructor; 
}
void Package::setTitle(string title) {
    this->title = title; 
}

void Package::attachMember(MemberRecord *record) {
    this->record = record;
}

void Package::dettachMember() {
    this->record = nullptr;
}

void Package::display() {
    cout << "Package ID: " << this->getPackageID() << endl;
    cout << "Instructor: " << this->getInstructor() << endl;
    cout << "Title: " << this->getTitle() << endl;
}

// ----------------------------MemberRecord----------------------------
class MemberRecord {
    string name;

    list<Package *> memberShipPackages;
public:
    MemberRecord(string name);
    MemberRecord();

    string getName();
    
    void setName(string name);

    void attachPackage(Package *package);
    void dettachPackage(Package *package);
};

MemberRecord::MemberRecord(string name) {
    this->setName(name);
}

MemberRecord::MemberRecord(): MemberRecord("HCMUS Member") {}

string MemberRecord::getName() {
    return this->name;
}

void MemberRecord::setName(string name) {
    this->name = name;
}

void MemberRecord::attachPackage(Package *package) {
    this->memberShipPackages.push_back(package);
}

void MemberRecord::dettachPackage(Package *package) {
    this->memberShipPackages.remove(package);
}





// ----------------------------Gym----------------------------
class Gym {
    string name;
    list<Package *> membershipPackages;
    list<MemberRecord *> memberRecords;

public:
    Gym(string name = "HCMUS Super Gym");

    void setName(string name);
    string getName();

    void registerOneMember(string memberName);
    void addNewPackage(Package *package);
    void displayPackageAvailable();
    void displayPackagesActive();
    void assignPackage(string packageID, string memberName);
    void terminatePackage(string packageID);

    ~Gym();
};

Gym::Gym(string name) {
    this->setName(name);
}

void Gym::setName(string name) {
    this->name = name;
}

string Gym::getName() {
    return this->name;
}

void Gym::registerOneMember(string memberName) {
    MemberRecord *newMember = new MemberRecord(memberName);
    this->memberRecords.push_back(newMember);
}

void Gym::addNewPackage(Package *package) {
    this->membershipPackages.push_back(package);
}

void Gym::displayPackageAvailable() {
    cout << "--------Available Packages--------\n";
    for (auto package: this->membershipPackages) {
        if (package->isAvailable()) {
            package->display();
            cout << "----------------------------------\n";
        }
    }
}

void Gym::displayPackagesActive() {
    cout << "--------Active Packages--------\n";
    for (auto package: this->membershipPackages) {
        if (!package->isAvailable()) { // Not available is active
            package->display();
            cout << "----------------------------------\n";
        }      
    }
}

void Gym::assignPackage(string packageId, string memberName) {
    Package *currentPackage = nullptr;
    for (auto package : this->membershipPackages) {
        if (package->getPackageID() == packageId) {
            currentPackage = package;
            break;
        }
    }
    // Test case 1: package ID is NA
    if (currentPackage == nullptr) {
        cout << "Package with ID = " << packageId << " is not found\n";
        return;
    }

    // Test case 2: Package with ID is not available
    if (!currentPackage->isAvailable()) {
        cout << "Package with ID = " << packageId << "is not available. Let's consider another package! \n";
        return;
    }

    MemberRecord *currentRecord = nullptr;
    for (auto record : this->memberRecords) {
        if (record->getName() == memberName) {
            currentRecord = record;
            break;
        }
    }

    // Test case 3: Member record is not found
    if (currentRecord == nullptr) {
        cout << "Member record with name = " << memberName << " is not found. Let's register! \n";
        return;
    }

    // Test case 4: Assign package successfully!
    currentPackage->attachMember(currentRecord);
    currentRecord->attachPackage(currentPackage);
    cout << "Member with name = " << memberName << " assign a package with ID " << packageId << " successfully! \n";

}

void Gym::terminatePackage(string packageID) {
    Package *currentPackage = nullptr;
    for (auto package : this->membershipPackages) {
        if (package->getPackageID() == packageID) {
            currentPackage = package;
            break;
        }
    }
    // Test case 1: Package ID is NA
    if (currentPackage == nullptr) {
        cout << "Package with ID = " << packageID << " is not found\n";
        return;
    }

    MemberRecord *currentRecord = currentPackage->getRecord();
    // Test case 2: Member is not found
    if (currentRecord == nullptr) {
        cout << "There is no member assigning package with ID = " << packageID << endl;
        return;
    }

    // Test case 3: Terminate package successfully!
    currentPackage->dettachMember();
    currentRecord->dettachPackage(currentPackage);
    cout << "Terminate package with ID = " << packageID << " successfully! \n";
}

Gym::~Gym() {
    for (auto record : this->memberRecords) {
        delete(record);
    }
    this->memberRecords.clear();
    this->membershipPackages.clear();
}

int main() {
    Gym BGym = Gym("BGYM Hiep Binh Chanh");

    Package* p1 = new Package("P001", "Hoang Master", "Yoga Flow");
    Package* p2 = new Package("P002", "Minh Coach", "Power Lifting");
    Package* p3 = new Package("P003", "Long Pro", "Kick Boxing");
    Package* p4 = new Package("P004", "An Trainer", "Pilates Sculpt");
    Package* p5 = new Package("P005", "Hoa Sensei", "Zumba Dance");

    BGym.addNewPackage(p1);
    BGym.addNewPackage(p2);
    BGym.addNewPackage(p3);
    BGym.addNewPackage(p4);
    BGym.addNewPackage(p5);

    BGym.registerOneMember("Member 1");
    BGym.registerOneMember("Member 2");

    // Test case 1
    BGym.assignPackage("P006", "Member 1");
    // Test case 4
    BGym.assignPackage("P001", "Member 2");
    // Test case 2
    BGym.assignPackage("P001", "Member 1");
    // Test case 3
    BGym.assignPackage("P002", "Member 3");

    // BGym.displayPackageAvailable();

    // Test case 1
    BGym.terminatePackage("P006");
    // Test case 2
    BGym.terminatePackage("P003");
    // Test case 3
    BGym.terminatePackage("P001");

    delete(p1);
    delete(p2);
    delete(p3);
    delete(p4);
    delete(p5);

    return 0;
}