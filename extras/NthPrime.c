
#include "NthPrime.h"
#include "stdbool.h"

int64_t NthPrime(int16_t n) {
    int64_t candidatePrime = 3;
    while(n > 0) {
        bool prime = true;
        for(int64_t i = 2; i < candidatePrime; i++) {
            if (candidatePrime % i == 0) {
                prime = false;
                break;
            }
        }
        if(prime) {
            n -= 1;
        }
        candidatePrime += 1;
    }

    return candidatePrime - 1;
}