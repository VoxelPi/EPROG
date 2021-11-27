/**
 * Aufgabe 8.1
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Returns the binary representation of an given integer between 0 and 655535
 */ 
int* dec2bin(int N, int* n) {
    int *binary = malloc(16 * sizeof(int));
    assert(binary != NULL);
    
    int a = N;
    int b = (65535 + 1) / 2; // Value of bit i. (65535 + 1) / 2 = Value of highest bit.
    *n = 1; // Number has always at least on bit. 0 = ( 0 )
    for (int i = 15; i >= 0; --i) {
        if (a >= b) {
            // Set ith bit to 1.
            binary[i] = 1;
            a -= b;

            // Set n_bits
            if (*n == 1) {
                *n = i + 1;
            }
        } else {
            // Set ith bit to 0.
            binary[i] = 0;
        }
        b /= 2;
    }

    // Reduce array if possible.
    binary = realloc(binary, *n * sizeof(int));
    assert(binary != NULL);

    return binary;
}

int main() {
    int N = 0;

    // Get user input for N.
    do {
        printf("N = ");
        scanf("%d", &N);
    } while (!(0 <= N && N <= 65535));
    
    // Calculate binary representation of N.
    int n = 0;
    int *binary = dec2bin(N, &n);

    // Print binary representation of N.
    printf("%d (base 10) = ", N);
    for (int i = n - 1; i >= 0; --i) {

        // Print optional seperation symbol, to make the output more readable.
        if (i != n - 1 && (i+1) % 4 == 0 && i != 0) {
            printf("_");
        }

        // Print digit of binary number.
        printf("%d", binary[i]);
    }
    printf(" (base 2)\n");

    // Free allocated memeory.
    free(binary);

    return 0;
}