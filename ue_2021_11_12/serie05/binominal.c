/*
 * Aufgabe 5.3
 * Peter Smek, 09.11.2021
 */

#include <assert.h>
#include <stdio.h>

/**
 * Calculates the binominalcoefficient of (n k) using one loop.
 */ 
int binominal(int n, int k) {
    assert(n >= 0);
    assert(k >= 0);
    assert(k < n);

    int num = 1;
    int den = 1;
    for (int i = 0; i < k; ++i) {
        num *= (n - i);
        den *= (i + 1);
    }

    return num / den;
}

/**
 * Calculates the binominalcoefficient of (n k) using two loops.
 */ 
int binominal2(int n, int k) {
    assert(n >= 0);
    assert(k >= 0);
    assert(k < n);

    int num = 1;
    for (int i = n-k+1; i <= n; ++i) {
        num *= i;
    }
    
    int den = 1;
    for (int i = 1; i <= k; ++i) {
        den *= i;
    }

    return num / den;
}

int main() {
    int k = 0, n = 0;

    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0);

    do {
        printf("k = ");
        scanf("%d", &k);
    } while (k < 0 || k > n);

    printf("binominal1(%d, %d) = %d\n", n, k, binominal(n, k));
    printf("binominal2(%d, %d) = %d\n", n, k, binominal2(n, k));
    return 0;
}