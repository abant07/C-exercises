// Amogh Bantwal
// amoghb07@uw.edu

#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
#include "limits.h"

bool isValidNumber(char* num);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Must provide 1 positive integer argument\n");
        return 1;
    }

    if (!isValidNumber(argv[1])) {
        printf("Invalid input. Must input a postive number\n");
        return 1;
    }

    char* endptr;
    unsigned long param = strtoul(argv[1], &endptr, 10);

    double result = 0.0;
    bool minus = false;
    for (unsigned int n = 0; n <= param; n++) {
        if (n == 0) {
            result += 3;
        }
        else {
            if (minus) {
                result -= (4.0 / (2*n * (2*n + 1) * (2*n + 2)));
            }
            else {
                result += (4.0 / (2*n * (2*n + 1) * (2*n + 2)));
            }
            minus = !minus;
        }
    }
    printf("Our estimate of Pi is %.20lf\n", result);

    return 0;
}

bool isValidNumber(char* num) {
    for(int i = 0; num[i] != '\0'; i++) {
        if (!isdigit(num[i])) {
            return false;
        }
    }
    return true;
}