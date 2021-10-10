#include "tnary_tree.h"
//Constructor
TNaryTree::TNaryTree(int n) {
    N = n;
    root = nullptr;
}

void TNaryTree::Update(Pentagon &&pentagon, std::string &&tree_path) {
    if (tree_path == "") {
        if (root == nullptr) {
            set_root(pentagon);
        } else root->key = pentagon;
    } else {
        std::shared_ptr<Node> cur = root;
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
                std::shared_ptr<Node> item(new Node(pentagon));
                cur->son = item;
            } else cur->son->key = pentagon;
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            ++degree;
            if (degree > N) {
                throw std::out_of_range("Node cannot be added due to overflow");
            }
            if (cur->brother == nullptr) {
                std::shared_ptr<Node> item(new Node(pentagon));
                cur->brother = item;
            } else cur->brother->key = pentagon;
        }
    }
}

void TNaryTree::set_root(Pentagon &pentagon) {
    std::shared_ptr<Node> cur(new Node(pentagon));
    root = cur;
}

void TNaryTree::Print(std::ostream &os) const {
    std::shared_ptr<Node> cur = root;
    sub_print(cur,os);
}

void TNaryTree::sub_print(std::shared_ptr<Node> cur,std::ostream &os) const{
    cur->Print(os);
    if (cur->son != nullptr) {
        sub_print(cur->son, os);
    }
    if (cur->brother != nullptr) {
        sub_print(cur->brother,os);
    }
    return;
}

bool TNaryTree::Empty() {
    if (root == nullptr)
        return true;
    else return false;
}

void TNaryTree::Clear(std::string &&tree_path) {
    std::shared_ptr<Node> cur;
    if (tree_path == "") {
        sub_clear(root);
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
            std::shared_ptr<Node> cur_d = cur->son;
            cur->son = nullptr;
            sub_clear(cur_d);
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            std::shared_ptr<Node> cur_d = cur->brother;
            cur->brother = nullptr;
            sub_clear(cur_d);
        }
    }
}

void TNaryTree::sub_clear(std::shared_ptr<Node> cur) {
    if (cur->son != nullptr) {
        sub_clear(cur->son);
    }
    if (cur->brother != nullptr) {
        sub_clear(cur->brother);
    }
    //cur.reset();
    return;
}

double TNaryTree::Area(std::string &&tree_path) {
    double sum = 0;
    std::shared_ptr<Node> cur;
    if (tree_path == "") {
        sub_area(root,sum);
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
            sub_area(cur->son,sum);
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            sub_area(cur->brother,sum);
        }
    }
    return sum;
}

void TNaryTree::sub_area(std::shared_ptr<Node> cur,double& sum) {
    if (cur->son != nullptr) {
        sub_area(cur->son,sum);
    }
    if (cur->brother != nullptr) {
        sub_area(cur->brother,sum);
    }
    sum += cur->key.Area();
}

TNaryTree::~TNaryTree() {
    sub_clear(root);
}

TNaryTree::TNaryTree(const TNaryTree& other) {
    N = other.N;
    std::shared_ptr<Node> cp = other.root;
    std::shared_ptr<Node> item(new Node(cp->key));
    root = item;
    std::shared_ptr<Node> cur = root;
    if (cp->son != nullptr) {
        sub_copy(cur->son,cp->son);
    }
    if (cp->brother != nullptr) {
        sub_copy(cur->brother,cp->brother);
    }
}

void TNaryTree::sub_copy(std::shared_ptr<Node>& cur,std::shared_ptr<Node> cp) {
    std::shared_ptr<Node> item(new Node(cp->key));
    cur = item;
    if (cp->son != nullptr) {
        sub_copy(cur->son,cp->son);
    }
    if (cp->brother != nullptr) {
        sub_copy(cur->brother,cp->brother);
    }
    return;
}

std::ostream &operator<<(std::ostream &os, const TNaryTree &tree) {
    std::shared_ptr<Node> cur = tree.root;
    tree.sub_print_operator(cur,os);
    return os;
}

void TNaryTree::sub_print_operator(std::shared_ptr<Node> cur, std::ostream& os) const{
    os << cur->key.Area();
    if (cur->son != nullptr) {
        os << ": [";
        sub_print_operator(cur->son, os);
        os << "]";
    }
    if (cur->brother != nullptr) {
        os << ", ";
        sub_print_operator(cur->brother,os);
        //os << "]";
    }
    return;
}