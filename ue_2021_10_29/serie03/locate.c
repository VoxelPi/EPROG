/*
* Aufgabe 3.5
* Peter Smek, 27.10.2021
*/


#include <stdio.h>

int locate(double c_x, double c_y, double c_r, double p_u, double p_v) {
    double x = p_u - c_x;
    double y = p_v - c_y;

    if (x*x + y*y > c_r*c_r) {
        return 1;
    } else if (x*x + y*y == c_r*c_r) {
        return 0;
    } else {
        return -1;
    }
}

int main() {

    double c_x = 0, c_y = 0, c_r = 0;
    double p_u = 0, p_v = 0;

    printf("Circle:\n");
    printf("  x = ");
    scanf("%lf", &c_x);
    printf("  y = ");
    scanf("%lf", &c_y);
    printf("  r = ");
    scanf("%lf", &c_r);

    printf("Point:\n");
    printf("  u = ");
    scanf("%lf", &p_u);
    printf("  v = ");
    scanf("%lf", &p_v);

    int result = locate(c_x, c_y, c_r, p_u, p_v);

    printf("The point is ");
    if (result < 0) {
        printf("inside ");
    } else if (result == 0) {
        printf("on the border of ");
    } else {
        printf("outside ");
    }
    printf("the circle.\n");

    return 0;
}