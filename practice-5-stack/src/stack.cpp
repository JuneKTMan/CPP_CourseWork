#include "../inc/stack.hpp"

Stack::Stack() {
    this->head = nullptr;
}

Stack::~Stack() {

    //TODO: Must implement this function
    Node* current_node = head;
    while(current_node != nullptr) {

        Node* next_node = current_node->getNext();
        delete current_node;
        current_node = next_node;
    }

}

void Stack::print() {

    //TODO: Must implement this function
    Node* current_node = head;
    while(current_node != nullptr) {
        cout << current_node->getValue() << endl;
        current_node = current_node->getNext();
    }

}

void Stack::push(int value) {

    //TODO: Must implement this function
    Node* new_node = new Node(value);
    new_node->setNext(head);
    head = new_node;

}

Node* Stack::pop() {

    //TODO: Must implement this function

    if(head == nullptr) {

        return nullptr;

    }
    Node* topStack = head;
    head = head->getNext();
    topStack ->setNext(nullptr);
    return topStack;


}
