#ifndef EX9_NODE_HPP
#define EX9_NODE_HPP

using namespace std;

//enum Color {RED, BLACK};

class Node {
private:
    int value;
    Node    *leftBranch, *rightBranch;

    // If RED-BLACK may want:
//     Node *parentNode;
     //bool isRed;

    // If AVL may want
    int height;

    // Plus getters and setters for them as well

public:
    Node(int value) {
        this->value = value;
        this->leftBranch = nullptr;
        this->rightBranch = nullptr;
        //AVL Tree
        this->height = 0;

        // RED-BLACK Tree
        //this->parentNode = nullptr;
        //this->color = RED;
    }

    int getValue() {
        return value;
    }

    void setValue(int value) {
        this->value = value;
    }

    Node *getLeftBranch() {
        return leftBranch;
    }

    void setLeftBranch(Node* left) {
        this->leftBranch = left;
    }

    Node *getRightBranch() {
        return rightBranch;
    }

    void setRightBranch(Node* right) {
        this->rightBranch = right;
    }

    int getHeight(){
        return height;
    }

    void setHeight(int height){
        this->height = height;
    }

    // Red and Black
//    Node* getParentNode() {
//        return parentNode;
//    }
//
//    void setParentNode(Node* parent) {
//        this->parentNode = parent;
//    }


};


#endif //EX9_NODE_HPP
