#ifndef DVECTOR
#define DVECTOR

#include <iostream>

namespace dvector333 {

class DVector {
    private:
        double* vector;
    
    public:
        DVector();
        DVector(const double x, const double y, const double z);
        DVector(const DVector& vector);
        ~DVector();

        // passsing in aliases prevents copying the entire object, and putting as const
        // makes it so we cannot edit "v"
        DVector& operator=(const DVector& v);
        DVector& operator+=(const DVector& v);
        DVector& operator-=(const DVector& v);

        // Declare the operator functions as friends to access private members
        friend DVector operator+(const DVector& u, const DVector& v);
        friend DVector operator-(const DVector& u, const DVector& v);
        friend DVector operator*(const DVector& u, const double k);
        friend double operator*(const DVector& u, const DVector& v);
        friend std::ostream& operator<<(std::ostream& s, const DVector& v);
};

}


#endif