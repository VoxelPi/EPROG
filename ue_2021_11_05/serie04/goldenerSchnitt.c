/*
 * Aufgabe 4.3
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

// 0 1 2 3 4 5  6  7
// 1 1 2 3 5 8 13 21

/**
 * Calculates the min value of n so that |a_n+1/a_n - a_n/a_n-1| <= 1/k.
 */
int cauchy(int k) {
    assert(k > 0);

    int n = 1;
    int a = 1;
    int a_prev = 1;
    double b = ((a + a_prev) / (double)a) - (a / (double)a_prev);
    printf("%.35f <=? %.35f (%d)\n", fabs(b), 1.0/k, fabs(b) <= (1.0 / k));

    while (fabs(b) > (1.0 / k)) {
        // Calculate new values for a, a_prev and b.
        int tmp = a;
        a += a_prev;
        a_prev = tmp;

        b = ((a + a_prev) / (double)a) - (a / (double)a_prev);
        printf("%.35f <=? %.35f (%d)\n", fabs(b), 1.0/k, fabs(b) <= (1.0 / k));

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
 * Validate the output of cauchy(k) by manually calculating and comparing b_n with b_(n-1).
 */ 