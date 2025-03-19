#include "Cartesian.hh"
#include "Polar.hh"
#include <iostream>

int main(int argc, char* argv[]) {
    Cartesian p1(5, 3);
    Cartesian p2(2, 8);

    Polar p3(9,1);
    Polar p4(3,5);

    std::cout << p1.ToString() << std::endl;
    std::cout << p1.Distance(p2) << std::endl;

    std::cout << p3.ToString() << std::endl;
    std::cout << p3.Distance(p4) << std::endl;
}