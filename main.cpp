#include <iostream>
#include "pentagon.h"
int main() {

    Pentagon p1;
    p1.Print();

    Point a(0,0),b(0,2),c(1,3),d(2,3),e(3,0);
    Pentagon p2(a,b,c,d,e);
    p2.Print();
    std::cout << "Area is " << p2.Area() << "\n";

    Pentagon p3(std::cin);
    p3.Print();

    return 0;
}
/* 2 3
   4 5
   10 23
   3 5
   1 2 */
