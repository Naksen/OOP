#ifndef LAB2_TNARY_TREE_H
#define LAB2_TNARY_TREE_H
#include "node.h"
class TNaryTree {
public:
    TNaryTree(int n);
    TNaryTree(const TNaryTree& other);
    void sub_copy(Node*& cur,Node* cp);
    void Update(Pentagon &&pentagon, std::string &&tree_path="");
    Node* get_root();
    void set_root(Pentagon &pentagon);
    void Print(std::ostream& os) const;
    void sub_print(Node* cur,std::ostream &os) const;
    void Clear(std::string &&tree_path);
    void sub_clear(Node* cur);
    bool Empty();
    double Area(std::string &&tree_path);
    void sub_area(Node* cur,double& sum);
    friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);
    void sub_print_operator(Node* cur, std::ostream &os) const;
    virtual ~TNaryTree();
private:
    int N;
    Node* root;
};
#endif //LAB2_TNARY_TREE_H
