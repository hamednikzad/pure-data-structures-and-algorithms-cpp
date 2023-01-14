//
// Created by Hamed on 1/13/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_GENERICLIST_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_GENERICLIST_H

template<class T>
class GenericList {
private:
    T *items;

private:
    void checkCapacity(int size);

    void changeCapacity(int newCapacity);

    void copyArray(T *array, int srcIndex, int dstIndex);

public:
    int count;
    int capacity;

public:
    GenericList(int capacity);

    void print();

    T getValue(int index);

    void addValue(T value);

    void clear();

    int indexOf(T item);

    void insert(int index, T item);
};

#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_GENERICLIST_H
