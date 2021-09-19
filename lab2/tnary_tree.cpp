#include "tnary_tree.h"

TNaryTree::TNaryTree(int N_value):N(N_value) {}

void TNaryTree::add_node(Node* current_node,Pentagon& p) {
    if (current_node->n == -1) {

        current_node->init_node(p);
        return;

    } else if (current_node->n >= 1 && current_node->n < N){

        current_node->add_son(p);
        return;

    } else {

        for (int i = 0; i < N - 1; i++) {

            add_node(&current_node->sons[i],p);

        }

    };
}
