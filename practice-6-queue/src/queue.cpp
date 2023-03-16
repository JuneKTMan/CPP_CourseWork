#include "../inc/queue.hpp"

Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
}

Queue::~Queue() {

    //TODO: Must implement this function
    Node* current_node = head;
    while(current_node != nullptr) {
        Node* next_node = current_node->getNext();
        delete current_node;
        current_node = next_node;
    }

}

void Queue::print() {

    //TODO: Must implement this function
    Node* current_node = head;
    while(current_node != nullptr) {
        cout << current_node->getValue() << endl;
        current_node = current_node->getNext();
    }

}

void Queue::enqueue(int value) {

    //TODO: Must implement this function


    Node* temp_node = new Node(value);
    if( tail == nullptr) {
        head = tail = temp_node;
        return;
    }

    tail->setNext(temp_node);
    tail = temp_node;


}

Node* Queue::dequeue() {

    //TODO: Must implement this function
    if(head == nullptr) {
        return nullptr;
    }

    Node* temp_node = head;
    head = head->getNext();

    temp_node ->setNext(nullptr);
    return temp_node;

}
