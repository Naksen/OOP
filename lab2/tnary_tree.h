#ifndef LAB2_TNARY_TREE_H
#define LAB2_TNARY_TREE_H

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
  Pentagon &GetItem(const std::string &&tree_path = "");
  virtual ~TNaryTree();

 private:
  int N;
  Node *root;

  Node *get_root();
  void set_root(const Pentagon &pentagon);
  void sub_copy(Node *&cur, Node *cp);
  void sub_print(Node *cur, std::ostream &os) const;
  void sub_remove(Node *cur);
  void sub_area(Node *cur, double &sum);
  void sub_print_operator(Node *cur, std::ostream &os) const;
};

#endif //LAB2_TNARY_TREE_H
