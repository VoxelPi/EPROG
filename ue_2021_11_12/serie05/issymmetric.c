/*
 * Aufgabe 5.6
 * Peter Smek, 09.11.2021
 */

#include <stdio.h>

#define N 3

/**
 * Returns if the given matrix of size nxn is symmetric.
 */ 
int issymmetric(double A[], int n) {
    // Loop over all rows.
    for (int j = 0; j < n; ++j) {
        // Loop over all columns.
        for (int k = 0; k < n; ++k) {
            // Return false if A_jk is not A_kj.
            if (A[j + k * n] != A[k + j * n]) {
                return 0;
            }
        }
    }

    // Return true.
    return 1;
}

int main() {
    double A[N * N];

    // Get user input.
    printf("Matrix A:\n");
    for (int j = 0; j < N; ++j) {
        printf("Row %d:\n", j);
        for (int k = 0; k < N; ++k) {
            A[j + k * N];
            printf("A[%d, %d] = ", j, k);
            scanf("%lf", &A[j + k * N]);
        }
    }

    // Check if A is symmetric.
    if (issymmetric(A, N)) {
        printf("A is symmetric.\n");
    } else {
        printf("A is not symmetric.\n");
    }

    return 0;
}