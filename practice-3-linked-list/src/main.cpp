#include <iostream>

#include "../inc/linked_list.hpp"

using namespace std;


int main() {

    // create our LinkedList object
    LinkedList *myLinkedList = new LinkedList();

    // Print current list
    cout << "Part 1: Linked List values: ";
    myLinkedList->print();
    cout << "NULL" << endl;

    // PART 2 - add the following items to the "front" of the list
    myLinkedList->insertAtBeginning(10);
    myLinkedList->insertAtBeginning(20);
    myLinkedList->insertAtBeginning(30);
    myLinkedList->insertAtBeginning(40);
    myLinkedList->insertAtBeginning(50);
    myLinkedList->insertAtBeginning(60);
    myLinkedList->insertAtBeginning(70);
    myLinkedList->insertAtBeginning(80);
    myLinkedList->insertAtBeginning(90); // 90 will now be at the front

    // Print current list
    cout << "Part 2: Linked List values: ";
    myLinkedList->print();
    cout << "NULL" << endl;


    // PART 3 - add the following items to the "end" of the list
    myLinkedList->insertAtEnd(100);

    // Print current list
    cout << "Part 3: Linked List values: ";
    myLinkedList->print();
    cout << "NULL" << endl;


    // PART 4 - delete the first item in the list
    myLinkedList->deleteAtBeginning();

    // Print current list
    cout << "Part 4: Linked List values: ";
    myLinkedList->print();
    cout << "NULL" << endl;


    // PART 5 - delete the last item in the list
    myLinkedList->deleteAtEnd();

    // Print current list
    cout << "Part 5: Linked List values: ";
    myLinkedList->print();
    cout << "NULL" << endl;


    // Output Time Complexity of Different Operations
    cout << endl << "Big O Analysis:" << endl;
    cout << "Time complexity of LinkedList print operation: O(N) " << std::endl;
    cout << "Time complexity of LinkedList insertAtBeginning operation: O(1) " << std::endl;
    cout << "Time complexity of LinkedList insertAtEnd operation: O(N) " << std::endl;
    cout << "Time complexity of LinkedList deleteAtBeginning operation: O(1) " << std::endl;
    cout << "Time complexity of LinkedList deleteAtEnd operation: O(N) " << std::endl;


    // clean up LinkedList
    delete myLinkedList;

    return 0;
}
