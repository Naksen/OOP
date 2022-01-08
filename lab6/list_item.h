#ifndef LAB6__LIST_ITEM_H_
#define LAB6__LIST_ITEM_H_

#include <memory>

template <typename T>
class ListItem {
 public:
  ListItem(): data(0) {}
  ListItem(T t): data(t){}
  std::shared_ptr<ListItem<T>> getNext() {
    return next;
  }

  void setNext(std::shared_ptr<ListItem<T>> _next) {
    next = _next;
  }

  T getData() {
    return data;
  }
 private:
  std::shared_ptr<ListItem<T>> next = nullptr;
  T data;
};


#endif //LAB6__LIST_ITEM_H_
