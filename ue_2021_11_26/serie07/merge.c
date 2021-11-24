/*
 * Aufgabe 7.7
 * Peter Smek, 21.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Merges two sorted vectors into one sorted vector.
 */ 
double* merge(double* a, int m, double* b, int n) {
    int c_n = m + n;

    double *c = malloc(c_n * sizeof(double));
    assert(c != NULL);

    int i_a = 0, i_b = 0;
    for (int i = 0; i < c_n; ++i) {
        // Check if all elements of vector a have been copied to c.
        if (i_a >= m) {
            c[i] = b[i_b];
            ++i_b;
            continue;
        }

        // Check if all elements of vector b have been copied to c.
        if (i_b >= n) {
            c[i] = a[i_a];
            ++i_a;
            continue;
        }

        // Copy min(a[i_a], b[i_b]) to c[i].
        if (a[i_a] <= b[i_b]) {
            c[i] = a[i_a];
            ++i_a;
        } else {
            c[i] = b[i_b];
            ++i_b;
        }
    }

    return c;
}

int main() {

    int m = 0, n = 0, c_n = 0;
    double *a = NULL, *b = NULL, *c = NULL;

    // Get user input for m.
    do {
        printf("m = ");
        scanf("%d", &m);
    } while (m < 0);

    // Get user input for n.
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0);

    // Allocate memory for vectors a and b.
    a = malloc(m * sizeof(double));
    assert(a != NULL);

    b = malloc(n * sizeof(double));
    assert(b != NULL);

    // Get user input for vector a.
    printf("Vector a:\n");
    for (int i = 0; i < m; ++i) {
        printf("  a[%d] = ", i);
        scanf("%lf", a + i);
    }

    // Get user input for vector b.
    printf("Vector b:\n");
    for (int i = 0; i < n; ++i) {
        printf("  b%d] = ", i);
        scanf("%lf", b + i);
    }

    // Merge a and b.
    c = merge(a, m, b, n);
    c_n = m + n;

    // Print c.
    printf("Vector c:\n");
    for (int i = 0; i < c_n; ++i) {
        printf("  c[%d] = %f\n", i, c[i]);
    }

    // Free memory.
    free(a);
    free(b);
    free(c);

    return 0;
}