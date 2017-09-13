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

    void printTreePrivate(Leaf<T> * node, int spaces);

    void printNodePrivate(Leaf<T> * node, int spaces);

    int getDepthPrivate(Leaf<T> * node, int depth = 0);

public:

    BinaryTree(T value);

    BinaryTree();

    Leaf<T> *createLeaf(T value);

    void put(T value);

    void printInOrder();

    void printTree();

    int getDepth();
};


#endif //BINARY_TREE_BINARYTREE_H
