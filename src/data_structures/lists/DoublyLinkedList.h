//
// Created by Hamed on 1/20/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_DOUBLYLINKEDLIST_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_DOUBLYLINKEDLIST_H

template<typename T>
struct doublyLinkedListNode {
    T Data;
    doublyLinkedListNode<T> *Next;
    doublyLinkedListNode<T> *Prev;
};

template<class T>
class DoublyLinkedList {
private:
    doublyLinkedListNode<T> *head;

private:
    doublyLinkedListNode<T> *find(T data);

public:
    int count;

public:
    DoublyLinkedList();

    ~DoublyLinkedList();

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

    void traverse(void (*func)(int));

    void clear();
};

template struct doublyLinkedListNode<int>;
template class DoublyLinkedList<int>;
#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_DOUBLYLINKEDLIST_H
