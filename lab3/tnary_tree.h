#ifndef LAB3_TNARY_TREE_H
#define LAB3_TNARY_TREE_H
#include "node.h"
class TNaryTree {
public:
    TNaryTree(int n);
    TNaryTree(const TNaryTree& other);
    void sub_copy(std::shared_ptr<Node>& cur,std::shared_ptr<Node> cp);
    void Update(const Pentagon &&pentagon,const std::string &&tree_path="");
    void set_root(const Pentagon &pentagon);
    void Print(std::ostream& os) const;
    void sub_print(std::shared_ptr<Node> cur,std::ostream &os) const;
    void RemoveSubTree(const std::string &&tree_path);
    void sub_clear(std::shared_ptr<Node> cur);
    bool Empty();
    double Area(const std::string &&tree_path);
    void sub_area(std::shared_ptr<Node> cur,double& sum);
    friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);
    void sub_print_operator(std::shared_ptr<Node> cur, std::ostream &os) const;
    Pentagon& GetItem(const std::string &&tree_path="");
    virtual ~TNaryTree();
private:
    int N;
    std::shared_ptr<Node> root;
};
#endif //LAB3_TNARY_TREE_H
