/*
 * Aufgabe 4.6
 * Peter Smek, 29.10.2021
 */

#include <stdio.h>

/**
 * Return scalar product of the vectors u and v.
 */ 
double skalarprodukt(double u[3], double v[3]) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

/**
 * Calculate vector product of the vectors u and v and stores it in w.
 */ 
void vektorprodukt(double u[3], double v[3], double w[3]) {
    w[0] = u[1] * v[2] - u[2] * v[1];
    w[1] = u[2] * v[0] - u[0] * v[2];
    w[2] = u[0] * v[1] - u[1] * v[0];
}

int main() {
    double u[3] = { 0.0, 0.0, 0.0 };
    double v[3] = { 0.0, 0.0, 0.0 };
    double w[3] = { 0.0, 0.0, 0.0 };

    // Get user input for vector u.
    printf("Vector u:\n");
    printf("  a = ");
    scanf("%lf", &(u[0]));
    printf("  b = ");
    scanf("%lf", &(u[1]));
    printf("  c = ");
    scanf("%lf", &(u[2]));

    // Get user input for vector v.
    printf("Vector v:\n");
    printf("  x = ");
    scanf("%lf", &(v[0]));
    printf("  y = ");
    scanf("%lf", &(v[1]));
    printf("  z = ");
    scanf("%lf", &(v[2]));

    // Print scalar product u * v.
    printf("Scalar product u * v = %f\n", skalarprodukt(u, v));
    
    // Print vector product u x v.
    vektorprodukt(u, v, w);
    printf("                       / %10.5f \\\n", w[0]);
    printf("Vector product u x v = | %10.5f |\n", w[1]);
    printf("                       \\ %10.5f /\n", w[2]);

    return 0;
}

/*
* Test scalar product for different vectors.
* Test vector product for different vectors.
*/