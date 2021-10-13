#include <iostream>
#include "pentagon.h"
#include "tnary_tree.h"
int main() {
    TNaryTree t(3);
    t.Update(Pentagon({0,0},{0,2},{1,3},{2,3},{3,0}),"");
    if (t.Empty()) std::cout << "Tree is empty\n";
    else std::cout << "Tree is not empty\n";
    t.Update(Pentagon({0,0},{0,3},{1,3},{2,3},{3,0}),"c");
    t.Update(Pentagon({0,0},{0,4},{1,3},{2,3},{3,0}),"cb");
    t.Update(Pentagon({0,0},{0,6},{1,3},{2,3},{3,0}),"cbb");
    t.Update(Pentagon({0,0},{0,8},{1,3},{2,3},{3,0}),"cc");

    t.Print(std::cout);
    std::cout << "___________________________________________\n";
    t.Update(Pentagon({0,0},{0,0},{0,0},{0,0},{0,0}),"");

    t.RemoveSubTree("cbb");
    t.Print(std::cout);
    std::cout << "___________________________________________\n";

    t.Update(Pentagon({0,0},{0,6},{1,3},{2,3},{3,0}),"cbb");
    t.Print(std::cout);
    std::cout << t.Area("") << "\n";
    std::cout << "___________________________________________\n";

    TNaryTree z(t);
    z.Print(std::cout);
    std::cout << "___________________________________________\n";
    std::cout << z;

    return 0;
}
