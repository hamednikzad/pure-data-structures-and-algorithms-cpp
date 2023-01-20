//
// Created by Hamed on 1/13/2023.
//

#include "GenericList.h"
#include <stdexcept>
#include <iostream>

using std::cout;

template<class T>
void GenericList<T>::checkCapacity(int size) {
    if (capacity >= size) {
        return;
    }

    int newCapacity = count * 2;

    if (newCapacity < size) {
        newCapacity = size;
    }

    changeCapacity(newCapacity);
}

template<class T>
void GenericList<T>::changeCapacity(int newCapacity) {
    if (newCapacity <= count) {
        throw std::out_of_range("Capacity out of range");
    }

    if (newCapacity == capacity) {
        return;
    }

    if (newCapacity > 0) {
        T *newItems;
        newItems = new T[newCapacity];
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                newItems[i] = items[i];
            }
        }
        delete[] items;

        items = std::move(newItems);
    }

    capacity = newCapacity;
}

template<class T>
void GenericList<T>::print() {
    cout << "Capacity: " << capacity << ", Count: " << count << std::endl;
    std::string sep;
    for (int i = 0; i < count; ++i) {
        sep = ", ";
        if (i == count - 1) {
            sep = "";
        }
        cout << items[i] << sep;
    }
    cout << std::endl;
}

template<class T>
T GenericList<T>::getValue(int index) {
    if (index < 0 || index >= count) return {};

    return items[index];
}

template<class T>
void GenericList<T>::addValue(T value) {
    if (count == capacity) {
        checkCapacity(count + 1);
    }

    items[count++] = std::move(value);
}

template<class T>
void GenericList<T>::clear() {
    if (count <= 0) {
        return;
    }

    for (int i = 0; i < count; i++) {
        items[i] = {};
    }
    count = 0;
}

template<class T>
int GenericList<T>::indexOf(T item) {
    for (int i = 0; i < count; i++) {
        if (items[i] == item) {
            return i;
        }
    }
    return -1;
}

template<class T>
void GenericList<T>::insert(int index, T value) {
    if (index < 0 || index > count) {
        cout << "index out of range";
        return;
    }
    if (count == capacity) {
        checkCapacity(count + 1);
    }
    if (index < count) {
        for (int i = count; i > index; i--) {
            items[i] = items[i - 1];
        }
    }
    items[index] = value;
    count++;
}

template<class T>
bool GenericList<T>::contains(T item) {
    for (int i = 0; i < count; i++) {
        if (items[i] == item) {
            return true;
        }
    }
    return false;
}

//template class GenericList<int>;