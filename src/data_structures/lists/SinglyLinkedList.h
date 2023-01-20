//
// Created by Hamed on 1/19/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_SINGLYLINKEDLIST_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_SINGLYLINKEDLIST_H

#include <functional>

template<typename T>
struct linkedListNode {
    T Data;
    linkedListNode<T> *Next;
};

template<class T>
class SinglyLinkedList {
private:
    linkedListNode<T> *head;

private:
    linkedListNode<T> *find(T data);

public:
    int count;

public:
    SinglyLinkedList();

    ~SinglyLinkedList();

    bool isEmpty() { return count == 0; }

    void addFirst(T data);

    void addLast(T data);

    bool contains(T data) { return find(data) != nullptr; }

    void remove(int index);

    void removeLast();

    void removeFirst();

    bool removeValue(T data);

    T getValueAtIndex(int index);

    void print();

    void traverse(std::function<void(T)> func);

    void clear();
};


template struct linkedListNode<int>;
template class SinglyLinkedList<int>;
#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_SINGLYLINKEDLIST_H
