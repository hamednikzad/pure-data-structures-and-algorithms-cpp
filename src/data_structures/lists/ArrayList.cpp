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

string ArrayList::getString(int index) {
    ObjectType item = items[index];

    if (holds_alternative<int>(item)) {
        return to_string(get<int>(item));
    } else if (holds_alternative<string>(item)) {
        return get<string>(item);
    } else if (holds_alternative<float>(item)) {
        return to_string(get<float>(item));
    } else if (holds_alternative<double>(item)) {
        return to_string(get<double>(item));
    }
    return std::string();
}

void ArrayList::print() {
    printf("Capacity:%d, Count:%d\t", capacity, count);
    auto sep = ", ";
    for (int i = 0; i < count; ++i) {
        sep = ", ";
        if (i == count - 1) {
            sep = "";
        }
        //printf("%s", string(items[i]))
        cout << getString(i) << sep;
    }
    cout << std::endl;
}

void ArrayList::addValue(ObjectType value) {
    /*if list.Count == len(list.items) {
        list.checkCapacity(list.Count + 1)
    }*/

    items[count++] = value;
}


