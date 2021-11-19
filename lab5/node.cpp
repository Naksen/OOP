#include "node.h"

template <class T>
Node<T>::Node(const std::shared_ptr<T> &k) {
  key = k;
  son = nullptr;
  brother = nullptr;
}

template <class T>
Node<T>::Node(const Node &other) {
  this->son = other.son;
  this->brother = other.brother;
  this->key = other.key;
}

template <class T>
std::shared_ptr<Node<T>> Node<T>::last_son() {
  std::shared_ptr<Node<T>> ls = son;
  int number_of_sons = 0;
  while (ls->brother != nullptr) {
    ls = ls->brother;
    ++number_of_sons;
  }
  return ls;
}

template<class T>
std::ostream &operator<<(std::ostream & os, const Node<T> &obj) {
  os << "Item: " << *obj.key << std::endl;
  return os;
}

#include "pentagon.h"
template class Node<Pentagon>;
template std::ostream& operator<<(std::ostream& os, const Node<Pentagon>& obj);