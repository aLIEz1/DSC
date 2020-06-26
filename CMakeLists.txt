cmake_minimum_required(VERSION 3.16)
project(DS C)

set(CMAKE_C_STANDARD 99)

add_executable(DS src/LinkedList/SinglyLinkedList.c src/LinkedList/CircularLinkedList.c src/Stack/SeqStack.c)