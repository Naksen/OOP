#ifndef LAB6__LIST_NODE_H_
#define LAB6__LIST_NODE_H_
#include <iostream>
#include "pentagon.h"
#include <memory>

template <class T>
class HListItem
{
 public:
  HListItem(const std::shared_ptr<Pentagon> &pentagon);
  template <class A>
  friend std::ostream &operator<<(std::ostream &os, HListItem<A> &obj);
  ~HListItem();
  std::shared_ptr<T> pentagon;
  std::shared_ptr<HListItem<T>> next;
};
#include "list_node.cpp"
#endif //LAB6__LIST_NODE_H_
