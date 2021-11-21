/*
 * Aufgabe 7.1
 * Peter Smek, 21.11.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates (f(x + h) - f(x)) / h.
 */ 
double phi(double (*fct)(double), double x, double h) {
    assert(h > 0);

    return (fct(x + h) - fct(x)) / h;
}

/**
 * Approximates the derivative f'(x) at the fixed point x.
 */ 
double* diff(double (*fct)(double), double x, double h0, double tau, int *n) {

    double h_n = h0;
    double h_n1;

    double *phi_h_n_series = NULL;

    double phi_h_n;
    double phi_h_n1 = phi(fct, x, h0);

    for (*n = 1; ; ++*n) {
        // Calculate h_(n+1)
        h_n1 = h_n / 2;

        // Calculate phi at h_n and h_(n+1)
        phi_h_n = phi_h_n1;
        phi_h_n1 = phi(fct, x, h_n1);

        // Reallocate vector.
        phi_h_n_series = realloc(phi_h_n_series, *n * sizeof(double));
        assert(phi_h_n_series != NULL);
        phi_h_n_series[*n - 1] = phi_h_n;

        // Calculate tolerance
        double tolerance = tau;
        if (fabs(phi_h_n) > tau) {
            tolerance * fabs(phi_h_n);
        }

        // Check if |phi(h_n) - phi(h_(n+1))| <= tolerance
        if (fabs(phi_h_n - phi_h_n1) <= tolerance) {
            return phi_h_n_series;
        }

        // Calculate next h_n
        h_n = h_n1;
    }
}

/**
 *  Test function 1
 */ 
double f_const(double x) {
    return 1;
}

/**
 *  Test function 2
 */ 
double f_lin(double x) {
    return x;
}

/**
 *  Test function 3
 */ 
double f_square(double x) {
    return x * x / 2;
}

/**
 * Main program.
 */ 
int main() {
    int n = 0;
    double x = 0, h0 = 0, tau = 1e-3;
    double *phi_series = NULL;

    // Get user input for x.
    printf("x = ");
    scanf("%lf", &x);

    // Get user input for h0.
    do {
        printf("h0 = ");
        scanf("%lf", &h0);
    } while (h0 <= 0);

    // Get user input for tau.
    do {
        printf("tau = ");
        scanf("%lf", &tau);
    } while (tau <= 0);

    // Calculate phi series.
    phi_series = diff(f_square, x, h0, tau, &n);

    // Print phi series.
    for (int i = 0; i < n; ++i) {
        printf("phi(h_%d) = %f\n", i, phi_series[i]);
    }

    // Free allocated memory.
    free(phi_series);
    phi_series = NULL;
    n = 0;

    return 0;
}