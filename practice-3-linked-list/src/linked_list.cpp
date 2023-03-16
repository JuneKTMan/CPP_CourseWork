#include "../inc/linked_list.hpp"

LinkedList::LinkedList() {
    this->head = nullptr;
}

void LinkedList::print() {

    // TODO: Must implement this function

    Node* current_node = head;
    while(current_node != nullptr) {
        cout<< current_node->getValue() << " ";
        current_node = current_node->getNext();
    }


}

void LinkedList::insertAtBeginning(int value) {

    // TODO: Must implement this function
    Node* new_node = new Node(value);
    new_node->setNext(head);
    head = new_node;

}

void LinkedList::insertAtEnd(int value) {

    // TODO: Must implement this function
    Node* last_node = this->head;
    while(last_node->getNext() != nullptr){
        last_node = last_node->getNext();
    }
    Node* new_node = new Node(value);
    last_node->setNext(new_node);

}

void LinkedList::deleteAtBeginning() {

    // TODO: Must implement this function
    Node* del_head_node = head;
    head = head->getNext();
    delete del_head_node;


}

void LinkedList::deleteAtEnd() {

    // TODO: Must implement this function
    Node* last_node = head;
    while(last_node->getNext()->getNext() != nullptr){ // get next.next value of the node
        last_node = last_node->getNext();

    }
    last_node->setNext(nullptr);

}
