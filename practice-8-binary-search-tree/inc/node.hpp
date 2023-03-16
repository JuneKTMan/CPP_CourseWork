#ifndef EX8_NODE_HPP
#define EX8_NODE_HPP

using namespace std;

class Node {
    private:
        int value;
        Node    *leftBranch, *rightBranch;

    public:
        Node(int value) {
            this->value = value;
            this->leftBranch = nullptr;
            this->rightBranch = nullptr;
        }

        int getValue() {
            return value;
        }

        void setValue(int value) {
            this->value = value;
        }

        Node* getLeftBranch() {
            return leftBranch;
        }

        void setLeftBranch(Node* left) {
            this->leftBranch = left;
        }
    
        Node* getRightBranch() {
            return rightBranch;
        }

        void setRightBranch(Node* right) {
            this->rightBranch = right;
        }
};

#endif //EX8_NODE_HPP
