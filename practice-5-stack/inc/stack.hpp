#ifndef EX5_STACK_HPP
#define EX5_STACK_HPP

#include <iostream>

#include "../inc/node.hpp"

using namespace std;

class Stack {
    private:
        Node* head;

    public:

        // constructor declaration
        Stack() ;

        // destructor declaration - should delete all nodes in destructor
        ~Stack() ;

        // public member function declarations

        // print the last NULL value in the function today
        void print();

        // add to beginning of List
        void push(int value);

        // remove from beginning of List
        // should return a nullptr if List is empty, otherwise return removed Node
        Node* pop();

};

#endif //EX5_STACK_HPP
