/*
 * Aufgabe 4.5
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <stdio.h>

/**
 * Calculates the number k so that k <= sqrt(x) < (k+1)
 */ 
int wurzelschranke(double x) {
    assert(x >= 0);

    // Increment k until condition is met.
    int k = 0;
    while (x >= (k+1)*(k+1)) { //!(k*k <= x && x < (k+1)*(k+1))
        ++k;
    }
    
    return k;
}

int main() {
    double x = 0;

    // Ask for user input for variable x. (x >= 0)
    do {
        printf("x = ");
        scanf("%lf", &x);
    } while (x < 0);

    // Print result.
    printf("k = %d\n", wurzelschranke(x));

    return 0;
}

/*
 * Tests:
 * Test that x in wurzelschranke is always >= 0.
 * Test that user input for x is always >= 0.
 * Validate results of wurzelschranke by manually calculating value for a few values of x.
 */ 