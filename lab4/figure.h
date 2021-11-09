#ifndef LAB4__FIGURE_H_
#define LAB4__FIGURE_H_
#include <memory>
#include "point.h"

class Figure {
 private:
  virtual void Print(std::ostream& os) = 0;
  virtual double Area() = 0;
  virtual size_t VertexesNumber() = 0;
};
#endif //LAB4__FIGURE_H_
