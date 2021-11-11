/*
 * Aufgabe 5.5
 * Peter Smek, 09.11.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define N 3

/**
 * Calculates the index of the first element with maximum absolute value.
 */ 
int maxabs(double x[], int n) {
    assert(n >= 0);

    // Set max value to |x[0]| and j to 0
    double max_abs = fabs(x[0]);
    int max_abs_j = 0;

    // Loop over all elements of x.
    for (int i = 1; i < n; ++i) {

        // If |x[i]| > max => max = |x[i]|, j = i
        if (fabs(x[i]) > max_abs) {
            max_abs = fabs(x[i]);
            max_abs_j = i;
        }
    }

    // Return index of max. element of x.
    return max_abs_j;
}

int main() {
    double x[N];

    // Get user input for x.
    printf("x[] =\n");
    for (int i = 0; i < N; ++i) {
        x[i] = 0.0;
        printf("  x[%d] = ", i);
        scanf("%lf", &x[i]);
    }

    // Calculate and print max abs of x.
    int j = maxabs(x, N);
    printf("Max of x: x[j=%d] = %f\n", j, fabs(x[j]));

    return 0;
}