
#ifndef LAB6__POINT_H_
#define LAB6__POINT_H_
#include <istream>

class Point {
 public:
  Point();
  Point(std::istream &is);
  Point(double x, double y);

  double dist(Point& other);
  friend double getx(Point& p);
  friend double gety(Point& p);

  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, const Point& p);

 private:
  double x_;
  double y_;

};
#endif //LAB6__POINT_H_
