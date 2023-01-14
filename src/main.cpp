#include <iostream>
#include "data_structures/lists/ArrayList.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ArrayList aList(5);
    aList.addValue(12.5);
    aList.addValue("Hi");
    aList.addValue(12);
    aList.print();

    return 0;
}
