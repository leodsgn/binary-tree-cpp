//
// Created by Leonardo Ribeiro on 12/06/17.
//

#ifndef TRABALHO_3A_VA_QUEUE_H
#define TRABALHO_3A_VA_QUEUE_H


#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "QueueNode.h"

using namespace std;

template<typename T>
class Queue {
private:
    QueueNode<T> * firstNode;
    QueueNode<T> * lastNode;
    int size = 0;

public:
    Queue() {
        firstNode = nullptr;
        lastNode = nullptr;
    }

    Queue(QueueNode<T> * node) {
        if(firstNode == nullptr) {
            this->firstNode = node;
            this->lastNode = node;
            size++;
        }
    }

    QueueNode<T> * enqueue(QueueNode<T> * node) {
        if(firstNode == nullptr && lastNode == nullptr) {
            firstNode = node;
            lastNode = node;

            return firstNode;
        }
        else {
            QueueNode<T> * aux = firstNode;
            lastNode = node;
            if(aux->getNextNode() == nullptr) {
                aux->setNextNode(node);
                aux->getNextNode()->setPreviousNode(aux);
                size++;
                return aux->getNextNode();
            }
            else {
                while(aux->getNextNode() != nullptr) {
                    aux = aux->getNextNode();
                }
                aux->setNextNode(node);
                aux->getNextNode()->setPreviousNode(aux);
                size++;

                return aux->getNextNode();
            }
        }
    }

    QueueNode<T> * dequeue() {
        if(firstNode == nullptr && lastNode == nullptr) {
            cout << "No nodes found in this queue" << endl;
            return nullptr;
        }
        else {

            if(firstNode->getNextNode() == nullptr) {
                QueueNode<T> * aux = firstNode;
                firstNode = nullptr;
                lastNode = nullptr;
                cout << "Queue is now empty" << endl;
                size--;
                return aux;
            }

            else {
                QueueNode<T> * aux = firstNode;
                firstNode = aux->getNextNode();
                firstNode->setPreviousNode(nullptr);

                size--;

                return aux;
            }
        }
    }

    QueueNode<T> * getFirstNode() {
        return firstNode;
    }


    int getSize() {
        return size;
    }
};

#endif //TRABALHO_3A_VA_QUEUE_H