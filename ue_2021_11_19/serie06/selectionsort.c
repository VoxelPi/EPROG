/*
 * Aufgabe 6.1
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
    selectionSort(x, n);

    // Print vector x.
    printf("Vector x = \n");
    for (int i = 0; i < n; ++i) {
        printf("  x[%d] = %f\n", i, x[i]);
    }

    // Free allocated memory.
    free(x);

    return 0;
}
