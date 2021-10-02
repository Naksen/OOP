#ifndef LAB2_FIGURE_H
#define LAB2_FIGURE_H

#include "point.h"

class Figure {
private:
    virtual void Print(std::ostream& os) = 0;
    virtual double Area() = 0;
    virtual size_t VertexesNumber() = 0;
};

#endif
