#include <iostream>

#include "../inc/linked_list.hpp"

using namespace std;


int main() {

    // create our LinkedList object
    LinkedList *myLinkedList = new LinkedList();
    Node *deletedNode;

    // PART 1 - add the following items to the list
    if(myLinkedList->insertAtLocation(2, "Bad Colour") == nullptr) {
        cout << "Could not insert node at location 2" << endl;
    }
    if(myLinkedList->insertAtLocation(1, "red") == nullptr) {
        cout << "Could not insert node at location 1" << endl;
    }
    if(myLinkedList->insertAtLocation(2, "yellow") == nullptr) {
        cout << "Could not insert node at location 2" << endl;
    }
    if(myLinkedList->insertAtLocation(3, "chartreuse") == nullptr ) {
        cout << "Could not insert node at location 3" << endl;
    }
    if(myLinkedList->insertAtLocation(5, "Bad Colour 2") == nullptr) {
        cout << "Could not insert node at location 5" << endl;
    }
    if(myLinkedList->insertAtLocation(4, "blue") == nullptr) {
        cout << "Could not insert node at location 4" << endl;
    }
    if(myLinkedList->insertAtLocation(5, "violet") == nullptr) {
        cout << "Could not insert node at location 5" << endl;
    }

    // Print current list
    cout << "Part 1: Linked List values: ";
    myLinkedList->print(); // will print final NULL and newline in print function today

    cout << endl;

    // PART 2 - delete a bad line and the "charteuse" line
    if( (deletedNode = myLinkedList->deleteAtLocation(9)) == nullptr ) {
        cout << "Could not delete node at location 9" << endl;
    }
    else{
        delete deletedNode;
    }
    if((deletedNode = myLinkedList->deleteAtLocation(3)) == nullptr) {
        cout << "Could not delete node at location 3" << endl;
    }
    else{
        delete deletedNode;
    }

    // Print current list
    cout << "Part 2: Linked List values: ";
    myLinkedList->print(); // will print final NULL and newline in print function today

    cout << endl;

    // PART 3 - insert orange
    if(myLinkedList->insertAtLocation(2, "orange") == nullptr) {
        cout << "Could not insert node at location 2" << endl;
    }

    // Print current list
    cout << "Part 3: Linked List values: ";
    myLinkedList->print(); // will print final NULL and newline in print function today

    cout << endl;

    // PART 4 - insert green
    if(myLinkedList->insertAtLocation(4, "green") == nullptr) {
        cout << "Could not insert node at location 4" << endl;
    }

    // Print current list
    cout << "Part 4: Linked List values: ";
    myLinkedList->print(); // will print final NULL and newline in print function today

    cout << endl;

    // PART 5 - insert indigo
    if(myLinkedList->insertAtLocation(6, "indigo") == nullptr) {
        cout << "Could not insert node at location 6" << endl;
    }

    // Print current list
    cout << "Part 5: Linked List values: ";
    myLinkedList->print(); // will print final NULL and newline in print function today

    cout << endl;

    // Output Time Complexity of Different Operations
    cout << endl << "Big O Analysis:" << endl;
    cout << "Time complexity of LinkedList print operation: O(N)" << std::endl;
    cout << "Time complexity of LinkedList insertAtLocation operation: O(N) " << std::endl;
    cout << "Time complexity of LinkedList deleteAtLocation operation: O(N)" << std::endl;

    // clean up LinkedList
    delete myLinkedList;

    return 0;
}
