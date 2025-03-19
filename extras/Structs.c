// Amogh Bantwal
// amoghb07@uw.edu


#include "stdio.h"
#include "stdbool.h"

struct Point {
    float x;
    float y;
};

struct Rectangle {
    struct Point* bottomLeft;
    struct Point* topRight;
};

float findArea(struct Rectangle rect);
bool insideRect(struct Rectangle rect, struct Point ptn);

int main(int argc, char* argv[]) {
    struct Point bottomL = {4, 5};
    struct Point topR = {9, 10};

    struct Rectangle rect = {&bottomL, &topR};

    printf("Area: %f\n", findArea(rect));

    struct Point p = {4, 6};
    printf("Inside? %d\n", insideRect(rect, p));

    return 0;
}

float findArea(struct Rectangle rect) {
    return (rect.topRight->y - rect.bottomLeft->y) * (rect.topRight->x - rect.bottomLeft->x);
}

bool insideRect(struct Rectangle rect, struct Point ptn) {
    if (ptn.x >= rect.bottomLeft->x && ptn.x <= rect.topRight->x && ptn.y >= rect.bottomLeft->y && ptn.y <= rect.topRight->y) {
        return true;
    }
    return false;
}