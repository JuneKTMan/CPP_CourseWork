#include "../inc/linked_list.hpp"

LinkedList::LinkedList() {
    this->head = nullptr;
}
//destructor to free the memorizes
LinkedList::~LinkedList() {

    //TODO: Must implement this function
    Node* current_node = head;
    while(current_node != nullptr) {

        Node* next_node = current_node->getNext();
        delete current_node;
        current_node = next_node;

    }

}

void LinkedList::print() {

    //TODO: Must implement this function
    Node* current_node = head;
    while(current_node != nullptr) {
        cout << current_node->getValue() << " ";
        current_node = current_node->getNext();
    }
    cout << "NULL" <<endl;


}

Node* LinkedList::insertAtLocation(int index, string value) {

    //TODO: Must implement this function

    Node* new_node = new Node(value);

    if(index == 1) {
        new_node->setNext(head);
        head = new_node;
        return new_node;


    }
    Node* current_node = head;
    for(int i = 1; i < index - 1; i++){
        current_node = current_node->getNext();

    }
    // This part can't write in the for loop will make it eternity nullptr
    if(current_node == nullptr){
        return nullptr;
    }

    new_node->setNext(current_node->getNext());
    current_node->setNext(new_node);
    return new_node;

}

Node* LinkedList::deleteAtLocation(int index) {

    //TODO: Must implement this function

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
