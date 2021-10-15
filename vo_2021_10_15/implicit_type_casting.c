#include <stdio.h>

int main() {
    double dbl1 = 2 / 3;
    double dbl2 = 2 / 3.;
    double dbl3 = 1e2;
    int int1 = 2;
    int int2 = 3;

    printf("a) %f\n", dbl1);
    printf("b) %f\n", dbl2);

    printf("c) %f\n", dbl3 * int1 / int2);
    printf("d) %f\n", dbl3 * (int1 / int2));

    return 0;
}