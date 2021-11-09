
#include "tnary_tree.h"

template <class T>
TNaryTree<T>::TNaryTree(int n) {
  N = n;
  root = nullptr;
}

template <class T>
TNaryTree<T>::TNaryTree() {
  N = 3;
  root = nullptr;
}

template <class T>
void TNaryTree<T>::Update(std::shared_ptr<T> k, const std::string &&tree_path) {
  if (tree_path == "") {
    if (root == nullptr) {
      set_root(k);
    } else root->key = k;
  } else {
    std::shared_ptr<Node<T>> cur = root;
    int degree = 1;
    for (int i = 0; i < tree_path.size() - 1; ++i) {

      if (tree_path[i] == 'c') {

        degree = 1;
        cur = cur->son;
        if (cur == nullptr) {
          throw std::invalid_argument("The node doesn't exist");
        }

      }
      if (tree_path[i] == 'b') {

        ++degree;
        cur = cur->brother;
        if (cur == nullptr) {
          throw std::invalid_argument("The node doesn't exist");
        }

      }

    }
    if (tree_path[tree_path.size() - 1] == 'c') {
      if (cur->son == nullptr) {
        std::shared_ptr<Node<T>> item(new Node(k));
        cur->son = item;
      } else cur->son->key = k;
    }
    if (tree_path[tree_path.size() - 1] == 'b') {
      ++degree;
      if (degree > N) {
        throw std::out_of_range("Node cannot be added due to overflow");
      }
      if (cur->brother == nullptr) {
        std::shared_ptr<Node<T>> item(new Node(k));
        cur->brother = item;
      } else cur->brother->key = k;
    }
  }
}

template <class T>
void TNaryTree<T>::set_root(std::shared_ptr<T> &k) {
  std::shared_ptr<Node<T>> cur(new Node(k));
  root = cur;
}

template <class T>
bool TNaryTree<T>::Empty() {
  if (root == nullptr)
    return true;
  else return false;
}

template <class T>
void TNaryTree<T>::RemoveSubTree(const std::string &&tree_path) {
  std::shared_ptr<Node<T>> cur;
  if (tree_path == "") {
    sub_remove(root);
  } else {
    cur = root;
    for (int i = 0; i < tree_path.size() - 1; ++i) {

      if (tree_path[i] == 'c') {

        cur = cur->son;

      }
      if (tree_path[i] == 'b') {

        cur = cur->brother;

      }

    }
    if (tree_path[tree_path.size() - 1] == 'c') {
      std::shared_ptr<Node<T>> cur_d = cur->son;
      cur->son = nullptr;
      sub_remove(cur_d);
    }
    if (tree_path[tree_path.size() - 1] == 'b') {
      std::shared_ptr<Node<T>> cur_d = cur->brother;
      cur->brother = nullptr;
      sub_remove(cur_d);
    }
  }
}

template <class T>
void TNaryTree<T>::sub_remove(std::shared_ptr<Node<T>> cur) {
  if (cur->son != nullptr) {
    std::shared_ptr<Node<T>> it = cur->son;
    cur->son = nullptr;
    sub_remove(it);
  }
  if (cur->brother != nullptr) {
    std::shared_ptr<Node<T>> it = cur->brother;
    cur->brother = nullptr;
    sub_remove(it);
  }
  cur.reset();
  return;
}

template <class T>
TNaryTree<T>::~TNaryTree() {
  if (root == nullptr) {
    return;
  }
  sub_remove(root);
}

template <class T>
TNaryTree<T>::TNaryTree(const TNaryTree &other) {
  N = other.N;
  std::shared_ptr<Node<T>> cp = other.root;
  std::shared_ptr<Node<T>> item(new Node(cp->key));
  root = item;
  std::shared_ptr<Node<T>> cur = root;
  if (cp->son != nullptr) {
    sub_copy(cur->son, cp->son);
  }
  if (cp->brother != nullptr) {
    sub_copy(cur->brother, cp->brother);
  }
}

template <class T>
void TNaryTree<T>::sub_copy(std::shared_ptr<Node<T>> &cur, std::shared_ptr<Node<T>> cp) {
  std::shared_ptr<Node<T>> item(new Node(cp->key));
  cur = item;
  if (cp->son != nullptr) {
    sub_copy(cur->son, cp->son);
  }
  if (cp->brother != nullptr) {
    sub_copy(cur->brother, cp->brother);
  }
  return;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const TNaryTree<T> &tree) {
  std::shared_ptr<Node<T>> cur = tree.root;
  tree.sub_print_operator(cur, os);
  return os;
}

template <class T>
void TNaryTree<T>::sub_print_operator(std::shared_ptr<Node<T>> cur, std::ostream &os) const {
  T k = *(cur->key);
  os << k.Area();
  if (cur->son != nullptr) {
    os << ": [";
    sub_print_operator(cur->son, os);
    os << "]";
  }
  if (cur->brother != nullptr) {
    os << ", ";
    sub_print_operator(cur->brother, os);
    //os << "]";
  }
  return;
}

template <class T>
const std::shared_ptr<T> &TNaryTree<T>::GetItem(const std::string &&tree_path) {
  std::shared_ptr<Node<T>> cur;
  if (tree_path == "") {
    return root->key;
  } else {
    cur = root;
    for (int i = 0; i < tree_path.size() - 1; ++i) {

      if (tree_path[i] == 'c') {

        cur = cur->son;

      }
      if (tree_path[i] == 'b') {

        cur = cur->brother;

      }

    }
    if (tree_path[tree_path.size() - 1] == 'c') {
      return cur->son->key;
    }
    if (tree_path[tree_path.size() - 1] == 'b') {
      return cur->brother->key;
    }
  }
}

template class TNaryTree<Pentagon>;
template std::ostream &operator<<(std::ostream &os, const TNaryTree<Pentagon> &tree);
