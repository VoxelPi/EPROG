/**
 * Aufgabe 8.8
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Bubble sort algorithm.
 */ 
void bubbleSort(double *x, int n) {
    // n_sorted is the number of already sorted entries at the end of the vector x.
    for (int n_sorted = 0; n_sorted < (n - 1); ++n_sorted) {

        // Loop over all unsorted elements of x between 0 and n - n_sorted - 1
        for (int i = 0; i < (n - 1 - n_sorted); ++i) {

            // If value of x[i] is greater than x[i+1] swap the two entries.
            if (x[i] > x[i + 1]) {
                double temp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = temp;
            }
        }
    }
}

/**
 * Gets a vector from the user.
 */ 
double* scanVector(int *n) {
    // Get user input for n.
    *n = 0;
    do {
        printf("n = ");
        scanf("%d", n);
    } while (n < 0);

    // Allocate vector x.
    double *x = malloc(*n * sizeof(double));
    assert(x != NULL);

    // Get user input for the entries of vector x.
    printf("Vector x:\n");
    for (int i = 0; i < *n; ++i) {
        printf("x[%d] = ", i);
        scanf("%lf", x + i);
    }

    // return the created vector.
    return x;
}

/**
 * Prints the given vector.
 */ 
void printVector(double *x, int n) {
    for (int i = 0; i < n; ++i) {
        printf("x[%d] = %f\n", i, x[i]);
    }
}

int main() {
    // Get vector from user.
    int n = 0;
    double *x = scanVector(&n);

    // Print the unsorted vector x.
    printf("\nVector x (unsorted):\n");
    printVector(x, n);

    // Sort the vector x.
    bubbleSort(x, n);

    // Print the sorted vector x.
    printf("\nVector x (sorted):\n");
    printVector(x, n);

    // Free allocated memory.
    free(x);

    return 0;
}