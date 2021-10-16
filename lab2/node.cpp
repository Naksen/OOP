#include "node.h"

Node::Node(const Pentagon &pentagon) {
  key = pentagon;
  son = nullptr;
  brother = nullptr;
}

Node::Node() {
  son = nullptr;
  brother = nullptr;
}

Node *Node::last_son() {
  Node *ls = son;
  int number_of_sons = 0;
  while (ls->brother != nullptr) {
    ls = ls->brother;
    ++number_of_sons;
  }
  return ls;
}

void Node::Print(std::ostream &os) {
  key.Print(os);
}
