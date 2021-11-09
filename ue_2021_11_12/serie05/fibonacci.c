/*
 * Aufgabe 5.4
 * Peter Smek, 09.11.2021
 */

#include <assert.h>
#include <stdio.h>

/**
 * Calculates the nth fibonacci number.
 * 
 * type determines the algorithm used:
 *   type=1: recursive
 *   type=2: loop
 */ 
int fibonacci(int n, int type) {
    // Check that n >= 0
    assert(n >= 0);
    // Check that type = 1 or 2
    assert(type == 1 || type == 2);

    // Early exit for a_0 = 0 and a_1 = 1.
    if (n <= 1) {
        return n;
    }

    if (type == 1) {
        // Recursive: a_n+1 = a_n + a_n-1 => a_n = a_n-1 + a_n-2.
        return fibonacci(n - 1, 1) + fibonacci(n - 2, 1);

    } else if (type == 2) {
        // Loop.
        int a_n_1 = 0; // a_n-1
        int a_n = 1; // a_n

        // Repeat n-1 times:
        for (int i = 1; i < n; ++i) {
            int temp = a_n; // temp is a_n
            a_n += a_n_1; // a_n = a_n + a_n-1 (=a_n+1)
            a_n_1 = temp; // a_n-1 = temp
        }

        // Return value of a_n.
        return a_n;
    }

    // Invalid algorithm used.
    return -1;
}

int main() {

    // Get user input.
    int n = 0;
    do {
        printf("n = ");
        scanf("%d", &n);
    } while(n < 0);

    // Print nth fibonacci number.
    printf("a_n (recursive) = %d\n", fibonacci(n, 1));
    printf("a_n (loop) = %d\n", fibonacci(n, 2));

    return 0;
}