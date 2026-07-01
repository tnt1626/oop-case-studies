#include <iostream>
#include <list>

using namespace std;

class Object;
class Image;
class Audio;
class HTMLFile;

// ---------------------
//   OBJECT
// ---------------------
class Object {
    string name;

public:
    Object(string name);

    void setName(string name);
    string getName();
    virtual void display() = 0;
    virtual int calculateObject() = 0;
};

Object::Object(string name) {
    this->setName(name);
}

void Object::setName(string name) {
    this->name = name;
}

string Object::getName() {
    return this->name;
}

// ---------------------
//   IMAGE
// ---------------------
class Image : public Object {
public:
    Image(string name);

    virtual void display();
    virtual int calculateObject();
};

Image::Image(string name) : Object(name) {}

void Image::display() {
    cout << "Image: " << this->getName() << endl;
}

int Image::calculateObject() {
    return 1;
}

// ---------------------
//   AUDIO
// ---------------------
class Audio : public Object {
public:
    Audio(string name);

    virtual void display();
    virtual int calculateObject();
};

Audio::Audio(string name) : Object(name) {}

void Audio::display() {
    cout << "Audio: " << this->getName() << endl;
}

int Audio::calculateObject() {
    return 1;
}

class HTMLFile : public Object {
    list<Object *> objects;
public:
    HTMLFile(string name);

    void addObject(Object *object);
    void removeObject(Object *object);
    virtual void display();
    virtual int calculateObject();
};

HTMLFile::HTMLFile(string name) : Object(name) {}

void HTMLFile::addObject(Object *object) {
    if (object == nullptr) {
        return;
    }
    this->objects.push_back(object);
}

void HTMLFile::removeObject(Object *object) {
    this->objects.remove(object);
}

void HTMLFile::display() {
    cout << "HTML File: " << this->getName() << endl;
    for (auto object : this->objects) {
        object->display();
    }
}

int HTMLFile::calculateObject() {
    int count = 1;
    for (auto object : this->objects) {
        count += object->calculateObject();
    }
    return count;
}

int main() {
    HTMLFile home("home.html");
    HTMLFile header("header.html");
    HTMLFile main("main.html");
    HTMLFile footer("footer.html");
    Image picture1("header.png");
    Image picture2("main.png");
    Audio audio("audio.mp3");

    home.addObject(&header);
    home.addObject(&main);
    home.addObject(&footer);
    header.addObject(&picture1);
    main.addObject(&picture2);
    main.addObject(&audio);

    home.display();
    cout << "Number of object in home.hmtl: " << home.calculateObject() << endl;
    return 0;
}