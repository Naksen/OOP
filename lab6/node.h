//
// Created by Руслан on 27.12.2021.
//

#ifndef LAB6__NODE_H_
#define LAB6__NODE_H_
#include<iostream>
#include<memory>
#include"pentagon.h"
template <class T>

class Node {
 public:

  Node(const std::shared_ptr<T> &k);
  Node(const Node &other);

  std::shared_ptr<Node<T>> last_son();

  template<class A>
  friend std::ostream &operator<<(std::ostream & os, const Node<A> &obj);

  std::shared_ptr<Node<T>> son;
  std::shared_ptr<Node<T>> brother;
  std::shared_ptr<T> key;
};
#endif //LAB6__NODE_H_
