#include "../inc/selfBalancedBST.hpp"

SelfBalancedBST::SelfBalancedBST() {
    this->root = nullptr;
}

// RED-BLACK Code
void SelfBalancedBST::printRecursively(const string& prefix, Node *currentNode, bool leftBranch) {

    // src: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    if( currentNode != nullptr )
    {
        cout << prefix;

        if(currentNode != this->root) {
            cout << (leftBranch ? "<-- " : "--> ");
        }

        // if RED-BLACK - print red nodes in Red

        cout << currentNode->getValue() << endl;


        // recursively print the next tree levels
        printRecursively( prefix + "    ",
                          currentNode->getLeftBranch(), true);
        printRecursively( prefix + "    ",
                          currentNode->getRightBranch(), false);
    }
}

void SelfBalancedBST::print() {

    printRecursively("", this->root, 0);

    // If AVL - print height of tree at end
    cout<< "Current height of tree: "<< calHeight(this->root)<<endl;

}


//AVL Tree

/* An empty tree(null) has height of-1
 * leaves have a height of 0
 * any other node*h has a height of 1 + max(h.leftheight, h.rightheight)
 * */

int SelfBalancedBST::calHeight(Node *h) {
    if (h == nullptr) {
        return -1;
    }
    return h->getHeight();

}


int SelfBalancedBST::calMax(int a, int b) {
    if(a > b) {
        return a;
    }else{
        return b;
    }
}

int SelfBalancedBST::getBalance(Node *bl) {
    if(bl == nullptr) {
        return 0;
    }else{
        return calHeight(bl->getRightBranch()) - calHeight(bl->getLeftBranch());
    }
}

// Red and Black should use this
//bool SelfBalancedBST::insert(int value) {
//
//    //TODO: Must implement this function
//    //if the root location is null, create a new node with a given value
//    if(root == nullptr) {
//        root = new Node(value);
//        return true;
//
//    }else{
//        // Create a current Node = location in ex8
//        Node* location = root;
//        while(true){
//            //if new value is lesser than the current location value, insert into left sub-branch
//            if(value < location->getValue()) {
//                if(location->getLeftBranch() == nullptr ){
//                    location->setLeftBranch(new Node(value));
//                    break;
//
//                }else{
//                    location = location->getLeftBranch();
//                }
//
//                //if new value is greater than the current location value, insert into right sub-branch
//            }else if(value > location->getValue()) {
//                if(location->getRightBranch() == nullptr ){
//                    location->setRightBranch(new Node(value));
//                    break;
//
//                }else{
//                    location = location->getRightBranch();
//                }
//
//            }else {
//                //if the condition not lesser and greater, then return false ( check duplicate)
//                return false;
//            }
//
//
//        }
//        getHeightAndBalance(location);
//
//    }
//
//    return true;
//
//}

// The height of left subtree - height of right sub-tree =  -1 / 0 / 1, any other node*h has a height of 1 + max(h.leftheight, h.rightheight)
Node* SelfBalancedBST::getHeightAndBalance(Node *blh) {

    bool wasRoot = false;

    if(blh == nullptr) {
        return blh ;
   }

   if(root == blh){
       wasRoot = true;
   }

   blh->setHeight(calMax(calHeight(blh->getLeftBranch()), calHeight(blh->getRightBranch())) + 1);
   int balance = getBalance(blh);
   if(balance < -1 && getBalance(blh->getLeftBranch()) <= 0) {
       //Left only
       //root = rotateRight(blh);
       blh = rotateRight(blh);

   }else if (balance < -1) {
       //Left right
       blh->setLeftBranch(rotateLeft(blh->getLeftBranch()));
       blh = rotateRight(blh);

   }else if (balance > 1 && getBalance(blh->getRightBranch()) >=0) { //right branch -1
       //Right only case
       blh = rotateLeft(blh);
   }else if (balance > 1 ) {
       //Right Left case
       blh->setRightBranch(rotateRight(blh->getRightBranch()));
       blh = rotateLeft(blh);
   }
   if(wasRoot){
       root = blh;
   }

   return blh;
}

Node *SelfBalancedBST::rotateLeft(Node *node) {
    Node* newRoot = node->getRightBranch();
    Node* subTree = newRoot->getLeftBranch();

    //Rotation
    newRoot->setLeftBranch(node);
    node->setRightBranch(subTree);

    //Update heights
    node->setHeight(calMax(calHeight(node->getLeftBranch()), calHeight(node->getRightBranch())) + 1);
    newRoot->setHeight(calMax(calHeight(newRoot->getLeftBranch()), calHeight(newRoot->getRightBranch())) + 1);

    return newRoot;

}

Node *SelfBalancedBST::rotateRight(Node *node) {

    Node* newRoot = node->getLeftBranch();
    Node* subTree = newRoot->getRightBranch();

    //Rotation
    newRoot->setRightBranch(node);
    node->setLeftBranch(subTree);

    //Update height
    node->setHeight(calMax(calHeight(node->getLeftBranch()), calHeight(node->getRightBranch())) +1);
    newRoot->setHeight(calMax(calHeight(newRoot->getLeftBranch()), calHeight(newRoot->getRightBranch())) + 1);

    return newRoot;

}



Node *SelfBalancedBST::search(int value, Node *location) {
    //TODO: Must implement this function

    //Base root if location is nullptr or have value at the location
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

//AVL tree
// or perhaps recursively
bool SelfBalancedBST::insert(int value, Node *location, Node *previous) {

    //TODO: Must implement this function

    bool inserted = false;

    if(root == nullptr) {
        root = new Node(value);
        inserted = true;
    }else {
        if (location == nullptr) {
            location = root;
        }
        //> Go left
        if (location->getValue() > value) {
            //if leftBranch is null, can inserted there!
            if (location->getLeftBranch() == nullptr) {
                Node *newNode = new Node(value);
                if(location->getHeight() == 0){
                    location->setHeight(1);
                }
                location->setLeftBranch(newNode);
                inserted = true;
                // if leftbranch is not null recursively to the branch, keep down recursively until to get a null child, then inserted!
            } else {
                inserted = insert(value, location->getLeftBranch(), location);
                if(inserted) {
                    Node* blNode = getHeightAndBalance(location);
                    if(previous != nullptr && previous->getLeftBranch() == location) {
                        previous->setLeftBranch(blNode);
                    }else if(previous != nullptr && previous->getRightBranch() == location){
                        previous->setRightBranch(blNode);
                    }
                }
            }
        }

            // Go right
        else if (location->getValue() < value) {
            //if RightBranch is null, can inserted there!
            if (location->getRightBranch() == nullptr) {
                Node *newNode = new Node(value);
                if(location->getHeight() == 0){
                    location->setHeight(1);
                }
                location->setRightBranch(newNode);
                inserted = true;
                // if Rightbranch is not null recursively to the branch, keep down recursively until to get a null child, then inserted!
            } else {
                inserted = insert(value, location->getRightBranch(), location);
                if(inserted) {
                    Node* blNode = getHeightAndBalance(location);
                    if(previous != nullptr && previous->getLeftBranch() == location) {
                        previous->setLeftBranch(blNode);
                    }else if(previous != nullptr && previous->getRightBranch() == location){
                        previous->setRightBranch(blNode);
                    }
                }

            }
        } else {
            inserted = false;

        }
    }


//        location = root;
//        previous = nullptr;

//        if (location != nullptr) {
//
//            if(value < location->getValue()) {
//                location = location->getLeftBranch();
//            }else if(value > location->getValue()) {
//                location = location->getRightBranch();
//            }else {
//                return false; // Not allow duplicate
//            }
//        }else{
//
//            Node* newNode = new Node(value);
//            if(value < previous->getValue()) {
//                previous->setLeftBranch(newNode);
//            }else {
//                previous->setRightBranch(newNode);
//            }
//


        //getHeightAndBalance(newNode);
        return inserted;
    }








