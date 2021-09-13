#include "hexagon.h"

#include <cmath>

Hexagon::Hexagon(): v1(0,0),v2(0,0),v3(0,0),v4(0,0),v5(0,0),v6(0,0){
    std::cout << "Default hexagon created" << std::endl;
}

Hexagon::Hexagon(Point v_1,Point v_2, Point v_3, Point v_4, Point v_5, Point v_6):
        v1(v_1), v2(v_2), v3(v_3), v4(v_4), v5(v_5), v6(v_6)
{
    std::cout << "Hexagon created" << std::endl;
}

Hexagon::Hexagon(Hexagon& other):
        Hexagon(other.v1,other.v2,other.v3,other.v4,other.v5,other.v6)
{
    std::cout << "Made copy of hexagon";
}

Hexagon::Hexagon(std::istream &is) {
    is >> v1 >> v2 >> v3 >> v4 >> v5 >> v6;
    std::cout << "Hexagon created via istream" << std::endl;
}

void Hexagon::Print(std::ostream& os) {
    os << "Hexagon:" << v1 << v2 << v3 << v4 << v5 << v6 << "\n";
}

Hexagon::~Hexagon() {
    std::cout << "Object hexagon ";
    Print(std::cout);
    std::cout << "deleted" << std::endl;
}

double Hexagon::Area() {
    Point ar[6];
    ar[0] = v1;
    ar[1] = v2;
    ar[2] = v3;
    ar[3] = v4;
    ar[4] = v5;
    ar[5] = v6;
    double res = 0;
    for (unsigned i = 0; i < 6; i++) {
        Point p = i ? ar[i-1] : ar[5];
        Point q = ar[i];
        res += (getx(p) - getx(q)) * (gety(p) + gety(q));
    }
    return fabs(res) / 2;
}

size_t Hexagon::VertexesNumber() {
    return 6;
}

