/*
 * Aufgabe 6.4
 * Peter Smek, 14.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a vector containing every sth entry of x.
 */ 
double* sampleVector(double x[], int n, int s, int *v_s_n) {
    assert(s > 0);
    assert(n > 0);

    // Calculate size of sample vector.
    *v_s_n = ((n - 1) / s) + 1;

    // Allocate memory for sample vector.
    double *v_s = malloc(*v_s_n * sizeof(double));
    assert(v_s != NULL);

    // Fill sample vector.
    for (int i = 0; i < n; ++i) {
        if (i % s == 0) {
            v_s[i / s] = x[i];
        }
    }

    // Return sample vector.
    return v_s;
}

int main() {
    double *x = NULL;
    int n = 0, s = 0;

    // Get user input for n.
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1);
    
    // Allocate memory for n doubles.
    x = malloc(n * sizeof(double));
    assert(x != NULL);

    // Get user input for vector x.
    printf("Vector x = \n");
    for (int i = 0; i < n; ++i) {
        x[i] = 0;
        printf("  x[%d] = ", i);
        scanf("%lf", x + i);
    }

    // Get user input for s.
    do {
        printf("s = ");
        scanf("%d", &s);
    } while (s < 1);

    // Get sample vector.
    int v_s_n = 0;
    double *v_s = sampleVector(x, n, s, &v_s_n);

    // Print vector x.
    printf("Vector v_s = \n");
    for (int i = 0; i < v_s_n; ++i) {
        printf("  v_s[%d] = %f\n", i, v_s[i]);
    }

    // Free allocated memory.
    free(x);
    free(v_s);

    return 0;
}
