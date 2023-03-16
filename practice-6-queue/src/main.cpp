#include <iostream>

#include "../inc/queue.hpp"

using namespace std;


int main() {

    // create our Queue object
    Queue *myQueue = new Queue();
    Node *removedNode;

    // PART 1 - add the following items to the queue
    myQueue->enqueue(10);
    myQueue->enqueue(20);
    myQueue->enqueue(30);
    myQueue->enqueue(40);
    myQueue->enqueue(50);

    // Print current queue
    cout << "Part 1: Enqueues - Queue values: " << endl;
    myQueue->print(); // let's print each value on own line for nice "view" of queue

    cout << endl;


    // PART 2 - dequeue the "first" two nodes
    // remember this is FIFO - so first nodes will be first added
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }

    // Print current queue
    cout << "Part 2: Dequeues - Queue values: " << endl;
    myQueue->print(); // let's print each value on own line for nice "view" of queue

    cout << endl;


    // PART 3 - add a new node
    myQueue->enqueue(60);

    // Print current queue
    cout << "Part 3: Enqueues - Queue values: " << endl;
    myQueue->print(); // let's print each value on own line for nice "view" of queue

    cout << endl;


    // PART 4 - dequeue the "first" five nodes - only four in queue so last will error
    // remember this is FIFO - so first nodes will be first added
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }
    if( (removedNode = myQueue->dequeue()) == nullptr ) {
        cout << "Could not remove node - queue empty" << endl;
    }
    else{
        delete removedNode;
    }

    // Print current queue
    cout << "Part 4: Dequeues - Queue values: " << endl;
    myQueue->print(); // let's print each value on own line for nice "view" of queue

    cout << endl;


    // Output Time Complexity of Different Operations
    cout << "Big O Analysis:" << endl;
    cout << "Time complexity of Queue print operation: O(N) " << std::endl;
    cout << "Time complexity of Queue enqueue operation: O(1) " << std::endl;
    cout << "Time complexity of Queue dequeue operation: O(1) " << std::endl;

    // clean up LinkedList
    delete myQueue;

    return 0;
}
