#ifndef EX4_LINKED_LIST_HPP
#define EX4_LINKED_LIST_HPP

#include <iostream>

#include "../inc/node.hpp"

using namespace std;

class LinkedList {
    private:
        Node* head;

    public:

        // constructor declaration
        LinkedList() ;

        // destructor declaration - should delete all nodes in destructor
        ~LinkedList() ;

        // public member function declarations - print the last NULL value in the function today
        void print();

        // should return a nullptr if cannot insert/delete at that location
        Node* insertAtLocation(int index, string value);
        Node* deleteAtLocation(int index);

};

#endif //EX4_LINKED_LIST_HPP
