#ifndef EX3_LINKED_LIST_HPP
#define EX3_LINKED_LIST_HPP

#include <iostream>

#include "../inc/node.hpp"

using namespace std;

class LinkedList {
    private:
        Node* head;

    public:

        // constructor declaration
        LinkedList() ;

        // public member function declarations
        void print();

        void insertAtBeginning(int value);
        void insertAtEnd(int value);

        void deleteAtBeginning();
        void deleteAtEnd();

};

#endif //EX3_LINKED_LIST_HPP
