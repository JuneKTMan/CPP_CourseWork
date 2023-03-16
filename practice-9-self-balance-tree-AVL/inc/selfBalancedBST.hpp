#ifndef EX9_SELFBALANCEDBST_HPP
#define EX9_SELFBALANCEDBST_HPP

#include <iostream>
#include <stdio.h>

#include "../inc/node.hpp"

using namespace std;


class SelfBalancedBST {
private:
    Node* root;

public:

    // constructor declaration
    SelfBalancedBST();

    // public member function declarations

    // print tree in nice visual fashion
    void print();

    // add to the tree - perhaps recursively
    //bool insert(int value);

    // add to the tree - perhaps recursively - hence the location pointer
     //bool insert(int value,Node *location = nullptr,Node *previous = nullptr);
    bool insert(int value,Node *location = nullptr, Node *previous = nullptr);

    // search and find a value in the tree - should do so recursively - hence the location pointer
    // should return a nullptr if Tree is empty or not found, otherwise return the found Node
    Node* search(int value ,Node *location = nullptr);

    //AVL Tree
    //to get the height of the tree
    int calHeight(Node *h);

    //Return the maximum of two int
    int calMax(int a, int b);

    //get balance
    int getBalance(Node *bl);

    //Get the Balance Factor of the Node
    Node* getHeightAndBalance(Node *blh);

    //add to the tree follow the example in happy coder
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);



private:
    //helper function to recursively print nodes in the tree
    // RED-BLACK if red-black tree - let's print red nodes in red
    // if AVL, may want to print height
    void printRecursively(const string& prefix, Node *currentNode, bool leftBranch);


};

#endif //EX9_SELFBALANCEDBST_HPP
