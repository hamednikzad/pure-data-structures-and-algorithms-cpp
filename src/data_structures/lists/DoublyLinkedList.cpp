//
// Created by Hamed on 1/20/2023.
//

#include <iostream>
#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : count(0) {}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    std::cout << "Destructor" << std::endl;

    clear();
}

template<class T>
doublyLinkedListNode<T> *DoublyLinkedList<T>::find(T data) {
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
void DoublyLinkedList<T>::addFirst(T data) {
    auto newNode = new doublyLinkedListNode<T>{data};

    if (!head) {
        head = newNode;
        count++;
        return;
    }

    newNode->Next = head;
    head->Prev = newNode;
    head = newNode;
    count++;
}

template<class T>
void DoublyLinkedList<T>::addLast(T data) {
    auto newNode = new doublyLinkedListNode<T>{data};

    if (!head) {
        head = newNode;
        count++;
        return;
    }
    auto current = head;
    while (current->Next) {
        current = current->Next;
    }
    newNode->Prev = current;
    current->Next = newNode;
    count++;
}

template<class T>
void DoublyLinkedList<T>::remove(int index) {
    if (!head || index < 0 || index >= count) {
        return;
    }

    if (index == 0) {
        auto temp = head->Next;
        delete head;
        head = temp;
        if (head) {
            head->Prev = 0;
        }
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
        if (current->Next) {
            current->Next->Prev = prev;
        }
        delete current;
    }

    count--;
}

template<class T>
void DoublyLinkedList<T>::removeLast() {
    remove(count - 1);
}

template<class T>
void DoublyLinkedList<T>::removeFirst() {
    remove(0);
}

template<class T>
bool DoublyLinkedList<T>::removeValue(T data) {
    if (!head) {
        return false;
    }

    if (head->Data == data) {
        head = head->Next;

        if (head) {
            head->Prev = 0;
        }

        count--;
        return true;
    }

    auto current = head;
    auto prev = head;
    while (current) {
        if (current->Data == data) {
            prev->Next = current->Next;

            if (current->Next) {
                current->Next->Prev = prev;
            }

            count--;
            return true;
        }

        prev = current;
        current = current->Next;
    }

    return false;
}

template<class T>
T DoublyLinkedList<T>::getValueAtIndex(int index) {
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
void DoublyLinkedList<T>::print() {
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
void DoublyLinkedList<T>::traverse(void (*func)(int)) {
    if (!head) {
        return;
    }
    auto current = head;
    while (current) {
        func(current->Data);
        current = current->Next;
    }
}

template<class T>
void DoublyLinkedList<T>::clear() {
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
