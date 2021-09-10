#include <iostream>
#include "pentagon.h"
int main() {

    Pentagon p;
    p.Print();

    Pentagon a({3,4},{5,6},{7,8},{9,10},{12,13});
    a.Print();

    Pentagon b(std::cin);
    b.Print();

    return 0;
}
/* 2 3
   4 5
   10 23
   3 5
   1 2 */
