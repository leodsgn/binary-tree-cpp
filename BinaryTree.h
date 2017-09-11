//
// Created by Leonardo Ribeiro on 30/08/17.
//

#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include "Leaf.h"

template<typename T>
class BinaryTree {
private:
    Leaf<T> *father;

    void addLeaf(T value, Leaf<T> * node);

    void printInOrderPrivate(Leaf<T> * node);

public:

    BinaryTree(T value);

    BinaryTree();

    Leaf<T> *createLeaf(T value);

    void put(T value);

    void printInOrder();
};


#endif //BINARY_TREE_BINARYTREE_H
