//
// Created by junej on 2023-02-09.
//
#include "../inc/container.hpp"


// In here to store the stack/queue file
Container::Container() {
    this->head = nullptr;

}

Container::~Container() {
    Node* temp = head;
    while(temp != nullptr) {
        Node* pre = temp->getNext();
        delete temp;
        temp = pre;
    }
}



void Container::push(MapLocation* value) {

    Node* next = new Node(value);
    //push
    next ->setNext(head);
    head = next;

}



Node* Container::pop() {
    if(head == nullptr) {
        return nullptr;
    }else {
        Node* temp = head;
        head = head->getNext();
        temp->setNext(nullptr);
        return temp;
    }
}


Node *Container::peek() {
    return head;
}

bool Container::isEmpty() {
    return head == nullptr;
}




