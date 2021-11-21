/*
 * Aufgabe 7.3
 * Peter Smek, 21.11.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Finds the root of the given function.
 */ 
double newton(double (*fct)(double), double (*fctprime)(double), double x0, double tau) {
    assert(tau > 0);

    double x_n; // x_n
    double x_n_1 = x0; // x_(n-1)

    while (1) {
        // Calculate x_n.
        x_n = x_n_1 - fct(x_n_1) / fctprime(x_n_1);

        // Break condition 1.
        if (fabs(fctprime(x_n)) <= tau) {
            printf("WARNING: Numerical result probably false.\n");
            break;
        }

        // Calculate tolerance.
        double tolerance = tau;
        if (fabs(x_n) > tau) {
            tolerance *= fabs(x_n);
        }

        // Break condition 2.
        if (fabs(fct(x_n)) <= tau && fabs(x_n - x_n_1) <= tolerance) {
            break;
        }

        // Set x_(n-1) to x_n.
        x_n_1 = x_n;
    }

    return x_n;
}

/**
 * Function f(x) = x².
 */ 
double f(double x) {
    return x * x * x - 2;
}

/**
 * Derivative f'(x) = 2*x of f.
 */ 
double f_prime(double x) {
    return 3 * x * x;
}

/**
 * Main program.
 */ 
int main() {
    double x0 = 0, tau = 1e-3;

    // Get user input for x.
    printf("x0 = ");
    scanf("%lf", &x0);

    // Get user input for tau.
    do {
        printf("tau = ");
        scanf("%lf", &tau);
    } while (tau <= 0);

    double root = newton(f, f_prime, x0, tau);

    printf("Found f(x) = 0 at x=%f\n", root);

    return 0;
}