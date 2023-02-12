//
// Created by Hamed on 2/12/2023.
//

#include <iostream>
#include "LinkedListQueue.h"

template<class T>
LinkedListQueue<T>::LinkedListQueue(){
    list = new SinglyLinkedList<T>();
}

template<class T>
LinkedListQueue<T>::~LinkedListQueue() {
    std::cout << "Destructor" << std::endl;

    list->clear();
}

template<class T>
bool LinkedListQueue<T>::isEmpty() {
    return list->isEmpty();
}

template<class T>
void LinkedListQueue<T>::enqueue(T value) {
    list->addLast(value);
}

template<class T>
T LinkedListQueue<T>::dequeue() {
    if (list->isEmpty())
        return {};

    auto value = list->getValueAtIndex(0);
    list->removeFirst();

    return value;
}

template<class T>
T LinkedListQueue<T>::peek() {
    if (list->isEmpty())
        return {};

    auto value = list->getValueAtIndex(0);

    return value;
}

template<class T>
void LinkedListQueue<T>::print() {
    list->print();
}

template<class T>
void LinkedListQueue<T>::clear() {
    list->clear();
}
