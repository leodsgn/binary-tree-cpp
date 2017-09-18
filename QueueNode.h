//
// Created by Leonardo Ribeiro on 12/06/17.
//

#ifndef TRABALHO_3A_VA_NODE_H
#define TRABALHO_3A_VA_NODE_H

template<typename T>
class QueueNode {

private:
    T * value;
    QueueNode<T> * nextNode;
    QueueNode<T> * previousNode;

public:
    QueueNode(T * value){
        this->value = value;
        nextNode = nullptr;
        previousNode = nullptr;
    }

    QueueNode(){
        value = nullptr;
        nextNode = nullptr;
        previousNode = nullptr;
    }

    void setValue(T * value) {
        this->value = value;
    }

    void setNextNode(QueueNode<T> * node) {
        this->nextNode = node;
    }

    void deleteNextNode() {
        this->nextNode = nullptr;
    }

    void setPreviousNode(QueueNode<T> * node) {
        this->previousNode = node;
    }

    void deletePreviousNode() {
        this->previousNode = nullptr;
    }

    T * getValue() {
        return this->value;
    }

    QueueNode<T> * getNextNode() {
        return this->nextNode;
    }

    QueueNode<T> * getPreviousNode() {
        return this->previousNode;
    }
};

#endif //TRABALHO_3A_VA_NODE_H