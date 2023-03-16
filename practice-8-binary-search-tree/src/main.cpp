#include <iostream>

#include "../inc/binarySearchTree.hpp"

using namespace std;


int main() {

    // create our BinarySearchTree object
    BinarySearchTree *myBST = new BinarySearchTree();
    Node *removedNode, *foundNode;

    cout << endl;

    // PART 1 - add the following items to the tree - last insert of duplicate should fail
    if(!myBST->insert(10)) {
        cout << "Could not insert - possible duplicate: " << 10 << endl;
    }
    if(!myBST->insert(20)) {
        cout << "Could not insert - possible duplicate: " << 20 << endl;
    }
    if(!myBST->insert(30)) {
        cout << "Could not insert - possible duplicate: " << 30 << endl;
    }
    if(!myBST->insert(40)) {
        cout << "Could not insert - possible duplicate: " << 40 << endl;
    }
    if(!myBST->insert(50)) {
        cout << "Could not insert - possible duplicate: " << 50 << endl;
    }
    if(!myBST->insert(60)) {
        cout << "Could not insert - possible duplicate: " << 60 << endl;
    }
    if(!myBST->insert(70)) {
        cout << "Could not insert - possible duplicate: " << 70 << endl;
    }
    if(!myBST->insert(80)) {
        cout << "Could not insert - possible duplicate: " << 80 << endl;
    }
    if(!myBST->insert(90)) {
        cout << "Could not insert - possible duplicate: " << 90 << endl;
    }

    // this should "fail"
    if(!myBST->insert(40)) {
        cout << "Could not insert - possible duplicate: " << 40 << endl;
    }


    // Print current tree
    cout << "Part 1: Initial Inserts - BST values: " << endl;
    myBST->print(); // let's print a nice "view" of the tree

    cout << endl;

    // PART 2 - search a couple of nodes - one will be found and one will not
    cout << "Part 2: Search results" << endl;
    if( (foundNode = myBST->search(60)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 60 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 60 << endl;
    }

    if( (foundNode = myBST->search(75)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 75 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 75 << endl;
    }

    cout << endl;

    // Output Time Complexity of Different Operations
    cout << "Big O Analysis of Unbalanced Tree:" << endl;
    cout << "Time complexity of Unbalanced Binary Search Tree print operation: O(N) " << std::endl;
    cout << "Time complexity of Unbalanced Binary Search Tree insert operation: O(N) " << std::endl;
    cout << "Time complexity of Unbalanced Binary Search Tree search operation: O(N) " << std::endl;

    cout << endl;

    // clean up old Binary Search Tree
    delete myBST;

    // create a new BinarySearchTree object
    myBST = new BinarySearchTree();

    // PART 3 - add the following items to the tree - fifth insert of duplicate should fail
    if(!myBST->insert(50)) {
        cout << "Could not insert - possible duplicate: " << 50 << endl;
    }
    if(!myBST->insert(30)) {
        cout << "Could not insert - possible duplicate: " << 30 << endl;
    }
    if(!myBST->insert(70)) {
        cout << "Could not insert - possible duplicate: " << 70 << endl;
    }
    if(!myBST->insert(20)) {
        cout << "Could not insert - possible duplicate: " << 20 << endl;
    }

    // this should "fail"
    if(!myBST->insert(70)) {
        cout << "Could not insert - possible duplicate: " << 70 << endl;
    }

    if(!myBST->insert(80)) {
        cout << "Could not insert - possible duplicate: " << 80 << endl;
    }
    if(!myBST->insert(40)) {
        cout << "Could not insert - possible duplicate: " << 40 << endl;
    }
    if(!myBST->insert(90)) {
        cout << "Could not insert - possible duplicate: " << 90 << endl;
    }
    if(!myBST->insert(10)) {
        cout << "Could not insert - possible duplicate: " << 10 << endl;
    }
    if(!myBST->insert(60)) {
        cout << "Could not insert - possible duplicate: " << 60 << endl;
    }

    // Print current tree
    cout << "Part 3: New Inserts - BST values: " << endl;
    myBST->print(); // let's print a nice "view" of the tree

    cout << endl;

    // PART 4 - search a couple of nodes - one will be found and one will not
    cout << "Part 4: Search results" << endl;
    if( (foundNode = myBST->search(80)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 80 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 80 << endl;
    }

    if( (foundNode = myBST->search(15)) == nullptr ) {
        cout << "Could not find the following value in the tree: " << 15 << endl;
    }
    else
    {
        cout << "Found the following value in the tree: " << 15 << endl;
    }

    cout << endl;

    // Output Time Complexity of Different Operations
    cout << "Big O Analysis of Balanced Tree:" << endl;
    cout << "Time complexity of Balanced Binary Search Tree print operation: O(N)" << std::endl;
    cout << "Time complexity of Balanced Binary Search Tree insert operation: O(log N)" << std::endl;
    cout << "Time complexity of Balanced Binary Search Tree search operation: O(log N)" << std::endl;

    // clean up second Binary Search Tree
    delete myBST;

    return 0;
}
