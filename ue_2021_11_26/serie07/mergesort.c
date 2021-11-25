/*
 * Aufgabe 7.8
 * Peter Smek, 25.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Merges two sorted vectors into one sorted vector and stores it in result.
 * 
 * Code from exercise 7.7.
 */ 
void merge(double* a, int m, double* b, int n, double *result) {
    int c_n = m + n;

    int i_a = 0, i_b = 0;
    for (int i = 0; i < c_n; ++i) {
        // Check if all elements of vector a have been copied to c.
        if (i_a >= m) {
            result[i] = b[i_b];
            ++i_b;
            continue;
        }

        // Check if all elements of vector b have been copied to c.
        if (i_b >= n) {
            result[i] = a[i_a];
            ++i_a;
            continue;
        }

        // Copy min(a[i_a], b[i_b]) to c[i].
        if (a[i_a] <= b[i_b]) {
            result[i] = a[i_a];
            ++i_a;
        } else {
            result[i] = b[i_b];
            ++i_b;
        }
    }
}

void mergeSort(double* x, int n) {
    // If n <= 1 vector is already sorted.
    if (n <= 1) {
        return;
    }

    // If n = 2 sort the two elements manually.
    if (n == 2) {
        if (x[0] > x[1]) {
            double temp = x[0];
            x[0] = x[1];
            x[1] = temp;
        }
        return;
    }

    // Allocate memory for temporary array.
    double *temp_array = malloc(n * sizeof(double));
    assert(temp_array != NULL);

    // Calculate split index and number of elements in each half of the vector.
    int i_split = n / 2;
    int n_a = i_split;
    int n_b = n - n_a;

    // Sort both halfs of the vector.
    mergeSort(x, n_a);
    mergeSort(x + i_split, n_b);

    // Merge the two halfs together.
    merge(x, n_a, x + i_split, n_b, temp_array);
    for (int i = 0; i < n; ++i) {
        x[i] = temp_array[i];
    }

    // Free allocated memory.
    free(temp_array);
}

int main() {

    int n = 0;
    double *x = NULL;

    // Get user input for n.
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0);

    // Allocate memory for vector x.
    x = malloc(n * sizeof(double));
    assert(x != NULL);

    // Get user input for vector x.
    printf("Vector x:\n");
    for (int i = 0; i < n; ++i) {
        printf("  x%d] = ", i);
        scanf("%lf", x + i);
    }

    // Print x.
    printf("Vector x:\n");
    for (int i = 0; i < n; ++i) {
        printf("  x[%d] = %f\n", i, x[i]);
    }

    // Merge a and b.
    mergeSort(x, n);

    // Print x.
    printf("Vector x:\n");
    for (int i = 0; i < n; ++i) {
        printf("  x[%d] = %f\n", i, x[i]);
    }

    // Free memory.
    free(x);

    return 0;
}