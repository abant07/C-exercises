// Amogh Bantwal
// amoghb07@uw.edu

#include "stdint.h"
#include "stdio.h"
#include <stdlib.h>

typedef struct Point3d {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} Point3d;

Point3d* AllocatePoint3d(uint16_t x, uint16_t y, uint16_t z);

int main(int argc, char* argv[]) {
    Point3d* test1 = AllocatePoint3d(3, 4, 6);
    if (test1->x != 3) {
        printf("X should be %d", 3);
    }
    else if (test1->y != 4) {
        printf("Y should be %d", 4);
    }
    else if (test1->z != 6) {
        printf("Z should be %d", 6);
    }

    free(test1);

    Point3d* test2 = AllocatePoint3d(5, 9, 0);

    if (test2->x != 5) {
        printf("X should be %d\n", 5);
    }
    else if (test2->y != 9) {
        printf("Y should be %d\n", 9);
    }
    else if (test2->z != 0) {
        printf("Z should be %d\n", 0);
    }

    free(test2);

    return 0;
}

Point3d* AllocatePoint3d(uint16_t x, uint16_t y, uint16_t z) {
    Point3d* ptr = (Point3d*) malloc(sizeof(Point3d));

    if (ptr != NULL) {
        ptr->x = x;
        ptr->y = y;
        ptr->z = z;
        return ptr;
    }
    return ptr;
}
