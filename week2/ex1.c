#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Value= %d, Size= %lu\n", a, sizeof(a));
    printf("Value= %f, Size= %lu\n", b, sizeof(a));
    printf("Value= %lf, Size= %lu\n", c, sizeof(a));

    return 0;
}