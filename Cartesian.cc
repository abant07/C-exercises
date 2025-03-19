#include "Cartesian.hh"
#include <cmath>


double Cartesian::Distance(const Cartesian& coord) const {
    return sqrt(pow(this->x_ - coord.x_, 2) + pow(this->y_ - coord.y_, 2));
}

std::string Cartesian::ToString() {
    std::string result = "Cartesian: (" + std::to_string(this->x_) + "," + std::to_string(this->y_) + ")";
    return result;
}