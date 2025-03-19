// Amogh Bantwal
// amoghb07@uw.edu

#include <iostream>
#include "Vector.hh"

namespace vector333 {
Vector::Vector() {
    this->x_ = 0;
    this->y_ = 0;
    this->z_ = 0;
}

Vector::Vector(const int x, const int y, const int z) {
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

Vector::Vector(const Vector& vector) {
    this->x_ = vector.x_;
    this->y_ = vector.y_;
    this->z_ = vector.z_;
}

Vector::~Vector() { }

Vector& Vector::operator=(const Vector& v) {
    if (this != &v) { // if the alias is not equal to ourselves. we need to prevent v from being the same as this object
    // if they were the same and no check, we would be copying dynamically allocated data. so we
    // would be destructing data before actually being able to copy it. so only use if not modiying in place
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
    }
    // in assignment operators, we delete the memeory from the destination, then fill it with the
    // source, but if they are the same object, we just delted the thing we needed to add.
    return *this;
}

Vector& Vector::operator+=(const Vector& v) {
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;
    return *this;
}

// we are outisde the class, so cannot access private vars. only if we decare operator as Vector::operator+ its a
// member class
Vector operator+(const Vector& v, const Vector& u) {
    return Vector(v.get_x() + u.get_x(), v.get_y() + u.get_y(), v.get_z() + u.get_z());
}

Vector operator-(const Vector& v, const Vector& u) {
    return Vector(v.get_x() - u.get_x(), v.get_y() - u.get_y(), v.get_z() - u.get_z());
}

double operator*(const Vector& v, const Vector& u) {
    return (v.get_x() * u.get_x()) + (v.get_y() * u.get_y()) + (v.get_z() * u.get_z());
}

Vector operator*(const Vector& v, double k) {
    return Vector(v.get_x() * k, v.get_y() * k, v.get_z() * k);
}

std::ostream& operator<<(std::ostream& s, const Vector& v) {
    s << "(" << v.get_x() << "," << v.get_y() << "," << v.get_z() << ")";
    return s;
}

}