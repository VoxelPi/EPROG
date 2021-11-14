/*
 * Aufgabe 6.2
 * Peter Smek, 14.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Selection sort algorithm from EPROG_VO-4:109
 */ 
void selectionSort(double *x, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_j = i;
        for (int j = i + 1; j < n; ++j) {
            if (x[j] < x[min_j]) {
                min_j = j;
            }
        }

        if (min_j != i) {
            double temp = x[min_j];
            x[min_j] = x[i];
            x[i] = temp;
        }
    }
}

/**
 * Filter and sort unique numbers from vector x.
 */
void unique(double *x, int *n) {
    for (int i = 1; i < *n; ++i) {
        // Assume x[i] is unique.
        int unique = 1;
        // Check if the vector contains already a value x[j] = x[i] with j < i.
        for (int i_prev = 0; i_prev < i; ++i_prev) {
            // If duplicate is found set unique to 0 and break.
            if (x[i] == x[i_prev]) {
                unique = 0;
                break;
            }
        }

        // if x[i] is not unique, shift all x[j] with j > i to x[j - 1].
        if (!unique) {
            for (int j = i; j < *n - 1; ++j) {
                x[j] = x[j + 1];
            }
            // Decrement size of vector x.
            --*n;

            // Decrement i, so that next loop iteration uses the same i.
            --i;
        }
    }

    // Sort the vector x.
    selectionSort(x, *n);
}

int main() {
    double *x = NULL;
    int n = 0;

    // Get user input for n.
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0);
    
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

    // Sort vector x.
    unique(x, &n);

    // Print vector x.
    printf("Vector x = \n");
    for (int i = 0; i < n; ++i) {
        printf("  x[%d] = %f\n", i, x[i]);
    }

    // Free allocated memory.
    free(x);
}
