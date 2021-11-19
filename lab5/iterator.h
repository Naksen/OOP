#ifndef LAB5__ITERATOR_H_
#define LAB5__ITERATOR_H_

#endif //LAB5__ITERATOR_H_

#include <iostream>
#include <memory>

template <class item, class T>
class TIterator {
 public:
  TIterator(std::shared_ptr<item> n){
    node_ptr = n;
  }

  T operator*() {
    return *(node_ptr->key);
  }

  void to_son(){
    if (node_ptr->son == nullptr){
      std::cout << "Node does not exist" << std::endl;
    } else {
      node_ptr = node_ptr->son;
    }
  }
  void to_brother(){
    if (node_ptr->brother == nullptr){
      std::cout << "Node does not exist" << std::endl;
    } else {
      node_ptr = node_ptr->brother;
    }
  }

  bool operator==(TIterator const& i) {
    return node_ptr == i.node_ptr;
  }

  bool operator!=(TIterator const& i) {
    return *this != i;
  }

 private:
  std::shared_ptr<item> node_ptr;
};