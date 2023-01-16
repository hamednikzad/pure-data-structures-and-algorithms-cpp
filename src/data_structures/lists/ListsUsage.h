//
// Created by Hamed on 1/15/2023.
//

#include "GenericList.h"
#include "ArrayList.h"
#include <iostream>

using namespace std;

namespace list_usage{
    class ListUsage {
        static void arrayListUsage() {
            cout << "ArrayList *************************" << std::endl;

            ArrayList list(2);
            list.addValue(12.5);
            list.addValue("Hi");
            list.addValue(12);
            list.print();

            cout << "Value at 2: " << ArrayList::getString(list.getValue(2)) << std::endl;
            cout << "Index of at Hi is: " << list.indexOf("Hi") << std::endl;

            cout << "Inserting new value..." << std::endl;
            list.insert(2, "New Value!");
            list.print();

            cout << "Is list contains 12: " << list.contains(12) << std::endl;

            cout << "Clearing List..." << std::endl;
            list.clear();
            list.print();

            cout << "ArrayList end ---------------------" << std::endl;
        }

        static void genericListUsage() {
            cout << "GenericList *************************" << std::endl;

            GenericList<int> list(2);
            list.addValue(1);
            list.addValue(2);
            list.addValue(3);
            list.print();

            cout << "Value at 2: " << list.getValue(2) << std::endl;
            cout << "Index of value 3: " << list.indexOf(3) << std::endl;

            cout << "Inserting new value..." << std::endl;
            list.insert(2, 5);
            list.print();

            cout << "Is list contains 12: " << list.contains(12) << std::endl;

            cout << "Clearing List..." << std::endl;
            list.clear();
            list.print();

            cout << "GenericList end ---------------------" << std::endl;
        }

    public:
        static void use() {
            arrayListUsage();

            genericListUsage();
        }
    };
}

