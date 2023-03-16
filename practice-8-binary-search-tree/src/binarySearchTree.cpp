#include "../inc/binarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

void BinarySearchTree::printRecursively(const string& prefix, Node *currentNode, bool leftBranch) {

    // src: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    if( currentNode != nullptr )
    {
        cout << prefix;

        if(currentNode != this->root) {
            cout << (leftBranch ? "<-- " : "--> ");
        }

        cout << currentNode->getValue() << endl;

        // recursively print the next tree levels
        printRecursively( prefix + "    ",
                          currentNode->getLeftBranch(), true);
        printRecursively( prefix + "    ",
                          currentNode->getRightBranch(), false);
    }
}

void BinarySearchTree::print() {

    printRecursively("", this->root, 0);

}

bool BinarySearchTree::insert(int value,Node *location) {

    //TODO: Must implement this function
    //if the root location is null, create a new node with a given value
    if(root == nullptr) {
        root = new Node(value);
        return true;
    }

    if(location == nullptr) {
        location = root;
    }


    //if new value is lesser than the current location value, insert into left sub-branch
    if(value < location->getValue()) {
        if(location->getLeftBranch() == nullptr ){
            location->setLeftBranch(new Node(value));
            return true;
        }
        return insert(value, location->getLeftBranch());
    }

    //if new value is greater than the current location value, insert into right sub-branch
    else if(value > location->getValue()) {
        if(location->getRightBranch() == nullptr ){
            location->setRightBranch(new Node(value));
            return true;
        }
        return insert(value, location->getRightBranch());

    }else {
        //if the condition not lesser and greater, then return false ( check duplicate)
        return false;
    }

}

Node* BinarySearchTree::search(int value,Node *location) {

    //TODO: Must implement this function


    //Base root if location is nullptr or have value at the location
//    if (location == nullptr || location->getValue() == value){
//        return location;
//    }
      if (location == nullptr) {
          location = root;
      }

    // if the new get value is greater than the root location value -> search right branch
    if (value < location->getValue()) {
        // tell the tree, no value inside the left then return nullptr
        if(location->getLeftBranch() == nullptr ){
            return nullptr;
        }
        return search(value, location->getLeftBranch());
    }

    // if the new get Value is lesser than the root location value -> search left branch
    else if(value > location->getValue()) {
        if(location->getRightBranch() == nullptr ){
            return nullptr;
        }
        return search(value, location->getRightBranch());
    }
    else{
        return location;
    }



}
