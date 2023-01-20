//
// Created by Hamed on 1/19/2023.
//

#include <iostream>
#include "SinglyLinkedList.h"

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() : count(0) {}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    std::cout << "Destructor" << std::endl;

    clear();
}

template<class T>
linkedListNode<T> *SinglyLinkedList<T>::find(T data) {
    if (!head)
        return {};

    auto current = head;
    while (current) {
        if (current->Data == data)
            return current;

        current = current->Next;
    }

    return {};
}

template<class T>
void SinglyLinkedList<T>::addFirst(T data) {
    auto newNode = new linkedListNode<T>{data};

    if (!head) {
        head = newNode;
        count++;
        return;
    }

    newNode->Next = head;
    head = newNode;
    count++;
}

template<class T>
void SinglyLinkedList<T>::addLast(T data) {
    auto newNode = new linkedListNode<T>{data};

    if (!head) {
        head = newNode;
        count++;
        return;
    }
    auto current = head;
    while (current->Next) {
        current = current->Next;
    }
    current->Next = newNode;
    count++;
}

template<class T>
void SinglyLinkedList<T>::remove(int index) {
    if (!head || index < 0 || index >= count) {
        return;
    }

    if (index == 0) {
        auto temp = head->Next;
        delete head;
        head = temp;
    } else {
        auto current = head;
        auto prev = head;
        int i = 0;
        while (current && i < index) {
            prev = current;
            current = current->Next;
            i++;
        }

        prev->Next = current->Next;
        delete current;
    }

    count--;
}

template<class T>
void SinglyLinkedList<T>::removeLast() {
    remove(count - 1);
}

template<class T>
void SinglyLinkedList<T>::removeFirst() {
    remove(0);
}

template<class T>
bool SinglyLinkedList<T>::removeValue(T data) {
    if (!head) {
        return false;
    }

    if (head->Data == data) {
        head = head->Next;


        count--;
        return true;
    }

    auto current = head;
    auto prev = head;
    while (current) {
        if (current->Data == data) {
            prev->Next = current->Next;

            count--;
            return true;
        }

        prev = current;
        current = current->Next;
    }

    return false;
}

template<class T>
T SinglyLinkedList<T>::getValueAtIndex(int index) {
    if (!head || index < 0 || index >= count) {
        return {};
    }

    int i = 0;
    auto current = head;
    for (; i != index && current; i++) {
        current = current->Next;
    }

    return current->Data;
}

template<class T>
void SinglyLinkedList<T>::print() {
    printf("Count:%d =>\t", count);
    auto current = head;
    std::string sep = ", ";
    while (current != nullptr) {
        if (!current->Next) {
            sep = "";
        }
        printf("%d %s", current->Data, sep.c_str());
        current = current->Next;
    }
    printf("\n");
}

template<class T>
void SinglyLinkedList<T>::traverse(std::function<void(T)> func) {
    if (!head) {
        return;
    }
    auto current = head;
    while (!current) {
        func(current->Data);
        current = current->Next;
    }
}

template<class T>
void SinglyLinkedList<T>::clear() {
    if (!head)
        return;

    auto current = head;
    while (current){
        auto next = current->Next;
        delete current;
        current = next;
    }
    head = 0;
    count = 0;
}
