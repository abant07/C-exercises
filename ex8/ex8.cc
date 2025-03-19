// Amogh Bantwal
// amoghb07@uw.edu

#include <iostream>
#include "Vector.hh"

using namespace std;
using namespace vector333;

int main(int argc, char* argv[]) {

    // u = (1,2,3)
    Vector u(1,2,3);
    // z = (1,2,3)
    Vector z = u;
    
    // (1,2,3)
    cout << u << endl;

    u += z;
    // (2,4,6)
    cout << u << endl;

    u -= z;
    // (1,2,3)
    cout << u << endl;

    Vector i = u + z;

    // i = (2,4,6)
    cout << i << endl;
    
    Vector a = i - u - z;

    // i = (0,0,0)
    cout << a << endl;

    Vector m = a * 2;

    // (0,0,0)
    cout << m << endl;

    // 14
    double val = u * z;


    cout << val << endl;

    return EXIT_SUCCESS;
}