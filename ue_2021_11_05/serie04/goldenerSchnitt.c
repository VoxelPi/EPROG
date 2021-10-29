/*
 * Aufgabe 4.3
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

/**
 * Calculates the min value of n so that a_n+1/a_n - a_n/a_n-1 <= 1/k is.
 */
int cauchy(int k) {
    assert(k > 0);

    int a = 1;
    int a_prev = 1;

    int n = 1;
    while (1) {
        // Calculate b.
        double b = ((a + a_prev) / (double)a) - (a / (double)a_prev);
        
        // Check if break condition is true.
        if (fabs(b) <= (1.0 / k)) {
            break;
        }
        
        // Calculates new values for a and a_prev.
        int tmp = a;
        a += a_prev;
        a_prev = tmp;

        // Increment n.
        ++n;
    }

    return n;
}

int main() {
    int k = 0;

    // Get user input for k.
    do {
        printf("k = ");
        scanf("%d", &k);
    } while (k <= 0);

    // Print result.
    printf("n = %d\n", cauchy(k));

    return 0;
}

/*
 * Tests:
 * Check that k is always > 0.
 * Check that k parameter of cauchy is always > 0.
 * Validate the output of cauchy(k).
 */ 