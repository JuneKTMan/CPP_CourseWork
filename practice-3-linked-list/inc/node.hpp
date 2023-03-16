#ifndef EX3_NODE_HPP
#define EX3_NODE_HPP

class Node {
    //create a struct Node
    private:
        int value;
        Node* next;

    public:
        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }

        int getValue() {
            return value;
        }

        void setValue(int value) {
            this->value = value;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node* next) {
            this->next = next;
        }
};

#endif //EX3_NODE_HPP
