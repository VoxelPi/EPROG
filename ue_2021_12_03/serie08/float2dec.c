/**
 * Aufgabe 8.4
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the decimal value of the given float.
 */ 
double float2dec(int M, int *a, int e) {
    // Initialize x to 0.
    double x = 0.0;

    // Calculate sum of digits.
    double power_of_two = 1;
    for (int k = 1; k <= M; ++k) {
        power_of_two /= 2.0;
        x += a[k - 1] * power_of_two;
    }

    // Multiply x by 2^e
    if (e > 0) {
        for (int i = 0; i < e; ++i) {
            x *= 2.0;
        }
    } else if (e < 0) {
        for (int i = 0; i < -e; ++i) {
            x /= 2.0;
        }
    }

    // Return x.
    return x;
}

int main() {
    int M = 0, e = 0;
    int *a = NULL;

    // Get user input for M.
    do {
        printf("M = ");
        scanf("%d", &M);
    } while (M <= 0);

    // Allocate memory for digits vector.
    a = malloc(M * sizeof(int));
    assert(a != NULL);

    // Get user input for digits vector.
    printf("digits:\n");
    for (int i = 0; i < M; ++i) {
        a[i] = 0;
        do {
            printf("a[%d] = ", i);
            scanf("%d", a + i);
        } while (a[i] != 0 && a[i] != 1);
    }

    // Get user input for exponent.
    printf("e = ");
    scanf("%d", &e);

    // Calculate and print corresponding decimal number.
    printf("x = %f\n", float2dec(M, a, e));

    // Free allocated memory.
    free(a);

    return 0;
}