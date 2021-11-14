/*
 * Aufgabe 6.3
 * Peter Smek, 14.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates mean and variance of the vector x.
 */ 
void meanVariance(double x[], int n, double *mean, double *variance) {
    // Calculate mean of vector x.
    *mean = 0;
    for (int i = 0; i < n; ++i) {
        *mean += x[i];
    }
    *mean /= n;

    // Calculate variance of vector x.
    *variance = 0;
    for (int i = 0; i < n; ++i) {
        *variance += (x[i] - *mean) * (x[i] - *mean);
    }
    *variance /= (n - 1);
}

int main() {
    double *x = NULL;
    int n = 0;

    double mean = 0;
    double variance = 0;

    while (1) {
        // Increase array size.
        x = realloc(x, (n + 1) * sizeof(double));
        assert(x != NULL);

        // Get user input for x[n].
        printf("> ");
        scanf("%lf", x + n);

        // Exit if input is 0.
        if (x[n] == 0) {
            break;
        }

        // Increment n.
        ++n;

        // Calculate and print mean and variance.
        meanVariance(x, n, &mean, &variance);
        printf("mean(x) = %f    variance(x) = %f\n", mean, variance);
    }

    // Free allocated memory.
    free(x);
}
