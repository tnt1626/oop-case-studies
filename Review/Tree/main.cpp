#include <iostream>
#include <list>

using namespace std;

class Node;
class Leaf;
class Tree;

class Node {
    int value;

public:
    Node(int value = 0);

    void setValue(int value);
    int getValue();
    virtual void display() = 0;
    virtual int calculateChildrenValue() = 0;
};

Node::Node(int value) {
    this->setValue(value);
}

void Node::setValue(int value) {
    this->value = value;
}

int Node::getValue() {
    return this->value;
}

class Leaf : public Node {
public:
    Leaf(int value);

    virtual void display();
    virtual int calculateChildrenValue();
};

Leaf::Leaf(int value) : Node(value) {}

void Leaf::display() {
    cout << "Leaf Node with value: " << this->getValue() << endl;
    return;
}

int Leaf::calculateChildrenValue() {
    return this->getValue();
}

class Tree : public Node {
    list<Node *> children;

public:
    Tree(int value);

    void addNode(Node *node);
    void removeNode(Node *node);
    virtual void display();
    virtual int calculateChildrenValue();
};

Tree::Tree(int value) : Node(value) {}

void Tree::addNode(Node *node) {
    if (node == nullptr) {
        return;
    }
    this->children.push_back(node);
}

void Tree::removeNode(Node *node) {
    this->children.remove(node);
}

void Tree::display() {
    cout << "Node's Value: " << this->getValue() << endl;
    cout << "Children Node: \n";
    for (auto node : this->children) {
        node->display();
    }
}

int Tree::calculateChildrenValue() {
    int sum = this->getValue();
    for (auto node : this->children) {
        sum += node->calculateChildrenValue();
    }
    return sum;
}

int main() {
    Leaf l1(2);
    Leaf l2(7);
    Leaf right(15);
    Tree left(5);
    Tree root(10);

    left.addNode(&l1);
    left.addNode(&l2);

    // left.display();

    root.addNode(&left);
    root.addNode(&right);

    root.display();
    cout << "Sum of Tree: " << root.calculateChildrenValue() << endl;
    return 0;
}