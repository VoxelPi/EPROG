#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;
    double dbl1 = a / b;
    double dbl2 = (double) (a / b);
    double dbl3 = (double) a / b;
    double dbl4 = a / (double) b;

    printf("a) %f\n", dbl1);
    printf("b) %f\n", dbl2);
    printf("c) %f\n", dbl3);
    printf("d) %f\n", dbl4);

    return 0;
}