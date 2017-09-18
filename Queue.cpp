//
// Created by Leonardo Ribeiro on 13/09/17.
//

#include "Queue.h"


bool Queue::empty();
int Queue::size();
template<typename T>
QueueNode<T> Queue::front();
template<typename T>
QueueNode<T> Queue::back();
void Queue::push_back();
void Queue::pop_front();