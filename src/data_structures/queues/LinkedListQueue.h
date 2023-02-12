//
// Created by Hamed on 2/12/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_LINKEDLISTQUEUE_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_LINKEDLISTQUEUE_H

#include "../lists/SinglyLinkedList.h"

template<class T>
class LinkedListQueue {
private:
    SinglyLinkedList<T> *list;

public:
    LinkedListQueue();

    ~LinkedListQueue();

    bool isEmpty();

    void enqueue(T value);

    T dequeue();

    T peek();

    void print();

    void clear();
};

template class LinkedListQueue<int>;
#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_LINKEDLISTQUEUE_H
