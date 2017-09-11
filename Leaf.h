//
// Created by Leonardo Ribeiro on 30/08/17.
//

#ifndef BINARY_TREE_LEAF_H
#define BINARY_TREE_LEAF_H

template<typename T>
class Leaf {
private:
    T value;
    Leaf<T> * left; // values lower then actual leaf
    Leaf<T> * right; // values higher then actual leaf
    Leaf<T> * parent; // parent node if it has it

public:

    Leaf(T value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    T getValue() {
        return value;
    }

    void setValue(T value) {
        this->value = value;
    }

    Leaf * getLeftChildren() {
        return left;
    }

    void setLeftChildren(T value) {
        this->left = new Leaf(value);
        this->left->parent = this;
    }

    Leaf * getRightChildren() {
        return right;
    }

    void setRightChildren(T value) {
        this->right = new Leaf(value);
        this->right->parent = this;
    }
};


#endif //BINARY_TREE_LEAF_H
