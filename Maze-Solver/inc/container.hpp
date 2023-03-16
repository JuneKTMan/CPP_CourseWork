//
// Created by junej on 2023-02-09.
//
#ifndef ASSIGN2_CONTAINER_HPP
#define ASSIGN2_CONTAINER_HPP

#include "../inc/node.hpp"

// a stack to read the file
using namespace std;


//Container = maze
class Container {
private:
    Node *head;


public:
    //stack
    Container();

    ~Container();

    void push(MapLocation* value);

    Node* pop();

    Node* peek();

    bool isEmpty();


};


#endif //ASSIGN2_CONTAINER_HPP
