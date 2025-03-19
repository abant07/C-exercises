#ifndef VECTOR
#define VECTOR

#include <iostream>

namespace vector333 {

class Vector {

public:
    Vector(); // deafult 0 arg constructor
    Vector(const int x, const int y, const int z); // 3 argument constructor
    Vector(const Vector& vector); // copy constructor
    ~Vector(); // destructor

    // accessor methods
    int get_x() const { return x_; }
    int get_y() const { return y_; }
    int get_z() const { return z_; }


    // member functions are funcitons that have access to private and public method within the class.
    // non memeber functions are functions that are not apart of the class
    // friend functions are functions that are passed in a reference to the class and so they need
    // private permissions

    // the opreators if they are memeber functions only take in a single parameter. else if they
    // take 2, they are non memeber functions or friend functions
    Vector& operator=(const Vector& v); // assigment operator
    Vector& operator+=(const Vector& v); // add the two values 
    Vector& operator-=(const Vector& v);
    
private:
    // instance fields
    int x_; 
    int y_;
    int z_;
};

Vector operator+(const Vector &a, const Vector &b);
Vector operator-(const Vector &a, const Vector &b);

// dot-product: if a is (a,b,c) and b is (x,y,z),
// return ax+by+cz
double operator*(const Vector &a, const Vector &b);

// scalar multiplication: if v is (a,b,c), return (ak,bk,ck)
Vector operator*(const double k, const Vector &v);
Vector operator*(const Vector &v, const double k);

// Stream output: define << for Vectors
std::ostream & operator<<(std::ostream &out, const Vector &v);

}

#endif
