#include <stdio.h>

int main() {

    double a = 0, b = 0, c = 0;
    double x = 0;

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    printf("x = ");
    scanf("%lf", &x);

    double y = (a * x*x) + (b * x) + (c);

    printf("a*x² + b*x + c = %f\n", y);

    return 0;
}
