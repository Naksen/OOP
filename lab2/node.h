#ifndef LAB2_NODE_H
#define LAB2_NODE_H
#include "pentagon.h"
#include <vector>
class Node {
public:
    Node();
    void increase_son_number();
    void add_son(Pentagon& p);
    void my_realloc(int new_n);
    void init_node(Pentagon& p);

    std::vector<Node*> ch;
    int n;
    Node* sons;
    Pentagon key;
};
#endif //LAB2_NODE_H
