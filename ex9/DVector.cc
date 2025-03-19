// Amogh Bantwal
// amoghb07@uw.edu

#include <iostream>
#include "DVector.hh"

namespace dvector333{

DVector::DVector() {
    this->vector = new double[3];
    this->vector[0] = 0;
    this->vector[1] = 0;
    this->vector[2] = 0;
}

DVector::DVector(const double x, const double y, const double z) {
    this->vector = new double[3];
    this->vector[0] = x;
    this->vector[1] = y;
    this->vector[2] = z;
}

DVector::DVector(const DVector& vector) {
    this->vector = new double[3];
    this->vector[0] = vector.vector[0];
    this->vector[1] = vector.vector[1];
    this->vector[2] = vector.vector[2];
}

DVector::~DVector() {
    delete[] this->vector;
}

DVector& DVector::operator=(const DVector& v) {
    if (this != &v) {
        this->vector[0] = v.vector[0];
        this->vector[1] = v.vector[1];
        this->vector[2] = v.vector[2];
    }

    return *this;
}

DVector& DVector::operator+=(const DVector& v) {
    this->vector[0] += v.vector[0];
    this->vector[1] += v.vector[1];
    this->vector[2] += v.vector[2];

    return *this;
}

DVector& DVector::operator-=(const DVector& v) {
    this->vector[0] -= v.vector[0];
    this->vector[1] -= v.vector[1];
    this->vector[2] -= v.vector[2];
    return *this;
}


// non memeber functions that have access to the private variables. we needed
// to declare themm not in the DVector class, but in the dvector333 namespace
DVector operator+(const DVector& u, const DVector& v) {
    return DVector (
        u.vector[0] + v.vector[0],
        u.vector[1] + v.vector[1],
        u.vector[2] + v.vector[2]
    );
}

DVector operator-(const DVector& u, const DVector& v) {
    return DVector (
        u.vector[0] - v.vector[0],
        u.vector[1] - v.vector[1],
        u.vector[2] - v.vector[2]
    );
}

DVector operator*(const DVector& u, const double k) {
    return DVector (
        u.vector[0] * k,
        u.vector[1] * k,
        u.vector[2] * k
    );
}

double operator*(const DVector& u,const DVector& v) {
    return (u.vector[0] * v.vector[0]) + (u.vector[1] * v.vector[1]) + (u.vector[2] * v.vector[2]);
}


std::ostream& operator<<(std::ostream& s, const DVector& v) {
    s << "(" << v.vector[0] << "," << v.vector[1] << "," << v.vector[2] << ")";
    return s;
}
}
