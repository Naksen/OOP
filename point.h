#ifndef OOP_LAB_1_POINT_H
#define OOP_LAB_1_POINT_H
#include <iostream>

class Point {
public:
    Point();
    Point(std::istream &is);
    Point(double x, double y);

    double dist(Point& other);

    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, Point& p);

    double x_;
    double y_;

};
#endif
