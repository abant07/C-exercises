// Amogh Bantwal
// amoghb07@uw.edu


#include <iostream>
#include "DVector.hh"

using namespace dvector333;
using namespace std;

int main(int argc, char* argv[]) {
    // u = (1,2,3)
    DVector u(1,2,3);
    // z = (1,2,3)
    DVector z = u;
    
    // (1,2,3)
    cout << u << endl;

    u += z;
    // (2,4,6)
    cout << u << endl;

    u -= z;
    // (1,2,3)
    cout << u << endl;

    DVector i = u + z;

    // i = (2,4,6)
    cout << i << endl;
    
    DVector a = i - u - z;

    // i = (0,0,0)
    cout << a << endl;

    DVector m = a * 2;

    // (0,0,0)
    cout << m << endl;

    // 14
    double val = u * z;


    std::cout << val << std::endl;


    return EXIT_SUCCESS;
}