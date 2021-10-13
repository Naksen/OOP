#ifndef LAB3_NODE_H
#define LAB3_NODE_H
#include "pentagon.h"
class Node {
public:
    Node();
    Node(const Pentagon &pentagon);

    std::shared_ptr<Node> last_son();
    void Print(std::ostream &os);

    //Node* son;
    std::shared_ptr<Node> son;
    //Node* brother;
    std::shared_ptr<Node> brother;
    Pentagon key;
};
#endif //LAB3_NODE_H
