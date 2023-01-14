//
// Created by Hamed on 1/13/2023.
//

#include "GenericList.h"
#include <stdexcept>
#include <iostream>

using std::cout;

template<class T>
GenericList<T>::GenericList(int capacity): capacity(10), count(0) {
    if(capacity <= 0)
        throw std::invalid_argument("Capacity should be non negative");

    items = new T[capacity];
}

template<class T>
void GenericList<T>::checkCapacity(int size) {

}

template<class T>
void GenericList<T>::changeCapacity(int newCapacity) {

}

template<class T>
void GenericList<T>::copyArray(T *array, int srcIndex, int dstIndex) {

}

template<class T>
void GenericList<T>::print() {
    cout << capacity << count << std::endl;
}

template<class T>
T GenericList<T>::getValue(int index) {
    return nullptr;
}

template<class T>
void GenericList<T>::addValue(T value) {

}

template<class T>
void GenericList<T>::clear() {

}

template<class T>
int GenericList<T>::indexOf(T item) {
    return 0;
}

template<class T>
void GenericList<T>::insert(int index, T item) {

}