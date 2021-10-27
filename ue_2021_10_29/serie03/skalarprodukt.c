/*
* Aufgabe 3.1
* Peter Smek, 27.10.2021
*/

#include <stdio.h>

double skalarprodukt(double u_a, double u_b, double u_c, double v_x, double v_y, double v_z) {
    return u_a * v_x + u_b * v_y + u_c * v_z;
}

int main() {
    double u_a = 0, u_b = 0, u_c = 0;
    double v_x = 0, v_y = 0, v_z = 0;

    printf("Vector u:\n");
    printf("  a = ");
    scanf("%lf", &u_a);
    printf("  b = ");
    scanf("%lf", &u_b);
    printf("  c = ");
    scanf("%lf", &u_c);
    printf("Vector v:\n");
    printf("  x = ");
    scanf("%lf", &v_x);
    printf("  y = ");
    scanf("%lf", &v_y);
    printf("  z = ");
    scanf("%lf", &v_z);

    printf("u * v = %f\n", skalarprodukt(u_a, u_b, u_c, v_x, v_y, v_z));

    return 0;
}
