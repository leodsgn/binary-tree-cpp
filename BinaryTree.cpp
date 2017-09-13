#include <iostream>
#include <math.h>
#include <queue>
#include "BinaryTree.h"

using namespace std;

const int SPACE = 2;

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

//    if(node != nullptr) {
//
//        if (node->getLeftChildren() != nullptr) {
//            printInOrderPrivate(node->getLeftChildren());
//        }
//
//        cout << node->getValue();
//
//        if (node->getRightChildren() != nullptr) {
//            printInOrderPrivate(node->getRightChildren());
//        }
//    }
//
//    else {
//        cout << "The tree is empty." << endl;
//    }
}


void BinaryTree::printTree() {
    printTreePrivate(father, getDepth());
}

template<typename T>
int BinaryTree::getDepth() {
    Leaf<T> * node = father;
    return getDepthPrivate(node);
}

template<typename T>
void BinaryTree::printNodePrivate(Leaf<T> * node, int spaces) {
    try {
        if (node != nullptr) {
            if (spaces != 0 && spaces % 2 == 0) {
                int depth = 0;

                while (depth < spaces / 2) {
                    cout << ' ';
                    depth++;
                }
                cout << node->getValue();
                while (depth < spaces / 2) {
                    cout << ' ';
                    depth++;
                }
            }

            else {
                throw 'Spaces should have 0 as rest.';
            }
        }
    }
    catch (string error) {
        cout << error << endl;
    }
}

template<typename T>
void BinaryTree::printTreePrivate(Leaf<T> * node, int spaces) {

}

template<typename T>
int BinaryTree::getDepthPrivate(Leaf<T> * node, int depth = 0) {
    int depthLeft = 0;
    int depthRight = 0;

    if (node != nullptr) {
        if (node->getLeftChildren() != nullptr) {
            depthLeft += getDepthPrivate(node->getLeftChildren(), depth + 1);
        }
        else if (node->getRightChildren() != nullptr) {
            depthRight += getDepthPrivate(node->getRightChildren(), depth + 1);
        }
    }

    return depthLeft >= depthRight ? (int) pow(2, depthLeft) : (int) pow(2, depthRight);
}