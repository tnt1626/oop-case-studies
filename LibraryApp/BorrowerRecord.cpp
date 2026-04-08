#include "BorrowerRecord.hpp"

using namespace std;

BorrowerRecord::BorrowerRecord(string name) {
    this->setName(name);
    this->books = {};
}

BorrowerRecord::BorrowerRecord(): BorrowerRecord("An danh") {}

void BorrowerRecord::setName(string name) {
    this->name = name;
}

string BorrowerRecord::getName() {
    return this->name;
}

void BorrowerRecord::attachBook(Book *book) {
    books.push_front(book);
}

void BorrowerRecord::detachBook(Book *book) {
    this->books.remove(book);
}
