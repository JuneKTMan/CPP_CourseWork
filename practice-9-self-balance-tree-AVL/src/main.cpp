#include <iostream>

#include "../inc/selfBalancedBST.hpp"

using namespace std;


int main() {

    // create our SelfBalancedBST object
    SelfBalancedBST *mySelfBalancedBST = new SelfBalancedBST();
    Node *foundNode;

    cout << endl;

    // PART 1 - add the following items to the tree - last insert of duplicate should fail
    if(!mySelfBalancedBST->insert(10)) {
        cout << "Could not insert - possible duplicate: " << 10 << endl;
    }
    if(!mySelfBalancedBST->insert(20)) {
        cout << "Could not insert - possible duplicate: " << 20 << endl;
    }
    if(!mySelfBalancedBST->insert(30)) {
        cout << "Could not insert - possible duplicate: " << 30 << endl;
    }
    if(!mySelfBalancedBST->insert(40)) {
        cout << "Could not insert - possible duplicate: " << 40 << endl;
    }
    if(!mySelfBalancedBST->insert(50)) {
        cout << "Could not insert - possible duplicate: " << 50 << endl;
    }
    if(!mySelfBalancedBST->insert(60)) {
        cout << "Could not insert - possible duplicate: " << 60 << endl;
    }
    if(!mySelfBalancedBST->insert(70)) {
        cout << "Could not insert - possible duplicate: " << 70 << endl;
    }
    if(!mySelfBalancedBST->insert(80)) {
        cout << "Could not insert - possible duplicate: " << 80 << endl;
    }
    if(!mySelfBalancedBST->insert(90)) {
        cout << "Could not insert - possible duplicate: " << 90 << endl;
    }
    if(!mySelfBalancedBST->insert(100)) {
        cout << "Could not insert - possible duplicate: " << 100 << endl;
    }
    if(!mySelfBalancedBST->insert(110)) {
        cout << "Could not insert - possible duplicate: " << 100 << endl;
    }
    if(!mySelfBalancedBST->insert(120)) {
        cout << "Could not insert - possible duplicate: " << 100 << endl;
    }

    // this should "fail"
    if(!mySelfBalancedBST->insert(40)) {
        cout << "Could not insert - possible duplicate: " << 40 << endl;
    }


    // Print current tree
    cout << "Part 1: Initial Inserts - Self-Balanced BST values: " << endl;
    mySelfBalancedBST->print(); // let's print a nice "view" of the tree

    cout << endl;

    // PART 2 - search a couple of nodes - one will be found and one will not
    cout << "Part 2: Search results" << endl;
    if( (foundNode = mySelfBalancedBST->search(60)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 60 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 60 << endl;
    }

    if( (foundNode = mySelfBalancedBST->search(75)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 75 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 75 << endl;
    }

    cout << endl;

    // clean up old Balanced Binary Search Tree
    delete mySelfBalancedBST;

    // create a new SelfBalancedBST object
    mySelfBalancedBST = new SelfBalancedBST();

    // PART 3 - add the following items to the tree - sixth insert of duplicate should fail
    if(!mySelfBalancedBST->insert(50)) {
        cout << "Could not insert - possible duplicate: " << 50 << endl;
    }
    if(!mySelfBalancedBST->insert(30)) {
        cout << "Could not insert - possible duplicate: " << 30 << endl;
    }
    if(!mySelfBalancedBST->insert(70)) {
        cout << "Could not insert - possible duplicate: " << 70 << endl;
    }
    if(!mySelfBalancedBST->insert(100)) {
        cout << "Could not insert - possible duplicate: " << 100 << endl;
    }
    if(!mySelfBalancedBST->insert(20)) {
        cout << "Could not insert - possible duplicate: " << 20 << endl;
    }

    // this should "fail"
    if(!mySelfBalancedBST->insert(70)) {
        cout << "Could not insert - possible duplicate: " << 70 << endl;
    }

    if(!mySelfBalancedBST->insert(80)) {
        cout << "Could not insert - possible duplicate: " << 80 << endl;
    }
    if(!mySelfBalancedBST->insert(110)) {
        cout << "Could not insert - possible duplicate: " << 100 << endl;
    }
    if(!mySelfBalancedBST->insert(40)) {
        cout << "Could not insert - possible duplicate: " << 40 << endl;
    }
    if(!mySelfBalancedBST->insert(90)) {
        cout << "Could not insert - possible duplicate: " << 90 << endl;
    }
    if(!mySelfBalancedBST->insert(120)) {
        cout << "Could not insert - possible duplicate: " << 100 << endl;
    }
    if(!mySelfBalancedBST->insert(10)) {
        cout << "Could not insert - possible duplicate: " << 10 << endl;
    }
    if(!mySelfBalancedBST->insert(60)) {
        cout << "Could not insert - possible duplicate: " << 60 << endl;
    }

    // Print current tree
    cout << "Part 3: New Inserts - Self-Balanced BST values: " << endl;
    mySelfBalancedBST->print(); // let's print a nice "view" of the tree - including its height

    cout << endl;

    // PART 4 - search a couple of nodes - one will be found and one will not
    cout << "Part 4: Search results" << endl;
    if( (foundNode = mySelfBalancedBST->search(90)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 90 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 90 << endl;
    }

    if( (foundNode = mySelfBalancedBST->search(25)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 25 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 25 << endl;
    }

    cout << endl;

    // Output Time Complexity of Different Operations
    cout << "Big O Analysis of Self-Balanced Tree:" << endl;
    cout << "Time complexity of Self-Balanced Binary Search Tree print operation: O(N)" << std::endl;
    cout << "Time complexity of Self-Balanced Binary Search Tree insert operation: O(log N)" << std::endl;
    cout << "Time complexity of Self-Balanced Binary Search Tree search operation: O(log N)" << std::endl;

    // clean up Self-Balanced Binary Search Tree
    delete mySelfBalancedBST;

    return 0;
}
