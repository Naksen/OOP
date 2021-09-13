#ifndef OOP_LAB_1_PENTAGON_H
#define OOP_LAB_1_PENTAGON_H

#include "figure.h"
#include "point.h"
#include <iostream>

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(Point v1,Point v2,Point v3,Point v4,Point v5);
    explicit Pentagon(std::istream &is);
    Pentagon(Pentagon &other);

    void Print(std::ostream& os) override;
    double Area() override;
    size_t VertexesNumber() override;

    ~Pentagon();
private:
    Point v1,v2,v3,v4,v5;
};
#endif
