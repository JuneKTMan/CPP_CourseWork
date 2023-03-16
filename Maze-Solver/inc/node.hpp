//
// Created by junej on 2023-02-21.
//

#ifndef ASSIGN2_NODE_HPP
#define ASSIGN2_NODE_HPP

using namespace std;
// Need to be change
class MapLocation{
public:
    int x;
    int y;
    bool isExplored;
    MapLocation* previous;
};

class Node {
private:
    MapLocation* value;
    Node* next;

public:
    Node(MapLocation* value) {
        this->value = value;
        this->next = nullptr;
    }

    MapLocation* getValue() {
        return value;
    }

    void setValue(MapLocation* value) {
        this->value = value;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }
};




#endif //ASSIGN2_NODE_HPP
