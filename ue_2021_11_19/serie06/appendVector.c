/*
 * Aufgabe 6.5
 * Peter Smek, 14.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Append vector y to vector x.
void appendVector(double **x, int *n, double *y, int m) {
    *x = realloc(*x, (*n + m) * sizeof(double));
    assert(x != NULL);

    // Copy y into x.
    for (int i = 0; i < m; ++i) {
        (*x)[i + *n] = y[i];
    }

    // Add length of y to length of x.
    *n += m;
}

int main() {
    double *x = NULL, *y = NULL;
    int n = 0, m = 0;

    // Get user input for n.
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0);

    // Get user input for m.
    do {
        printf("m = ");
        scanf("%d", &m);
    } while (m < 0);
    
    // Allocate memory for n doubles.
    x = malloc(n * sizeof(double));
    assert(x != NULL);
    
    // Allocate memory for m doubles.
    y = malloc(m * sizeof(double));
    assert(y != NULL);

    // Get user input for vector x.
    printf("Vector x = \n");
    for (int i = 0; i < n; ++i) {
        x[i] = 0;
        printf("  x[%d] = ", i);
        scanf("%lf", x + i);
    }

    // Get user input for vector y.
    printf("Vector y = \n");
    for (int i = 0; i < m; ++i) {
        y[i] = 0;
        printf("  y[%d] = ", i);
        scanf("%lf", y + i);
    }

    // Sort vector x.
    appendVector(&x, &n, y, m);

    // Print vector x.
    printf("Vector x = \n");
    for (int i = 0; i < n; ++i) {
        printf("  x[%d] = %f\n", i, x[i]);
    }

    // Free allocated memory.
    free(x);
    free(y);

    return 0;
}
