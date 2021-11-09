/*
 * Aufgabe 5.1
 * Peter Smek, 09.11.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define N 3

/**
 * Calculates the l_p norm of x.
 */ 
double pnorm(double x[], int n, double p) {
    assert(p >= 1);

    // Calculate sum.
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(fabs(x[i]), p);
    }

    // Calculate root.
    return pow(sum, 1/p);
}

int main() {

    double x[N];
    double p = 0;

    // Get user input for x.
    printf("x[] =\n");
    for (int i = 0; i < N; ++i) {
        x[i] = 0.0;
        printf("  x[%d] = ", i);
        scanf("%lf", &x[i]);
    }

    // Get user input for p.
    do {
        printf("p = ");
        scanf("%lf", &p);
    } while (p < 1);

    // Calculate l_p norm.
    printf("||x||_%.2f = %f\n", p, pnorm(x, N, p));

    return 0;
}