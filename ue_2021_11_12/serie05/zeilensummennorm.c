/*
 * Aufgabe 5.2
 * Peter Smek, 09.11.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define M 3
#define N 2

/**
 * Calculates the zeilensummennorm of the mxn matrix A.
 */ 
double zeilensummennorm(double A[], int m, int n) {
    assert(m >= 0);
    assert(n >= 0);

    // Calculate sum of first row.
    double max_sum = 0;
    for (int k = 0; k < n; ++k) {
        max_sum += fabs(A[0 + k * m]);
    }

    for (int j = 1; j < m; ++j) {
        // Calculate sum of jth row.
        int sum = 0;
        for (int k = 0; k < n; ++k) {
            sum += fabs(A[j + k * m]);
        }

        // If sum > max_sum set max_sum to sum.
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    // Return max. row sum.
    return max_sum;
}

int main() {
    double A[M * N];

    // Get user input.
    printf("Matrix A:\n");
    for (int j = 0; j < M; ++j) {
        printf("Row %d:\n", j);
        for (int k = 0; k < N; ++k) {
            A[j + k * M];
            printf("A[%d, %d] = ", j, k);
            scanf("%lf", &A[j + k * M]);
        }
    }

    // Calculate and print zeilensummennorm of A.
    printf("||A|| = %f\n", zeilensummennorm(A, M, N));

    return 0;
}