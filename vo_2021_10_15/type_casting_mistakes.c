#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;
    double dbl = (double) a / b;

    int i = dbl;

    printf("a) %f\n", dbl);
    printf("b) %f\n", dbl * b);
    printf("c) %d\n", i);
    printf("d) %d\n", i * b);

    return 0;
}