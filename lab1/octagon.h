#ifndef OOP_LAB_1_OCTAGON_H
#define OOP_LAB_1_OCTAGON_H
#include "figure.h"

#include <iostream>

class Octagon : public Figure {
public:
    Octagon();
    Octagon(Point v1,Point v2,Point v3,Point v4,Point v5,Point v6,Point v7, Point v8);
    explicit Octagon(std::istream &is);
    Octagon(Octagon &other);

    void Print(std::ostream& os) override;
    double Area() override;
    size_t VertexesNumber() override;

    ~Octagon();
private:
    Point v1,v2,v3,v4,v5,v6,v7,v8;
};
#endif
