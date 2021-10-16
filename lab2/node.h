#ifndef LAB2_NODE_H
#define LAB2_NODE_H
#include "pentagon.h"
class Node {
 public:
  Node();
  Node(const Pentagon &pentagon);

  Node *last_son();
  void Print(std::ostream &os);

  Node *son;
  Node *brother;
  Pentagon key;
};
#endif //LAB2_NODE_H
