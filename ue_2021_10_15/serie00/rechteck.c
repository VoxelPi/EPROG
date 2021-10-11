#include <stdio.h>

int main()
{
    double a = 0, b = 0;

    printf("Width: ");
    scanf("%lf", &a);

    printf("Height: ");
    scanf("%lf", &b);

    // Calculate area
    double A = a * b;

    printf("Area: %lf\n", A);
    return 0;
}
