//
// Created by Hamed on 1/13/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_GENERICLIST_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_GENERICLIST_H

#include <stdexcept>

template<class T>
class GenericList {
private:
    T *items;

private:
    void checkCapacity(int size);

    void changeCapacity(int newCapacity);

public:
    int count;
    int capacity;

public:
    GenericList(int capacity);

    ~GenericList();

    void print();

    T getValue(int index);

    void addValue(T value);

    void clear();

    int indexOf(T item);

    void insert(int index, T value);

    bool contains(T item);
};

template<class T>
GenericList<T>::GenericList(int capacity): capacity(10), count(0) {
    if(capacity <= 0)
        throw std::invalid_argument("Capacity should be non negative");

    items = new T[capacity];
}

template<class T>
GenericList<T>::~GenericList() {
    delete[] items;
}

template class GenericList<int>;
#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_GENERICLIST_H
