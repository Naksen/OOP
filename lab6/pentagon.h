//
// Created by Руслан on 27.12.2021.
//

#ifndef LAB6__PENTAGON_H_
#define LAB6__PENTAGON_H_
#include "figure.h"
#include "point.h"
#include <iostream>
#include "tallocator.h"

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

  void* operator new(size_t size);
  void operator delete(void* ptr);

  ~Pentagon();
 private:
  static TAllocator allocator;
  Point v1,v2,v3,v4,v5;
};
#endif //LAB6__PENTAGON_H_
