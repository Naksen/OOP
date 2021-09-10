#include "pentagon.h"
Point null;

Pentagon::Pentagon(): v1(null),v2(null),v3(null),v4(null),v5(null){
    std::cout << "Default pentagon created" << std::endl;
}

Pentagon::Pentagon(Point v_1,Point v_2, Point v_3, Point v_4, Point v_5):
    v1(v_1), v2(v_2), v3(v_3), v4(v_4), v5(v_5)
{
    std::cout << "Pentagon created" << std::endl;
}

Pentagon::Pentagon(std::istream &is) {

    is >> v1.x >> v1.y;
    is >> v2.x >> v2.y;
    is >> v3.x >> v3.y;
    is >> v4.x >> v4.y;
    is >> v5.x >> v5.y;
    std::cout << "Triangle created via istream" << std::endl;

}

Pentagon::Pentagon(Pentagon& other):
Pentagon(other.v1,other.v2,other.v3,other.v4,other.v5)
{
    std::cout << "Made copy of pentagon";
}

void Pentagon::Print() {

    std::cout << v1.x << " " << v1.y << "\n";
    std::cout << v2.x << " " << v2.y << "\n";
    std::cout << v3.x << " " << v3.y << "\n";
    std::cout << v4.x << " " << v4.y << "\n";
    std::cout << v5.x << " " << v5.y << "\n";

}

Pentagon::~Pentagon() {
    std::cout << "Object";
    Print();
    std::cout << "deleted" << std::endl;
}


