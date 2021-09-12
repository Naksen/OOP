#include <cmath>

#include "octagon.h"

Octagon::Octagon(): v1(0,0),v2(0,0),v3(0,0),v4(0,0),v5(0,0),v6(0,0),v7(0,0),v8(0,0){
    std::cout << "Default octagon created" << std::endl;
}

Octagon::Octagon(Point v_1,Point v_2, Point v_3, Point v_4, Point v_5, Point v_6, Point v_7, Point v_8):
        v1(v_1), v2(v_2), v3(v_3), v4(v_4), v5(v_5), v6(v_6), v7(v_7), v8(v_8)
{
    std::cout << "Octagon created" << std::endl;
}

Octagon::Octagon(Octagon& other):
        Octagon(other.v1,other.v2,other.v3,other.v4,other.v5,other.v6,other.v7,other.v8)
{
    std::cout << "Made copy of octagon";
}

Octagon::Octagon(std::istream &is) {
    is >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8;
    std::cout << "Octagon created via istream" << std::endl;
}

void Octagon::Print(std::ostream& os) {
    os << "Octagon:" << v1 << v2 << v3 << v4 << v5 << v6 << v7 << v8 << "\n";
}

Octagon::~Octagon() {
    std::cout << "Object octagon ";
    Print(std::cout);
    std::cout << "deleted" << std::endl;
}

double Octagon::Area() {
    Point ar[8];
    ar[0] = v1;
    ar[1] = v2;
    ar[2] = v3;
    ar[3] = v4;
    ar[4] = v5;
    ar[5] = v6;
    ar[6] = v7;
    ar[7] = v8;
    double res = 0;
    for (unsigned i = 0; i < 8; i++) {
        Point p = i ? ar[i-1] : ar[7];
        Point q = ar[i];
        res += (getx(p) - getx(q)) * (gety(p) + gety(q));
    }
    return fabs(res) / 2;
}

size_t Octagon::VertexesNumber() {
    return 8;
}
