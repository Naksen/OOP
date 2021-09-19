#ifndef LAB2_TNARY_TREE_H
#define LAB2_TNARY_TREE_H
#include "node.h"
class TNaryTree {
public:
    TNaryTree(int N);
    void add_node(Node* node, Pentagon& p);
private:
    int N;
    Node root;
};
#endif //LAB2_TNARY_TREE_H
