//
// Created by junej on 1/31/2023.
//

#include <fstream>
#include "../inc/linked_list.hpp"
LinkedList::LinkedList() {
    this->head = nullptr;
}

//destructor to free the memorizes
LinkedList::~LinkedList() {

    Node* current_node = head;
    while(current_node != nullptr) {

        Node* next_node = current_node->getNext();
        delete current_node;
        current_node = next_node;

    }

}

//List function - print list
void LinkedList::print() {

    int index = 0;
    Node* current_node = head;
    while(current_node != nullptr) {
        index++;
        cout <<index<< ">" << current_node->getValue() <<endl;
        current_node = current_node->getNext();

    }

}

void LinkedList::printIndexList(int index, int start_num) {

    index = 1;

    Node* current_node = head;
    while(current_node != nullptr && start_num != 0) {

        cout <<index<< ">" << current_node->getValue() <<endl;
        current_node = current_node->getNext();

    }

}

// Start insert at the beginning
Node* LinkedList::insertAtBeginning(string value) {
    // Need to determent >> it ture to stack
    Node* new_node = new Node(value);
    new_node->setValue(value); ///<<<<test
    new_node->setNext(head);
    head = new_node;
    return new_node;
}



// Insert function
void LinkedList::insertAtLocation(int index, string value){

    if (index <1) {
        return;
    }

    Node* new_node = new Node(value);

    if(index == 1) {
        new_node->setNext(head);
        head = new_node;
        return;
    }

    Node* current_node = head;
    for(int i = 1; i < index - 1; i++){
        current_node = current_node->getNext();
    }

    if(current_node == nullptr) {
        return;
    }

    new_node->setNext(current_node->getNext());
    current_node->setNext(new_node);
    return;

}

// Delete from the beginning
void LinkedList::deleteAtBeginning() {

    Node* del_head_node = head;
    head = head->getNext();
    delete del_head_node;

}

Node *LinkedList::deleteAtLocation(int index) {
    if (index < 1) {
        return nullptr;
    }

    if (index == 1) {
        Node* delete_node = head;
        head ->getNext();
        return delete_node;
    }

    Node* current_node = head;

    for (int i = 1; i < index - 1; i ++){
        if(current_node != nullptr) {
            current_node = current_node->getNext(); //<<<<
        }
    }

    if (current_node == nullptr || current_node ->getNext() == nullptr){
        return nullptr;
    }

    Node* delete_node = current_node->getNext();
    current_node->setNext(delete_node->getNext());
    return delete_node;
}

void LinkedList::printAllList(Node* head) {
    if (head == nullptr) {
        return;
    }
    printAllList(head->getNext());
    cout << head->getValue() << endl;

}


void LinkedList::insertAtEnd(string value) {
    Node* last_node = this->head;
    while(last_node->getNext() != nullptr){
        last_node = last_node->getNext();
    }
    Node* new_node = new Node(value);
    last_node->setNext(new_node);

}

Node* LinkedList::reverse() {

    Node* current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while(current != nullptr) {
        //Store next
        next = current->getNext();
        //Reverse
        current->setNext(prev);
        //Move pointers one position ahead.
        prev = current;
        current = next;

    }
    head = prev;
    return current;

}



void LinkedList::saveToFile2(string fileName) {

    ofstream outfile;
    outfile.open(fileName);   //ios::app
    if(outfile.is_open()) {
        Node* current = head;
//        int index = 1;
        while(current != nullptr) {
            outfile << current->getValue() << endl;
            current = current->getNext();
//            index++;
        }
        outfile.close();
    }
    else{
        cout << "File can't create and save!" << endl;
    }

}


