#include <iostream>
#include "data_structures/lists/ArrayList.h"

int main() {
    std::cout << "Hello, Data structures!" << std::endl;
    ArrayList aList(5);
    aList.addValue(12.5);
    aList.addValue("Hi");
    aList.addValue(12);
    aList.print();

    cout << "Value at 2: " << ArrayList::getString(aList.getValue(2)) << std::endl;
    cout << "Index of at Hi is: " << aList.indexOf("Hi") << std::endl;

    cout << "Inserting new value..." << std::endl;
    aList.insert(2, "New Value!");
    aList.print();

    cout << "Is list contains 12: " << aList.contains(12) << std::endl;

    cout << "Clearing List..." << std::endl;
    aList.clear();
    aList.print();

    return 0;
}
