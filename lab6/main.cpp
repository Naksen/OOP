#include <iostream>
#include "pentagon.h"
#include "tnary_tree.h"
int main() {
  TNaryTree<Pentagon> t(3);

  std::shared_ptr<Pentagon> p1(new Pentagon({0, 0}, {0, 2}, {1, 3}, {2, 3}, {3, 0}));
  std::shared_ptr<Pentagon> p2(new Pentagon({0, 0}, {0, 3}, {1, 3}, {2, 3}, {3, 0}));
  std::shared_ptr<Pentagon> p3(new Pentagon({0, 0}, {0, 4}, {1, 3}, {2, 3}, {3, 0}));
  std::shared_ptr<Pentagon> p4(new Pentagon({0, 0}, {0, 6}, {1, 3}, {2, 3}, {3, 0}));
  std::shared_ptr<Pentagon> p5(new Pentagon({0, 0}, {0, 8}, {1, 3}, {2, 3}, {3, 0}));
  std::shared_ptr<Pentagon> p6(new Pentagon({0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}));

  t.Update(p1,"");
  t.Update(p2,"c");
  t.Update(p3,"cb");
  t.Update(p4,"cbb");
  t.Update(p5,"cc");
  std::cout << t << std::endl;

  std::shared_ptr<Node<Pentagon>> r = t.getroot();

  TIterator<Node<Pentagon>, Pentagon> iter1(r);

  std::cout << "Iterator work:" << std::endl;
  std::cout << *iter1 << std::endl;
  iter1.to_son();
  std::cout << *iter1 << std::endl;
  iter1.to_brother();
  std::cout << *iter1 << std::endl;

  TIterator<Node<Pentagon>, Pentagon> iter2(r);
  iter2.to_son();

  return 0;
}