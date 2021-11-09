/*
 * Aufgabe 5.7
 * Peter Smek, 09.11.2021
 */

#include <stdio.h>

#define N 5

/**
 * Prints all unique numbers in x.
 */ 
void printUnique(double x[], int n) {
    printf("Unique numbers: \n");
    for (int i = 0; i < n; ++i) {
        // Assume x[i] is unique.
        int unique = 1;

        // Check if x[i] is not unique.
        for (int j = 0; j < n; ++j) {
            // Skip if i = j
            if (i == j) {
                continue;
            }

            // Set unique to 0 if x[i] = x[j].
            if (x[i] == x[j]) {
                unique = 0;
            }
        }

        // Print x[i] if unique.
        if (unique) {
            printf("  %f\n", x[i]);
        }
    }
}

int main() {
    double x[N];

    // Get user input.
    printf("Vector x:\n");
    for (int i = 0; i < N; ++i) {
        x[i] = 0;
        printf("  x[%2d] = ", i);
        scanf("%lf", &x[i]);
    }

    // Print unique numbers.
    printUnique(x, N);

    return 0;
}