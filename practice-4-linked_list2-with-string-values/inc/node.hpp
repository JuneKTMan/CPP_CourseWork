#ifndef EX4_NODE_HPP
#define EX4_NODE_HPP

#include <string>

using namespace std;

class Node {
    private:
        string value;
        Node* next;

    public:
        Node(string value) {
            this->value = value;
            this->next = nullptr;
        }

        string getValue() {
            return value;
        }

        void setValue(string value) {
            this->value = value;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node* next) {
            this->next = next;
        }
};

#endif //EX4_NODE_HPP
