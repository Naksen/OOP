#ifndef LAB6__TLINKED_LIST_H_
#define LAB6__TLINKED_LIST_H_

#include <memory>
#include <iostream>
#include "list_item.h"

template<typename T>
class TLinkedList {
 public:
  TLinkedList() : length(0), head(nullptr) {}

  void pushBack(T t) {
    if (length == 0) {
      head = std::make_shared<ListItem<T>>(new (ListItem<T>));
    } else {
      ListItem<T> temp;
      while (temp.getNext() != nullptr) {
        temp = *temp.getNext();
      }
    }
    length++;
  }

  int size() {
    return length;
  }

  void erase(int i) {
    while (i--) {
      head = head->getNext();
    }
    if (length > 0) {
      length--;
    } else {
      std::cout << "list too small" << std::endl;
    }
  }

  std::shared_ptr<ListItem<T>> getFirst() {
    return head;
  }

 private:
  std::shared_ptr<ListItem<T>> head;
  int length;
};


#endif //LAB6__TLINKED_LIST_H_
