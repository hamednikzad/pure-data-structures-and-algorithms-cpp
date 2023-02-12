cmake_minimum_required(VERSION 3.21)
project(pure_data_structures_and_algorithms_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(pure_data_structures_and_algorithms_cpp src/main.cpp src/data_structures/lists/GenericList.cpp src/data_structures/lists/GenericList.h src/data_structures/lists/ArrayList.cpp src/data_structures/lists/ArrayList.h src/data_structures/lists/ListsUsage.h src/data_structures/lists/SinglyLinkedList.cpp src/data_structures/lists/SinglyLinkedList.h src/data_structures/lists/DoublyLinkedList.cpp src/data_structures/lists/DoublyLinkedList.h src/data_structures/queues/LinkedListQueue.cpp src/data_structures/queues/LinkedListQueue.h src/data_structures/queues/QueueUsage.h)
