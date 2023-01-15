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
    ObjectType *items = nullptr;

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

    void addValue(const ObjectType &value);

    void clear();

    int indexOf(const ObjectType &item);

    void insert(int index, const ObjectType &value);

    bool contains(const ObjectType &item);
};


#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_ARRAYLIST_H
