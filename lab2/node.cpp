#include "node.h"

Node::Node(): n(-1) {}

void Node::increase_son_number() {
    n += 1;
    if (n > 2) {
        my_realloc(n);
    } else sons = new Node[n-1];
}

void Node::add_son(Pentagon& p) {
    increase_son_number();
    Node son;
    son.key = p;
    sons[n-1] = son;
}

void Node::my_realloc(int new_n) {
    Node* new_sons = new Node[new_n - 1];
    for (int i = 0; i < n - 1; i++) {

        new_sons[i] = sons[i];

    }
    delete sons;
    sons = new Node[new_n - 1];
    for (int i = 0; i < n - 1; i++) {

        sons[i] = new_sons[i];

    }
    delete[] new_sons;
}

void Node::init_node(Pentagon& p) {
    if (n == -1) {

        key = p;
        n = 1;

    }
};