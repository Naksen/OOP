#ifndef OOP_LAB_1_FIGURE_H
#define OOP_LAB_1_FIGURE_H
#include "point.h"

class Figure {
private:
    virtual void Print() = 0;
    virtual double Area() = 0;
};

#endif
