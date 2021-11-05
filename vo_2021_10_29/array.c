#include <stdio.h>

int main() {
    double x[3] = {0,0,0};

    printf("Read a vector x in R^3 from keyboard:\n");

    // read x0
    printf("x_0 = ");
    scanf("%lf",&x[0]);

    // read x1
    printf("x_1 = ");
    scanf("%lf",&x[1]);

    // read x2
    printf("x_2 = ");
    scanf("%lf",&x[2]);

    // print vector (componentwise)
    printf("x = (%f, %f, %f)\n",x[0],x[1],x[2]);

    return 0;
}