#ifndef LAB2_TNARY_TREE_H
#define LAB2_TNARY_TREE_H
#include "node.h"
class TNaryTree {
public:
    TNaryTree(int n);
    TNaryTree(const TNaryTree& other);
    void sub_copy(Node*& cur,Node* cp);
    void Update(const Pentagon &&pentagon, const std::string &&tree_path="");
    Node* get_root();
    void set_root(const Pentagon &pentagon);
    void Print(std::ostream& os) const;
    void sub_print(Node* cur,std::ostream &os) const;
    void RemoveSubTree(const std::string &&tree_path);
    void sub_remove(Node* cur);
    bool Empty();
    double Area(const std::string &&tree_path);
    void sub_area(Node* cur,double& sum);
    friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);
    void sub_print_operator(Node* cur, std::ostream &os) const;
    Pentagon& GetItem(const std::string &&tree_path="");
    virtual ~TNaryTree();
private:
    int N;
    Node* root;
};
#endif //LAB2_TNARY_TREE_H
