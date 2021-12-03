/**
 * Aufgabe 8.3
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the float corresponding to the given decimal number x.
 */ 
int* dec2float(double x, int M, int *e) {
    // Allocate memory of digits vector.
    int *a = malloc(M * sizeof(int));
    assert(a != NULL);

    // Initialize all digits.
    a[0] = 1; // Normalized float.
    for (int i = 1; i < M; ++i) {
        a[i] = 0;
    }

    // Initialize exponent.
    *e = 0;

    // If x is 0, return.
    if (x == 0) {
        return a;
    }

    // Note: 0 < x

    // calculate exponent e.
    if (x >= 1) {
        // If x >= 1, increment e until and half x < 1. (First digit must be 1.)
        while (x >= 1) {
            x /= 2;
            ++(*e);
        }
    } else {
        // If x < 0.5, decrement e and double x until x >= 0.5. (First digit must be 1.)
        while (x < 0.5) {
            x *= 2;
            --(*e);
        }
    }

    // Note: 0.5 <= x < 1

    x -= 0.5;

    // Note: 0 <= x < 0.5

    // Calculate digits.
    // First digit (a[0]) is 1 (definition normalized float).
    for (int i = 1; i < M; ++i) {
        x *= 2; // Note: 0 <= x < 1
        
        if (x >= 0.5) {
            a[i] = 1; // Set (i+1)th digit to 1
            x -= 0.5; // Subtract 0.5 from x. => x < 0.5
        } else {
            a[i] = 0; // Set (i+1)th digit to 0
        }
        // Note: 0 <= x < 0.5
    }
    
    return a;
}

int main() {
    double x = 0;
    int M = 0;

    int e = 0;
    int *a = NULL;

    // Get user input for x.
    do {
        printf("x = ");
        scanf("%lf", &x);
    } while (x < 0);

    // Get user input for M.
    do {
        printf("M = ");
        scanf("%d", &M);
    } while (M <= 0);

    // Calculated corresponding float representation of x.
    a = dec2float(x, M, &e);

    // Print calculated digits.
    printf("digits:\n");
    for (int i = 0; i < M; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // Print calculated exponent.
    printf("e = %d\n", e);

    // Free allocated memory.
    free(a);

    return 0;
}