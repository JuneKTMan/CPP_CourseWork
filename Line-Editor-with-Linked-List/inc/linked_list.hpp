//
// Created by junej on 1/31/2023.
//

#ifndef ASSIGN1_LINKED_LIST_HPP
#define ASSIGN1_LINKED_LIST_HPP

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


    void printAllList(Node* head);

    void printIndexList(int index, int start_num);

    Node* insertAtBeginning(string value);

    void deleteAtBeginning();

    // should return a nullptr if cannot insert/delete at that location
    void insertAtLocation(int index, string value);
    Node* deleteAtLocation(int index);

    void insertAtEnd(string value);
    Node* reverse();

    void saveToFile2(string fileName);


};


#endif //ASSIGN1_LINKED_LIST_HPP
