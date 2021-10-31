#ifndef LAB3_TNARY_TREE_H
#define LAB3_TNARY_TREE_H
#include "node.h"
class TNaryTree {
 public:
  TNaryTree();
  TNaryTree(int n);
  TNaryTree(const TNaryTree &other);
  void Update(const Pentagon &&pentagon, const std::string &&tree_path = "");
  void Print(std::ostream &os) const;
  void RemoveSubTree(const std::string &&tree_path);
  bool Empty();
  double Area(const std::string &&tree_path);
  friend std::ostream &operator<<(std::ostream &os, const TNaryTree &tree);
  const Pentagon &GetItem(const std::string &&tree_path = "");
  virtual ~TNaryTree();
 private:
  int N;
  std::shared_ptr<Node> root;

  void sub_copy(std::shared_ptr<Node> &cur, std::shared_ptr<Node> cp);
  void set_root(const Pentagon &pentagon);
  void sub_print(std::shared_ptr<Node> cur, std::ostream &os) const;
  void sub_remove(std::shared_ptr<Node> cur);
  void sub_area(std::shared_ptr<Node> cur, double &sum);
  void sub_print_operator(std::shared_ptr<Node> cur, std::ostream &os) const;
};
#endif //LAB3_TNARY_TREE_H
