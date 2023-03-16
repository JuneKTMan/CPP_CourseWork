#ifndef EX6_QUEUE_HPP
#define EX6_QUEUE_HPP

#include <iostream>

#include "../inc/node.hpp"

using namespace std;

class Queue {
    private:
        Node* head;
        Node* tail;

    public:

        // constructor declaration
        Queue() ;

        // destructor declaration - should delete all nodes in destructor
        ~Queue() ;

        // public member function declarations

        // print the last NULL value in the function today
        void print();

        // add to end of List
        void enqueue(int value);

        // remove from beginning of List
        // should return a nullptr if List is empty, otherwise return removed Node
        Node* dequeue();

};

#endif //EX6_QUEUE_HPP
