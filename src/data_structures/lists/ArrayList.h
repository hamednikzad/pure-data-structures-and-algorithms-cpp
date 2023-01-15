//
// Created by Hamed on 1/13/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_ARRAYLIST_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_ARRAYLIST_H

#include <variant>
#include <string>

using namespace std;

using ObjectType = variant<string, int, float, double>;

class ArrayList {
private:
    ObjectType *items;

private:
    void checkCapacity(int size);

    void changeCapacity(int newCapacity);

    std::string getString(int index);

public:
    int count;
    int capacity;

public:
    ArrayList(int capacity);
    ~ArrayList();

    void print();

    ObjectType getValue(int index);

    static std::string getString(ObjectType value);

    void addValue(ObjectType value);

    void clear();

    int indexOf(ObjectType item);

    void insert(int index, ObjectType item);

    bool contains(ObjectType item);
};


#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_ARRAYLIST_H
