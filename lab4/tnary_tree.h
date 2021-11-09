#ifndef LAB4__TNARY_TREE_H_
#define LAB4__TNARY_TREE_H_
#include "node.h"
template <class T>
class TNaryTree {
 public:
  TNaryTree();
  TNaryTree(int n);
  TNaryTree(const TNaryTree<T> &other);

  void Update(std::shared_ptr<T> k, const std::string &&tree_path = "");
  void RemoveSubTree(const std::string &&tree_path);
  bool Empty();

  template<class A>
  friend std::ostream &operator<<(std::ostream &os, const TNaryTree<A> &tree);

  const std::shared_ptr<T> &GetItem(const std::string &&tree_path = "");
  virtual ~TNaryTree();

 private:
  int N;
  std::shared_ptr<Node<T>> root;

  void sub_copy(std::shared_ptr<Node<T>> &cur, std::shared_ptr<Node<T>> cp);
  void set_root(std::shared_ptr<T> &k);
  void sub_remove(std::shared_ptr<Node<T>> cur);
  void sub_print_operator(std::shared_ptr<Node<T>> cur, std::ostream &os) const;
};
#endif //LAB4__TNARY_TREE_H_
