//
// Created by Hamed on 1/13/2023.
//

#include "ArrayList.h"
#include <stdexcept>
#include <iostream>
#include <string>

using std::cout;

ArrayList::ArrayList(int capacity) : capacity(capacity), count(0) {
    if (capacity <= 0)
        throw std::invalid_argument("Capacity should be non negative");

    items = new ObjectType[capacity];
}

ArrayList::~ArrayList() {
    delete[] items;
}

string ArrayList::getString(int index) {
    if (index < 0 || index >= count) return {};

    auto item = items[index];

    return getString(item);
}

void ArrayList::print() {
    printf("Capacity:%d, Count:%d\t", capacity, count);
    string sep;
    for (int i = 0; i < count; ++i) {
        sep = ", ";
        if (i == count - 1) {
            sep = "";
        }
        cout << getString(i) << sep;
    }
    cout << std::endl;
}

void ArrayList::addValue(const ObjectType &value) {
    if (count == capacity) {
        checkCapacity(count + 1);
    }

    items[count++] = value;
}

void ArrayList::checkCapacity(int size) {
    if (capacity >= size) {
        return;
    }

    int newCapacity = count * 2;

    if (newCapacity < size) {
        newCapacity = size;
    }

    changeCapacity(newCapacity);
}

void ArrayList::changeCapacity(int newCapacity) {
    if (newCapacity <= count) {
        throw std::out_of_range("Capacity out of range");
    }

    if (newCapacity == capacity) {
        return;
    }

    if (newCapacity > 0) {
        ObjectType *newItems;
        newItems = new ObjectType[newCapacity];
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

ObjectType ArrayList::getValue(int index) {
    if (index < 0 || index >= count) return {};

    return items[index];
}

void ArrayList::clear() {
    if (count <= 0) {
        return;
    }

    for (int i = 0; i < count; i++) {
        items[i] = {};
    }
    count = 0;
}

int ArrayList::indexOf(const ObjectType& item) {
    for (int i = 0; i < count; i++) {
        if (items[i] == item) {
            return i;
        }
    }
    return -1;
}

void ArrayList::insert(int index, const ObjectType &value) {
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

bool ArrayList::contains(const ObjectType& item) {
    for (int i = 0; i < count; i++) {
        if (items[i] == item) {
            return true;
        }
    }
    return false;
}

std::string ArrayList::getString(ObjectType value) {
    if (holds_alternative<int>(value)) {
        return to_string(get<int>(value));
    } else if (holds_alternative<string>(value)) {
        return get<string>(value);
    } else if (holds_alternative<float>(value)) {
        return to_string(get<float>(value));
    } else if (holds_alternative<double>(value)) {
        return to_string(get<double>(value));
    }
    return {};
}


