#include <iostream>

#include "../inc/stack.hpp"

using namespace std;


int main() {

    // create our Stack object
    Stack *myStack = new Stack();
    Node *removedNode;

    // PART 1 - add the following items to the stack
    myStack->push(10);
    myStack->push(20);
    myStack->push(30);
    myStack->push(40);
    myStack->push(50);

    // Print current stack
    cout << "Part 1: Pushes - Stack values: " << endl;
    myStack->print(); // let's print each value on own line for nice "view" of stack

    cout << endl;


    // PART 2 - pop the "first" two nodes
    // remember this is LIFO - so first nodes will be last added
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }

    // Print current stack
    cout << "Part 2: Pops - Stack values: " << endl;
    myStack->print(); // let's print each value on own line for nice "view" of stack

    cout << endl;


    // PART 3 - add a new node
    myStack->push(60);

    // Print current stack
    cout << "Part 3: Pushes - Stack values: " << endl;
    myStack->print(); // let's print each value on own line for nice "view" of stack

    cout << endl;


    // PART 4 - pop the "first" five nodes - only four in stack so last will error
    // remember this is LIFO - so first nodes will be last added
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myStack->pop()) == nullptr ) {
        cout << "Could not remove node - stack empty" << endl;
    }
    else{
        delete removedNode;
    }

    // Print current stack
    cout << "Part 4: Pops - Stack values: " << endl;
    myStack->print(); // let's print each value on own line for nice "view" of stack

    cout << endl;


    // Output Time Complexity of Different Operations
    cout << "Big O Analysis:" << endl;
    cout << "Time complexity of Stack print operation: O(N)" << std::endl;
    cout << "Time complexity of Stack push operation: O(1)" << std::endl;
    cout << "Time complexity of Stack pop operation: O(1)" << std::endl;

    // clean up LinkedList
    delete myStack;

    return 0;
}
