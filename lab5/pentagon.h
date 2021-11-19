//
// Created by Руслан on 31.10.2021.
//

#ifndef LAB4__PENTAGON_H_
#define LAB4__PENTAGON_H_
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

  friend std::ostream &operator<<(std::ostream &os, const Pentagon &figure);

  ~Pentagon();
 private:
  Point v1,v2,v3,v4,v5;
};
#endif //LAB4__PENTAGON_H_
