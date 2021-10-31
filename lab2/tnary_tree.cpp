#include "tnary_tree.h"

//Constructor
TNaryTree::TNaryTree(int n) {
  N = n;
  root = nullptr;
}

TNaryTree::TNaryTree() {
  N = 3;
  root = nullptr;
}

void TNaryTree::Update(const Pentagon &&pentagon, const std::string &&tree_path) {
  if (tree_path == "") {
    if (root == nullptr) {
      set_root(pentagon);
    } else root->key = pentagon;
  } else {
    Node *cur = get_root();
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
        cur->son = new Node(pentagon);
      } else cur->son->key = pentagon;
    }
    if (tree_path[tree_path.size() - 1] == 'b') {
      ++degree;
      if (degree > N) {
        throw std::out_of_range("Node cannot be added due to overflow");
      }
      if (cur->brother == nullptr) {
        cur->brother = new Node(pentagon);
      } else cur->brother->key = pentagon;
    }
  }
}

Node *TNaryTree::get_root() {
  return root;
}

void TNaryTree::set_root(const Pentagon &pentagon) {
  root = new Node(pentagon);
}

void TNaryTree::Print(std::ostream &os) const {
  Node *cur = root;
  sub_print(cur, os);
}

void TNaryTree::sub_print(Node *cur, std::ostream &os) const {
  cur->Print(os);
  if (cur->son != nullptr) {
    sub_print(cur->son, os);
  }
  if (cur->brother != nullptr) {
    sub_print(cur->brother, os);
  }
  return;
}

bool TNaryTree::Empty() {
  if (root == nullptr)
    return true;
  else return false;
}

void TNaryTree::RemoveSubTree(const std::string &&tree_path) {
  Node *cur;
  if (tree_path == "") {
    sub_remove(root);
  } else {
    cur = get_root();
    for (int i = 0; i < tree_path.size() - 1; ++i) {
      if (tree_path[i] == 'c') {
        cur = cur->son;
      }
      if (tree_path[i] == 'b') {
        cur = cur->brother;
      }
    }
    if (tree_path[tree_path.size() - 1] == 'c') {
      Node *cur_d = cur->son;
      cur->son = nullptr;
      sub_remove(cur_d);
    }
    if (tree_path[tree_path.size() - 1] == 'b') {
      Node *cur_d = cur->brother;
      cur->brother = nullptr;
      sub_remove(cur_d);
    }
  }
}

void TNaryTree::sub_remove(Node *cur) {
  if (cur->son != nullptr) {
    sub_remove(cur->son);
  }
  if (cur->brother != nullptr) {
    sub_remove(cur->brother);
  }
  delete (cur);
  return;
}

double TNaryTree::Area(const std::string &&tree_path) {
  double sum = 0;
  Node *cur;
  if (tree_path == "") {
    sub_area(root, sum);
  } else {
    cur = get_root();
    for (int i = 0; i < tree_path.size() - 1; ++i) {

      if (tree_path[i] == 'c') {

        cur = cur->son;

      }
      if (tree_path[i] == 'b') {

        cur = cur->brother;

      }

    }
    if (tree_path[tree_path.size() - 1] == 'c') {
      sub_area(cur->son, sum);
    }
    if (tree_path[tree_path.size() - 1] == 'b') {
      sub_area(cur->brother, sum);
    }
  }
  return sum;
}

void TNaryTree::sub_area(Node *cur, double &sum) {
  if (cur->son != nullptr) {
    sub_area(cur->son, sum);
  }
  if (cur->brother != nullptr) {
    sub_area(cur->brother, sum);
  }
  sum += cur->key.Area();
}

TNaryTree::~TNaryTree() {
  sub_remove(root);
}

TNaryTree::TNaryTree(const TNaryTree &other) {
  N = other.N;
  Node *cp = other.root;
  root = new Node(cp->key);
  Node *cur = root;
  if (cp->son != nullptr) {
    sub_copy(cur->son, cp->son);
  }
  if (cp->brother != nullptr) {
    sub_copy(cur->brother, cp->brother);
  }
}

void TNaryTree::sub_copy(Node *&cur, Node *cp) {
  cur = new Node(cp->key);
  if (cp->son != nullptr) {
    sub_copy(cur->son, cp->son);
  }
  if (cp->brother != nullptr) {
    sub_copy(cur->brother, cp->brother);
  }
  return;
}

std::ostream &operator<<(std::ostream &os, const TNaryTree &tree) {
  Node *cur = tree.root;
  tree.sub_print_operator(cur, os);
  return os;
}

void TNaryTree::sub_print_operator(Node *cur, std::ostream &os) const {
  os << cur->key.Area();
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

Pentagon &TNaryTree::GetItem(const std::string &&tree_path) {
  Node *cur;
  if (tree_path == "") {
    return root->key;
  } else {
    cur = get_root();
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


