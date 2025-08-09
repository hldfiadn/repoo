//Timestamp : 1639116930357
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

struct titik
{
    int x, y, z;
};


int main(){
    struct titik t = {.y = 0, .z = 1, .x = 2};
    struct titik *p = &t;
    p -> x = 3;
    printf("%d%d%d\n", t.x, t.y, t.z);
}

