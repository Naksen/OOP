#ifndef OOP_LAB_1_HEXAGON_H
#define OOP_LAB_1_HEXAGON_H

#include "figure.h"

#include <iostream>

class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(Point v1,Point v2,Point v3,Point v4,Point v5,Point v6);
    explicit Hexagon(std::istream &is);
    Hexagon(Hexagon &other);

    void Print(std::ostream& os) override;
    double Area() override;
    size_t VertexesNumber() override;

    ~Hexagon();
private:
    Point v1,v2,v3,v4,v5,v6;
};
#endif
