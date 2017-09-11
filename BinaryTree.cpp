#include <iostream>
#include "BinaryTree.h"

using namespace std;


BinaryTree::BinaryTree() {}

template<typename T>
BinaryTree::BinaryTree(T value) {
    father = new Leaf<T>(value);
}

template<typename T>
void BinaryTree::addLeaf(T value, Leaf<T> * node) {

    if (node == nullptr) {
        node = createLeaf(value);
        addLeaf(value, node);
    }

    else if (value < node->getValue()) {
        if (node->getLeftChildren() == nullptr) {
            node->setLeftChildren(value);
        }
        else {
            addLeaf(value, node->getLeftChildren());
        }
    }

    else if (value > node->getLeftChildren()) {
        if (node->getRightChildren() == nullptr) {
            node->setRightChildren(value);
        }
        else {
            addLeaf(value, node->getRightChildren());
        }
    }
}

template<typename T>
Leaf<T> *BinaryTree::createLeaf(T value) {
    return new Leaf<T>(value);
}

template<typename T>
void BinaryTree::put(T value) {
    Leaf<T> * node = father;
    addLeaf(value, node);
}

void BinaryTree::printInOrder() {
    printInOrderPrivate(father);
}

template<typename T>
void BinaryTree::printInOrderPrivate(Leaf<T> * node) {

    if(node != nullptr) {}
    else {
        cout << "The tree is empty." << endl;
    }
}