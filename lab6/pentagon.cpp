//
// Created by Руслан on 27.12.2021.
//

#include "pentagon.h"
#include <cmath>

Pentagon::Pentagon(): v1(0,0),v2(0,0),v3(0,0),v4(0,0),v5(0,0){
  //std::cout << "Default pentagon created" << std::endl;
}

Pentagon::Pentagon(Point v_1,Point v_2, Point v_3, Point v_4, Point v_5):
    v1(v_1), v2(v_2), v3(v_3), v4(v_4), v5(v_5)
{
  //std::cout << "Pentagon created" << std::endl;
}

Pentagon::Pentagon(Pentagon& other):
    Pentagon(other.v1,other.v2,other.v3,other.v4,other.v5)
{
  //std::cout << "Made copy of pentagon";
}

Pentagon::Pentagon(std::istream &is) {
  is >> v1 >> v2 >> v3 >> v4 >> v5;
  //std::cout << "Pentagon created via istream" << std::endl;
}

void Pentagon::Print(std::ostream& os) {
  os << "Pentagon:" << v1 << v2 << v3 << v4 << v5 << "\n";
}

Pentagon::~Pentagon() {
  //std::cout << "Object Pentagon ";
  //Print(std::cout);
  //std::cout << "deleted" << std::endl;
}

double Pentagon::Area() {
  Point ar[5];
  ar[0] = v1;
  ar[1] = v2;
  ar[2] = v3;
  ar[3] = v4;
  ar[4] = v5;
  double res = 0;
  for (unsigned i = 0; i < 5; i++) {
    Point p = i ? ar[i-1] : ar[4];
    Point q = ar[i];
    res += (getx(p) - getx(q)) * (gety(p) + gety(q));
  }
  return fabs(res) / 2;
}

size_t Pentagon::VertexesNumber() {
  return 5;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &figure)
{
  os << "Pentagon: " << figure.v1 << " " << figure.v2 << " " << figure.v3 << " " << figure.v4 << " " << figure.v5;
  return os;
}