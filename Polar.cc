#include "Polar.hh"
#include <cmath>

double Polar::Distance(const Polar& coord) const {
    return sqrt(pow(this->radius_*cos(this->angle_) - coord.radius_*cos(coord.angle_), 2) + pow(this->radius_*sin(this->angle_) - coord.radius_*sin(coord.angle_), 2));
}

std::string Polar::ToString() {
    std::string result = "Polar: (" + std::to_string(this->radius_) + "," + std::to_string(this->angle_) + ")";
    return result;
}