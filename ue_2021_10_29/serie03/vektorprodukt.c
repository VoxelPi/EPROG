/*
* Aufgabe 3.3
* Peter Smek, 27.10.2021
*/


#include <stdio.h>

void vektorprodukt(double u_a, double u_b, double u_c, double v_x, double v_y, double v_z) {
    double w_1 = u_b * v_z - u_c * v_y;
    double w_2 = u_c * v_x - u_a * v_z;
    double w_3 = u_a * v_y - u_b * v_x;

    printf("        / %10.5f \\\n", w_1);
    printf("u x v = | %10.5f |\n", w_2);
    printf("        \\ %10.5f /\n", w_3);
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

    vektorprodukt(u_a, u_b, u_c, v_x, v_y, v_z);

    return 0;
}
