//
// Created by Hamed on 2/12/2023.
//

#ifndef PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_QUEUEUSAGE_H
#define PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_QUEUEUSAGE_H

#include <iostream>
#include "LinkedListQueue.h"

using namespace std;

namespace queue_usage{
    class QueueUsage{
        static void linkedListUsage(){
            cout << "LinkedListUsage *************************" << std::endl;
            auto list = LinkedListQueue<int>();
            list.enqueue(1);
            list.enqueue(2);
            list.enqueue(3);
            list.enqueue(4);
            list.print();

            cout << "First value in list: " << list.peek()<< std::endl;
            cout << "Dequeue: " << list.dequeue()<< std::endl;
            list.print();
            cout << "IsEmpty: " << list.isEmpty()<< std::endl;
            list.clear();
            cout << "Clearing..."<< std::endl;
            list.print();
        }

    public:
        static void use(){
            linkedListUsage();
        }
    };
}

#endif //PURE_DATA_STRUCTURES_AND_ALGORITHMS_CPP_QUEUEUSAGE_H
