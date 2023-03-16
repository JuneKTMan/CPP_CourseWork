#ifndef EX5_NODE_HPP
#define EX5_NODE_HPP

using namespace std;

class Node {
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

#endif //EX5_NODE_HPP
