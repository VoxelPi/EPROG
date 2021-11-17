/*
 * Aufgabe 6.1
 * Peter Smek, 14.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Removes all elements x[j] with x[j] >= n.
 */ 
double* cut(double *x, int *x_n, int n) {
    // Iterate over all elements of x.
    for (int j = 0; j < *x_n; ++j) {

        // Check if x[j] is >= n.
        if (x[j] >= n) {

            // Shift all x[i] with i > j to x[i - 1].
            for (int i = j; i < *x_n - 1; ++i) {
                x[i] = x[i + 1];
            }

            // Decrement array length.
            --*x_n;
            --j;

            // Reallocate x.
            x = realloc(x, (*x_n) * sizeof(double));
            assert(!(*x_n > 0 && x == NULL));
        }
    }

    return x;
}

int main() {
    double *x = NULL;
    int x_n = 0, n = 0;

    // Get user input for x_n.
    do {
        printf("x_n = ");
        scanf("%d", &x_n);
    } while (x_n < 0);
    
    // Allocate memory for n doubles.
    x = malloc(x_n * sizeof(double));
    assert(x != NULL);

    // Get user input for vector x.
    printf("Vector x = \n");
    for (int i = 0; i < x_n; ++i) {
        x[i] = 0;
        printf("  x[%d] = ", i);
        scanf("%lf", x + i);
    }

    // Get user input for n.
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0);

    // Cut vector x.
    x = cut(x, &x_n, n);

    // Print vector x.
    printf("Vector x = \n");
    for (int i = 0; i < x_n; ++i) {
        printf("  x[%d] = %f\n", i, x[i]);
    }

    // Free allocated memory.
    free(x);

    return 0;
}
