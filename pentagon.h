#ifndef OOP_LAB_1_PENTAGON_H
#define OOP_LAB_1_PENTAGON_H

#include "figure.h"
#include <iostream>

struct Point{
    double x = 0;
    double y = 0;
};

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(Point v1,Point v2,Point v3,Point v4,Point v5);
    Pentagon(std::istream &is);
    Pentagon(Pentagon &other);

    void Print();
    double Square();

    ~Pentagon();
private:
    Point v1,v2,v3,v4,v5;
};
#endif
