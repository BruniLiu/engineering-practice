#include <stdio.h>

struct point{
    int x;
    int y;
};

int main(){
    struct point p;
    p.x = 3;
    p.y = 4;

    struct point *pp;
    pp = &p;
    (*pp).x = 10;
    (*pp).y = 9;

    printf("x=%d, y=%d\n", p.x, p.y);
    printf("x=%d, y=%d\n", pp->x, pp->y);
    return 0;
}