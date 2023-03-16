#ifndef EX8_BINARYSEARCHTREE_HPP
#define EX8_BINARYSEARCHTREE_HPP

#include <iostream>

#include "../inc/node.hpp"

using namespace std;

class BinarySearchTree {
private:
    Node* root;

public:

    // constructor declaration
    BinarySearchTree() ;

    // public member function declarations

    // print tree in nice visual fashion
    void print();

    // add to the tree - should do so recursively - hence the location pointer
    bool insert(int value,Node *location = nullptr);

    // search and find a value in the tree - should do so recursively - hence the location pointer
    // should return a nullptr if Tree is empty or not found, otherwise return the found Node
    Node* search(int value ,Node *location = nullptr);

private:
    //helper function to recursively print nodes in the tree
    void printRecursively(const string& prefix, Node *currentNode, bool leftBranch);

};

#endif //EX8_BINARYSEARCHTREE_HPP
